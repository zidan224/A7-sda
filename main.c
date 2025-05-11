#include <stdio.h>
#include <stdlib.h>
#include "BinSTree.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int pilihan;

	do {
    printf("-------------MENU--------------\n");
	printf("1.  Insert node\n");
    printf("2.  Print Tree\n");
    printf("3.  Transversal PreOrder\n");
    printf("4.  Transversal InOrder\n");
    printf("5.  Transversal PostOrder\n");
    printf("6.  Transversal LevelOrder\n");
    printf("7.  Serach Node Tree\n");
    printf("8.  Jumlah Daun/Leaf\n");
    printf("9.  Mencari Kedalaman Node Tree\n");
    printf("10. Membandingkan 2 Node Tree\n");
    printf("0. Exit\n");
	printf("-------------------------------\n");
    printf("Pilihan Anda: ");
    
	scanf("%d", &pilihan); getchar();  // Ambil pilihan dan buang newline

        switch (pilihan) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
				break;
			case 0:
                printf("Program selesai.\n");
                break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 0);

    return 0;
}

