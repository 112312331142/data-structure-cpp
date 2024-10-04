//#include<stdio.h>
//#include<stdlib.h>
//
//using namespace std;
//#define MaxSize 100
//
//typedef char ElemType;
//typedef double ElemType1;
//
//typedef struct {
//	ElemType data[MaxSize];
//	int top;
//}SqStack;
//
//typedef struct {
//	ElemType1 data[MaxSize];
//	int top;
//}SqStack1;
//
//void InitStack(SqStack*& s) {
//	s = new SqStack;
//	s->top = -1;
//}
//
//bool Push(SqStack*& s, ElemType e) {
//	if (s->top == MaxSize - 1)
//		return false;
//	s->top++;
//	s->data[s->top] = e;
//	return true;
//}
//
//void Pop(SqStack*& s, ElemType& e) {
//	if (s->top == -1)
//		return;
//	e = s->data[s->top];
//	s->top--;
//}
//
//void InitStack1(SqStack1*& s) {
//	s = new SqStack1;
//	s->top = -1;
//}
//
//void Push1(SqStack1*& s, ElemType1 e) {
//	if (s->top == MaxSize - 1)
//		return;
//	s->top++;
//	s->data[s->top] = e;
//}
//
//void Pop1(SqStack1*& s, ElemType1& e) {
//	if (s->top == -1)
//		return;
//	s->data[s->top] = e;
//	s->top--;
//}
//
//bool StackEmpty(SqStack* op) {
//	return op->top == -1;
//}
//
//bool GetTop1(SqStack1* op, ElemType1& e) {
//	if (op->top == -1)
//		return false;
//	e = op->data[op->top];
//	return true;
//}
//
//bool GetTop(SqStack* op, ElemType& e) {
//	if (op->top == -1)
//		return false;
//	e = op->data[op->top];
//	return true;
//}
//
//void trans(char* exp, char postexp[]) {
//	char e;
//	SqStack* Optr;
//	InitStack(Optr);
//	int i = 0;
//	while (*exp != '\0') {
//		switch (*exp) {
//		case'(':
//			Push(Optr, '(');
//			exp++;
//			break;
//		case')':Pop(Optr, e);
//			while (e != '(') {
//				postexp[i++] = e;
//				Pop(Optr, e);
//			}
//			exp++;
//			break;
//		case'+':
//		case'-':
//			while (!StackEmpty(Optr)) {
//				GetTop(Optr, e);
//				if (e != '(') {
//					postexp[i++] = e;
//					Pop(Optr, e);
//				}
//				else break;
//			}
//			Push(Optr, *exp);
//			exp++;
//			break;
//		case'*':
//		case'/':
//			while (!StackEmpty(Optr)) {
//				GetTop(Optr, e);
//				if (e == '*' || e == '/') {
//					postexp[i++] = e;
//					Pop(Optr, e);
//				}
//				else
//					break;
//			}
//			Push(Optr, *exp);
//			exp++;
//			break;
//		default:
//			while (*exp >= '0' && *exp <= '9') {
//				postexp[i++] = *exp;
//				exp++;
//			}
//			postexp[i++] = '#';
//		}
//	}
//	while (!StackEmpty(Optr)) {
//		Pop(Optr, e);
//		postexp[i++] = e;
//	}
//	postexp[i] = '\0';
//}
//
//double compvalue(char* postexp) {
//	double d, a, b, c, e;
//	SqStack1* Opnd;
//	InitStack1(Opnd);
//	while (*postexp != '\0') {
//		switch (*postexp) {
//		case'+':
//			Pop1(Opnd, a);
//			Pop1(Opnd, b);
//			c = b + a;
//			Push1(Opnd, c);
//			break;
//		case'-':
//			Pop1(Opnd, a);
//			Pop1(Opnd, b);
//			c = b - a;
//			Push1(Opnd, c);
//			break;
//		case'*':
//			Pop1(Opnd, a);
//			Pop1(Opnd, b);
//			c = b * a;
//			Push1(Opnd, c);
//			break;
//		case'/':
//			Pop1(Opnd, a);
//			Pop1(Opnd, b);
//			if (a != 0) {
//				c = b / a;
//				Push1(Opnd, c);
//				break;
//			}
//			else {
//				printf("\n\terror!\n");
//				exit(0);
//
//			}
//			break;
//		default:
//			d = 0;
//			while (*postexp >= '0' && *postexp <= '9') {
//				d = 10 * d + *postexp - '0';
//				postexp++;
//			}
//			Push1(Opnd, d);
//			break;
//		}
//		postexp++;
//	}
//	GetTop1(Opnd, e);
//	return e;
//}
//
//int main() {
//	char exp[] = "(56-20)/(4+1)";
//	char postexp[MaxSize];
//	trans(exp, postexp);
//	printf("%s\n", exp);
//	printf("%s\n", postexp);
//	printf("%g\n", compvalue(postexp));
//	return 1;
//}