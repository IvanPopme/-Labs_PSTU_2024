#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RU");
	float a, b;
	{
		cin >> a >> b;
	}

	if (b == 0)
	{
		std::cout << "�� ���� ������ ������" << endl;
	}
	else;
	{
		cout << a / b << endl;
	}
	return 0;
}