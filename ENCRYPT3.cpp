#include <iostream>
#include "DynamicLibrary.h"

int main() {
    const char* rawText = "abc";
    const char* rawText2 = "bcd";
    int key = 1;

    char* encrypted = encrypt(rawText, key);
    std::cout << encrypted << std::endl;

    char* decrypted = decrypt(rawText2, key);
    std::cout << decrypted << std::endl;


    delete[] encrypted;
    encrypted = nullptr;
    delete[] decrypted;
    decrypted = nullptr;

    return 0;
}