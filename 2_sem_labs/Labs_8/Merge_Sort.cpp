#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int start, int end);

void mergeSort(int arr[], int start, int end)
{
    if (start >= end) return;
    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void merge(int arr[], int left, int mid, int right)
{
    int leftRange = mid - left + 1;
    int rightRange = right - mid;

    int* leftArr = new int[leftRange];
    int* rightArr = new int[rightRange];

    for (int i = 0; i < leftRange; i++)
    {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < rightRange; i++) 
    {
        rightArr[i] = arr[mid + 1 + i];
    }

    int leftIndex = 0;
    int rightIndex = 0;
    int mergeIndex = left;  

    while (leftIndex < leftRange && rightIndex < rightRange)
    {
        if (leftArr[leftIndex] <= rightArr[rightIndex]) 
        {
            arr[mergeIndex] = leftArr[leftIndex];
            leftIndex++;
        }
        else
        {
            arr[mergeIndex] = rightArr[rightIndex];
            rightIndex++;
        }
        mergeIndex++;
    }

    while (leftIndex < leftRange)
    {
        arr[mergeIndex] = leftArr[leftIndex];
        leftIndex++;
        mergeIndex++;
    }

    while (rightIndex < rightRange)
    {
        arr[mergeIndex] = rightArr[rightIndex];
        rightIndex++;
        mergeIndex++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

int main()
{
    setlocale(LC_ALL, "RU");
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << endl;

    return 0;
}
