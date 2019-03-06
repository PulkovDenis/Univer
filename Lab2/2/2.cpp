#include <stdio.h>
#include <iostream>

using namespace std;

int main ()
{
    int N = 0;
    int m[N];
    int i;
    int a;

    cout << "Введите искомое число: ";
    cin >> a;

    cout << "Введите длину последовательности: ";
    cin >> N;

    cout << "Введите последовательность целых чисел: ";
    cin >> m[N];

    for (i = 0; i < N; i++) {
        if (m[i]!=0) {
            if (a ==m[i]) {
                cout << "Найдено: " << a << endl;
            } else {
                cout << "Не найдено" << endl;
            }
        } else {
            break;
        }
    }

    return 0;
}
