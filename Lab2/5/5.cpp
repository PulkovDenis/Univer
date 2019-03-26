#include <iostream>
#

using namespace std;

int main()

{
    int b;
    int k;
    int n = 0;

    cout << "Введите последовательность чисел: ";

    for(int a = 0; ; a++) {
        cin >> k;
        if (k != 0) {
            for (b = 2; b < k; b++) {
                if (k % b == 0) {
                    n++;
                }
            }
            if (n < 1) {
                cout << "Простое: " << k << endl;
            }
            n = 0;
        }  else {
            break;
        }
    }
    return 0;
}
