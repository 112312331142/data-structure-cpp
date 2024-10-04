#include<iostream>
using namespace std;

int main() {
	int a[5] = {1, 2, 3, 3, 5};
	for (int x:a) {
		cout << x;
	}
}