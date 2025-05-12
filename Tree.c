#include "BinSTree.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* findMorse(BinTree root, char target, char* code, int index) {
    if (root == Nil) return NULL;
    if (Info(root) == target) {
        code[index] = '\0';
        return code;
    }
    char* found = findMorse(Left(root), target, code, index + 1);
    if (found) {
        code[index] = '.';
        return found;
    }
    found = findMorse(Right(root), target, code, index + 1);
    if (found) {
        code[index] = '-';
        return found;
    }
    return NULL;
}

void konversiMorse(BinTree morseTree, char* kata) {
    for (int i = 0; kata[i]; i++) {
        char huruf = toupper(kata[i]);
        if (huruf >= 'A' && huruf <= 'Z') {
            char morseCode[7];
            char* result = findMorse(morseTree, huruf, morseCode, 0);
            if (result) printf("%s ", result);
            else printf("? ");
        } else if (huruf == ' ') printf("  ");
        else printf("? ");
    }
    printf("\n");
}

char findChar(BinTree root, char* code) {
    if (root == Nil) return '#';
    if (*code == '\0') return Info(root);
    if (*code == '.') return findChar(Left(root), code + 1);
    if (*code == '-') return findChar(Right(root), code + 1);
    return '#';
}

void konversiKata(BinTree morseTree, char* kodeMorse) {
    char *token = strtok(kodeMorse, " ");
    while (token) {
        if (strcmp(token, "") != 0) {
            char karakter = findChar(morseTree, token);
            if (karakter != '*' && karakter != '#') printf("%c", karakter);
            else if (karakter == '#') printf("?");
        }
        token = strtok(NULL, " ");
    }
    printf("\n");
}