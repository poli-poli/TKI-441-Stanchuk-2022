/* Импорт библиотек */
#include <iostream>
#include <ctime>

/* Объявляем прееменные и функции */
size_t getSize();
char getChar();
char* initArray(size_t size);
void display(char *array, size_t size);
char getMin(char *array, size_t size);


/* Текст программы */
int main()
{
    setlocale(LC_ALL, "Rus");
    srand ( time(NULL) );

    // Создаём массив
    size_t size = getSize();
    char *array = initArray(size);

    // Печатаем массив
    std::cout << "Исходный массив: ";
    display(array, size);

    std::cout << "Минимальный элемент типа char: " << getMin(array, size) << std::endl;
    
    return 0;
}

/* Функция создания массива */
char* initArray(size_t size)
{
    char *array = new char[size];
    for (int i = 0; i < size; i++) array[i] = getChar();

    return array;
}

/* Функция получения размера массива  */
size_t getSize()
{
    int tmp_size;

    std::cout << "Введите длинну массива: ";
    std::cin >> tmp_size;

    if (tmp_size <= 0)
    {
        std::cout << "Длина не может быть <= 0\n";
        exit(1);
    }
    
    return tmp_size;
}

/* Функция печати массива  */
void display(char *array, size_t size)
{
    std::cout << "[";
    for (int i = 0; i < size; i++) std::cout << "\"" << array[i] << "\", ";
    std::cout << "\b\b\n";
}
/* Функция заполнения случайными символами по заданному диапазону
random_number = firs_value + rand() % last_value;
где firs_value - минимальное число из желаемого диапазона
last_value - ширина выборки  */
char getChar() {
    return char(rand() % 42 + 48);
}
/* Функция получения минимального символа массива  */
char getMin(char *array, size_t size)
{
    char minChar = array[0];
    if (size == 1) return minChar;

    for (int i = 1; i < size; i++)
    {
        if (array[i] < minChar) minChar = array[i];
    }

    return minChar;
}