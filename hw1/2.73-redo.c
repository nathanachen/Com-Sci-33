#include <limits.h>

int saturating_add(int x, int y)
{
  int sum;
  int size = sizeof(int)<<3;
  int mask = 1;
  
  int signX = (x>>(size - 1)) & mask;

  int overYes = __builtin_add_overflow(x, y, &sum);

  int exOver = 1 + ~overYes;
  int exXSign = 1 + ~signX;                           
  int over = exXSign^INT_MAX;
  over = exOver & over;
  sum = (~exOver) & sum;

  return sum|over;
}
