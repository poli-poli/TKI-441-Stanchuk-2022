/* Импорт библиотек */
#include <iostream>
#include <random>


/**
 * Функция getSize
 *
 * @brief возвращает размер массива из ввода пользователя.
 *        Если значение <= 0 - кидает ошибку
 *
 * @return размер массива
 */
size_t getSize();

/**
 * Функция getChar
 *
 * @return случайный char
 */
char getChar();

/**
 * Функция initArray
 *
 * @brief служит для создания массива
 *
 * @param size размер массива
 *
 * @return указатель на массив
 */
char* initArray(const size_t size);

/**
 * Функция display
 *
 * @brief выводит в консоль массив
 */
void display(char* array, const size_t size);

/**
 * Функция getMin
 *
 * @brief служит для получения минимального символа массива
 *
 * @param array указатель на массив
 * @param size размер массива
 *
 * @return случайный char
 */
char getMin(char* array, const size_t size);

/**
 * Функция delete_array
 * @brief используется для безопасного удаления массива
 *
 * @param array указатель на масив
 */
void delete_array (char*&);

/**
 * Точка входа в программу, возвращает 0, в случае успеха
 */
/* Текст программы */  
int main()
{
    setlocale(LC_ALL, "Rus");
   

    // Проверяем ввод
    size_t tmp_size;    // Используется для временного хранения результата
    try 
    {
        tmp_size = getSize();
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    // Создаём массив
    const size_t SIZE = tmp_size;
    char* array = initArray(SIZE);

    // Печатаем массив
    std::cout << "Исходный массив: ";
    display(array, SIZE);

    std::cout << "Минимальный элемент типа char: " << getMin(array, SIZE) << std::endl;
    delete_array(array);

    return 0;
}


/* Функция получения размера массива  */
size_t getSize()
{
    int tmp_size;

    std::cout << "Введите длинну массива: ";
    std::cin >> tmp_size;

    if (tmp_size <= 0)
    {
        throw std::invalid_argument("Длина не может быть <= 0");
    }

    return tmp_size;
}

/* Функция создания массива */
char* initArray(const size_t size)
{
    char* array = new char[size];
    for (size_t i = 0; i < size; i++)
    {
        array[i] = getChar();
    }
    return array;
}

/* Функция печати массива */
void display(char* array, const size_t size)
{
    // Проверка массива на сущестование
    if (array == nullptr)
    {
        throw std::logic_error("Array = nullptr");
    }
    std::cout << "[";
    for (size_t i = 0; i < size; i++) std::cout << "\"" << array[i] << "\", ";
    std::cout << "\b\b]\n";
}

/* Функция получения случайного char */
char getChar() {
    // Минимальное число желаемого диапазона
    const size_t MIN_CHAR = 42;
    // Максимальное число желаемого диапазона
    const size_t MAX_CHAR = 90;

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<size_t> dist(MIN_CHAR, MAX_CHAR);

    return char(dist(mt));
}

/* Поиск минимального элемента */
char getMin(char* array, const size_t size)
{
    // Проверка массива на сущестование
    if (array == nullptr)
    {
        throw std::logic_error("Array = nullptr");
    }
    // Минимальный элемент
    char minChar = array[0];

    for (size_t i = 1; i < size; i++)
    {
        if (array[i] < minChar) minChar = array[i];
    }

    return minChar;
}

/* Безопасное удаление массива */
void delete_array(char*& array)
{
    if (array == nullptr) return;

    delete[] array;
    array = nullptr;
}
