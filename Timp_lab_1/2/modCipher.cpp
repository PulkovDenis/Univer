#include <modCipher.h>

modCipher::modCipher(int skey)
{
    key = skey;
}

string modCipher :: encryption(string &text)
{
    int k = 0;
    int simvoli = text.size();
    int stroki = ((simvoli - 1) / key) + 1;
    char** tabl = new char* [stroki];
    for (int i = 0; i < stroki; i++)
        tabl[i] = new char [key];
    for (int i = 0; i < stroki; i++)
        for (int j = 0; j < key; j++) {
            if(k < simvoli) {
                tabl[i][j] = text [k];
                k++;
            }
        }
    k = 0;
    for (int j = key - 1; j >= 0 ; j--)
        for (int i = 0; i < stroki; i++) {
            text[k] = tabl[i][j];
            k++;
        }
    return text;
}

string modCipher :: transcript(string &text)
{
    int k = 0;
    int simvoli = text.size();
    int stroki = ((simvoli - 1) / key) + 1;
    char** tabl = new char* [stroki];
    for (int i = 0; i < stroki; i++)
        tabl[i] = new char [key];

    for (int j = key - 1; j >= 0 ; j--)
        for (int i = 0; i < stroki; i++) {
            tabl[i][j] = text[k];
            k++;
        }
    k = 0;
    for (int i = 0; i < stroki; i++)
        for (int j = 0; j < key; j++) {
            text[k] = tabl[i][j];
            k++;
        }
    return text;
}
