#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n, k;
	cin >> n;
	if (n <= 3)
	{
		cout << "number > 3\n";
	}
	else
	{
	k = sqrt(n); // áåðåì êâàäðàòíûé êîðåíü ÷èñëà k
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
	}
	return 0;
}
