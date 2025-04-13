#include <iostream>
using namespace std;

// Рекурсивный вариант
int interpolationSearchRec(int arr[], int low, int high, int x)
{
	if (high >= low && x >= arr[low] && x <= arr[high])
	{
		int pos = low + (((x - arr[low]) * (high - low)) / (arr[high]
			- arr[low]));
		if (arr[pos] == x) return pos;
		if (arr[pos] > x) return interpolationSearchRec(arr, low, pos - 1, x);
		if (arr[pos] < x) return interpolationSearchRec(arr, pos + 1,
			high, x);
	}
	return -1;
}
int main()
{
	setlocale(LC_ALL, "RU");
	int arr[10] = { 1,23,41,9,5,45,33,75,34,22 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 22;

	int resRec = interpolationSearchRec(arr, 0, n - 1, x);
	if (resRec == -1) cout << "Элемент " << x << " не найден" << endl;
	else cout << "Элемент " << x << " найден по индексу " << resRec <<
		endl;
	return 0;
}
