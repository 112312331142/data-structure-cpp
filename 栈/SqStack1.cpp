#include<stdio.h>
#include<malloc.h>
#define MaxSize 100
//typedef double ElemType;
typedef struct linknode1 {
	double data[MaxSize];
	int top;
}SqStack1;

void InitStack1(SqStack1*& s) {
	s = (SqStack1*)malloc(sizeof(SqStack1));
	s->top = -1;
}

void DestroyStack1(SqStack1*& s) {
	free(s);
}

bool StackEmpty1(SqStack1* s) {
	return s->top == -1;
}

bool Push1(SqStack1*& s, double e) {
	if (s->top == MaxSize - 1)
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

bool Pop1(SqStack1*& s, double& e) {
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}

bool GetTop1(SqStack1* s, double& e) {
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	return true;
}