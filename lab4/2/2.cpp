#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


class String
{
private:
    int length = 0;
    char *value;
public:
    String() {

    }
    String(const String &str) {
        value = str.value;
        value = new char [length + 1];
        for (int i = 0; i < length; i++) {
            value[i] = str.value[i];
        }
    }
    String(const char * s){
        
    }
    
    friend ostream & operator<<(ostream & out, const String & str) {
        return out << str.value;
    }
    ~String() {
        delete[] value;
    }
};

int main()
{
    String str1;
    String str2(str1);
    cout << str1 << endl;
    return 0;
}
