#include"constant.h"

Status Push(SqStack * S,SElemType e)
{
	if(!S->base)
		exit(OVERFLOW);
	if(S->top-S->base>=S->stacksize)
		S->base=(SElemType *)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(SElemType));
	if(!S->base)
		exit(OVERFLOW);
	S->top=S->base+S->stacksize;
	S->stacksize+=STACKINCREMENT;
	*S->top++=e;
	return OK;
}