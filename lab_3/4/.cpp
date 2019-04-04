#include <iostream>
#include <string>

using namespace std;

int main ()
{

    std::string phrase = "I am 18 years old";
    int n = stoi(phrase.substr(5,2));
    std::cout << n <<std::endl;

    return 0;
}
