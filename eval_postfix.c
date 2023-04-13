#include<stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdbool.h>

#include <string.h>

#include "stack.h"

int ch_to_i(char c)
{
	return c - '0';
}

int evaluate(char op, int left_arg, int right_arg)
{
	int r;

	switch (op) {
	case '+':
		r = left_arg + right_arg;
		break;
	case '-':
		r = left_arg - right_arg;
		break;
	case '*':
		r = left_arg * right_arg;
		break;
	case '/':
		r = left_arg / right_arg;
		break;
	default:
		assert(0);
		break;
	}

	return r;
}

int eval_postfix(char *postfix_exp)
{
	struct stack s;
	int len, i, r;
	int left_arg, right_arg;
	char c;

	init_stack(&s);

	len = strlen(postfix_exp);

	for (i = 0; i < len; i++) {
		c = postfix_exp[i];

		if (c >= '0' && c <= '9') {
			push(&s, ch_to_i(c));
		}
		else {
			assert(!is_empty(&s));
			right_arg = pop(&s);

			assert(!is_empty(&s));
			left_arg = pop(&s);

			push(&s, evaluate(c, left_arg, right_arg));
		}
	}
	
	assert(!is_empty(&s));

	r = pop(&s);

	assert(is_empty(&s));

	uninit_stack(&s);

	return r;
}

void main()
{
	char exp[256];
	int r;

	strcpy(exp, "28+73/*");
	//strcpy(exp, "25*64//23*+");

	printf("%s: ", exp);
	r = eval_postfix(exp);

	printf("%d", r);
}