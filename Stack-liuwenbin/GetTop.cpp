#include"constant.h"

Status GetTop(SqStack S,SElemType * e)
{
	if(S.base==S.top)
		return ERROR;
	*e=*(S.top-1);
	return OK;
}