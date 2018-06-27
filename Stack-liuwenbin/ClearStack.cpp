#include"constant.h"

Status ClearStack(SqStack * S)
{
	if(!S->base)
		exit(OVERFLOW);
	S->top=S->base;
	return OK;
}