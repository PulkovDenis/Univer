#include <iostream>
#include <string>

using namespace std;

int main ()
{
    int b = 0;
    int c = 0;
    int d = 0;
    string s = "deb http://mirror.mephi.ru/debian/ stretch main contrib non-free"
               "deb-src http://mirror.mephi.ru/debian/ stretch main contrib non-free"
               "deb http://security.debian.org/ stretch/updates main contrib non-free"
               "deb-src http://security.debian.org/ stretch/updates main contrib non-free"
               "deb http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free"
               "deb-src http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free"
               "deb http://mirror.mephi.ru/debian stretch-backports main contrib non-free"
               "deb-src http://mirror.mephi.ru/debian stretch-backports main contrib non-free";
    int a = s.size();
    for (int i = 0; i < a; i++) {
        if (((s[i] >= 'A') && (s[i] <= 'Z')) || ((s[i] >= 'a') && (s[i] <= 'z'))) {
            b++;
        } else if ((s[i] >= '0') && (s[i] <= '9')) {
            c++;
        } else if (((s[i] >= '!') && (s[i] <= '/')) || ((s[i] >= ':') && (s[i] <= '@')) || ((s[i] >= '[') && (s[i] <= '_' + 1)) || ((s[i] >= '{') && (s[i] <= '~')))
            d++;
    }
    cout << "Длина строки: " << a << endl;
    cout << "Количество букв: " << b << endl;
    cout << "Количество цифр: " << c << endl;
    cout << "Количество символов: " << d << endl;
    return 0;
}
