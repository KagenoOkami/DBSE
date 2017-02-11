// ---------------- SUPER DEFINES ------------------------

//#define FOR( begin, till, with, lambda ) if( begin, >=, till, , lambda VAR_CALC( begin, +, with ) FORSTEP
//#define FORSTEP

#define FUNCTION( ... ) __VA_ARGS__
#define SAY( ... ) __VA_ARGS__

#define MIN( lhs, rhs ) !min lhs rhs

#define MAX( lhs, rhs ) 

#define REG_CALC( var_name, op, value ) VAR_CALC( REG_GET( var_name ), op, value )

//#define REG_SET(reg,value) VAR_SET(REG(reg),value)
//#define REG_GET(reg) VAR_GET(REG(reg))

#define OBJ_GET(obj_name,pointer) READFILE2(obj_name,pointer)

#define VAR_CALC(var_name,op,value) VAR_SET( var_name, CALC( VAR_GET( var_name ), op, value ) )

#define VAR_LOG( var_name, value ) SAVELOG( FILELOCATION-var_name, value)
#define VAR_SET( var_name, value ) SAVEFILE( FILELOCATION-var_name, value)
#define VAR_GET( var_name ) READFILE1( FILELOCATION-var_name )


// Read a file, replace what you want to replace and then save it.
// Save( replace( read( param(1) ), param(2) )
//#define REPLACEFILE( SAVEFILE( READFILE(  ) )

//!Variable_Create savefile( variablename, value )
//!Variable_Assign savefile( variablename, value )
//!Variable_Get readfile2( VariableName, Line )

// For loop

// ---------------- FUCTION CALLS ------------------------

// Generates a random number between min and max
// Returns int
#define RAND2(min, max) @rand@[min|max]
// Generates a random number between min and max, and is bound to uni
// Returns int
#define RAND3(min, max, uni) @rand@[min|max|unique]

// If statement without else
#define IF4( lhs, op, rhs, suc ) @if@[op||lhs||rhs||suc]
// If statement with else
#define IF5( lhs, op, rhs, suc, fail ) @if@[op||lhs||rhs||suc||fail]

// Calculates op val1 val2
#define CALC( lhs, op, rhs ) @calc@[op|lhs|rhs]

// saves 'string' to file at filelocation.
#define SAVEFILE( filelocation, string ) @savefile@[filelocation.txt,string]
// appends 'string' to file at filelocation.
#define SAVELOG( filelocation, string ) @savelog@[filelocation.txt,string]
// Reads 'string' from file at filelocation
#define READFILE1( filelocation )  @readfile@[filelocation.txt]
// Reads line 'line' from file at filelocation
#define READFILE2( filelocation, line )  @readfile@[line,filelocation.txt]

#define EXEC( time, command ) @exec@[time,command]

// ------------------ VARIABELS ---------------------------

#define ME() /me

#define USERNAME @user@

#define PARAM(index) @target@[index]
//#define REG(index) REG-index

#define TRUE 1
#define FALSE 0

#define DEVIDE /

//#define \ /