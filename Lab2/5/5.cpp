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
            for (b = 2; b*b <= m[i]; b++) {
                if (m[i] % b == 0) {
                    cout << "Не простое: " << m[i] << endl;
                    return 0;
                }
            }
            cout << "Простое: " << m[i] << endl;
        } else {
            break;
        }
    }
    return 0;
}
