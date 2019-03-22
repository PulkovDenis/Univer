#include <iostream>

using namespace std;

int main()
{
    int a;
    int b;
    cout << "Введите одно целое число: ";
    cin >> a;

    cout << "Является ли данное число простым?\n";

    for (b = 2; b < a; b++) {
        if (a % b == 0) {
            cout << "Нет\n" << endl;
            return 0;
        }
    }
    cout << "Да\n" << endl;
    return 0;
}
