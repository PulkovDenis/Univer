#include <stdio.h>
#include <iostream>

using namespace std;

int main ()
{
    int N = 5;
    int m[N];
    int i;
    int a;

    cout << "Введите искомое число: ";
    cin >> a;

    cout << "Введите последовательность целых чисел: ";

    for (i = 0; i < N; i++) {
        cin >> m[i];
    }

    for (i = 0; i < N; i++) {
        if (m[i]!=0) {
            if (m[i] == a) {
                cout << "Найдено: " << a << endl;
                return 0;
            }
        } else {
            break;
        }
    }

    cout << "Не найдено" << endl;

    return 0;
}
