#define R 7
#define S 5
#define T 8

long A[R][S][T];

long ele (long i, long j, long k) 
{
  return A[R - i][1 - j][k - 1];
}

/*
(1)
The equation for the memoryaddress of a 3-D array can be derived from equation 3.1
by treating the 3-D array as a 2-D array with a 1-D array as the first dimension and
a 2-D array as the second dimension, adding up to 3-D.

Equation 3.1 is &D[i][j] = xD + L*(C*i + j), but now we transform that into
A[R][S][T] = xA + L*((S*T*i) + (T*j) + k).

(2)
L = 8 because type long

A[R-i][1-j][k-1]=xA+8*(S*T*(R-i)+T*(1-j)+k-1)

  movl	$7, %eax              // 7
	subq	%rdi, %rax            // 7-i
	leaq	(%rax,%rax,4), %rax   // 5*(7-i)
	subq	%rsi, %rax            // 5*(7-i) - j
	leaq	7(%rdx,%rax,8), %rax  // 8*(5*(7-i) - j)+k+7
	movq	A(,%rax,8), %rax      // A[8*(5*(7-i)-j)+k+7]

offset:
  8*(5*(7-i)-j)+k+7
= 8*5*(7-i)-8*j+k+7

Hypothesis: R=7, T=8, S=5

double-check:
  S*T*(R-i)+T*(1-j)+k-1
= S*T*(R-i)+T-T*j+k-1
= 5*8*(7-i)+8-8*j+k-1 = 8*5*(7-i)-8*j+k+7

Final Answer: R=7, T=8, S=5
*/
