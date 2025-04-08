#include <iostream>
#include <cstdio>
using namespace std;
bool isConsonant(char c)
{
    c = tolower(c);
    return (c >= 'a' && c <= 'z' && c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u');
}

int main() 
{
    setlocale(LC_ALL, "RU");
    const char* f1_name = "F1.txt";
    const char* f2_name = "F2.txt";

    // Открываем файл F1 для записи (с fopen_s)
    FILE* f1;
    errno_t err = fopen_s(&f1, f1_name, "w");
    if (err != 0 || !f1) 
    {
        perror("Ошибка создания F1");
        return 1;
    }

    // Записываем 10 строк
    fprintf(f1, "1. This is line one.\n");
    fprintf(f1, "2. This is line two.\n");
    fprintf(f1, "3. This is line three.\n");
    fprintf(f1, "4. This is line four.\n");
    fprintf(f1, "5. This is line five.\n");
    fprintf(f1, "6. This is line six.\n");
    fprintf(f1, "7. This is line seven.\n");
    fprintf(f1, "8. This is line eight.\n");
    fprintf(f1, "9. This is line nine.\n");
    fprintf(f1, "10. This is line ten.\n");
    fclose(f1);

    // Ввод N и K
    int N, K;
    std::cout << "Введите N (1-10): ";
    std::cin >> N;
    std::cout << "Введите K (" << N << "-10): ";
    std::cin >> K;

    if (N < 1 || K > 10 || N > K) {
        std::cout << "Ошибка: некорректный диапазон!\n";
        return 1;
    }

    // Открываем F1 для чтения и F2 для записи 
    FILE* f2;
    err = fopen_s(&f1, f1_name, "r");
    err = fopen_s(&f2, f2_name, "w");
    if (err != 0 || !f1 || !f2) 
    {
        perror("Ошибка открытия файлов");
        return 1;
    }

    char buffer[256];
    int line_num = 0;
    int consonant_count = 0;

    // Копируем строки из F1 в F2
    while (fgets(buffer, sizeof(buffer), f1)) 
    {
        line_num++;
        if (line_num >= N && line_num <= K)
        {
            fputs(buffer, f2);
            for (int i = 0; buffer[i] != '\0'; i++)
            {
                if (isConsonant(buffer[i])) consonant_count++;
            }
        }
    }

    fclose(f1);
    fclose(f2);

    std::cout << "Скопировано строк: " << (K - N + 1) << "\n";
    std::cout << "Согласных букв в F2: " << consonant_count << "\n";

    return 0;
}
