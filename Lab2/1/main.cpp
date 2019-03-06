#include <stdio.h>
#include <iostream>

using namespace std;

int main ()
{
    int a = 0;
    int i;
    float m[a];
    cout << "Введите длину последовательности: ";
    cin >> a;
    cout << "Введите значения: ";
    for (i = 0; i<a; i++) {
        cin >> m[i];
    }
    return 0;
}
