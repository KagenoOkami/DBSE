#include "defines.h"

__FILE__ __DATE__ __TIME__

#define FILELOCATION SL_GROUPCHECK

// balance // 0> means failed, 0< succeeded
// DC
// ongoing

string groupcheck_start( int DC );
FUNCTION(
	VAR_SET(groupcheck,TRUE)		// ongoing
	VAR_LOG(groupcheck,PARAM(1))	// DC
	VAR_LOG(groupcheck,0)			// balance
	SAY( USERNAME has started a groupcheck! Use !groupcheck and roll higher than PARAM(1) to help him! )
)

string groupcheck_end( void );
FUNCTION( // end the groupcheck and see if they failed
	VAR_SET(ongoing,FALSE)
	IF5( VAR_GET(balance), >, 0,
		SAY( Looks like the group succeeded its check! ( VAR_GET(balance) ) )
		, // else
		SAY( Looks like the group failed its check ( VAR_GET(balance) ) )
	)
)

string groupcheck( void );
FUNCTION(

	IF5( VAR_GET(ongoing), =, TRUE,
		IF5( RAND2(1, 20), >=, VAR_GET(DC), // check if that roll went against
			IF5( RAND2(1, 20), =, 20,
				SAY( USERNAME rolled a Critical Success ( RAND2(1, 20) )(+2) )
				VAR_CALC(balance,+,2)
				,	// else
				SAY( USERNAME rolled a success ( RAND2(1, 20) )(+1) )
				VAR_CALC(balance,+,1)
			)
			,	// else
			IF5( RAND2(1, 20), =, 1,
				SAY( USERNAME rolled a Critical Fail ( RAND2(1, 20) )(-2) )
				VAR_CALC(balance,-,2)
				,	// else
				SAY( USERNAME rolled a fail ( RAND2(1, 20) ) (-1) )
				VAR_CALC(balance,-,1)
			)
		)
		,	// else
		SAY( USERNAME, there is no groupcheck ongoing )
	)
)