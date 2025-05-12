#include <stdio.h>
#include <stdlib.h>
#include "BinSTree.h"

int main() {
    BinTree root = NULL;
    int choice, value, target;
    boolean isKiri;

    do {
        printf("\nMenu Operasi Binary Tree:\n");
        printf("1. Insert Node BST\n");
        printf("2. Delete Node (daun saja)\n");
        printf("3. Transversal PreOrder\n");
        printf("4. Transversal InOrder\n");
        printf("5. Transversal PostOrder\n");
        printf("6. Search Node (Tree Traversal)\n");
        printf("7. Search Node BST\n");
        printf("8. Mencari Kedalaman Node\n");
        printf("9. Membandingkan 2 Node Tree\n");
        printf("10. Print Tree\n");
        printf("11. Exit\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
    			printf("Masukkan nilai yang ingin di-insert: ");
    			scanf("%d", &value);
   				if (Search(root, value)) {
   				    printf("Node %d sudah ada, tidak bisa insert duplikat.\n", value);
    			} else {
        		InsSearch(&root, value);
    			}
    			break;
            case 2:
                printf("Masukkan nilai daun yang ingin dihapus: ");
                scanf("%d", &value);
                DelDaun(&root, value);
                break;
            case 3:
                printf("PreOrder: ");
                PreOrder(root);
                printf("\n");
                break;
            case 4:
                printf("InOrder: ");
                InOrder(root);
                printf("\n");
                break;
            case 5:
                printf("PostOrder: ");
                PostOrder(root);
                printf("\n");
                break;
            case 6:
                printf("Masukkan nilai yang dicari: ");
                scanf("%d", &value);
                if (Search(root, value)) {
                    printf("%d ditemukan dalam pohon.\n", value);
                } else {
                    printf("%d tidak ditemukan dalam pohon.\n", value);
                }
                break;
            case 7:
                printf("Masukkan nilai yang dicari dalam BST: ");
                scanf("%d", &value);
                if (BSearch(root, value)) {
                    printf("%d ditemukan dalam BST.\n", value);
                } else {
                    printf("%d tidak ditemukan dalam BST.\n", value);
                }
                break;
            case 8:
                printf("Masukkan nilai node: ");
                scanf("%d", &value);
                printf("Kedalaman (level) node %d adalah: %d\n", value, Level(root, value));
                break;
            case 9:
                printf("Masukkan dua nilai node: ");
                scanf("%d %d", &value, &target);
                if (Level(root, value) == Level(root, target))
                    printf("Kedua node berada di level yang sama.\n");
                else
                    printf("Kedua node berada di level yang berbeda.\n");
                break;
            case 10:
                printf("Tampilan Tree:\n");
                PrintTree(root, 0);
                break;
            case 11:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid.\n");
        }
    } while (choice != 11);

    return 0;
}
