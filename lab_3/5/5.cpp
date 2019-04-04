#include <iostream>
#include <string>
#include <locale>
#include <codecvt>

using namespace std;
locale loc("ru_RU.UTF-8");
wstring_convert<codecvt_utf8<wchar_t>, wchar_t> codec;

void decrypt(wstring& text,const int key)
{
    int vibor = 0;
    int razmer = text.size();
    for(int i = 0; i < razmer; i++) {
        if ((text[i] >= L'А' && text[i] <= L'Щ') && ((text[i] >= L'Ы') && (text[i] <= L'Я')) && (text[i] == L'Ё')) {
            ;
        } else {
            vibor++;
            break;
        }
    }
    if (vibor > 1) {
        cout << "Ошибка, в тексте имеются недопустимые символы!";
    } else {
        for (wchar_t &wc : text) {
            wc = tolower(wc, loc);
        }
        for (int i = 0; i < razmer; i ++) {
            text[i] -= key;
        }
    }
}


int main ()
{
    string s;
    int k;
    cout << "Введите текст для расшифровки: ";
    getline(cin, s);
    cin >> k;
    wstring ws = codec.from_bytes(s);

    decrypt(ws,k);

    s = codec.to_bytes(ws);
    cout << s << endl;
    return 0;

}
