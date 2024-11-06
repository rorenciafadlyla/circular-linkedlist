#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

// node *createNode(void);
void tambahAwal(node **head);
void tambahData(node **head);
void tambahAkhir(node **head);
void tranverse(node *head);
void hapusAwal(node **head);
void hapusData(node **head);
void hapusAkhir(node **head);
void cariData(node **head);
void jumlahData(node **head);
void totalData(node **head);

//========================================================

int main()
{
    node *head;
    int pilih;

    head = NULL;
    do
    {
        system("cls");
        printf("Masukkan pilihan\n");
        printf("1. Tambah data di awal\n");
        printf("2. Tambah data di tengah list\n");
        printf("3. Tambah data di akhir list \n");
        printf("4. Cetak isi list\n");
        printf("5. Hapus data di awal\n");
        printf("6. Hapus data ditengah list\n");
        printf("7. Hapus data di akhir list\n");
        printf("8. Cari data didalam list\n");
        printf("9. Jumlah data didalam list\n");
        printf("10. Hasil penjumlahan semua data dalam list\n");

        printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
        fflush(stdin);
        scanf("%d", &pilih);
        if (pilih == 1)
            tambahAwal(&head);
        else if (pilih == 2)
            tambahData(&head);
        else if (pilih == 3)
            tambahAkhir(&head);
        else if (pilih == 4)
        {
            tranverse(head);
            getch();
        }
        else if (pilih == 5)
            hapusAwal(&head);
        else if (pilih == 6)
            hapusData(&head);
        else if (pilih == 7)
            hapusAkhir(&head);
        else if (pilih == 8)
            cariData(&head);
        else if (pilih == 9)
            jumlahData(&head);
        else if (pilih == 10)
            totalData(&head);

    } while (pilih != 'q');

    return 0;
}

//========================================================

void tambahAwal(node **head)
{
    int bil;
    node *temp = *head, *pList;

    system("cls");
    fflush(stdin);
    printf("Masukkan bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);

    pList = (node *)malloc(sizeof(node));
    pList->data = bil;

    if (*head == NULL)
    {
        *head = pList;
        pList->next = *head;
    }
    else
    {
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        pList->next = *head;
        *head = pList;
    }
}

//========================================================

void tambahData(node **head)
{
    int pos, bil;
    node *pList, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nPosisi penyisipan setelah data bernilai : ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nBilangan : ");
    fflush(stdin);
    scanf("%d", &bil);

    pCur = *head;
    while (pCur != NULL && pCur->data != pos)
    {
        pCur = pCur->next;
    }

    pList = (node *)malloc(sizeof(node));

    if (pCur == NULL)
    {
        printf("\nNode tidak ditemukan");
        getch();
    }
    else if (pList == NULL)
    {
        printf("\nAlokasi memeori gagal");
        getch();
    }
    else
    {
        pList->data = bil;
        pList->next = pCur->next;
        pCur->next = pList;
        printf("\nData berhasil ditambahkan di urutan ke-%d.\n", pos);
    }
}

//========================================================

void tambahAkhir(node **head)
{
    int bil;
    node *pList, *pCur;

    system("cls");
    fflush(stdin);
    printf("Masukkan sebuah bilangan : ");
    fflush(stdin);
    scanf("%d", &bil);

    pList = (node *)malloc(sizeof(node));
    if (pList != NULL)
    {
        pList->data = bil;
        if (*head == NULL)
        {
            pList->next = pList;
            *head = pList;
        }
        else
        {
            pCur = *head;
            while (pCur->next != *head)
            {
                pCur = pCur->next;
            }
            pCur->next = pList;
            pList->next = *head;
        }
    }
    else
    {
        printf("\nAlokasi memori gagal");
        getch();
    }
}

//========================================================

void tranverse(node *head)
{
    // traverse a linked list
    node *pWalker;

    system("cls");
    if (head == NULL)
    {
        printf("List kosong");
        return;
    }

    pWalker = head;
    do
    {
        printf("%d -> ", pWalker->data);
        pWalker = pWalker->next;
    } while (pWalker != head);

    printf("HEAD\n");
}

//========================================================

void hapusAwal(node **head)
{
    node *pCur, *pTemp;
    if (*head == NULL)
    {
        printf("List kosong\n");
        getch();
        return;
    }

    if (*head == (*head)->next) // Only one node
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        pCur = *head;
        pTemp = *head;
        while (pTemp->next != *head) // Find the last node
        {
            pTemp = pTemp->next;
        }
        *head = (*head)->next; // Move head to next node
        pTemp->next = *head;   // Update last node's next
        free(pCur);
    }
    printf("\nData berhasil dihapus");
    getch();
}
//========================================================

void hapusData(node **head)
{
    int pos;
    node *pCur, *pPre, *pTemp;

    system("cls");
    tranverse(*head);
    printf("\nBilangan :  ");
    fflush(stdin);
    scanf("%d", &pos);

    pCur = *head;
    pTemp = *head;
    pPre = NULL;

    while (pCur != NULL && pCur->data != pos)
    {
        pPre = pCur;
        pCur = pCur->next;
    }

    if (pCur == NULL)
    {
        printf("\nData tidak ditemukan");
        getch();
        return;
    }

    if (pCur == *head)
    {
        while (pTemp->next != *head)
        {
            pTemp = pTemp->next;
        }
        *head = pCur->next;
        pTemp->next = *head;
    }
    else
    {
        pPre->next = pCur->next;
    }
    free(pCur);
    printf("\nData berhasil dihapus");
    getch();
}

//========================================================

void hapusAkhir(node **head)
{
    node *pCur, *pPre;
    if (*head == NULL)
    {
        printf("\nlist kosong");
        getch();
        return;
    }

    if (*head == (*head)->next)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        pCur = *head;
        while (pCur->next != *head)
        {
            pPre = pCur;
            pCur = pCur->next;
        }
        pPre->next = *head;
        free(pCur);
    }
    printf("\nData berhasil dihapus");
    getch();
}

//========================================================

void cariData(node **head)
{
    int target, index = 0;
    node *pWalker;

    system("cls");
    fflush(stdin);
    printf("Masukkan angka yang dicari: ");
    fflush(stdin);
    scanf("%d", &target);

    if (*head == NULL)
    {
        printf("\nList kosong");
        getch();
        return;
    }

    pWalker = *head;

    do
    {
        if (pWalker->data == target)
        {
            printf("\nData %d ditemukan pada index : %d ", target, index);
            getch();
            return;
        }

        pWalker = pWalker->next;
        index++;
    } while (pWalker != *head);

    printf("\nData tidak ditemukan");
    getch();
}

//========================================================

void jumlahData(node **head)
{
    int count = 0;
    node *pWalker, *pTemp;

    system("cls");
    tranverse(*head);

    if (*head == NULL)
    {
        printf("\nlist kosong");
        getch();
        return;
    }

    pWalker = *head;
    pTemp = *head;

    while (pTemp->next != *head)
    {
        pTemp = pTemp->next;
    }

    do
    {
        count++;
        pWalker = pWalker->next;
    } while (pWalker != *head);

    printf("\njumlah data dalam list adalah %d\n ", count);
    getch();
}

//========================================================

void totalData(node **head)
{
    int total;
    node *pWalker, *pTemp;

    system("cls");
    tranverse(*head);

    if (*head == NULL)
    {
        printf("\nList kosong");
        getch();
        return;
    }

    pWalker = *head;
    pTemp = pWalker;

    printf("\nData: ");
    do
    {
        total += pWalker->data;
        printf("%d", pWalker->data);
        if (pWalker->next != pTemp)
        {
            printf(" + ");
        }
        pWalker = pWalker->next;
    } while (pWalker != pTemp);

    printf("\nTotal penjumlahan data dalam list adalah %d\n ", total);
    getch();
}