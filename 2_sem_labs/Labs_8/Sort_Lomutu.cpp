#include <iostream>
using namespace std;

// Функция разбиения массива по схеме Ломуто
int partition(int arr[], int low, int high) 
{
    int pivot = arr[high]; // выбираем последний элемент как опорный
    int i = low - 1; // индекс элемента, который меньше pivot
    
    for (int j = low; j <= high - 1; j++) 
    {
        // если текущий элемент меньше или равен опорному
        if (arr[j] <= pivot) 
        {
            i++; // увеличиваем индекс меньшего элемента
            swap(arr[i], arr[j]); // меняем элементы местами
        }
    }
    swap(arr[i + 1], arr[high]); // помещаем опорный элемент на правильную позицию
    return (i + 1); // возвращаем индекс опорного элемента
}

// Рекурсивная функция быстрой сортировки
void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        // pi - индекс опорного элемента, arr[pi] теперь на правильном месте
        int pi = partition(arr, low, high);
        
        // Рекурсивно сортируем элементы до и после опорного элемента
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
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

// Пример использования
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
