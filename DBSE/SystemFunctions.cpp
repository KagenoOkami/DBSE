#include "defines.h"

__FILE__ __DATE__ __TIME__

#define FILELOCATION system

!min lhs rhs
FUNCTION(
	IF5( PARAM(1), >=, PARAM(2), PARAM(1), PARAM(2) )
)

!max lhs rhs
FUNCTION(
	IF5( PARAM(1), >=, PARAM(2), PARAM(2), PARAM(1) )
)

!param1 1
FUNCTION(
	SAY( (PARAM(1)) )
)

!param2 1 2
FUNCTION(
	SAY( (PARAM(1)) (PARAM(2)) )
)

!param3 1 2 3
FUNCTION(
	SAY( (PARAM(1)) (PARAM(3)) (PARAM(3)) )
)

!switch RunThis
@if@[@target@[1]||RunThis||Run Whatever||Do Nothing]