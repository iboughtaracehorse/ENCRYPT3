#include <iostream>
#include "DynamicLibrary.h"

int main() {
    const char* rawText = "abc";
    int key = 1;

    char* encrypted = encrypt(rawText, key);
    std::cout << encrypted;

    delete[] encrypted;
    encrypted = nullptr;


    
    return 0;
}