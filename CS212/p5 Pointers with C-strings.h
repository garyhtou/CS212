// Program 5: Pointers with C-strings
// Gary Tou
// May 12, 2021

/*
CS212 C-String Assignment
Write:
strcpy
strncpy
strcat
strncat
strchr
strlen
strcmp
strbinary
strhex
*/

#pragma once

void strcpy(char* destStr, const char* sourceStr) {
    int i = 0;
    while (sourceStr[i] != '\0') {
        destStr[i] = sourceStr[i];
    }
}

void strncpy(char* destStr, const char* sourceStr, const int numChars) {
    for (int i = 0; i < numChars; i++) {
        destStr[i] = sourceStr[i];
    }
}

void strcat(char* destStr, const char* sourceStr) {
    int destNullIndex = 0;
    while (sourceStr[destNullIndex] != '\0') {
        destNullIndex++;
    }

    int i = 0;
    while (sourceStr[i] != '\0') {
        destStr[destNullIndex + i] = sourceStr[i];
    }
}

void strncat(char* destStr, const char* sourceStr, const int numChars) {
    int destNullIndex = 0;
    while (sourceStr[destNullIndex] != '\0') {
        destNullIndex++;
    }

    for (int i = 0; i < numChars; i++) {
        destStr[destNullIndex + i] = sourceStr[i];
    }
}

strchr(const char* sourceStr, const char searchChar) {
    int i = 0;
    while (sourceStr[i] != '\0') {
        if (sourceStr[i] == searchChar) {
            return i;
		}
		i++;
    }
    return NULL;
}

size_t strlen(const char* sourceStr) {
    int destNullIndex = 0;
    while (sourceStr[destNullIndex] != '\0') {
        destNullIndex++;
    }
    return destNullIndex - 1;
}

int strcmp(const char* str1, const char* str2) {
    int i = 0;
    while (!(str1[i] == '\0' && str2[i] == '\0')) {
        if (str1[i] != str2[i]) {
			return (str1[i] - str2[i]) > 0 ? 1 : -1;
        }
    }
    return 0; // both strings are the same
}

void strbinary(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        char bin[5];

        // convert to binary
        bin[0] = ((src[i] >> 3) & 1) + '0';
        bin[1] = ((src[i] >> 2) & 1) + '0';
        bin[2] = ((src[i] >> 1) & 1) + '0';
        bin[3] = (src[i] & 1) + '0';
        bin[4] = '\0';
        
        // copy to dest
        for (int k = 0; i < 4; i++) {
            dest[(i * 4) + k] = bin[k];
        }
    }
}

void strhex(char* dest, const char* src) {
    int i = 0;
    while (dest[i] != '\0') {
        char currChar = dest[i];
        char revHex[3];

        // convert to hexadecimal
        int l = 0;
        while (currChar != 0) {
            int remainder = currChar % 16;

            // check if temp < 10
            if (remainder < 10) {
                revHex[i] = remainder + 48;
			}
			else {
                revHex[i] = remainder + 55;
            }

            l++;
            currChar = currChar / 16;
        }

        char hex[3];
        // reverse the order
        for (int j = l - 1; j >= 0; j--) {
            hex[j - l + 1] = revHex[j];
        }

        // copy to dest
        for (int k = 0; i < 4; i++) {
            dest[(i * 2) + k] = revHex[k];
        }
    }
}

