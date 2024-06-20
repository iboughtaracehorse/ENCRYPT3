#include <iostream>
#include "DynamicLibrary.h"

int main() {
    size_t initialSize = 256;
    char* rawText = new char[256];

    char* buffer = new char[256];
    char* mode = new char[20];
    int key = 1;
    bool end = false;

    while (!end) {
        std::cout << "Enter a mode(encrypt/decrypt/exit): ";
        std::cin >> mode;

        if (strcmp(mode, "exit") == 0) {
            return 0;
        }

        if (strcmp(mode, "encrypt") == 0) {
            std::cout << "Enter a text: ";
            std::cin.ignore();
            std::cin.getline(rawText, initialSize);

            std::cout << "Enter a key: ";
            std::cin >> key;

            char* encrypted = encrypt(rawText, key);
            std::cout << "Encrypted: " << encrypted << std::endl;

            strcpy_s(buffer, initialSize, encrypted);

            delete[] encrypted;
            encrypted = nullptr;
        }

        else if (strcmp(mode, "decrypt") == 0) {
            int decryptMode;
            char* decrypted = new char[256];
            std::cout << "To decrypt text from buffer enter 1\nTo decrypt new text enter 2: ";
            std::cin >> decryptMode;

            if (decryptMode == 1) {

                if (buffer[0] == '\0') {
                    std::cerr << "Buffer is empty! No text to decrypt." << std::endl;
                }
                else {
                    char* decrypted = decrypt(buffer, key);
                    std::cout << "Decrypted: " << decrypted << std::endl;

                }
              
            }
            else if (decryptMode == 2) {

                std::cout << "Enter a text: ";
                std::cin.ignore();
                std::cin.getline(rawText, initialSize);

                std::cout << "Enter a key: ";
                std::cin >> key;

                char* decrypted = decrypt(rawText, key);
                std::cout << "Decrypted: " << decrypted << std::endl;
            }



            delete[] decrypted;
            decrypted = nullptr;
        }
        else {
            std::cerr << "Invalid mode!" << std::endl;
        }
    }

  

    delete[] rawText;
    rawText = nullptr;
    delete[] buffer;
    buffer = nullptr;
    delete[] mode;
    mode = nullptr;

    return 0;
}