#include <stdio.h>
#include <iostream>

using namespace std;

int main()

{
    int a = 5;
    int m[a];
    int i;
    int b;
    int n = 0;

    cout << "Введите последовательность чисел: ";
    for( i = 0; i < a; i++) {
        cin >> m[i];
    }
    for( i = 0; i < a; i++) {
        if (m[i]!=0) {
            for (b = 2; b <= abs(m[i]); b++) {
                if (m[i] % b == 0) {
                    n++;
                }
            }
            if (n > 1) {
                cout << "Не простое: " << m[i] << endl;
                n = 0;
            } else {
                cout << "Простое: " << m[i] << endl;
                n = 0;
            }
        }  else {
            break;
        }
    }
    return 0;
}
