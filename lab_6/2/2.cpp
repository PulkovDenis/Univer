#include <iostream>
#include <string>

using namespace std;

template <typename T1, typename T2> class DoubleBox
{
private:
    T1  content1 = T1();
    T2 content2 = T2();
public:
    DoubleBox() {};
    DoubleBox(T1 s, T2 k) {
        content1 = s;
        content2 = k;
    }
    void SetContent(T1 s1, T2 k1) {
        content1 = s1;
        content2 = k1;
    }
    void GetContent() {
        cout << content1 << endl;
        cout << content2 << endl;
    }
};

int main()
{
    DoubleBox <string, int> content("Hello ", 2018);
    content.GetContent();
    content.SetContent("world", 2019);
    content.GetContent();
    return 0;
}
