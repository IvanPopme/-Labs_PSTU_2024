#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	int x, fuct, sum;
	cin >> n >> x;
	sum = 1 * x;
	fuct = 1;
	for (int i = 2; i <= n; i++)
	{
		fuct *= 1;
		sum +=(pow(x, i) / fuct);
	}
	cout << sum << endl;
	return 0;
}