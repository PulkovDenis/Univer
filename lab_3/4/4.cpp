#include <iostream>
#include <string>
#include <locale>
#include <codecvt>

using namespace std;
locale loc("ru_RU.UTF-8");
wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;

void encrypt(wstring& text,const int key)
{

    int razmer = text.size();
    for(int i = 0; i < razmer; i++) {
        if (text[i] >= ' ' && text[i] <= '~') {
            text.erase(i,1);
            i--;
        }
    }

    for (wchar_t &wc : text) {
        wc = toupper(wc, loc);
    }
    razmer = text.size();
    for (int i = 0; i < razmer; i ++) {
        text[i] += key;
    }

}

int main ()
{
    string s;
    int k;
    cout << "Введите текст для шифровки: ";
    getline(cin, s);
    cin >> k;
    wstring ws = codec.from_bytes(s);

    encrypt(ws,k);

    s = codec.to_bytes(ws);
    cout << s << endl;
    return 0;

}
