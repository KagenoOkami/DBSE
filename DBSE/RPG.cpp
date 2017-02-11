// G++ -E -P RPG.cpp > main.txt
// https://docs.google.com/document/d/1wsvavmMQIdqG5A7vLugcfcK9SV26VoyurbxQwgOy0Bc/edit?usp=sharing
#include "defines.h"

__FILE__ __DATE__ __TIME__

#define FILELOCATION SL_RPG


// USERNAME
#define MAXHEALTH 1
#define CURRENTHEALTH 2
#define TEMPHEALTH 3
// damage
#define DAMAGESIDES 4
#define DAMAGEAMOUNT 5
#define ARMOURCLASS 6
// Death
#define DEATHSAVES 7
#define DEATHFAILS 8
// Hitdice
#define HITDICESIDES 9
#define HITDICEMAX 10
#define HITDICELEFT 11
// Attributes
#define STRENGTH 12
#define DEXTERITY 13
#define CONSTITUTION 14
#define INTELLIGENCE 15
#define WISDOM 16
#define CHARISMA 17
// Skills
#define ACROBATICS 18
#define ANIMALHANDLING 19
#define ARCANA 20
#define ATHLETICS 21
#define DECEPTION 22
#define HISTORY 23
#define INSIGHT 24
#define INTIMIDATION 25
#define INVESTIGATION 26
#define MEDICINE 27
#define NATURE 28
#define PERCEPTION 29
#define PERFORMANCE 30
#define PERSUATION 31
#define RELIGION 32
#define SLEIGHTOFHAND 33
#define STEALTH 34
#define SURVIVAL 35
// Level
#define LEVEL 36
#define EXPERIANCE 37
// Status Effects
#define BLINDED 38
#define CHARMED 39
#define DEAFENED 40 
#define FRIGHTENED 41
#define GRAPPLED 42
#define INCAPACITATED 43
#define INVISIBLE 44
#define PARALIZED 45
#define PETRIFIED 46
#define POISONED 47
#define PRONE 48
#define RESTRAINED 49
#define STUNNED 50
#define UNCONSCIOUS 51
// Misc
#define SPEED 52
#define EXHAUSTION 53
#define HIDDEN 54
#define SHORTTERMMADNESS 55
#define LONGTERMMADNESS 56
#define INDEFINITEMADNESS 57
// DONE
#define EXISTS 58


// Allows a user to join the encounter
// !join
!join
FUNCTION(
	// Health
//	IF5( OBJ_GET(USERNAME,EXISTS), !=, TRUE,
		VAR_SET( USERNAME,)
		VAR_LOG( USERNAME, 10 )			//MAXHEALTH
		VAR_LOG( USERNAME, 11 )			//CURRENTHEALTH
		VAR_LOG( USERNAME, 0 )			//TEMPHEALTH
		// damage
		VAR_LOG( USERNAME, 6 )			//DAMAGESIDES
		VAR_LOG( USERNAME, 1 )			//DAMAGEAMOUNT
		VAR_LOG( USERNAME, 10 )			//ARMOURCLASS
		// Death
		VAR_LOG( USERNAME, 0 )			//DEATHSAVES
		VAR_LOG( USERNAME, 0 )			//DEATHFAILS
		// Hitdice
		VAR_LOG( USERNAME, 0)			//HITDICESIDES
		VAR_LOG( USERNAME, 0)			//HITDICEMAX
		VAR_LOG( USERNAME, 0)			//HITDICELEFT
		// Attributes
		VAR_LOG( USERNAME, 8 )			//STRENGTH
		VAR_LOG( USERNAME, 8 )			//DEXTERITY
		VAR_LOG( USERNAME, 8 )			//CONSTITUTION
		VAR_LOG( USERNAME, 8 )			//INTELLIGENCE
		VAR_LOG( USERNAME, 8 )			//WISDOM
		VAR_LOG( USERNAME, 8 )			//CHARISMA
		// Skills
		VAR_LOG( USERNAME, 0 )			//ACROBATICS
		VAR_LOG( USERNAME, 0 )			//ANIMALHANDLING
		VAR_LOG( USERNAME, 0 )			//ARCANA
		VAR_LOG( USERNAME, 0 )			//ATHLETICS
		VAR_LOG( USERNAME, 0 )			//DECEPTION
		VAR_LOG( USERNAME, 0 )			//HISTORY
		VAR_LOG( USERNAME, 0 )			//INSIGHT
		VAR_LOG( USERNAME, 0 )			//INTIMIDATION
		VAR_LOG( USERNAME, 0 )			//INVESTIGATION
		VAR_LOG( USERNAME, 0 )			//MEDICINE
		VAR_LOG( USERNAME, 0 )			//NATURE
		VAR_LOG( USERNAME, 0 )			//PERCEPTION
		VAR_LOG( USERNAME, 0 )			//PERFORMANCE
		VAR_LOG( USERNAME, 0 )			//PERSUATION
		VAR_LOG( USERNAME, 0 )			//RELIGION
		VAR_LOG( USERNAME, 0 )			//SLEIGHTOFHAND
		VAR_LOG( USERNAME, 0 )			//STEALTH
		VAR_LOG( USERNAME, 0 )			//SURVIVAL
		// Level
		VAR_LOG( USERNAME, 0 )			//LEVEL
		VAR_LOG( USERNAME, 0 )			//EXPERIANCE
		// Status Effects
		VAR_LOG( USERNAME, FALSE )		//BLINDED
		VAR_LOG( USERNAME, FALSE )		//CHARMED
		VAR_LOG( USERNAME, FALSE )		//DEAFENED
		VAR_LOG( USERNAME, FALSE )		//FRIGHTENED
		VAR_LOG( USERNAME, FALSE )		//GRAPPLED
		VAR_LOG( USERNAME, FALSE )		//INCAPACITATED
		VAR_LOG( USERNAME, FALSE )		//INVISIBLE
		VAR_LOG( USERNAME, FALSE )		//PARALIZED
		VAR_LOG( USERNAME, FALSE )		//PETRIFIED
		VAR_LOG( USERNAME, FALSE )		//POISONED
		VAR_LOG( USERNAME, FALSE )		//PRONE
		VAR_LOG( USERNAME, FALSE )		//RESTRAINED
		VAR_LOG( USERNAME, FALSE )		//STUNNED
		VAR_LOG( USERNAME, FALSE )		//UNCONSCIOUS
		// Misc
		VAR_LOG( USERNAME, 30 )			//SPEED
		VAR_LOG( USERNAME, 0 )			//EXHAUSTION
		VAR_LOG( USERNAME, FALSE )		//HIDDEN
		VAR_LOG( USERNAME, FALSE )		//SHORTTERMMADNESS
		VAR_LOG( USERNAME, FALSE )		//LONGTERMMADNESS
		VAR_LOG( USERNAME, FALSE )		//INDEFINITEMADNESS
		// DONE
		VAR_LOG( USERNAME, TRUE )		//EXISTS
		SAY( USERNAME has joined the pack!)
//		, // else
//		SAY( USERNAME is already part of the pack!)
//	)
)


// (attribute - 10) / 2
!system_getattributemod
FUNCTION(
	CALC( CALC(PARAM_1, -, 10) , DEVIDE, 2 )
)

// ( attributemod + proficiency + misc
//!system_getrollmod FUNCTION(
//							CALC( GET_VAR( USERNAMEPARAM(1), +, GET_VAR( USERNAME) )
//							)

// ( level / 4 ) +2
// level
!system_getproficiency
FUNCTION( 
	CALC( CALC( PARAM_1, DEVIDE, 2 ), +, 2 )
)

// username variablename newvalue
!system_setvar
FUNCTION(
	VAR_SET( PARAM(1)/PARAM(2), PARAM(3) )
)
// username variablename
// return void
!system_getvar
FUNCTION(
	VAR_GET( PARAM(1)/PARAM(2) )
)
// player
// return bool
!system_isdead
FUNCTION(
	IF5( GET_VAR(PARAM(1)/currenthealth), >,  0,
		FALSE
		,
		TRUE
	)
)

// playername
// return text
!attack
FUNCTION(
	IF5( !system_isdead USERNAME, =, 0,
		IF5( !system_isdead PARAM(1), =, 0,
			VAR_SET( REG(1), RAND3(1, 20, ar) )
			IF5( VAR_GET( REG(1) ), >=, GET_VAR(PARAM(1)/armourclass),
				VAR_SET( REG(2), RAND3( GET_VAR( PARAM(1)/damageamount ), CALC( GET_VAR( PARAM(1)/damageamount ), *, GET_VAR( PARAM(1)/damagesides) ), dr ) )
				IF5( VAR_GET( REG(1) ), =, 20,
					VAR_CALC( REG(1), *, 2 )
					SAY( USERNAME has hit PARAM(1) for GET_VAR( REG(2) ) critical damage! )
					,
					SAY( USERNAME has hit PARAM(1) for GET_VAR( REG(2) ) damage! )
				)
				VAR_CALC( PARAM(1)/currenthealth, -, GET_VAR( REG(2) ) )
				,
				SAY( Looks like USERNAME could not damage PARAM(1)! )
			)
			,
			SAY( Sorry, but PARAM(1) is dead )
		)
		,
		SAY( Sorry, but you are death )
	)
)







//!damage dicesides, diceamount, damagetype
!damage
FUNCTION( SAY( USERNAME took )
	RAND( PARAM_2, CALC(PARAM_1, *, PARAM_2) )
	IF4( PARAM_3,,,
		SAY(PARAM_3)
	)
	SAY( damage! )
)