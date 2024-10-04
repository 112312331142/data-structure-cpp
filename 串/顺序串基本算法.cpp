//#include"sqstring.cpp"
//int main() {
//	SqString s, s1, s2, s3,s4;
//	printf("顺序串算法如下：\n");
//	printf("(1)建立串\n");
//	StrAssign(s, "abcdefghijklmn");
//	StrAssign(s1, "123");
//	printf("(2)输出：");
//	DispStr(s);
//	printf("（3）串长：%d\n",StrLength(s));
//	printf("（4）插入\n");
//	s2 = InsStr(s, 9, s1);
//	printf("(5)输出串2：");
//	DispStr(s2);
//	printf("(6)删除\n");
//	s2 = DelStr(s, 2, 3);
//	printf("(7)输出：");
//	DispStr(s2);
//	printf("(8)替换\n");
//	s2 = RepStr(s, 2, 5, s1);
//	printf("(9)输出：");
//	DispStr(s2);
//	printf("(10)提取\n");
//	s3 = SubStr(s, 2, 10);
//	printf("(11)输出：");
//	DispStr(s3);
//	printf("(12)连接\n");
//	s4 = Concat(s1, s2);
//	printf("(13)输出：");
//	DispStr(s4);
//	DestroyStr(s);
//	DestroyStr(s1);
//	DestroyStr(s2);
//	DestroyStr(s3);
//	DestroyStr(s4);
//	return 1;
//}