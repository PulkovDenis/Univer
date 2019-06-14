#include <iostream>

using namespace std;

template <typename T> void sort (T* arr, int m)
{
    for (int i = 1; i < m; ++i)
        for (int j = m - 1; j >= i; --j)
            if (arr[j - 1] > arr[j])
                swap(arr[j], arr[j - 1]);
}

int main( )
{
    double a[] = { 11.1, 12.1, 1.1, 18.1, 4.1, 5.1, 2.1 };
    int n = sizeof(a) / sizeof(a[0]);
    sort(a,n);
    for (int i = 0; i < n; i++)
        cout << a[i] << endl;
    return 0;
}
