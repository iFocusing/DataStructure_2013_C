#include"constant.h"

Status ClearStack(SqStack S)
{
	if(!S.base)
		exit(OVERFLOW);
	if(S.top==S.base)
		return TRUE;
	return FALSE;
}