#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define add(...) add_(__VAR_LIST__,3,2,1,0)
#define add_(_3, _2, _1, N, ...) N


int addingNumbers( int nHowMany, ... )
{
  int Sum =0;
  
  va_list ArgList;
  va_start( ArgList, nHowMany );
  
  for( int i = 0; i < nHowMany; i++ )
    Sum += va_arg( ArgList, int );
  
  va_end( ArgList );
  
  return Sum;
} 

int main( int argc, char** argv)
{
 // system( "clear" );
 printf( "\n\n Variadic functions: \n\n" );

 printf( "\n 10 + 20 = %d ",           addingNumbers( 2, 10, 20 )  );
 printf( "\n 10 + 20 + 30 = %d ",      addingNumbers( 3, 10, 20, 30 )  );
 printf( "\n 10 + 20 + 30 + 40 = %d ", addingNumbers( 4, 10, 20, 30, 40 )  );

 printf( "\n\n" );

 return EXIT_SUCCESS;
}