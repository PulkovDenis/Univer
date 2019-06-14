#include <UnitTest++/UnitTest++.h>
#include </home/pulkov/timp_lab_2/2/modCipher.h>
#include <string>

string s = "ProgrammingLanguages";

SUITE(KeyTest)
{
    TEST(ValidKey) {
        CHECK_EQUAL("gmLusomggeranngPriaa",modCipher(4, "ProgrammingLanguages").encryption(s));
    }
    TEST(LongKey) {
        CHECK_THROW(modCipher cp(1, "ProgrammingLanguages"),cipher_error);
    }
}

struct KeyB_fixture {
    modCipher * p;
    KeyB_fixture() {
        p = new modCipher(4, "ProgrammingLanguages");
    }
    ~KeyB_fixture() {
        delete p;
    }
};

SUITE(EncryptTest)
{
    TEST_FIXTURE(KeyB_fixture, UpCaseString) {
        CHECK_EQUAL("GMLUSOMGGERANNGPRIAA",
                    p->encryption("PROGRAMMINGLANGUAGES"));
    }
    TEST_FIXTURE(KeyB_fixture, LowCaseString) {
        CHECK_EQUAL("gmlusomggeranngpriaa",
                    p->encryption("programminglanguages"));
    }
    TEST_FIXTURE(KeyB_fixture, StringWithWhitspaceAndPunct) {
        CHECK_EQUAL("gmLusomggeranngPriaa",
                    p->encryption("Programming Languages"));
    }
    TEST_FIXTURE(KeyB_fixture, StringWithNumbers) {
        CHECK_THROW(p->encryption("ProgrammingLanguages2019"), cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, EmptyString) {
        CHECK_THROW(p->encryption(""),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, NoAlphaString) {
        CHECK_THROW(p->encryption("1234+8765=9999"),cipher_error);
    }
    TEST(MaxShiftKey) {
        CHECK_EQUAL("segaugnaLgnimmargorP",
                    modCipher(20,"ProgrammingLanguages").encryption("ProgrammingLanguages"));
    }
}

SUITE(DecryptText)
{
    TEST_FIXTURE(KeyB_fixture, UpCaseString) {
        CHECK_EQUAL("PROGRAMMINGLANGUAGES",
                    p->transcript("GMLUSOMGGERANNGPRIAA","PROGRAMMINGLANGUAGES"));
    }
    TEST_FIXTURE(KeyB_fixture, LowCaseString) {
        CHECK_EQUAL("PROgRAMMINGLANGUAGES", p->transcript("gMLUSOMGGERANNGPRIAA", "PROgRAMMINGLANGUAGES"));
    }
    TEST_FIXTURE(KeyB_fixture, WhitespaceString) {
        CHECK_THROW(p->transcript("gmLusomggeranngPriaa","Pr ogram ming Lang uages"),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, DigitsString) {
        CHECK_THROW(p->transcript("ProgrammingLanguages2019", "ProgrammingLanguages2019"),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, PunctString) {
        CHECK_THROW(p->transcript("Programming,Languages", "Programming,Languages"),cipher_error);
    }
    TEST_FIXTURE(KeyB_fixture, EmptyString) {
        CHECK_THROW(p->transcript("", ""),cipher_error);
    }
    TEST(MaxShiftKey) {
        CHECK_EQUAL("ProgrammingLanguages",
                    modCipher(20, "ProgrammingLanguages").transcript("segaugnaLgnimmargorP", "ProgrammingLanguages"));
    }
}

int main(int argc, char **argv)
{
    return UnitTest::RunAllTests();
}
