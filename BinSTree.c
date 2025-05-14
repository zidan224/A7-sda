#include "BinSTree.h"
#include <stdlib.h>

address Alokasi(infotype X) {
    address P = (address) malloc(sizeof(Node));
    if (P != Nil) {
        Info(P) = X;
        Left(P) = Nil;
        Right(P) = Nil;
    }
    return P;
}

BinTree Tree(infotype Akar, BinTree L, BinTree R) {
    address P = Alokasi(Akar);
    if (P != Nil) {
        Left(P) = L;
        Right(P) = R;
    }
    return P;
}

void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree *P) {
    *P = Alokasi(Akar);
    if (*P != Nil) {
        Left(*P) = L;
        Right(*P) = R;
    }
}

void BuildTree(BinTree *P) {
    char c;
    scanf(" %c", &c);
    if (c == '#') {
        *P = Nil;
    } else {
        *P = Alokasi((infotype)(c - '0'));
        if (*P != Nil) {
            BuildTree(&Left(*P));
            BuildTree(&Right(*P));
        }
    }
}

boolean IsUnerLeft(BinTree P) {
    return (P != Nil) && (Left(P) != Nil) && (Right(P) == Nil);
}

boolean IsUnerRight(BinTree P) {
    return (P != Nil) && (Left(P) == Nil) && (Right(P) != Nil);
}

boolean IsBiner(BinTree P) {
    return (P != Nil) && (Left(P) != Nil) && (Right(P) != Nil);
}

boolean IsEmpty(BinTree P) {
    return P == Nil;
}

void PreOrder(BinTree P) {
    if (P != Nil) {
        printf("%d ", Info(P));
        PreOrder(Left(P));
        PreOrder(Right(P));
    }
}

void InOrder(BinTree P) {
    if (P != Nil) {
        InOrder(Left(P));
        printf("%d ", Info(P));
        InOrder(Right(P));
    }
}

void PostOrder(BinTree P) {
    if (P != Nil) {
        PostOrder(Left(P));
        PostOrder(Right(P));
        printf("%d ", Info(P));
    }
}

void PrintTree(BinTree P, int level) {
    int i;
    if (P != Nil) {
        // Cetak info node
        for (i = 0; i < level * 2; i++) {
            printf(" ");
        }
        printf("Info  = %d\n", Info(P));

        // Cetak info anak kiri
        for (i = 0; i < level * 2; i++) {
            printf(" ");
        }
        printf("Left  = ");
        if (Left(P) != Nil) {
            printf("%d\n", Info(Left(P)));
        } else {
            printf("Nil\n");
        }

        // Cetak info anak kanan
        for (i = 0; i < level * 2; i++) {
            printf(" ");
        }
        printf("Right = ");
        if (Right(P) != Nil) {
            printf("%d\n", Info(Right(P)));
        } else {
            printf("Nil\n");
        }

        // Cetak level
        for (i = 0; i < level * 2; i++) {
            printf(" ");
        }
        printf("Level = %d\n\n", level);

        // Rekursi ke kiri dan kanan
        PrintTree(Left(P), level + 1);
        PrintTree(Right(P), level + 1);
    }
}



boolean Search(BinTree P, infotype X) {
    if (P == Nil) return false;
    if (Info(P) == X) return true;
    return Search(Left(P), X) || Search(Right(P), X);
}

int nbElmt(BinTree P) {
    if (P == Nil) return 0;
    return 1 + nbElmt(Left(P)) + nbElmt(Right(P));
}

int nbDaun(BinTree P) {
    if (P == Nil) return 0;
    if (Left(P) == Nil && Right(P) == Nil) return 1;
    return nbDaun(Left(P)) + nbDaun(Right(P));
}

boolean IsSkewLeft(BinTree P) {
    if (P == Nil) return true;
    if (Right(P) != Nil) return false;
    return IsSkewLeft(Left(P));
}

boolean IsSkewRight(BinTree P) {
    if (P == Nil) return true;
    if (Left(P) != Nil) return false;
    return IsSkewRight(Right(P));
}

int Level(BinTree P, infotype X) {
    if (P == Nil) return 0;
    if (Info(P) == X) return 1;

    int left = Level(Left(P), X);
    if (left > 0) return left + 1;

    int right = Level(Right(P), X);
    if (right > 0) return right + 1;

    return 0;
}

int Depth(BinTree P) {
    if (P == Nil) return 0;
    int dLeft = Depth(Left(P));
    int dRight = Depth(Right(P));
    return 1 + (dLeft > dRight ? dLeft : dRight);
}

int Max(infotype Data1, infotype Data2) {
    return (Data1 > Data2) ? Data1 : Data2;
}

void AddDaunTerkiri(BinTree *P, infotype X) {
    if (*P == Nil) {
        *P = Alokasi(X);
    } else if (Left(*P) == Nil) {
        Left(*P) = Alokasi(X);
    } else {
        AddDaunTerkiri(&(Left(*P)), X);
    }
}

void AddDaun(BinTree *P, infotype X, infotype Y, boolean Kiri) {
    if (*P != Nil) {
        if (Left(*P) == Nil && Right(*P) == Nil && Info(*P) == X) {
            if (Kiri)
                Left(*P) = Alokasi(Y);
            else
                Right(*P) = Alokasi(Y);
        } else {
            AddDaun(&(Left(*P)), X, Y, Kiri);
            AddDaun(&(Right(*P)), X, Y, Kiri);
        }
    }
}

void DelDaunTerkiri(BinTree *T, infotype *X) {
    address temp;
    if (*T != Nil) {
        if (Left(*T) == Nil && Right(*T) == Nil) {
            *X = Info(*T);
            temp = *T;
            *T = Nil;
            free(temp);
        } else {
            DelDaunTerkiri(&Left(*T), X);
        }
    }
}

void DelDaun(BinTree *T, infotype X) {
    if (*T != Nil) {
        if (Left(*T) == Nil && Right(*T) == Nil && Info(*T) == X) {
            free(*T);
            *T = Nil;
        } else {
            DelDaun(&Left(*T), X);
            DelDaun(&Right(*T), X);
        }
    }
}

ListOfNode MakeListDaun(BinTree P) {
    ListOfNode L = Nil;
    if (P != Nil) {
        if (Left(P) == Nil && Right(P) == Nil) {
            address1 newNode = (address1) malloc(sizeof(ElmtList));
            if (newNode != Nil) {
                InfoList(newNode) = Info(P);
                Next(newNode) = L;
                L = newNode;
            }
        } else {
            ListOfNode leftLeaves = MakeListDaun(Left(P));
            ListOfNode rightLeaves = MakeListDaun(Right(P));
            address1 current = leftLeaves;
            if (current == Nil) {
                L = rightLeaves;
            } else {
                while (Next(current) != Nil) {
                    current = Next(current);
                }
                Next(current) = rightLeaves;
                L = leftLeaves;
            }
        }
    }
    return L;
}

BinTree BuildBalanceTree(int N) {
    if (N <= 0) {
        return Nil;
    }
    int nL = N / 2;
    int nR = N - nL - 1;
    infotype Akar;
    printf("Masukkan nilai akar: ");
    scanf("%d", &Akar);
    BinTree L = BuildBalanceTree(nL);
    BinTree R = BuildBalanceTree(nR);
    return Tree(Akar, L, R);
}

boolean BSearch(BinTree P, infotype X) {
    if (P == Nil) return false;
    if (Info(P) == X) return true;
    else if (X < Info(P)) return BSearch(Left(P), X);
    else return BSearch(Right(P), X);
}

address BinSearch(BinTree P, infotype X) {
    if (P == Nil || Info(P) == X) return P;
    if (X < Info(P)) return BinSearch(Left(P), X);
    else return BinSearch(Right(P), X);
}

void InsSearch(BinTree *P, infotype X) {
    if (*P == Nil) {
        *P = Alokasi(X);
        if (*P == Nil) {
            printf("Gagal mengalokasi node baru untuk nilai %d\n", X);
        }
    } else {
        if (X < Info(*P)) {
            InsSearch(&Left(*P), X);
        } else if (X > Info(*P)) {
            InsSearch(&Right(*P), X);
        } else {
            // nilai sudah ada
        }
    }
}

void InsertManual(BinTree *P, infotype parent, infotype newVal, boolean kiri, boolean gantiKalauAda) {
    if (*P != Nil) {
        if (Info(*P) == parent) {
            if (kiri) {
                if (Left(*P) == Nil || gantiKalauAda) {
                    if (Left(*P) != Nil && gantiKalauAda) {
                        free(Left(*P)); // Hapus node lama kalau menimpa
                    }
                    Left(*P) = Alokasi(newVal);
                } else {
                    printf("Left child sudah ada dan gantiKalauAda = false\n");
                }
            } else {
                if (Right(*P) == Nil || gantiKalauAda) {
                    if (Right(*P) != Nil && gantiKalauAda) {
                        free(Right(*P)); // Hapus node lama kalau menimpa
                    }
                    Right(*P) = Alokasi(newVal);
                } else {
                    printf("Right child sudah ada dan gantiKalauAda = false\n");
                }
            }
        } else {
            // Cari ke kiri dan kanan
            InsertManual(&Left(*P), parent, newVal, kiri, gantiKalauAda);
            InsertManual(&Right(*P), parent, newVal, kiri, gantiKalauAda);
        }
    }
}


