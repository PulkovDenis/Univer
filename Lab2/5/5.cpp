#include <stdio.h>
#include <iostream>

using namespace std;

int main()

{
    int a = 5;
    int m[a];
    int i;
    int b;

    cout << "Введите последовательность чисел: ";
    for( i = 0; i < a; i++) {
        cin >> m[i];

        if (m[i]!=0) {
            for (b = 2; b!=m[i]; b++) {
                if (m[i] % b == 0) {
                    cout << "Не простое: \n" << m[i] << endl;
                    return 0;
                }
            }
            cout << "Простое: \n" << m[i] << endl;
        }
        cout << "Простое: \n" << m[i] << endl;

    }
    return 0;
}
