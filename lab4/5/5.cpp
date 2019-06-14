#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


class String
{
private:
    char *value;
    int length = 0;

public:
    String():value(new char[1] {}),length(0) {};
    String(const String &str) {
        value = str.value;
        value = new char [length + 1];
        for (int i = 0; i < length; i++) {
            value[i] = str.value[i];
        }
    }
    String(const char * str) {
        while(str[length] != 0) {
            length++;
            value = new char [length + 1];
            for (int i = 0; i < length; i++)
                value[i] = str[i];
        }
    }
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] value;
            length=other.length;
            value = new char[length+1];
            for (int i=0; i<=length; i++) {
                value[i]=other.value[i];
            }
        }
        return *this;
    }
    String operator-() const {
        String temporary;
        temporary.length = length;
        delete[] temporary.value;
        temporary.value = new char [length + 1];
        for(int i = 0; i < length; i++)
            temporary.value[i] = value[length - i - 1];
        temporary.value[length] = 0;
        return temporary;
    }
    String operator+() {
        
    }

    friend ostream & operator<<(ostream & out, const String & str) {
        return out << str.value;
    }
    friend istream& operator >> (istream& in, String & str) {
        return in >> str.value;
    }
    ~String() {
        delete[] value;
    }
};

int main()
{
    String str4 = "abc";
    str4 = -str4;
    cout << str4 << endl;
    return 0;
}
