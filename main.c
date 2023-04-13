#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

int eval_postfix( int *exp, int len );

void main()
{
	int r;
  int exp[32] = { 32, 64, '+', 96, '+' };
  int len = 5;

  r = eval_postfix(exp, len);

	printf("%d", r);
}
