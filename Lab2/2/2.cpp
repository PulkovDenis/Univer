#include <iostream>

using namespace std;

int main ()
{
    int a = 0;
    int b;
    int k;

    cout << "Введите искомое число: ";

    cin >> k;
    if (k != 0) {
        for (a = 0; ; a++) {
            cout << "Введите значение последовательности: ";
            cin >> b;
            if (b != 0 && b == k) {
                cout << "Найдено" << endl;
                return 0;
            } else if (b == 0) {
                break;
            }
        }
        cout << "Не найдено" << endl;
        return 0;

    }
}
