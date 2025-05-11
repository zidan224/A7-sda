#include "BinSTree.h"
#include <stdio.h>
#include <stdlib.h>

address Alokasi(infotype X){
	address P = (address) malloc(sizeof(Node));
	if (P==Nil){
		printf("alokasi gagal");
		return 0;
	}
	return P;
}
	

BinTree Tree (infotype Akar, BinTree L, BinTree R){
	address P = Alokasi(Akar);
	if (P!=Nil){
		P->	left = L;
		P->right = R;
	}
	return P;
}

void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P){
	*P = Tree(Akar, L, R);  
}

boolean IsUnerLeft (BinTree P){
    return (P != Nil) && (Left(P) != Nil) && (Right(P) == Nil);
}

boolean IsUnerRight (BinTree P){
    return (P != Nil) && (Left(P) == Nil) && (Right(P) != Nil);
}

boolean IsEmpty (BinTree P){
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

void PrintTree (BinTree P, int h){
	if (P != Nil) {
    for (int i = 0; i < h; i++) printf(" ");
    printf("%d\n", Info(P));
    PrintTree(Left(P), h + 2);
    PrintTree(Right(P), h + 2);
    }
}

boolean Search (BinTree P, infotype X){
    if (P == Nil) return false;
    if (Info(P) == X) return true;
    return Search(Left(P), X) || Search(Right(P), X);
}

int nbElmt (BinTree P){
	if (P == Nil) return 0;
    return 1 + nbElmt(Left(P)) + nbElmt(Right(P));
}

int nbDaun (BinTree P){
	if (P == Nil) return 0;
    if (Left(P) == Nil && Right(P) == Nil) return 1;
    return nbDaun(Left(P)) + nbDaun(Right(P));
}

boolean IsSkewLeft (BinTree P){
    if (P == Nil) return true;
    if (Right(P) != Nil) return false;
    return IsSkewLeft(Left(P));
}

boolean IsSkewRight (BinTree P){
    if (P == Nil) return true;
    if (Left(P) != Nil) return false;
    return IsSkewRight(Right(P));
}

int Level (BinTree P, infotype X){
	if (P == Nil) return 0;
    if (Info(P) == X) return 1;
    
    int left = Level(Left(P), X);
    if (left > 0) return left + 1;
    
    int right = Level(Right(P), X);
    if (right > 0) return right + 1;
    
    return 0;
}

int Depth (BinTree P){
	if (P == Nil) return 0;
    int dLeft = Depth(Left(P));
    int dRight = Depth(Right(P));
    return 1 + (dLeft > dRight ? dLeft : dRight);
}

int Max (infotype Data1, infotype Data2){
	return (Data1 > Data2) ? Data1 : Data2;
}

void AddDaunTerkiri (BinTree *P, infotype X){
	if (*P == Nil) {
        *P = Alokasi(X);
    } else if (Left(*P) == Nil) {
        Left(*P) = Alokasi(X);
    } else {
        AddDaunTerkiri(&(Left(*P)), X);
    }
}

void AddDaun (BinTree *P, infotype X, infotype Y, boolean Kiri){
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

void DelDaunTerkiri (BinTree *T, infotype *X);

void DelDaun (BinTree *T, infotype X);

ListOfNode MakeListDaun (BinTree P);

ListOfNode MakeListPreOrder (BinTree P);

ListOfNode MakeListLevel (BinTree P, int N);

BinTree BuildBalanceTree (int N);

boolean BSearch (BinTree P, infotype X){
    if (P == Nil) return false;
    if (Info(P) == X) return true;
    else if (X < Info(P)) return BSearch(Left(P), X);
    else return BSearch(Right(P), X);
}

address BinSearch (BinTree P, infotype X);

void InsSearch (BinTree *P, infotype X){
    if (*P == Nil) {
        *P = Alokasi(X);
    } else {
        if (X < Info(*P)) {
            InsSearch(&Left(*P), X);
        } else if (X > Info(*P)) {
            InsSearch(&Right(*P), X);
        }
    }
}

int main (){
    int a;
    printf("halo \n");
}

