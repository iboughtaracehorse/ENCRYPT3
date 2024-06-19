#include <iostream> 
#include "DynamicLibrary.h"


extern "C" __declspec(dllexport) char* encrypt(const char* rawText, int key) {
    const size_t alphabetSize = 26;

    size_t textLen = strlen(rawText);
    char* result = new char[textLen + 1];

    for (size_t i = 0; i < textLen; i++) {
        char curChar = rawText[i];

        if (isalpha(curChar)) { 
            result[i] = curChar + key;
        }
        else {
            result[i] = curChar;
        }
    }

    result[textLen] = '/0';
    return result;
}

extern "C" __declspec(dllexport) char* decrypt(const char* rawText, int key) {
    const size_t alphabetSize = 26;

    size_t textLen = strlen(rawText);
    char* result = new char[textLen + 1];

    for (size_t i = 0; i < textLen; i++) {
        char curChar = rawText[i];

        if (isalpha(curChar)) { 
            result[i] = curChar - key;
        }
        else {
            result[i] = curChar;
        }
    }

    result[textLen] = '/0';
    return result;
}
