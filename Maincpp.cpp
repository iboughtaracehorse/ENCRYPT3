

#include <iostream>
#include "Windows.h"
#include "DynamicLibrary.h"

int main()
{
    const char* dllPath = "C:\\Users\\dariy\\Documents\\GitHub\\ENCRYPT3\\encrypt.dll";

    HINSTANCE ENCRYPT = LoadLibraryA(dllPath);
    if (ENCRYPT == NULL) {

        DWORD error = GetLastError();

        printf("Could not load\n");
        return -1;
    }

    typedef char* (*EncryptFunctionType)(const char* rawText, int key);
    typedef void (*FreeFunctionType)(char* ptr);
    typedef char* (*DecryptFunctionType)(const char* rawText, int key);



    EncryptFunctionType encrypt = (EncryptFunctionType)GetProcAddress(ENCRYPT, "encrypt");
    if (!encrypt) {
        printf("Could not locate the function\n");
        FreeLibrary(ENCRYPT);
        return -1;
    }

    FreeFunctionType free_encrypted = (FreeFunctionType)GetProcAddress(ENCRYPT, "free_encrypted");
    if (!free_encrypted) {
        printf("Could not locate the function2\n");
        FreeLibrary(ENCRYPT);
        return -1;
    }

    DecryptFunctionType decrypt = (DecryptFunctionType)GetProcAddress(ENCRYPT, "decrypt");
    if (!decrypt) {
        printf("Could not locate the function3\n");
        FreeLibrary(ENCRYPT);
        return -1;
    }


    char rawText[256];
    std::cout << "Enter text: ";
    std::cin.getline(rawText, sizeof(rawText));

    int key = 1;

    char* encrypted = encrypt(rawText, key);
    if (encrypted) {
        std::cout << "Encrypted: " << encrypted << std::endl;
    }
    else {
        std::cout << "Encryption failed.\n";
    }

    FreeLibrary(ENCRYPT);
    return 0;
}
