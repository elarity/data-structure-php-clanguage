#include <stdio.h>

int main( int argc, char * argv[] ) {
  int target = 938;
  int arr_index;
  int arr_length;
  int arr[]  = { 11, 234, 12, 44, 4534, 134, 94, 938, 13342, 87762 }; 
  arr_length = sizeof( arr ) / sizeof( int ); 
  for( int i = 0; i < arr_length; i++ ) {
    if ( target == arr[ i ] ) {
      arr_index = i; 
      break; 
    }
  }
  printf( "bingo : %d\n", arr_index );
  return 0;
}
