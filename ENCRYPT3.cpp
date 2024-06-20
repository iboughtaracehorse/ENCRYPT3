#include <iostream>
#include "DynamicLibrary.h"

int main() {
    size_t initialSize = 256;
    char* rawText = new char[256];

    char* buffer = new char[256];
    char* mode = new char[20];
    int key = 1;

    std::cout << "Enter a mode: ";
    std::cin >> mode;

    std::cout << "Enter a text: ";
    std::cin.ignore();
    std::cin.getline(rawText, initialSize);

    std::cout << "Enter a key: ";
    std::cin >> key;

   
    if (strcmp(mode, "encrypt") == 0) {
        char* encrypted = encrypt(rawText, key);
        std::cout << "Encrypted: " << encrypted << std::endl;

        strcpy_s(buffer,initialSize, encrypted);

        delete[] encrypted;
        encrypted = nullptr;
    }
    else if (strcmp(mode, "decrypt") == 0) {
        int decryptMode;
        char* decrypted = new char[256];
        std::cout << "To decrypt text from buffer enter 1\n To decrypt new text enter 2: ";
        std::cin >> decryptMode;

        if (decryptMode == 1) {
            char* decrypted = decrypt(buffer, key);
            std::cout << "Decrypted: " << decrypted << std::endl;

        }
        else if (decryptMode == 2) {
            char* decrypted = decrypt(rawText, key);
            std::cout << "Decrypted: " << decrypted << std::endl;
        }

        

        delete[] decrypted;
        decrypted = nullptr;
    }
    else {
        std::cerr << "Invalid mode!" << std::endl;
    }

    delete[] rawText;
    rawText = nullptr;
    delete[] mode;
    mode = nullptr;

    return 0;
}