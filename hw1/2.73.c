#include <limits.h>

int saturating_add(int x, int y)
{
  int sum = y + x;
  int size = sizeof(int)<<3;
  int mask = 1;

  int signSum = (sum>>(size - 1)) & mask;
  int signY = (y>>(size - 1)) & mask;
  int signX = (x>>(size - 1)) & mask;

  int overflow1 = ~(signX ^ signY);
  int overflow2 = (signX ^ signSum) & overflow1;
  int exOver = 1 + ~overflow2;
  int exXSign = 1 + ~signX;                           
  int overflow3 = INT_MAX ^ exXSign;
  
  overflow3 = exOver & overflow3;
  sum = (~exOver) & sum;

  return (sum | overflow3);
}
