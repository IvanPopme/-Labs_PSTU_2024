#include <iostream>
using namespace std;
float main()
{
	setlocale(LC_ALL, "RU");
	float a, b;
	{
		cin >> a >> b;
	}

	if (b == 0)
	{
		std::cout << "Íà íîëü äåëèòü íåëüçÿ" << endl;
	}
	else;
	{
		cout << a / b << endl;
	}
	return 0;
}
