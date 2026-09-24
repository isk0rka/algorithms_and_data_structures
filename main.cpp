/*Проверка кратности. На вход подаются два целых числа A и B. Проверить,
 делится ли A на B без остатка, или наоборот,
 либо они не делятся друг на друга.*/
#include <iostream>

using namespace std;

int main() {
    int A, B;
    bool correctInput = false;

    while (!correctInput) {
        cout << "Введите два целых числа A и B: ";
        cin >> A >> B;
        if (cin.fail()) {
            cout << "Неверный ввод. Пожалуйста, введите два целых числа.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            correctInput = true;
        }
    }

    if (B != 0 && A % B == 0) {
        cout << A << " делится на " << B << " без остатка." << endl;
    } 
    else if (A != 0 && B % A == 0) {
        cout << B << " делится на " << A << " без остатка." << endl;
    } 
    else {
        cout << "Числа " << A << " и " << B << " не делятся друг на друга без остатка." << endl;
    }
    
    return 0;
}
 