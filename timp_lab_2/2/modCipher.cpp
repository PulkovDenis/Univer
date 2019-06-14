#include </home/pulkov/timp_lab_2/2/modCipher.h>

modCipher::modCipher(int skey, string text)
{
    key = getValidKey(skey, text);
}

string modCipher :: encryption(string text)
{
    string t = getValidOpenText(text);
    int k = 0;
    int simvoli = t.size();
    int stroki = ((simvoli - 1) / key) + 1;
    char** tabl = new char* [stroki];
    for (int i = 0; i < stroki; i++)
        tabl[i] = new char [key];
    for (int i = 0; i < stroki; i++)
        for (int j = 0; j < key; j++) {
            if(k < simvoli) {
                tabl[i][j] = t[k];
                k++;
            }
        }
    k = 0;
    for (int j = key - 1; j >= 0 ; j--)
        for (int i = 0; i < stroki; i++) {
            t[k] = tabl[i][j];
            k++;
        }
    return t;
}

string modCipher :: transcript(string text, string open_text)
{
    string t = getValidCipherText(text, open_text);
    int k = 0;
    int simvoli = t.size();
    int stroki = ((simvoli - 1) / key) + 1;
    char** tabl = new char* [stroki];
    for (int i = 0; i < stroki; i++)
        tabl[i] = new char [key];

    for (int j = key - 1; j >= 0 ; j--)
        for (int i = 0; i < stroki; i++) {
            tabl[i][j] = t[k];
            k++;
        }
    k = 0;
    for (int i = 0; i < stroki; i++)
        for (int j = 0; j < key; j++) {
            t[k] = tabl[i][j];
            k++;
        }
    return t;
}

inline int modCipher::getValidKey(int key, const string & Text)
{
    if(key < 2 || key > Text.size())
        throw cipher_error("Ключ некоректного размера");
    return key;
}

inline string modCipher::getValidOpenText(std::string & s)
{
    int razmer = s.size();
    for(int i = 0; i < razmer; i++)
        if (s[i] == ' ') {
            s.erase(i,1);
            i--;
            razmer = s.size();
        }
    if (s.empty())
        throw cipher_error("Отсутствует открытый текст!");
    for(int i = 0; i < razmer; i++)
        if(s[i] < 'A' || s[i] > 'z')
            throw cipher_error("В тексте встречены некоректные символы!");
    return s;
}

inline string modCipher::getValidCipherText(std::string & s, std::string &open_text)
{
    int r1 = s.size();
    int r2 = open_text.size();
    if (s.empty())
        throw cipher_error("Отсутствует зашифрованный текст!");
    for(int i = 0; i < r1; i++)
        if(s[i] < 'A' || s[i] > 'z')
            throw cipher_error("Некоректные символы!");
    if (r1 != r2)
        throw cipher_error (string ("Неправельный зашифрованный текст:  ") + s);
    return s;
}
