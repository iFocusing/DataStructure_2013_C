#include"constant.h"

Status DestroyStack(SqStack * S)
{
	if(!S->base)
		exit(OVERFLOW);
	free(S->base);
	S->base=NULL;
	return OK;
}