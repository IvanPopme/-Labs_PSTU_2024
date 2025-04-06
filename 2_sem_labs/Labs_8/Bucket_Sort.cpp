#include <iostream>
using namespace std;
int* bucketSort(int arr[], int n)
{
    const int BUCKET_NUM = 10;
    const int BUCKET_SIZE = 10;
    int buckets[BUCKET_NUM][BUCKET_SIZE];
    int bucketSizes[BUCKET_NUM] = { 0 };

    // Распределение по ведрам
    for (int i = 0; i < n; i++) 
    {
        int bucketIndex = arr[i] / BUCKET_NUM;
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    // Сортировка ведер (вставками)
    for (int i = 0; i < BUCKET_NUM; i++) 
    {
        for (int j = 1; j < bucketSizes[i]; j++)
        {
            int key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) 
            {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    // Сборка обратно в массив
    int idx = 0;
    for (int i = 0; i < BUCKET_NUM; i++)
    {
        for (int j = 0; j < bucketSizes[i]; j++)
        {
            arr[idx++] = buckets[i][j];
        }
    }

    return arr;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() 
{
    setlocale(LC_ALL, "RU");
    int arr[] = { 29, 25, 3, 49, 9, 37, 21, 43, 19, 5, 12, 33, 8, 41 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "До сортировки: ";
    printArray(arr, n);

    bucketSort(arr, n);

    cout << "После сортировки: ";
    printArray(arr, n);

    return 0;
}
