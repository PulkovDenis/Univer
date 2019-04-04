#include <iostream>
#include <ctime>

using namespace std;

void normirovka(double *massiv, int razmer)
{
    srand(time(0));
    double random;
    double max = 0;
    double min = 1;
    double normir;
    double *m = new double [razmer];

    for (int i = 0; i < razmer; i++) {
        random = rand()%1000;
        massiv[i] = random/1000;
        if (massiv[i] > max)
            max = massiv[i];
        if (massiv[i] < min)
            min = massiv[i];
    }

    for (int i = 0; i < razmer; i++) {
        normir = (massiv[i] - min)/(max - min);
        cout << "Нормированное значение: " << normir << endl;
        m[i] = normir;
    }

    cout << "Значения массива: [    ";
    for (int i = 0; i < razmer; i++) {
        cout << m[i] << "   " ;
    }
    cout << "]" << endl;
    delete[] m;
}

int main()
{
    int razm;
    cout << "Введите размер массива: ";
    cin >> razm;
    double *arr = new double [razm];
    normirovka(arr, razm);
    delete[] arr;
    return 0;
}
