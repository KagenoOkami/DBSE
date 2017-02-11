// G++ -E -P main.cpp > main.txt
// https://docs.google.com/document/d/1wsvavmMQIdqG5A7vLugcfcK9SV26VoyurbxQwgOy0Bc/edit?usp=sharing
#include "defines.h"

__FILE__ __DATE__ __TIME__

#define FILELOCATION SL_Encounter

//-------------- GLOBAL VARS --------------------
// encounter.ongoing bool
// encounter.joinphase bool
// encounter.turn int
// encounter.players int

//-------------- FUNTION STATIC ------------------
// USERNAME.initiative int
// USERNAME.health int
// USERNAME.damage int
// USERNAME.armourclass int

!dnd_encounter_init FUNCTION( 
								VAR_SET( encounter.ongoing, FALSE )
								VAR_SET( encounter.joinphase, FALSE)
								VAR_SET( encounter.turn, 0)
								VAR_SET( encounter.players, 0)
								SAY( D&D encounter has been initialized! )
							)

// Starts an encounter.
!start_encounter IF5( VAR_GET( encounter.ongoing ), =, FALSE,
						VAR_SET( encounter.ongoing, TRUE )
						VAR_SET( encounter.joinphase, TRUE )
						VAR_SET( encounter.players, 0 )
						SAY( An encounter has started! Be ready to sign up with !join )
//						EXEC( CALC(5, *, 60 ), !Join_end )
						,
						SAY( USERNAME, there is already an encounter ongoing )
					)

// Allows a user to join the encounter
// !join
!join IF5( VAR_GET( encounter.ongoing ), =, TRUE,
		   IF5( VAR_GET( encounter.joinphase ), =, TRUE,
					VAR_SET( USERNAME/initiative, RAND2(1, 20))
					VAR_SET( USERNAME/health, 10 )
					VAR_SET( USERNAME/damage, 6 )
					VAR_SET( USERNAME/armourclass, 10 )
					VAR_SET( encounter.players, CALC( VAR_GET(encounter.players), +, 1 ))
					SAY( USERNAME joined the fray with initiative RAND2(1, 20)! )
					,
					SAY( Sorry USERNAME but you cannot join the encounter now ) 
				)
				,
				SAY( Sorry USERNAME but there is no encounter going on right now )
			)

!join_end IF4( VAR_GET( encounter.ongoing ), =, TRUE,
		   IF4( VAR_GET( encounter.joinphase ), =, TRUE,
					VAR_SET( encounter.joinphase, FALSE )
					SAY( Everyone signed thier papers proper? Gather your swords, bows, shields and floppy trouts, we are going to war!)
//					EXEC( 60, !start_round )
				)
			  )

!start_round IF4( VAR_GET( encounter.ongoing ), =, TRUE,
					 VAR_SET( encounter.joinphase, FALSE )
					 VAR_SET( encounter.battlephase, TRUE )
					 VAR_SET( encounter.turn, 20 )
					 SAY( A new round, new chances! )
//					 EXEC( 60, !next_turn )
				)

// !attack playername[1]
!attack FUNCTION(   VAR_SET( reg1, RAND3(1, 20, a) )
					VAR_SET( reg2, RAND3(1,VAR_GET(USERNAME.damage),d) )
					IF5( VAR_GET( encounter.ongoing ), =, TRUE,
						IF5( VAR_GET( encounter.battlephase ), =, TRUE,
							IF5( VAR_GET( USERNAME.initiative ), =, 20,
								IF5( VAR_GET( USERNAME.health ), >, 0,
									IF5( VAR_GET( PARAM(1).health ), >, 0,
										IF5( VAR_GET(reg1), >=, PARAM(1).armourclass,
											IF5( VAR_GET(reg1), =, 20,
													VAR_CALC( PARAM(1).health, -, CALC( VAR_GET(reg2), *, 2 ) )
													SAY( USERNAME crittalicy hit PARAM(1) for CALC( VAR_GET(reg2), *, 2 )! )
													,
													VAR_CALC( PARAM(1).health, -, VAR_GET(reg2) )
													SAY( USERNAME hit PARAM(1) for VAR_GET(reg2) damage! )
												)
												,
												SAY( USERNAME did not manage to hit PARAM(1) )
											)
											,
											SAY( PARAM(1) is not alive anymore )
										)
										,
										SAY( USERNAME, you are not alive )
									)
									,
									SAY( USERNAME, it is not your turn! )
								)
								,
								SAY( USERNAME, the battlephase has not started yet! )
							)
							,
							SAY( USERNAME, there is no encounter ongoing )
						)
					)

//
!next_turn IF4( VAR_GET(encounter.ongoing), >=, TRUE,
					IF4( VAR_GET( encounter.turn ), <, 20,
						VAR_CALC( encounter.turn, -, 1 )
						SAY( The battle is moving on! Its turn VAR_GET( encounter.turn )! )
//						,
//						EXEC(0, !start_round )
					)
				)
// increments the turn so that the next (set of) player and monsters can have thier turn

// Ends the encounter
!end_encounter IF5( VAR_GET(encounter.ongoing ), >=, TRUE,
						SAY( as the dust settles you count your dead, you count your loot )
						VAR_SET( encounter.ongoing, FALSE)
						,
						VAR_SET( encounter.ongoing, FALSE)
						SAY( USERNAME there is no encounter to end )
					)



// ------------------- 
















// !contest target_player bet-gems
!contest 

// bet-gems
!contest_accept
// Say that you accepted, and immediatly roll 2 dice and declare the winner/loser (first roll is attacker, second is defender.
// Winner can't take more gems than the loser bet. The rest is returned.
//

//
!contest_decline
// Say that you declined and end the game.