#pragma once
#include <vector>
#include <string>
#include <map>

using namespace std;

class modAlphaCipher
{
private:
    wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    map <wchar_t, int> alphaNum;
    vector <int> key;
    vector <int> convert(const wstring &s);
    wstring convert(const vector <int> &v);
public:
    modAlphaCipher() = delete;
    modAlphaCipher(const wstring &skey);
    wstring encrypt(const wstring &open_text);
    wstring decrypt(const wstring &cipher_text);
};
