#include <iostream>
#include <cctype>
#include <locale>
#include "modAlphaCipher.h"

using namespace std;

bool isValid(const wstring &s)
{
    locale loc("ru_RU.UTF-8");
    for(auto c:s) {
        if(!isalpha(c, loc) || !isupper(c, loc)) {
            return false;
        }
    }
    return true;;
}

int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    wstring key, text;
    unsigned op;
    wcout << L"Шифр готов. Введите ключ: ";
    wcin >> key;
    if(!isValid(key)) {
        wcerr << L"Неверный ключ" << endl;
        return 1;
    }
    wcout << L"Ключ загружен." << endl;
    modAlphaCipher cipher(key);
    do {
        wcout << L"Введите операцию (0-выйти, 1-зашифровать, 2-расшифровать): ";
        wcin >> op;
        if(op > 2) {
            wcout << L"Неверный номер операции" << endl;
        } else if(op > 0) {
            wcout << L"Введите текст: ";
            wcin >> text;
            if(isValid(text)) {
                if(op == 1) {
                    wcout << L"Зашифрованный текст: " << cipher.encrypt(text) << endl;
                } else {
                    wcout << L"Расшифрованный текст: " << cipher.decrypt(text) << endl;
                }
            } else {
                wcout << L"Неверный текст" << endl;
            }
        }
    } while(op != 0);
    return 0;
}
