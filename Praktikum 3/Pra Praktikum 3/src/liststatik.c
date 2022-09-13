// NIM : 13521102
// Nama : Jimly Firdaus
// Tanggal : 13 September 2022
// Topik praktikum : ADT List
// Deskripsi : Implementasi List Statik

#include "liststatik.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l)
{
    /* I.S. l sembarang */
    /* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
    /* Proses: Inisialisasi semua elemen List l dengan MARK */
    int i = 0;
    while (i < CAPACITY)
    {
        ELMT(*l, i) = MARK;
        i++;
    }
}
/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l)
{
    /* Mengirimkan banyaknya elemen efektif List */
    /* Mengirimkan nol jika List kosong */
    int len = 0;
    int i = 0;
    while (i < CAPACITY)
    {
        if (ELMT(l, i) != MARK)
        {
            len++;
        }
        else
        {
            return len;
        }
        i++;
    }
    return len;
}

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l)
{
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l pertama */
    IdxType firstIdx = 0;
    while (firstIdx < CAPACITY)
    {
        if (ELMT(l, firstIdx) != MARK)
            return firstIdx;
        else
            firstIdx++;
    }
    return firstIdx;
}

IdxType getLastIdx(ListStatik l)
{
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l terakhir */
    return listLength(l) - 1 + getFirstIdx(l);
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i)
{
    /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
    /* yaitu antara indeks yang terdefinisi utk container*/
    return i < CAPACITY && i >= 0;
}

boolean isIdxEff(ListStatik l, IdxType i)
{
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
    /* yaitu antara 0..length(l)-1 */
    return i >= 0 && i <= listLength(l) - 1;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l)
{
    /* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
    return listLength(l) == 0;
}

/* *** Test List penuh *** */
boolean isFull(ListStatik l)
{
    /* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    return listLength(l) == CAPACITY;
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l)
{
    /* I.S. l sembarang */
    /* F.S. List l terdefinisi */
    /* Proses: membaca banyaknya elemen l dan mengisi nilainya */
    /* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
    /*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
    /*    Jika n tidak valid, tidak diberikan pesan kesalahan */
    /* 2. Jika 0 < n <= CAPACITY; Lakukan n kali:
              Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
    /*    Jika n = 0; hanya terbentuk List kosong */
    // Baca banyak elemen list
    int n;
    do
    {
        scanf("%d", &n);
    } while (!(n >= 0 && n <= CAPACITY));
    // Isi list
    if (n > 0) {
    int i, x;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        l->contents[i] = x;
        printf("\n");
    }
    }
}

void printList(ListStatik l)
{
    /* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung
       siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
       karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
    /* I.S. l boleh kosong */
    /* F.S. Jika l tidak kosong: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika List kosong : menulis [] */
    int i;
    if (listLength(l) == 0)
    {
        printf("[]");
    }
    else
    {
        printf("[");
        for (i = 0; i < listLength(l); i++)
        {
            if (i == listLength(l) - 1)
                printf("%d", l.contents[i]);
            else
                printf("%d,", l.contents[i]);
        }
        printf("]");
    }
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus)
{
    /* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
    /* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada
           indeks yang sama dijumlahkan */
    /* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi
           elemen l2 pada indeks yang sama */
    ListStatik l3;
    int i;
    for (i = 0; i < listLength(l1); i++)
    {
        if (plus)
            l3.contents[i] = l1.contents[i] + l2.contents[i];
        else
            l3.contents[i] = l1.contents[i] - l2.contents[i];
    }
    return l3;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatik l1, ListStatik l2)
{
    /* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua
       elemennya sama */
    if (listLength(l1) != listLength(l2))
        return false;
    else
    {
        int i = 0;
        while (i < listLength(l1))
        {
            if (l1.contents[i] != l2.contents[i])
                return false;
            i++;
        }
        return true;
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, ElType val)
{
    /* Search apakah ada elemen List l yang bernilai val */
    /* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
    /* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
    /* Skema Searching yang digunakan bebas */
    int i;
    if (listLength(l) == 0)
        return IDX_UNDEF;
    else
    {
        for (i = 0; i < listLength(l); i++)
        {
            if (l.contents[i] == val)
                return i;
        }
        return IDX_UNDEF;
    }
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min)
{
    /* I.S. List l tidak kosong */
    /* F.S. Max berisi nilai terbesar dalam l;
            Min berisi nilai terkecil dalam l */
    int i;
    *max = l.contents[0];
    *min = l.contents[0];
    for (i = 0; i < listLength(l); i++)
    {
        if (*max < l.contents[i])
            *max = l.contents[i];
        if (*min > l.contents[i])
            *min = l.contents[i];
    }
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, ElType val)
{
    /* Proses: Menambahkan val sebagai elemen pertama List */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen pertama l yang baru */
    /* *** Menambahkan elemen pada index tertentu *** */
    if (listLength(*l) == 0)
        ELMT(*l, IDX_MIN) = val;
    if (listLength(*l) != CAPACITY)
    {
        int i;
        for (i = listLength(*l); i >= 1; i--)
        {
            l->contents[i] = l->contents[i - 1];
        }
        l->contents[0] = val;
    }
}

void insertAt(ListStatik *l, ElType val, IdxType idx)
{
    /* Proses: Menambahkan val sebagai elemen pada index idx List */
    /* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
    /* F.S. val adalah elemen yang disisipkan pada index idx l */
    int i;
    for (i = listLength(*l); i >= idx + 1; i--)
    {
        ELMT(*l, i) = ELMT(*l, i - 1);
    }
    ELMT(*l, idx) = val;
}

/* *** Menambahkan elemen terakhir *** */
void insertLast(ListStatik *l, ElType val)
{
    /* Proses: Menambahkan val sebagai elemen terakhir List */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen terakhir l yang baru */
    if (listLength(*l) == 0)
        ELMT(*l, IDX_MIN) = val;
    if (listLength(*l) != CAPACITY)
        l->contents[listLength(*l)] = val;
}

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, ElType *val)
{
    /* Proses : Menghapus elemen pertama List */
    /* I.S. List tidak kosong */
    /* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
    /*      Banyaknya elemen List berkurang satu */
    /*      List l mungkin menjadi kosong */
    *val = l->contents[0];
    int i;
    for (i = 0; i < listLength(*l) - 1; i++)
    {
        l->contents[i] = l->contents[i + 1];
    }
    l->contents[listLength(*l) - 1] = MARK;
}

/* *** Menghapus elemen pada index tertentu *** */
void deleteAt(ListStatik *l, ElType *val, IdxType idx)
{
    /* Proses : Menghapus elemen pada index idx List */
    /* I.S. List tidak kosong, idx adalah index yang valid di l */
    /* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
    /*      Banyaknya elemen List berkurang satu */
    /*      List l mungkin menjadi kosong */
    *val = l->contents[idx];
    int i;
    if (listLength(*l) == 1)
        l->contents[0] == MARK;
    else
    {
        for (i = idx; i < listLength(*l) - 1; i++)
        {
            l->contents[i] = l->contents[i + 1];
        }
        l->contents[listLength(*l) - 1] = MARK;
    }
}

/* *** Menghapus elemen terakhir *** */
void deleteLast(ListStatik *l, ElType *val)
{
    /* Proses : Menghapus elemen terakhir List */
    /* I.S. List tidak kosong */
    /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
    /*      Banyaknya elemen List berkurang satu */
    /*      List l mungkin menjadi kosong */
    *val = l->contents[listLength(*l) - 1];
    l->contents[listLength(*l) - 1] = MARK;
}

/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc)
{
    /* I.S. l boleh kosong */
    /* F.S. Jika asc = true, l terurut membesar */
    /*      Jika asc = false, l terurut mengecil */
    /* Proses : Mengurutkan l dengan salah satu algoritma sorting,
       algoritma bebas */
    if (asc)
    {
        ElType temp;
        int i;
        int idx;
        for (i = 1; i < listLength(*l); i++)
    {
        idx = i-1;
        temp = l->contents[i];
        while (temp < l->contents[idx] && idx >= 0)
        {
            l->contents[idx + 1] = l->contents[idx];
            idx--;
        }
        l->contents[idx + 1] = temp;
    }
    }
    else
    {
        ElType temp;
        int i;
        int idx;
        for (i = 1; i < listLength(*l); i++)
    {
        idx = i-1;
        temp = l->contents[i];
        while (temp > l->contents[idx] && idx >= 0)
        {
            l->contents[idx + 1] = l->contents[idx];
            idx--;
        }
        l->contents[idx + 1] = temp;
    }
    }
}
