// G++ -E -P main.cpp > main.txt
// https://docs.google.com/document/d/1wsvavmMQIdqG5A7vLugcfcK9SV26VoyurbxQwgOy0Bc/edit?usp=sharing
#include "defines.h"

__FILE__ __DATE__ __TIME__

#define FILELOCATION SL_Dice


!d
FUNCTION(
	SAY( USERNAME rolled a )
	IF5( PARAM(2), =, d,
		SAY( RAND3( PARAM(1) , CALC( PARAM(1), *, PARAM(3) ), roll ) )
		,	//else
		SAY( RAND2( 1 , PARAM(1) ) )
	)
)

!d20
FUNCTION(
	SAY( USERNAME rolled a )
	IF5( RAND2(1,20), =, 1,
		SAY( Critical Fail! )
		,
		IF5( RAND2(1,20), =, 20,
			SAY( Critical Success! )
			,
			SAY( RAND2(1,20) )
		)
	)
)

// !dd
!rolld
FUNCTION(
	!rolld_actual RAND3(1,20,1) RAND3(1,20,2)
)

!rolld_actual // the actual command
FUNCTION(
	SAY( USERNAME rolled a )
	IF5( MIN( PARAM(1), PARAM(2) ), =, 1,
		SAY( Critical Fail with disadvantage! (PARAM(1)) (PARAM(2)) )
		,
		!rolld_notfail PARAM(1) PARAM(2)		
	)
)

!rolld_notfail // if it's not a crit fail
FUNCTION(
	IF5( PARAM(1), =, 20,
		!rolld_success PARAM(1) PARAM(2)
		,
		SAY( MIN( PARAM(1), PARAM(2) ) with disadvantage!  (PARAM(1)) (PARAM(2))  )
	)
)

!rolld_success // if it's a success
FUNCTION(
	IF5( PARAM(2), =, 20,
		SAY( Critical Success with disadvantage! (PARAM(1)) (PARAM(2)) )
		,
		SAY( MIN( PARAM(1), PARAM(2) ) with disadvantage!  (PARAM(1)) (PARAM(2))  )
	)
)

// !da
!rolla
FUNCTION(
	!rolla_2 RAND3(1,20,1) RAND3(1,20,2)

)

!rolla_2
FUNCTION(	
	SAY( USERNAME rolled a )
	IF5( MAX( PARAM(1), PARAM(2) ), =, 20,
		SAY( Critical Succes with advantage! (PARAM(1)) (PARAM(2)) )
		,
		IF5( PARAM(1), =, 1,
			IF5( PARAM(2), =, 1,
				SAY( Critical Fail with advantage! (PARAM(1)) (PARAM(2)) )
				,
				SAY( MAX( PARAM(1), PARAM(2) ) with advantage!  (PARAM(1)) (PARAM(2)) )
			)
			,
			SAY( MAX( PARAM(1), PARAM(2) ) with advantage!  (PARAM(1)) (PARAM(2))  )
		)
	)
)