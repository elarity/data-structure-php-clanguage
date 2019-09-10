#include <stdio.h>

int main( int argc, char * argv[] ) {
  int arr_index;
  int target = 9381;
  int arr[]  = { [1]=11, 234, 12, 44, 4534, 134, 94, 938, 13342, 87762 }; 
  arr[ 0 ]   = target;
  int arr_length = sizeof( arr ) / sizeof( int ); 
  int arr_right_limit = arr_length - 1;
  while( arr[ arr_right_limit ] ) {
    //printf( "%d\n", arr[ arr_right_limit ] );
    if ( target == arr[ arr_right_limit ] ) {
      arr_index = arr_right_limit; 
      break; 
    }
    arr_right_limit--;
  }
  //printf( "bingo : %d\n", arr_index );
  if ( 0 == arr_index ) {
    printf( "没有找到\n" );
  }
  else {
    printf( "找到了，位置为%d\n", arr_index );
  }
  return 0;
}
