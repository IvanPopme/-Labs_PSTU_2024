#include <iostream>
using namespace std;
int main()
{
	int a, multip = 1;
	cin >> a;
	for (int i = 1; i <= a; i++)
	{
		multip *= i;
	}
	cout << multip << endl;
	return 0;
}
