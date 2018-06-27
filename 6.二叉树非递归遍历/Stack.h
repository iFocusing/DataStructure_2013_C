#ifndef _STACK_H
#define _STACK_H
#include <stdio.h>
#include <stdlib.h>


#define Type		  int
#define INITIAL_SIZE  30				//ջ�ĳ�ʼ����С---initial size of the stack
#define INCREASE_SIZE 20				//ջ��С������-----increase size of the stack
#define ROW           10				//��ӡջ��Ԫ�ص�ÿ�и���---the number of row
#define debug

typedef struct stack
{
	Type *data;
	int top;							//ջ��ָ��----top stack point
	int StackSize;						//ջ�Ĵ�С----size of the stack
}Stack;

/*************************************************************************
��������--------function definition
*************************************************************************
�������ƣ�InitStack
��������: ��ջ���г�ʼ��
����ֵ��  Stack *
����ֵ��  ��ʼ���ɹ�����0�������˳�
*************************************************************************/
int InitStack(Stack *stack)
{
	stack->data = (Type *)malloc(INITIAL_SIZE*sizeof(Type)); //ΪԪ�ؿ��ٿռ�--alloc the space for element
	if(stack->data == NULL)
	{
		fprintf(stderr,"���ٿռ�ʧ��");
		exit(1);
	}
	stack->top  = -1;										//ջ��ָ��Ϊ-1--set top point -1
	stack->StackSize = INITIAL_SIZE;						//��ʼ����С----set initial size

	#ifdef debug
		puts("��ʼ��ջ�ɹ���");
	#endif

	return 0;
}

/*************************************************************************
�������ƣ�Push
��������: ѹջ����
����ֵ��  Stack *,Type
����ֵ��  ��ʼ���ɹ�����0�����򷵻�1
*************************************************************************/
int Push(Stack *stack,Type elem)
{
	if(stack->top >= stack->StackSize - 1)
	{
		//����ռ䲻���ˣ������¿����µĿռ�--if the space is not enough,realloc the space
		stack->data = (Type *)realloc(stack->data,(stack->StackSize + INCREASE_SIZE)*sizeof(Type));
		stack->StackSize  += INCREASE_SIZE;

		#ifdef debug
			puts("�����¿ռ�ɹ���");
		#endif

		if(stack->data == NULL)
		{
			fprintf(stderr,"���ٿռ�ʧ�ܣ�ջ�Ѿ����ˣ�/n");
			return 1;
		}
	}
	stack->top +=  1;
	stack->data[stack->top] = elem;

	#ifdef debug
		puts("ѹջ�ɹ���");
	#endif

	return 0;
}

/*************************************************************************
�������ƣ�Pop
��������: ��ջ����
����ֵ��  Stack *,Type
����ֵ��  ���ص�����ֵ
*************************************************************************/
Type Pop(Stack *stack,Type elem)
{
	if(stack->top == -1)
	{
		fprintf(stderr,"ջ�Ѿ��գ���ջʧ�ܣ�");
		exit(1);
	}
	elem = stack->data[stack->top];

	stack->top --;
	#ifdef debug
		puts("��ջ�ɹ���");
	#endif
	return elem;
}

/*************************************************************************
�������ƣ�IsEmpty
��������: �ж�ջ�Ƿ�Ϊ��
����ֵ��  Stack *,Type
����ֵ��  Ϊ�շ���1�����򷵻�0
*************************************************************************/
int StackEmpty(Stack *stack)
{
	if(stack->top == -1)
	{
		return 1;
	}

	return 0;
}


/*************************************************************************
�������ƣ�getTopElem
��������: ���ջ��Ԫ��
����ֵ��  Stack *,Type
����ֵ��  ����ջ��Ԫ��
*************************************************************************/
Type GetTop(Stack *stack,Type elem)
{
	Type top;
	top = stack->data[stack->top];
	return top;
}

#endif
