The following algorithm gives how to evaluate a postfix expression.
1) Create a stack to store operands (or values).
2) Scan the given expression and do following for every scanned element.
    2a) If the element is a number, push it into the stack
    2b) If the element is a operator, pop operands for the operator from stack. Evaluate the operator and push the result back to the stack
3) When the expression is ended, the number in the stack is the final answer
In this project, with the code: defs.h, stack.h stack.c provided, one is required to implement the above algorithm in the provided prototype .c file eval_postfix.c, and the provided function prototype: int eval_postfix(int *postfix_exp, int len), where postfix_exp is the integer array holding the postfix expression, and len is the number of elements in the array (recall that this postfix_exp is the product of the previous assignment).
Assume that all operands are integers in this project, and division operation '/' will result in integer.
a main.c is provided to test the implementation.
