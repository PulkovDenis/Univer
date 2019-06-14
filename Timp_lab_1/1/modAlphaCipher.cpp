#include "modAlphaCipher.h"

modAlphaCipher::modAlphaCipher(const wstring &skey)
{
    for(unsigned i=0; i < numAlpha.size(); i++) {
        alphaNum[numAlpha[i]]=i;
    }
    key = convert(skey);
}

inline vector <int> modAlphaCipher::convert(const wstring &s)
{
    vector <int> result;
    for(auto c:s) {
        result.push_back(alphaNum[c]);
    }
    return result;
}

inline wstring modAlphaCipher::convert(const vector <int> &v)
{
    wstring result;
    for(auto i:v) {
        result.push_back(numAlpha[i]);
    }
    return result;
}

wstring modAlphaCipher::encrypt(const wstring &open_text)
{
    vector <int> work = convert(open_text);
    for(unsigned i = 0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}

wstring modAlphaCipher::decrypt(const wstring &cipher_text)
{
    vector <int> work = convert(cipher_text);
    for(unsigned i = 0; i < work.size(); i++) {
        work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}
