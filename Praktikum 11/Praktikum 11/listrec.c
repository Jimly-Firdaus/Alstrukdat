// NIM : 13521102
// Nama : Jimly Firdaus
// Tanggal : 14 November 2022
// Topik praktikum : ADT List Rekursif
// Deskripsi : Implementasi ADT List Rekursif

#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"
/* Manajemen Memori */
Address newNode(ElType x) {
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NIL, dan misalnya
   menghasilkan p, maka INFO(p)=x, NEXT(p)=NIL */
/* Jika alokasi gagal, mengirimkan NIL */
    Address p = (Address) malloc(sizeof(Node));
    if (p != NULL) {
        p->info = x;
        p->next = NULL;
    }
    return p;
}

/* Pemeriksaan Kondisi List */
boolean isEmpty(List l) {
/* Mengirimkan true jika l kosong dan false jika l tidak kosong */
    return (l == NULL);
}

boolean isOneElmt(List l) {
/* Mengirimkan true jika l berisi 1 elemen dan false jika > 1 elemen atau kosong */
    if (!isEmpty(l)) {
        return (l->next == NULL);
    } else {
        return false;
    }
}

/* Primitif-Primitif Pemrosesan List */
ElType head(List l) {
/* Mengirimkan elemen pertama sebuah list l yang tidak kosong */
    return l->info;
}

List tail(List l) {
/* Mengirimkan list l tanpa elemen pertamanya, mungkin mengirimkan list kosong */
    return l->next;
}

List konso(List l, ElType e) {
/* Mengirimkan list l dengan tambahan e sebagai elemen pertamanya. e dialokasi terlebih dahulu. 
   Jika alokasi gagal, mengirimkan l */
    Address p = newNode(e);
    if (p != NULL) {
        p->next = l;
        return p;
    } else {
        return l;
    }
}

List konsb(List l, ElType e) {
/* Mengirimkan list l dengan tambahan e sebagai elemen terakhirnya */
/* e harus dialokasi terlebih dahulu */
/* Jika alokasi e gagal, mengirimkan l */
    Address p = newNode(e);
    if (isEmpty(l)) {
        return newNode(e);
    } else {
        l->next = konsb(tail(l), e);
        return l;
    }

}

List copy(List l) {
/* Mengirimkan salinan list Ll (menjadi list baru) */
/* Jika ada alokasi gagal, mengirimkan l */ 
    if (isEmpty(l)) {
        return NULL;
    } else {
        return konso(copy(tail(l)), head(l));
    }

}

List concat(List l1, List l2) {
/* Mengirimkan salinan hasil konkatenasi list l1 dan l2 (menjadi list baru) */
/* Jika ada alokasi gagal, menghasilkan NIL */
    if (isEmpty(l1)) {
        return copy(l2);
    } else {
        return (konso(concat(tail(l1), l2), head(l1)));
    }
}

/* Fungsi dan Prosedur Lain */
int length(List l) {
/* Mengirimkan banyaknya elemen list l, mengembalikan 0 jika l kosong */
    if (isEmpty(l)) {
        return 0;
    } else {
        return length(tail(l)) + 1;
    }
}

boolean isMember(List l, ElType x) {
/* Mengirimkan true jika x adalah anggota list l dan false jika tidak */
    if (isEmpty(l)) {
        return false;
    } else {
        if (l->info == x) {
            return true;
        } else {
            return isMember(tail(l), x);
        }
    }
}

void displayList(List l) {
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa  */
    if (!isEmpty(l)) {
        printf("%d\n", l->info);
        displayList(tail(l));
    }
}



/*** Pencarian nilai ekstrim ***/
/* Prekondisi untuk Max/Min/Sum/Average : List tidak kosong */
ElType maxList (List l){
    if(isOneElmt(l)){
        return head(l);
    } else {
        ElType max = maxList(l->next);
        if (max < l->info) {
            max = l->info;
        } else {
            return max;
        }
    }
}
/* Mengirimkan nilai INFO(p) yang maksimum */

ElType minList (List l){
    if(isOneElmt(l)){
        return head(l);
    } else {
        ElType min = minList(l->next);
        if (min > l->info) {
            min = l->info;
        } else {
            return min;
        }
    }
}
/* Mengirimkan nilai INFO(p) yang minimum */

ElType sumList (List l){
/* Mengirimkan total jumlah elemen List l */
    if (isOneElmt(l)) {
        return head(l);
    } else {
        return sumList(l->next) + head(l);
    }

}

float averageList (List l) {
/* Mengirimkan nilai rata-rata elemen list l */
    int total = sumList(l);
    int len = length(l);
    return ((float) total / (float) len);
}

/*** Operasi-Operasi Lain ***/
List inverseList (List l) {
/* Mengirimkan list baru, hasil invers dari l dengan menyalin semua elemen list.
Semua elemen list baru harus dialokasi */
/* Jika alokasi gagal, hasilnya list kosong */
    if (isEmpty(l)) {
        return NULL;
    } else {
        return konsb(inverseList(tail(l)), head(l));
    }
}

void splitPosNeg (List l, List *l1, List *l2) {
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan l, dibentuk dua buah list l1 dan l2 */ 
/* l1 berisi semua elemen l yang positif atau 0, sedangkan l2 berisi
semua elemen l yang negatif; semua dengan urutan yang sama seperti di l */
/* l tidak berubah: Semua elemen l1 dan l2 harus dialokasi */
/* Jika l kosong, maka l1 dan l2 kosong */
    if(isEmpty(l)){
        return;
    } 
    else {
        if(l->info >= 0) {
            *l1 = konsb(*l1, l->info);
        } else {
            *l2 = konsb(*l2, l->info);
        }
        return splitPosNeg(l->next , l1, l2);
    }
}

void splitOnX (List l, ElType x, List *l1, List *l2) {
/* I.S. l dan x terdefinisi, l1 dan l2 sembarang. */
/* F.S. l1 berisi semua elemen l yang lebih kecil dari x, dengan urutan
kemunculan yang sama, l2 berisi semua elemen l yang tidak masuk ke
l1, dengan urutan kemunculan yang sama. */
    if (isEmpty(l)){
        return;
    }
    else {
        if (l->info < x) {
            *l1 = konsb(*l1, l->info);
        } else {
            *l2 = konsb(*l2, l->info);
        }
        return splitOnX(l->next, x, l1, l2);
    }

}

int compareList (List l1, List l2) {
/* Menghasilkan: -1 jika l1 < l2, 0 jika l1 = l2, dan 1 jika l1 > l2 */
/* Jika l[i] adalah elemen l pada urutan ke-i dan |l| adalah panjang l: */
/* l1 = l2: |l1| = |l2| dan untuk semua i, l1[i] = l2[i] */
/* l1 < l2: Jika i adalah urutan elemen yang berbeda yang terkecil
dari l1 dan l2, l1[i]<l2[i] atau: Jika pada semua elemen pada
urutan i yang sama, l1[i]=l2[i], namun |l1|<|l2| */
/* Contoh: [3,5,6,7] < [4,4,5,6]; [1,2,3]<[1,2,3,4] */
/* l1>l2: kebalikan dari l1<l2 */
    if (length(l1) > length(l2)) return 1;
    else if (length(l2) > length(l1)) return -1;
    else {
        if(!isEmpty(l1)) {
            if(l1->info != l2->info) {
                if (l1->info > l2->info) return 1;
                else return -1;
            } else return compareList(l1->next, l2->next);
        } else {
            return 0;
        }
    }

}

boolean isAllExist (List l1, List l2) {
/* Menghasilkan true jika semua elemen dalam l1 terdapat dalam l2 (tanpa
memperhatikan urutan ataupun banyaknya elemen).
Kedua list mungkin kosong. Jika l1 kosong, maka hasilnya false. */
    if(isEmpty(l1) && isEmpty(l2)) return true;
    if(isEmpty(l1)) return false;
    else {
        if (isOneElmt(l1)){
            if (isMember(l2, l1->info)) return true;
            else return false;
        } else {
            if (!isMember(l2, l1->info)) return false;
            else return isAllExist(l1->next, l2);
        }
    }
}