#include <iostream>
#include <string>
#include <modCipher.h>

using namespace std;

void check(string Text, int key)
{
    string cipherText;
    string decryptedText;
    modCipher cipher(key, Text);
    cipherText = cipher.encryption(Text);
    decryptedText = cipher.transcript(cipherText, Text);
    cout<<"key="<<key<<endl;
    cout<<Text<<endl;
    cout<<cipherText<<endl;
    cout<<decryptedText<<endl;
}

int main(int argc, char **argv)
{
    try {
        //check("ProgrammingLanguages", 1);
        check("Pr ogram mingLanguages", 4);
        //check("приветмир", 4);
        //check("                                            ", 2);
    } catch(const cipher_error & e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
/*bool isValid(const int k, string &text)
{
    int razm = text.size();
    if (k > razm)
        return false;
    return true;
}

int main()
{
    string text;
    int key;
    unsigned vibor;
    cout << "Введите тект: ";
    cin >> text;
    cout << "Введите ключ(кол-во столбцов): ";
    cin >> key;
    if (!isValid(key, text)) {
        cout <<"key not valid\n";
        return 1;
    }
    cout<<"Key loaded\n";
    modCipher cipher(key);
    do {
        cout << "Шифратор готов. Выберите опрецию (Выход - 0, Шифрока - 1, Расшифровка - 2): ";
        cin >> vibor;
        if (vibor > 2) {
            cout << "Неверная операция!\n" << endl;
        } else if (vibor > 0) {
            if (vibor == 1)
                cout << cipher.encryption(text) << endl;
            else
                cout << cipher.transcript(text) << endl;
        }
    } while (vibor != 0);
    return 0;
     */
