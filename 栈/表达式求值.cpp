//#include<stdio.h>
//#include<stdlib.h>
//#include"SqStack.cpp"
//#include"SqStack1.cpp"
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
//	DestroyStack(Optr);
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
//	DestroyStack1(Opnd);
//	return e;
//}
//
//int main() {
//	char exp[] = "(56-20)/(4+1)";
//	char postexp[MaxSize];
//	trans(exp,postexp);
//	printf("%s\n", exp);
//	printf("%s\n", postexp);
//	printf("%g\n", compvalue(postexp));
//	return 1;
//}