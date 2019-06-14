#pragma once
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <locale>
#include <codecvt>

using namespace std;
/** @file
* @author Пульков Д.Н.
* @version 1.0
* @date 11.06.2019
* @brief Заголовочный файл для модуля шифрование методом Гросвельда
*/
/** @brief Шифрование методом Гросвельда
 * @details Ключ устанавливается конструктором
 * Для шифрования и расшифрования используется метод encryption и transcription.
 * @warning Реализация только для русского языка
 */
class modAlphaCipher
{
    // Описание класса
private:
    wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; ///< Строка с прописным русским алфавитом
    std::map <char,int> alphaNum; ///< Ассоциативный массив "номер по символу"
    std::vector <int> key; ///< Ключ
    std::vector<int> convert(const std::string& s); ///< Преобразование строка-вектор
    std::string convert(const std::vector<int>& v); ///< Преобразование вектор-строка
    /** @brief Проверка ключа на валидность
    * @param [in] s - ключ. Не должен быть пустым, не должен содержать символов не русского алфавита, не должен быть вырожденным.
    * Строчные символы автоматически преобразуются к прописным.
    * @return Ключ, прошедший проверку
    * @throw cipher_error, если ключ пустой, если ключ содержит символы не русккого алфавита, если ключ вырожденный
    */
    std::string getValidKey(const std::string & s);
    /** @brief Проверка открытого текста на валидность
    * @param [in] s - открытый текст. Не должен быть пустым.
    * Все не-буквы удаляются.
    * Строчные символы автоматически преобразуются к прописным.
    * @return Открытый текст, прошедший проверку
    * @throw cipher_error, если открытый текст пустой
    */
    string getValidOpenText(const std::string & s);
    /** @brief Проверка зашифрованного текста на валидность
    * @param [in] s - зашифрованный текст. Все символы текста должны быть в верхнем регистре
    * @return Зашифрованный текст, прошедший проверку
    * @throw cipher_error, если зашифрованный текст некорректен
    */
    string getValidCipherText(const std::string & s);
public:
    modAlphaCipher()=delete; ///< Запрет конструктора без параметров
    /** @brief Конструктор присваивания
     * @param [in] skey - ключ
     * @details Установка ключа
     */
    modAlphaCipher(const std::string& skey);
    /**
    * @brief Зашифровывание
    * @param [in] open_text Открытый текст. Не должен быть пустой строкой.
    *
    Строчные символы автоматически преобразуются к
    прописным.
    *
    Все не-буквы удаляются
    * @return Зашифрованная строка
    * @throw cipher_error, если текст пустой
    */
    std::string encrypt(const std::string& open_text);
    /**
    * @brief Расшифрование
    * @param [in] cipher_text Зашифрованный текст. Должен быть символами русского алфавита в верхнем регистре.
    * @return Расшифрованная строка
    * @throw cipher_error, если в тексте присутствуют посторонние символы или символы в нижнем регистре.
    */
    std::string decrypt(const std::string& cipher_text);
};
/** @brief Класс-исключение
 * @details Производный класс от класса std::invalid_argument.
 * В данном классе перегружены конструкторы с параметрами. При перегрузке указан вызов конструктора базового класса с параметром.
 */
class cipher_error: public std::invalid_argument
{
public:
    explicit cipher_error (const std::string& what_arg):
        std::invalid_argument(what_arg) {}  ///< Вызов конструктора базового класса с параметром
    explicit cipher_error (const char* what_arg):
        std::invalid_argument(what_arg) {}   ///< Вызов конструктора базового класса с параметром
};
