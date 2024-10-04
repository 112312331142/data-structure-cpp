//#include<iostream>
//#include<string>
//using namespace std;
//
//void move(string* s, int index)
//{
//	int len = s->length();
//	for (int i = index; i < len; i++)
//	{
//		(*s)[i] = (*s)[i + 1];
//	}
//}
//void change(string* s, string t)
//{
//	int len1 = s->length();
//	int len2 = t.length();
//	int s_index = 0;//记录长串下标
//	while (s_index <= len1)
//	{
//		if ((*s)[s_index] == t[0])
//		{
//			int index_s1 = s_index;
//			bool flag = true;
//			for (int i = 1; i < len2; i++)
//			{
//				//char a1 = (*s)[s_index];
//				index_s1 = index_s1 + 1;
//				//char a2 = (*s)[index_s1];
//				if ((*s)[index_s1] != t[i])
//				{
//					flag = false;
//					break;
//				}
//			}
//			if (flag)
//			{
//				int index = s_index;
//				for (int n = 0; n < len2; n++)
//				{
//					move(s, index);
//				}
//				s_index--;
//			}
//		}
//		s_index++;
//	}
//
//}
//int main()
//{
//	string s = "abcdefgyzhabc";
//	cout << s << endl;
//	string t = "abc";
//	cout << t << endl;
//	change(&s, t);
//	cout << s << endl;
//	system("pause");
//	return 0;
//}
