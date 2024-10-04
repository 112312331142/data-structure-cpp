//#include <iostream>
//#include <stdio.h>
//
////定义常量 
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//#define MAXSIZE 100
//#define OVERFLOW -2
//
////个性化设置
//using namespace std;
//typedef char SElemType;
//typedef int NElemType;
//typedef int Status;
//
////结构体定义
//typedef struct {
//	SElemType* base;
//	SElemType* top;
//	int stacksize;
//}SqStack_optr;//OPTR运算符栈类型 
//
//typedef struct {
//	NElemType* base;
//	NElemType* top;
//	int stacksize;
//}SqStack_opnd;//OPND操作符栈类型 
//
////运算符栈初始化
//Status InitStackS(SqStack_optr& S) {
//	S.base = new SElemType[MAXSIZE];//新建连续存储空间，赋值给栈底指针 
//	if (!S.base) {
//		return OVERFLOW;//分批失败返回-2 
//	}
//	S.top = S.base;//把栈底指针的地址赋值给栈顶指针 
//	S.stacksize = MAXSIZE;//赋值栈的大小 
//	return OK;
//}
//
////操作数栈初始化
//Status InitStackN(SqStack_opnd& S) {
//	S.base = new NElemType[MAXSIZE];//新建连续存储空间，赋值给栈底指针 
//	if (!S.base) {
//		return OVERFLOW;//分批失败返回-2 
//	}
//	S.top = S.base;//把栈底指针的地址赋值给栈顶指针 
//	S.stacksize = MAXSIZE;//赋值栈的大小 
//	return OK;
//}
//
////运算符栈插入操作
//Status PushS(SqStack_optr& S, SElemType e) {
//	if (S.top - S.base == S.stacksize)//栈满
//		return ERROR;
//	*S.top++ = e;
//	return OK;
//}
//
////操作符栈插入操作
//Status PushN(SqStack_opnd& S, NElemType e) {
//	if (S.top - S.base == S.stacksize)//栈满
//		return ERROR;
//	*S.top++ = e;
//	return OK;
//}
//
////运算符栈出栈操作
//Status PopS(SqStack_optr& S, SElemType& e) {
//	if (S.top == S.base)//栈空
//		return ERROR;
//	e = *--S.top;
//	return OK;
//}
//
////操作符栈出栈操作
//Status PopN(SqStack_opnd& S, NElemType& e) {
//	if (S.top == S.base)//栈空
//		return ERROR;
//	e = *--S.top;
//	return OK;
//}
//
////运算符栈取栈顶元素
//SElemType GetTopS(SqStack_optr S) {
//	SElemType e;
//	if (S.top == S.base)
//		return ERROR;
//	e = *(S.top - 1);
//	return e;
//}
//
////操作符栈取栈顶元素
//NElemType GetTopN(SqStack_opnd S) {
//	NElemType e;
//	if (S.top == S.base)
//		return ERROR;
//	e = *(S.top - 1);
//	return e;
//}
//
////判断c是否为运算符，若是返回TURE,否则为FALSE 
//Status In(SElemType c) {
//	//判断c是否为运算符
//	switch (c)
//	{
//	case'+':
//		return TRUE;
//	case'-':
//		return TRUE;
//	case'*':
//		return TRUE;
//	case'/':
//		return TRUE;
//	case'(':
//		return TRUE;
//	case')':
//		return TRUE;
//	case'#':
//		return TRUE;
//	default:return FALSE;
//	}
//}
//
////判断运算符优先级，若t1>t2，OPND出栈，t1出栈，完成运算后压栈OPND;若t1<t2,t2压栈；若t1=t2,脱括号
//SElemType Precede(SElemType t1, SElemType t2) {
//	SElemType f;
//	switch (t2)
//	{
//	case'+':
//		if (t1 == '(' || t1 == '#')
//			f = '<';
//		else
//			f = '>';
//		break;
//	case'-':
//		if (t1 == '(' || t1 == '#')
//			f = '<';
//		else
//			f = '>';
//		break;
//	case'*':
//		if (t1 == '(' || t1 == '#' || t1 == '+' || t1 == '-')
//			f = '<';
//		else
//			f = '>';
//		break;
//	case'/':
//		if (t1 == '(' || t1 == '#' || t1 == '+' || t1 == '-')
//			f = '<';
//		else
//			f = '>';
//		break;
//	case'(':
//		if (t1 == '(')
//			f = '=';
//		else
//			f = '<';
//		break;
//	case')':
//		if (t1 == '(' || t1 == '#')
//			f = '=';
//		else
//			f = '>';
//		break;
//	case'#':
//		if (t1 == '(' || t1 == '#')
//			f = '=';
//		else
//			f = '>';
//		break;
//	}
//	return f;
//}
//
//
//NElemType Operate(NElemType a, SElemType theta, NElemType b) {//把操作数a，b拿来完成theta的运算，将结果通过c返回 
//	NElemType c;
//	cout << "a=" << a << ";b=" << b << endl;
//	switch (theta)
//	{
//	case'+':
//		c = a + b;
//		break;
//	case'-':
//		c = a - b;
//		break;
//	case'*':
//		c = a * b;
//		break;
//	case'/':
//		c = a / b;
//		break;
//	}
//	return c;
//}
//
//NElemType EvaiuateExpression() {
//	SqStack_optr OPTR;
//	SqStack_opnd OPND;
//	char ch, theta, x;
//	int a, b, t, e;
//	InitStackS(OPTR);//测试一个运算符栈，并将#压入栈底以便判断表达式是否计算完成 .
//	PushS(OPTR, '#');
//	InitStackN(OPND);//初始化一个操作符栈，用于存放表达式的所有数字以及中间的运算结果。.
//	cin >> ch;//读一个字符 
//	int num = 0;//判断上一次读取的是否是数字的标志位，初始设为0，遇到数字，改为1.遇到字符，改为0. 
//	while (ch != '#' || GetTopS(OPTR) != '#')
//	{
//		if (!In(ch))//判断读取的字符是否为操作数，若不是，执行下列操作. 
//		{
//			if (num == 1)
//			{
//				PopN(OPND, e);
//				t = ch - '0';//因ch为字符类型的数字，所以将其转化为数字的方法就是-'0'. 
//				PushN(OPND, e * 10 + t);
//				num = 1;
//				cin >> ch;
//			}
//			else
//			{
//				PushN(OPND, ch - '0');
//				num = 1;
//				cin >> ch;
//			}
//		}//ch不是运算符则进栈 
//		else
//		{
//			num = 0;
//			switch (Precede(GetTopS(OPTR), ch))
//			{//比较优先级 
//			case'<'://当前字符ch压入OPTR栈，读入下一字符ch 
//				PushS(OPTR, ch);
//				cin >> ch;
//				break;
//			case'>'://弹出OPTR栈顶的运算符运算，并将运算符结果入栈 
//				PopS(OPTR, theta);
//				PopN(OPND, b);
//				PopN(OPND, a);
//				PushN(OPND, Operate(a, theta, b));
//				break;
//			case'='://脱括号并接收下一字符 
//				PopS(OPTR, x);
//				cin >> ch;
//				break;
//			}//switch
//		}//else
//	}//while
//	return GetTopN(OPND);
//}
//
//int main()
//{
//	cout << "请输入算术表达式，并以#结束." << endl;
//	cout << "该表达式的结果为" << EvaiuateExpression() << endl;
//}