// NIM : 13521102
// Nama : Jimly Firdaus
// Tanggal : 7 November 2022
// Topik praktikum : ADT Linked List
// Deskripsi : Implementasi Linked Queue

#include "queuelinked.h"
#include <stdio.h>
#include <stdlib.h>

/* Prototype manajemen memori */
Address newNode(ElType x) {
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau NIL jika alokasi gagal */
    Address p = (Address) malloc (sizeof(Node));
    if (p != NIL) {
        p->info = x;
        p->next = NIL;
    }
    return p;
}

boolean isEmpty(Queue q) {
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NULL and ADDR_TAIL(q)=NULL */
    return (q.addrHead == NIL && q.addrTail == NIL);
}

int length(Queue q) {
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */
    int len = 0;
    Address p = q.addrHead;
    while (p != NIL)
    {
        p = p->next;
        len++;
    }
    // p == NIL
    return len;
}

/*** Kreator ***/
void CreateQueue(Queue *q) {
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */
    q->addrHead = NIL;
    q->addrTail = NIL;
}

void DisplayQueue(Queue q) {
/* Proses : Menuliskan isi Queue, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
    if (isEmpty(q)) {
        printf("[]");
    } else {
        printf("[");
        Address p = q.addrHead;
        while(p != NIL) {
            if (p->next != NIL) {
                printf("%d,", p->info);
            }
            else {
                printf("%d", p->info);
            }
            p = p->next;
        }
        // p= NIL
        printf("]");
    }

}

/*** Primitif Enqueue/Dequeue ***/
void enqueue(Queue *q, ElType x) {
/* Proses: Mengalokasi x dan menambahkan x pada bagian Tail dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi Tail, Tail "maju" */
    Address p = newNode(x);
    if (p != NIL) {
        if (isEmpty(*q)){
            q->addrHead = p;
        } else {
            q->addrTail->next = p;
        }
        q->addrTail = p;
    }
}

void dequeue(Queue *q, ElType *x) {
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
    Address p = q->addrHead;
    *x = p->info;
    if (q->addrHead->next == NIL) {
        q->addrHead = NIL;
        q->addrTail = NIL;
    } else {
        q->addrHead = p->next;
    }
    p->next = NIL;
    free(p);
}