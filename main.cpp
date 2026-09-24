/*
Подсчитать сумму элементов массива,
по значению принадлежащих интервалу [A,B]
*/

#include <iostream>
#include <sstream>
#include <string>
#include <random>

using namespace std;

bool is_valid_range(int A, int B)
{
    return A <= B;
}

int user_input(const char* message)
{
    while (true)
    {
        cout << message;

        string input;
        getline(cin, input);

        stringstream stream(input);

        int value;

        if (stream >> value)
        {
            stream >> ws;

            if (stream.eof())
            {
                return value;
            }
        }

        cout << "Неверный ввод. Введите целое число.\n";
    }
}

void user_input_range(int& A, int& B)
{
    A = user_input("Введите границу A: ");

    while (true)
    {
        B = user_input("Введите границу B: ");

        if (is_valid_range(A, B))
        {
            return;
        }

        cout << "Ошибка: B должно быть больше или равно A.\n";
    }
}

void generate_array(int array[], int size, int min_value, int max_value)
{
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(min_value, max_value);

    for (int i = 0; i < size; ++i)
    {
        array[i] = distribution(generator);
    }
}

void print_array(const int array[], int size)
{
    cout << "Массив: ";

    for (int i = 0; i < size; ++i)
    {
        cout << array[i] << " ";
    }

    cout << endl;
}

bool in_range(int value, int A, int B)
{
    return value >= A && value <= B;
}

int sum_in_range(const int array[], int size, int A, int B)
{
    int sum = 0;

    for (int i = 0; i < size; ++i)
    {
        if (in_range(array[i], A, B))
        {
            sum += array[i];
        }
    }

    return sum;
}

void print_result(int sum)
{
    cout << "Сумма элементов массива в диапазоне: "
         << sum << endl;
}

int main()
{
    constexpr int SIZE = 10;

    int array[SIZE];

    generate_array(array, SIZE, -50, 50);

    print_array(array, SIZE);

    int A;
    int B;

    user_input_range(A, B);

    int sum = sum_in_range(array, SIZE, A, B);

    print_result(sum);

    return 0;
}

/*────────────────────────────▓▓█───────
────────────────────────────▒██▒▒█──────
───────────────────────────█▓▓▓░▒▓▓─────
─────────────────────────▒█▓▒█░▒▒▒█─────
────────────────────────▒█▒▒▒█▒▒▒▒▓▒────
─▓▓▒░──────────────────▓█▒▒▒▓██▓▒░▒█────
─█▓▓██▓░──────────────▓█▒▒▒▒████▒▒▒█────
─▓█▓▒▒▓██▓░──────────▒█▒▒▒▒▒██▓█▓░░▓▒───
─▓▒▓▒▒▒▒▒▓█▓░──░▒▒▓▓██▒▒▒▒▒▒█████▒▒▒▓───
─▓░█▒▒▒▒▒▒▒▓▓█▓█▓▓▓▓▒▒▒▒▒▒▒▒██▓██▒░▒█───
─▓░▓█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓████▒▒▒█───
─▓░▓██▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓▒▒▒▒▒▒▒▒▒▓██░░░█───
─▓░▓███▒▒▒▒▒▒▒▒▒▒▒▓█▒▒▒▒▒▒▒▒▒▒▒▒▓▓▓▒▓▓──
─▒▒▒██▓▒▓█▓▒▒▒▒▒▒▒▓▒▒▒▒▒▒▓▓▓▒▒▒▒▒▒▒▓▒█──
──▓▒█▓▒▒▒▒▓▒▒▒▒▒▒▒▒▒▒▒▓█▓▓▓▓█▓▒▒▒▒▒▒▒▓▒─
──▓▒█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▓▓──────▓█▓▒▒▒▒▒▓█─
──▒▒▓▒▒▒▓▓▓▒▒▒▒▒▒▒▒▒▓▓───░▓▓───█▓▒▒▒▒▒█─
───█▒▒▓▓▓▒▒▓▓▒▒▒▒▒▒▓▓───█████▓──█▓▒▒▒▒▓▒
───▓▓█▒─────▒▓▒▒▒▒▒█───░██████──░█▒▒▒▒▓▓
───▓█▒──▒███─▒▓▒▒▒▒█────██████───▓▒▒▒▒▒▓
───██───█████─█▒▒▒▒█─────███▓────▓▓▒▒▒▒▓
───█▓───█████─▒▓▒▒▒█─────────────█▓▓▓▒▒▓
───█▓───░███──░▓▒▒▒▓█──────────░█▓▒▒▒▓▒▓
───██─────────▒▓▒▒▒▒▓▓──────░▒▓█▓────░▓▓
───▓█░────────█▓██▓▒▒▓█▓▓▓▓██▓▓▒▓▒░░▒▓▒▓
───▒██░──────▓▒███▓▒▒▒▒▓▓▓▓▒▒▒▒▒▒▓▓▓▓▒▓─
────█▓█▓▓▒▒▓█▓▒░██▒▒▓▓█▓▒▒▒▒▒▒▒▒▒▒▒▒▓▓█▒
────▓─░▓▓▓▓▓▒▓▓▓▓▒▓▓▓▒▓▒▒▒▒▒▒▒▒▒▒▒▓▓▓▓▓▓
────▒▒▒▓▒▒▒▒▒▒▓█░─░░░─▓▓▒▒▒▒▒▒▒▒▒▒▒▓██▓▒
─────█▓▒▒▒▒▒▒▒▒▓▓─░░░─▓▓▒▒▒▒▒▒▒▒▒▓▓▓▒▒▓▒
──────██▓▓▒▒▒▒▒▒█▒░░░░█▒▒▒▒▒▒▒▒▓█▓▓▒▒▒▒▒
─────░─▒██▓▓▒▒▒▒▒█▓▒▒▓▒▒▒▒▒▒▓███▓▒▒▒▒▒▓▓
──────────░▒▓▓▓▓▒▒▓▓▓▓▓▓████▓▓█▒▒▒▒▒▓▓*/