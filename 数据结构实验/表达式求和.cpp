//#include<iostream>
//#include<string.h>
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
//void InitSqStack(SqStack*& s) {
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
//void InitSqStack1(SqStack1*& s) {
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
//	e=s->data[s->top];
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
//ElemType Precede(ElemType a, ElemType b) {//a是op栈顶运算符，b是表达式的运算符。
//	ElemType f=' ';//定义f存放返回的符号
//	switch (b) {//表达式符号
//	case'+':
//		if (a == '(' || a == '=')//>表示退栈运算符，并存放入postexp
//			f = '<';
//		else
//			f = '>';
//		break;
//	case'-':
//		if (a == '(' || a == '=')
//			f = '<';
//		else
//			f = '>';
//		break;
//	case'*':
//		if (a == '(' || a == '+' || a == '-' || a == '=')//乘除的优先级比加减高
//			f = '<';
//		else
//			f = '>';
//		break;
//	case'/':
//		if (a == '(' || a == '+' || a == '-' || a == '=')
//			f = '<';
//		else
//			f = '>';
//		break;
//	case'('://表示一个子表达式的开始，直接将其进栈
//			f = '<';
//		break;
//	case')'://表示一个表达式的结束，需要计算表达式的值，出栈并存入postexp
//		if (a == '(' || a == '=')
//			f = '=';
//		else
//			f = '>';
//	}
//	return f;
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
//	//将算术表达式exp转换成后缀表达式postexp
//	char e;
//	SqStack* op; //定义并初始化运算符栈op;
//	int i=0;//作为访问postexp的下标
//	InitSqStack(op);
//	Push(op, '=');
//	while (*exp != '\0') {
//		if (*exp >= '0' && *exp <= '9') {
//			//将后续的所有数字均依次存放到postexp中, 并以字符'#'标志数值串结束;
//			while (*exp >= '0' && *exp <= '9') {
//				postexp[i++] = *exp;
//				exp++;
//			}
//			postexp[i++] = '#';
//		}
//		else
//		switch (Precede(op->data[op->top], *exp)) {
//		case'<'://栈顶运算符优先级低
//			Push(op, *exp);
//			exp++; //将ch进栈;  从exp读取下字符ch;
//			break;
//		case'='://只有栈顶运算符为'(',ch为')'的情况
//			Pop(op, e);
//			exp++;//退栈; 从exp读取下字符ch;
//			break;
//		case'>':
//			//栈顶运算符应先执行,所以出栈并存放到postexp中
//			Pop(op, e);
//			postexp[i++] = e;//退栈运算符并将其存放到postexp中
//			break;
//		}
//	}
//	while (op->data[op->top]!='=') {
//		//若字符串exp扫描完毕,则将运算符栈op中'='之前的所有运算符依次出栈并存放到
//		//postexp中。最后得到后缀表达式postexp; 
//		Pop(op, e);
//		postexp[i++] = e;
//	}
//	postexp[i] = '\0';
//}
//
//ElemType1 compvalue(char* postexp) {
//	double a, b, c, d, e;
//	SqStack1* op;
//	InitSqStack1(op);
//	while (*postexp != '\0') {//postexp字符串未遍历完时循环
//		switch (*postexp) {
//		case'+'://若ch为“+”,则从数值栈st中退栈两个运算数,相加后进栈st中。
//			Pop1(op, a);
//			Pop1(op, b);
//			c = b + a;
//			Push1(op, c);
//			break;
//		case'-':// 若ch为“－”,则从数值栈st中退栈两个运算数,相减后进栈st中。
//			Pop1(op, a);
//			Pop1(op, b);
//			c = b - a;
//			Push1(op, c);
//			break;
//		case'*'://若ch为“*”,则从数值栈st中退栈两个运算数,相乘后进栈st中。
//			Pop1(op, a);
//			Pop1(op, b);
//			c = b * a;
//			Push1(op, c);
//			break;
//		case'/'://若ch为“/”,则从数值栈st中退栈两个运算数,相除后进栈st中
//			Pop1(op, a);
//			Pop1(op, b);
//			if (a != 0) {//若除数为零,则提示相应的错误信息
//				c = b / a;
//				Push1(op, c);
//				break;
//			}
//			else
//				exit(0);
//			break;
//		default:
//			d = 0;//若字符串postexp扫描完毕,则数值栈op中的栈顶元素就是表达式的值。
//			while (*postexp >= '0' && *postexp <= '9') {
//				d = 10 * d + *postexp - '0';
//				postexp++;
//			}
//			Push1(op, d);
//			break;
//		}
//		postexp++;
//	}
//	GetTop1(op, e);//取栈顶元素e
//	return e;
//}
//
//int main() {
//	char exp[MaxSize];
//	cin >> exp;
//	int a = strlen(exp);
//	exp[a] = '\0';
//	char postexp[MaxSize];
//	trans(exp, postexp);
//	cout << "中缀：" << exp << endl;
//	cout << "后缀：" << postexp << endl;
//	cout << "value:" << compvalue(postexp) << endl;
//}