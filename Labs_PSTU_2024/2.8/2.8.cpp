#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n <= 2)
	{
		cout << "number > 2\n";
	}
	else
	{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
	}
	return 0;
}
