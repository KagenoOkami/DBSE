#include "defines.h"

__FILE__ __DATE__ __TIME__

#define FILELOCATION SL_RPG

!attack
FUNCTION(
	VAR_SET( reg1, RAND3(1, 20, ar) )
	SAY( USERNAME takes a swing at PARAM(1) and)
	IF5( VAR_GET(reg1), >=, 10,
		SAY( hits PARAM(1) for)
		VAR_SET( reg2, RAND3(1, 6, dr ) )
		IF5( VAR_GET(reg1), =, 20,
			VAR_CALC(reg2, *, 2 )
			SAY( VAR_GET(reg2) critical damage! (VAR_GET(reg1))(VAR_GET(reg2)) )
			,	// else
			SAY( VAR_GET(reg2) damage! (VAR_GET(reg1))(VAR_GET(reg2)))
		)
		,	// else
		SAY( misses! (VAR_GET(reg1)))
	)
)

!slap
FUNCTION(
	VAR_SET( reg1, RAND3(1, 20, ar) )
	SAY( USERNAME picks up the closest item and)
	IF5( VAR_GET(reg1), >=, 10,
		VAR_SET( reg2, RAND3(1, 4, dr ) )
		SAY( hits PARAM(1) for)
		IF5( VAR_GET(reg1), =, 20,
			VAR_CALC(reg2, *, 2 )
			SAY( VAR_GET(reg2) critical damage! (VAR_GET(reg1))(VAR_GET(reg2)) )
			,	// else
			SAY( VAR_GET(reg2) damage! (VAR_GET(reg1))(VAR_GET(reg2)))
		)
		,	// else
		SAY( misses PARAM(1)! (VAR_GET(reg1)))
	)
)

!hide
FUNCTION( VAR_SET( reg1, RAND3(1, 20, ar) )
	IF5( VAR_GET(reg1), >=, 10,
		IF5( VAR_GET(reg1), =, 1,
			SAY( HEY CHAT, USERNAME IS TRYING TO HIDE ( VAR_GET(reg1) ) )
			,	// else
			SAY( USERNAME disapears into the shadows... ( VAR_GET(reg1) ) )
		)
		,	// else
		SAY( USERNAME steps on a branch and alerts some people of him trying to sneak away )
	)
)

!wildsurge
FUNCTION (
	READFILE2( wildsurge, RAND2(1, 200) )
)

!trickortreat
FUNCTION (
	READFILE2( tricksandtreats, RAND2(1, 43) )
)

!gremlins
FUNCTION (
	SAY( The gremlins are attacking! )
	READFILE2( tricksandtreats, RAND2(1, 43) )
)

!gm_says
SAY( ME() *in a narrator voice* PARAM(1|) )

!howls
SAY( ME() howls at USERNAME )

!deathcount
SAY( Has he really died again?! (@counter@) )


!baseroll
FUNCTION(
	VAR_SET( reg1, RAND3(1, 20, ar) )
	IF5( VAR_GET(reg1), >=, 10,
		IF5( VAR_GET(reg1), =, 1,
			SAY( Critical Fail ( VAR_GET(reg1) ) )
			,	// else
			IF%( VAR_GET(reg1), =, 20,
				SAY( Critical Success ( VAR_GET(reg1) ) )
				,
				SAY( Roll Success ( VAR_GET(reg1) ) )
			)
		)
		, // else
		SAY( Roll Fail ( VAR_GET(reg1) ) )
	)
)

!check // number to roll against
FUNCTION( VAR_SET( reg1, RAND3(1, 20, ar) )
	IF5( VAR_GET(reg1), >=, PARAM(1),
		IF5( VAR_GET(reg1), =, 1,
			SAY( USERNAME suffered a Critical Fail! ( VAR_GET(reg1) ) )
			,	// else
			IF%( VAR_GET(reg1), =, 20,
				SAY( USERNAME had a Critical Success ( VAR_GET(reg1) ) )
				, // else
				SAY( USERNAME succeeded ( VAR_GET(reg1) ) )
			)
		)
		, // else
		SAY( USERNAME failed ( VAR_GET(reg1) ) )
	)
)