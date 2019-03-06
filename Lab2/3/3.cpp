#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int i;
    int a = 5;
    int m[a];
    int sum = 0;

    cout << "Введите значения последовательности: ";
    for (i = 0; i < a; i++) {
        cin >> m[i];
    }

    for (i = 0; i < a; i++)
        if (m[i]!=0) {
            if (m[i] > 0) {
                sum = sum + m[i];
            }
        } else {
            break;
        }
    cout << "Сумма положительных членов целочисленной последовательноти = " << sum << endl;
    return 0;
}
