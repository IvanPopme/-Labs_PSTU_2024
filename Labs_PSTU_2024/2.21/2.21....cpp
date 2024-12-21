#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RU");
	int tmp, next;
	bool ordered = true;
	cin >> tmp;
	while (tmp != 0)
	{
		cin >> next;
		if (next != 0 && tmp > next)
		{
			ordered = false;
		}
		tmp = next;
	}
	if (ordered)
	{
		cout << "ѕоследовательность упор€дочена по возрастанию" << endl;
	}
	else
	{
		cout << "ѕоследовательность не упор€дочена по возрастанию" << endl;
	}
	return 0;
}
