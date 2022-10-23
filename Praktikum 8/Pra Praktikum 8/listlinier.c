/* File : listlinier.c */
// NIM : 13521102
// Nama : Jimly Firdaus
// Tanggal : 23 Oktober 2022
// Topik praktikum : ADT Linked List
// Deskripsi : Implementasi List Linier

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

Address newNode(ElType val){
    Address p = (Address) malloc (sizeof(Node));
    if (p != NULL){
        p->info = val;
        p->next = NULL;
    }
    return p;
}

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    FIRST(*l) = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
/* Mengirim true jika list kosong */
    return (FIRST(l) == NULL);
}

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
    int ctr = 0;
    Address p = FIRST(l);
    while (ctr < idx){
        ctr++;
        p = p->next;
    }
    // ctr == idx;
    return p->info;
}

void setElmt(List *l, int idx, ElType val){
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
    int ctr = 0;
    Address p = FIRST(*l);

    while (ctr < idx)
    {
        ctr++;
        p = p->next;
    }
    // ctr == idx;
    p->info = val;
}

int indexOf(List l, ElType val){
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
    boolean found = false;
    int idx = 0;
    Address p = FIRST(l);
    if (isEmpty(l)){
        return IDX_UNDEF;
    } else {
    while (p != NULL && !found) {
        if (p->info == val) {
            found = true;
        } else {
            p = p->next;
            idx++;
        }
    }
    return idx;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
    Address p = newNode(val);
    if (p != NULL) {
        p->next = FIRST(*l);
        FIRST(*l) = p;
    }
}

void insertLast(List *l, ElType val){
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    if (isEmpty(*l)) {
        insertFirst(l, val);
    } else {
        Address p = newNode(val);
        Address loc = FIRST(*l);
        if (p != NULL){
            while (loc->next != NULL)
            {
                loc = loc->next;
            }
            // loc->next == NULL
            loc->next = p;
        }
    }
}

void insertAt(List *l, ElType val, int idx){
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    Address p = newNode(val);
    Address loc = FIRST(*l);
    int ctr = 0;
    if (idx == 0) {
        insertFirst(l, val);
    } else {
    if (p != NULL) {
        while (ctr < idx - 1) {
            ctr++;
            loc = loc->next;
        }
        // ctr == idx - 1
        p->next = loc->next;
        loc->next = p;
    }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val){
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
    Address p = FIRST(*l);
    *val = p->info;
    *l = p->next;
    free(p);
}

void deleteLast(List *l, ElType *val){
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
    Address p = FIRST(*l);
    Address loc = NULL;
    while (p->next != NULL) {
        loc = p;
        p = p->next;
    }
    // p.next == NULL && loc berada di belakang p
    if (loc == NULL){
        FIRST(*l) = NULL;
    } else {
        loc->next = NULL;
    }
    *val = p->info;
    free(p);
}

void deleteAt(List *l, int idx, ElType *val){
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
    Address loc = FIRST(*l);
    int ctr = 0;
    while (ctr < idx - 1){
        ctr++;
        loc = loc->next;
    }
    //  ctr == idx - 1
    Address p = loc->next;
    loc->next = p->next;
    *val = p->info;
    free(p);
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    if (isEmpty(l)){
        printf("[]\n");
    } else {
        Address p = FIRST(l);
        printf("[");
        while(p != NULL){
            printf("%d", p->info);
            p = p->next;
            if (p->next != NULL){
                printf(",");
            }
        }
        // p.next == NULL
        printf("]\n");
    }

}

int length(List l){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    int length = 0;
    Address p = FIRST(l);
    while (p != NULL){
        length++;
        p = p->next;
    }
    return length;
}

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2){
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
    List l3;
    CreateList(&l3);
    Address p = FIRST(l1);
    while (p != NULL)
    {
        insertLast(&l3, p->info);
        p = p->next;
    }
    p = FIRST(l2);
    while (p != NULL)
    {
        insertLast(&l3, p->info);
        p = p->next;
    }
    FIRST(l1) = NULL;
    FIRST(l2) = NULL;
    return l3;
}
