#include <iostream>
using namespace std;


// Функция для разделения массива и возврата индекса опорного элемента
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int num = 0;
    
    // Считаем количество элементов меньше опорного
    for (int i = low + 1; i <= high; i++) 
    {
        if (arr[i] < pivot)
        {
            num++;
        }
    }
    
    int pos = low + num; // позиция для опорного элемента
    swap(arr[pos], arr[low]); // перемещаем опорный элемент на правильную позицию
    
    // Разделяем элементы меньшие и большие опорного
    int i = low, j = high;
    while (i < pos && j > pos) 
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pos && j > pos) 
        {
            swap(arr[i++], arr[j--]);
        }
    }
    
    return pos;
}

// Рекурсивная функция быстрой сортировки
void quickSort(int arr[], int low, int high) 
{
    if (low >= high)
    {
        return;
    }
    
    int pI = partition(arr, low, high);
    
    // Сортируем левую часть
    quickSort(arr, low, pI - 1);
    // Сортируем правую часть
    quickSort(arr, pI + 1, high);
}

// Вспомогательная функция для вывода массива
void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    setlocale (LC_ALL, "RU");
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Исходный массив: ";
    printArray(arr, n);
    
    quickSort(arr, 0, n - 1);
    
    cout << "Отсортированный массив: ";
    printArray(arr, n);
    
    return 0;
}
