#include <iostream> 
#include "DynamicLibrary.h"


extern "C" __declspec(dllexport) char* encrypt(const char* rawText, int key) {
    const size_t alphabetSize = 26;

    size_t textLen = strlen(rawText);
    char* result = new char[textLen + 1];

    for (size_t i = 0; i < textLen; i++) {
        char curChar = rawText[i];

        if (islower(curChar)) {
            result[i] = 'a' + (curChar - 'a' + key) % alphabetSize;
        }
        else if (isupper(curChar)) {
            result[i] = 'A' + (curChar - 'A' + key) % alphabetSize;
        }
     

        
        else {
            result[i] = curChar;
        }
    }

    result[textLen] = '\0';
    return result;
}

extern "C" __declspec(dllexport) char* decrypt(const char* rawText, int key) {
    const size_t alphabetSize = 26;

    size_t textLen = strlen(rawText);
    char* result = new char[textLen + 1];

    for (size_t i = 0; i < textLen; i++) {
        char curChar = rawText[i];

        if (islower(curChar)) {
            result[i] = 'a' + (curChar - 'a' - key + alphabetSize) % alphabetSize;
        }
        else if (isupper(curChar)) {
            result[i] = 'A' + (curChar - 'A' - key + alphabetSize) % alphabetSize;
        }
        else {
            result[i] = curChar;
        }
    }

    result[textLen] = '\0';
    return result;
}
