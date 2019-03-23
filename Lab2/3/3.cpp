#include <iostream>

using namespace std;

int main()
{
    int a;
    int b;
    int sum = 0;

    for (a = 0; ; a++) {
        cout << "Введите значение целочисленной поледовательности: ";
        cin >> b;
        if (b != 0 && b > 0) {
            sum += b;
        } else if (b == 0) {
            break;
        }
    }
    cout << "Сумма положительной целочисленной последовательности = " << sum << endl;
    return 0;
}
