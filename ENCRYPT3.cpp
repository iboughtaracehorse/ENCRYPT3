#include <iostream>
#include "DynamicLibrary.h"

int main() {
    char* rawText;
    size_t initialSize = 256;
    rawText = new char[256];
    strcpy_s(rawText, initialSize, "abc");
    int key = 1;

    char* encrypted = encrypt(rawText, key);
    std::cout << encrypted << std::endl;

   char* decrypted = decrypt(rawText, key);
   std::cout << decrypted << std::endl;


    delete[] encrypted;
    encrypted = nullptr;
    delete[] decrypted;
    decrypted = nullptr;

    return 0;
}