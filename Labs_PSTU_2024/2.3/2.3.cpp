#include <iostream>
using namespace std;
int main()
{
	int a;
	int tmp, sum = 0;
	cin >> a;
	for (int i = 1; i <= a; i++)
	{
		tmp = 1;
		for (int j = i; j <= 2 * i; j++)
		{
			tmp *= j;
		}
		sum += tmp;
	}
	cout << sum << endl;
	return 0;
}