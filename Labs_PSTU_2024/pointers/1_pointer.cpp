#include <iostream>
using namespace std;
int main()
{
	int a, b, tmp;
	int* ptr1;
	int* ptr2;
	cin >> a >> b;
	cout << a << b << endl;
	ptr1 = &a;
	tmp = *ptr1;
	ptr2 = &b;
	ptr1 = ptr2;
	ptr2 = &tmp;
	a = *ptr1;
	b = *ptr2;
	cout << a << b << endl;
	return 0;
}