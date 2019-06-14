#include "modAlphaCipher.h"
#include <locale>
#include <codecvt>
std::locale loc("ru_RU.UTF-8");
std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec;
using namespace std;
modAlphaCipher::modAlphaCipher(const std::string& skey)
{
    for (unsigned i=0; i < numAlpha.size(); i++)
        alphaNum[numAlpha[i]]=i;
    key = convert(getValidKey(skey));
}

std::string modAlphaCipher::encrypt(const std::string& open_text)
{
    std::vector<int> work = convert(getValidOpenText(open_text));
    for(unsigned i=0; i < work.size(); i++)
        work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
    return convert(work);
}

std::string modAlphaCipher::decrypt(const std::string& cipher_text)
{
    std::vector<int> work = convert(getValidCipherText(cipher_text));
    for(unsigned i=0; i < work.size(); i++)
        work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();
    return convert(work);
}

inline std::vector<int> modAlphaCipher::convert(const std::string& s)
{
    std::wstring ws = codec.from_bytes(s); // перекодируем из UTF-8 в UTF-32
    std::vector<int> result;
    for(auto c:ws)
        result.push_back(alphaNum[c]);
    return result;
}

inline std::string modAlphaCipher::convert(const std::vector<int>& v)
{
    std::string result;
    std::wstring ws = codec.from_bytes(result); // перекодируем из UTF-8 в UTF-32
    for(auto i:v)
        ws.push_back(numAlpha[i]);
    result = codec.to_bytes(ws);
    return result;
}

inline std::string modAlphaCipher::getValidKey(const std::string & s)
{
    std::wstring ws = codec.from_bytes(s); // перекодируем из UTF-8 в UTF-32
    string mp;
    wstring tmp = codec.from_bytes(mp);
    tmp = ws;
    int error = 0;
    if (tmp.empty())
        throw cipher_error("Пустой ключ");
    int razmer = tmp.size();
    for (int i = 0; i < razmer; i++) {
        if(tmp[i] < L'А' || tmp[i] > L'я')
            throw cipher_error(string ("Неверный ключ:  ") + s);
        if (tmp[i] >= L'а' && tmp[i] <= L'я')
            tmp[i] -= 32;
    }
    for(int i = 0; i < razmer; i++)
        if (tmp[i] == L'А' || tmp[i] == L'а')
            error++;
    if (error == razmer)
        throw cipher_error(string ("Вырожденный ключ:  ") + s);
    mp = codec.to_bytes(tmp);
    return mp;
}

inline std::string modAlphaCipher::getValidOpenText(const std::string & s)
{
    std::string mp;
    wstring tmp = codec.from_bytes(mp);
    std::wstring ws = codec.from_bytes(s);
    for (auto c:ws) {
        if (c >= L'А' && c <= L'я') {
            if (c >= L'а' && c <= L'я')
                tmp.push_back(c -= 32);
            else
                tmp.push_back(c);
        }
    }
    if (tmp.empty())
        throw cipher_error("Отсутствует открытый текст!");
    mp = codec.to_bytes(tmp);
    return mp;
}

inline std::string modAlphaCipher::getValidCipherText(const std::string & s)
{
    std::string mp;
    wstring tmp = codec.from_bytes(mp);
    std::wstring ws = codec.from_bytes(s);
    tmp = ws;
    if (tmp.empty())
        throw cipher_error("Empty cipher text");
    for (auto c:tmp) {
        if ((c < L'А' || c > L'Я') && c != L'Ё')
            throw cipher_error(std::string("Неправельный зашифрованный текст!")+s);
    }
    mp = codec.to_bytes(tmp);
    return mp;
}
