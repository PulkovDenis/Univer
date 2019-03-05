#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int N = 0;
    int i;
    float A[N];
    float sum = 0;
    cout << "Введите длину последовательности: ";
    cin >> N;
    cout << "ВВедите значения с плавающей запятой: ";
    for (i=0; i<N; i++) {
        cin >> A[i];
    }

    for (i=0; i<N; i++) {
        sum = sum + A[i];
    }
    cout << "Среднее арифметиеское значение последовательности чисел = " << sum/N << endl;
    return 0;
}
