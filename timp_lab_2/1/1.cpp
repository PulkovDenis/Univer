#include <iostream>
#include <cctype>
#include <locale>
#include "modAlphaCipher.h"

using namespace std;

void check(const string& Text, const string& key, const bool destructCipherText=false)
{
    try {
        string cipherText;
        string decryptedText;
        modAlphaCipher cipher(key);
        cipherText = cipher.encrypt(Text);
        if (destructCipherText) // надо "портить"?
            cipherText[1] += 32;
        decryptedText = cipher.decrypt(cipherText);
        cout<<"key="<<key<<endl;
        cout<<Text<<endl;
        cout<<cipherText<<endl;
        cout<<decryptedText<<endl;
    } catch (const cipher_error &e) {
        cerr << "Ошибка:    " << e.what() << endl;
    }
}

int main(int argc, char **argv)
{
    check("ЯЗЫКИПРОГРАММИРОВАНИЯ","АААААААААААААААА");
    //check("ЯЗЫКИПРОГРАММИРОВАНИЯ","Ключ");
    // check("ЯЗЫКИПРОГРАММИРОВАНИЯ","");
    //check("ЯЗЫКИПРОГРАММИРОВАНИЯ","Кл12");
    //check("Пульков Денис Николаевич", "КЛЮЧ");
    //check("123", "КЛЮЧ");
    //check("ЯЗЫКИПРОГРАММИРОВАНИЯ","КЛЮЧ",true);
    return 0;
}
