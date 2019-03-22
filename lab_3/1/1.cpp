#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
using namespace std;

int main ()
{
    int a;
    cout << "Введите число в диапазоне от 1 до 100: ";
    cin >> a;
    locale loc("ru_RU.UTF-8");
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;
    string s = "В караване было  верблюдов";
    wstring ws = codec.from_bytes(s);
    if (a>=1 && a<=100) {
        if (a % 10 == 1 && a!=11) {
            ws.insert(16, to_wstring(a));
            ws.replace(11,4,L"был");
            ws.erase(25,2);
            s = codec.to_bytes(ws);
            cout << s << endl;
        }
        if ((a % 10 == 2 || a % 10 == 3 || a % 10 == 4) && a != 14) {
            ws.insert(16, to_wstring(a));
            ws.replace(26,2,L"а");
            s = codec.to_bytes(ws);
            cout << s << endl;
        } else {
            ws.insert(16, to_wstring(a));
            s = codec.to_bytes(ws);
            cout << s << endl;
        }
    }
    return 0;
}
