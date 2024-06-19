#pragma once

#ifndef DYNAMICLIBRARY_H
#define DYNAMICLIBRARY_H

#ifdef __cplusplus
extern "C" {
#endif

	__declspec(dllexport) char* encrypt(const char* rawText, int key);

#ifdef __cplusplus
}
#endif

#endif // DYNAMICLIBRARY_H
