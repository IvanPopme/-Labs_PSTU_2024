#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if (n <= 1)
	{
		cout << "number > 1\n";
	}
	else
	{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
	}
	return 0;
}
