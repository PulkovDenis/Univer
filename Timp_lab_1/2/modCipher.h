#pragma once
#include <vector>
#include <string>
#include <map>

using namespace std;

class modCipher
{
private:
    int key;
public:
    modCipher() = delete;
    modCipher(int skey);
    string encryption(string &text);
    string transcript(string &text);
};
