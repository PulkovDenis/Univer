#include <iostream>
#include <string>

using namespace std;

int main()
{
    int k;
    int q;
    string s = "deb http://mirror.mephi.ru/debian/ stretch main contrib non-free"
               "deb-src http://mirror.mephi.ru/debian/ stretch main contrib non-free"
               "deb http://security.debian.org/ stretch/updates main contrib non-free"
               "deb-src http://security.debian.org/ stretch/updates main contrib non-free"
               "deb http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free"
               "deb-src http://mirror.mephi.ru/debian/ stretch-updates main contrib non-free"
               "deb http://mirror.mephi.ru/debian stretch-backports main contrib non-free"
               "deb-src http://mirror.mephi.ru/debian stretch-backports main contrib non-free";
    for(int i = 0; s.find("mephi",k) > 0; i++) {
        k = s.find("mephi");
        if (k > 0) {
            s.replace(k, 5, "yandex");
            q = s.find("mephi",k);
            s.replace(q, 5, "yandex");
            k = q;
        } else {
            break;
        }
    }
    cout << s << endl;
    return 0;
}
