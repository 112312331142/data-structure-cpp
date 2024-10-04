//#include<iostream>
//using namespace std;
//#define MaxSize 100
//typedef struct {
//	char data[MaxSize];
//	int length;
//}SqString;
//
//void StrAssign(SqString& s, const char cstr[]) {
//	int i;
//	for (i = 0; cstr[i] != '\0'; i++)
//		s.data[i] = cstr[i];
//	s.length = i;
//}
//
//void DispStr(SqString s) {
//	if (s.length > 0) {
//		for (int i = 0; i < s.length; i++)
//			printf("%c", s.data[i]);
//		printf("\n");
//	}
//}
//
//void move(SqString &s, SqString t) {
//	int m = s.length, n = t.length, i = 0;
//	while (i <= m) {
//		if (s.data[i] == t.data[0]) {
//			int j = i;
//			bool flag = true;
//			for (int a = 1; a < n; a++) {
//				j += 1;
//				if (s.data[j] != t.data[a]) {
//					flag = false;
//					break;
//				}
//			}
//			if (flag) {
//				int k = i;
//				for (int b = 0; b < n; b++){
//					for (int c = k; c < m; c++)
//						s.data[c] = s.data[c + 1];
//		       	}
//				
//				i--;
//			}
//		}
//		i++;
//	}
//}
//
//int main() {
//	SqString s, t;
//	StrAssign(s, "abcffsdfabc");
//	DispStr(s);
//	StrAssign(t, "abc");
//	DispStr(t);
//	move(s, t);
//	DispStr(s);
//	return 0;
//}