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
	int i;
    for (i = 0; kata[i]; i++) {
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

BinTree createMorseTree() {
    BinTree T = Alokasi('*'); // root kosong

    // Level 1
    Left(T) = Alokasi('E');
    Right(T) = Alokasi('T');

    // Level 2
    Left(Left(T)) = Alokasi('I');
    Right(Left(T)) = Alokasi('A');
    Left(Right(T)) = Alokasi('N');
    Right(Right(T)) = Alokasi('M');

    // Level 3
    Left(Left(Left(T))) = Alokasi('S');
    Right(Left(Left(T))) = Alokasi('U');
    Left(Right(Left(T))) = Alokasi('R');
    Right(Right(Left(T))) = Alokasi('W');
    Left(Left(Right(T))) = Alokasi('D');
    Right(Left(Right(T))) = Alokasi('K');
    Left(Right(Right(T))) = Alokasi('G');
    Right(Right(Right(T))) = Alokasi('O');

    // Level 4
    Left(Left(Left(Left(T)))) = Alokasi('H');
    Right(Left(Left(Left(T)))) = Alokasi('V');
    Left(Right(Left(Left(T)))) = Alokasi('F');
    Right(Right(Left(Left(T)))) = Alokasi('\0'); // Unused
    Left(Left(Right(Left(T)))) = Alokasi('L');
    Right(Left(Right(Left(T)))) = Alokasi('\0'); // Unused
    Left(Right(Right(Left(T)))) = Alokasi('P');
    Right(Right(Right(Left(T)))) = Alokasi('J');
    Left(Left(Left(Right(T)))) = Alokasi('B');
    Right(Left(Left(Right(T)))) = Alokasi('X');
    Left(Right(Left(Right(T)))) = Alokasi('C');
    Right(Right(Left(Right(T)))) = Alokasi('Y');
    Left(Left(Right(Right(T)))) = Alokasi('Z');
    Right(Left(Right(Right(T)))) = Alokasi('Q');

    return T;
}
