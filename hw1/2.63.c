#include <limits.h>

unsigned long srl(unsigned long x, int k)
{
  /* Perform shift arithmetically */
  unsigned long xsra = (int) x >> k;
  int size = sizeof(int)<<3;
  
  unsigned mask = (1<<(size - k)) - 1;
  xsra = xsra&mask;
  return xsra;
}

long sra(long x, int k)
{
  /* Perform shift logically */
  long xsrl = (unsigned) x >> k;
  int size = sizeof(int)<<3;
  
  unsigned mask1 = (1<<(size - 1));
  int mask2 = x&mask1;
  mask2 = mask2 >> (k - 1);
  xsrl = xsrl|mask2;
  return xsrl;
}
