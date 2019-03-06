#include <stdio.h>
#include <iostream>

using namespace std;

int main ()
{
    int a = 0;
    int i;
    float m[a];
    float S = 0;

    cout << "Введите длину последовательности: ";
    cin >> a;
    cout << "Введите значения: ";

    for (i = 0; i<a; i++) {
        cin >> m[i];
    }

    for (i = 0; i<a; i++) {
        S = S + m[i];
    }
    cout << "Среднее арифметическое значение последовательности = " << S/a << endl;
    return 0;
}
