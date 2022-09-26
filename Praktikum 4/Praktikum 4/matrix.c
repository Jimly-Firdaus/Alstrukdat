// NIM : 13521102
// Nama : Jimly Firdaus
// Tanggal : 18 September 2022
// Topik praktikum : ADT Matrix
// Deskripsi : Implementasi ADT Matrix
#include <stdio.h>
#include "matrix.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */
void createMatrix(int nRows, int nCols, Matrix *m)
{
    /* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
    /* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
    /* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}
/* *** Selektor *** */
/* *** Selektor "Dunia Matrix" *** */
boolean isMatrixIdxValid(int i, int j)
{
    /* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
    return (i >= 0 && i < ROW_CAP && j >= 0 && j < COL_CAP);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getLastIdxRow(Matrix m)
{
    /* Mengirimkan Index baris terbesar m */
    return (ROW_EFF(m) - 1);
}

IdxType getLastIdxCol(Matrix m)
{
    /* Mengirimkan Index kolom terbesar m */
    return (COL_EFF(m) - 1);
}

boolean isIdxEff(Matrix m, IdxType i, IdxType j)
{
    /* Mengirimkan true jika i, j adalah Index efektif bagi m */
    return (i >= 0 && i < ROW_EFF(m) && j >= 0 && j < COL_EFF(m));
}
ElType getElmtDiagonal(Matrix m, IdxType i)
{
    /* Mengirimkan elemen m(i,i) */
    return ELMT(m, i, i);
}

/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mOut)
{
    /* Melakukan assignment mOut <- mIn */
    *mOut = mIn;
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol)
{
    /* I.S. isIdxValid(nRow,nCol) */
    /* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
    /* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
    /* Selanjutnya membaca nilai elemen per baris dan kolom */
    /* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
    1 2 3
    4 5 6
    8 9 10
    */
    createMatrix(nRow, nCol, m);
    int i, j;
    for (i = 0; i < nRow; i++)
    {
        for (j = 0; j < nCol; j++)
        {
            scanf("%d", &ELMT(*m, i, j));
        }
    }
}

void displayMatrix(Matrix m)
{
    /* I.S. m terdefinisi */
    /* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
       dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
    /* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
    /* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
    1 2 3
    4 5 6
    8 9 10
    */
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            printf("%d", ELMT(m, i, j));
            if (j != (COL_EFF(m) - 1))
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2)
{
    /* Prekondisi : m1 berukuran sama dengan m2 */
    /* Mengirim hasil penjumlahan matriks: m1 + m2 */
    Matrix m3;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++)
    {
        for (j = 0; j < COL_EFF(m1); j++)
        {
            ELMT(m3, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return m3;
}

Matrix subtractMatrix(Matrix m1, Matrix m2)
{
    /* Prekondisi : m1 berukuran sama dengan m2 */
    /* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
    Matrix m3;
    createMatrix(ROW_EFF(m1), COL_EFF(m1), &m3);
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++)
    {
        for (j = 0; j < COL_EFF(m1); j++)
        {
            ELMT(m3, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return m3;
}

Matrix multiplyMatrix(Matrix m1, Matrix m2)
{
    /* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
    /* Mengirim hasil perkalian matriks: salinan m1 * m2 */
    Matrix m3;
    int temp = 0;
    createMatrix(ROW_EFF(m1), COL_EFF(m2), &m3);
    int i, j;
    for (i = 0; i < ROW_EFF(m1); i++)
    {
        for (j = 0; j < COL_EFF(m2); j++)
        {
            for (int k = 0; k < ROW_EFF(m2); k++)
            {
                temp += (ELMT(m1, i, k) * ELMT(m2, k, j));
            }
            ELMT(m3, i, j) = temp;
            temp = 0;
        }
    }
    return m3;
}

Matrix multiplyByConst(Matrix m, ElType x)
{
    /* Mengirim hasil perkalian setiap elemen m dengan x */
    Matrix m1;
    createMatrix(ROW_EFF(m), COL_EFF(m), &m1);
    int i, j;
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            m1.mem[i][j] = x * (m.mem[i][j]);
        }
    }
    return m1;
}

void pMultiplyByConst(Matrix *m, ElType k)
{
    /* I.S. m terdefinisi, k terdefinisi */
    /* F.S. Mengalikan setiap elemen m dengan k */
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++)
    {
        for (j = 0; j < COL_EFF(*m); j++)
        {
            m->mem[i][j] = k * (m->mem[i][j]);
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isMatrixEqual(Matrix m1, Matrix m2)
{
    /* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
    /* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
    /* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
    if (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2))
    {
        boolean result = true;
        for (int i = 0; i < ROW_EFF(m1); i++)
        {
            for (int j = 0; j < COL_EFF(m2); j++)
            {
                if (ELMT(m1, i, j) != ELMT(m2, i, j))
                {
                    result = false;
                }
            }
        }
        return result;
    }
    else
    {
        return false;
    }
}

boolean isMatrixNotEqual(Matrix m1, Matrix m2)
{
    return (!isMatrixEqual(m1, m2));
}
/* Mengirimkan true jika m1 tidak sama dengan m2 */
boolean isMatrixSizeEqual(Matrix m1, Matrix m2)
{
    /* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
    /* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */
    return (ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2));
}

/* ********** Operasi lain ********** */
int countElmt(Matrix m)
{
    /* Mengirimkan banyaknya elemen m */
    return (ROW_EFF(m) * COL_EFF(m));
}

/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m)
{
    /* Mengirimkan true jika m adalah matriks dg ukuran baris dan   kolom sama */
    return (ROW_EFF(m) == COL_EFF(m));
}

boolean isSymmetric(Matrix m)
{
    /* Mengirimkan true jika m adalah matriks simetri : isSquare(m)
       dan untuk setiap elemen m, m(i,j)=m(j,i) */
    if (isSquare(m))
    {
        int i = 0, j = 0;
        boolean symetric = true;
        while (i < ROW_EFF(m) && symetric == true)
        {
            while (j < ROW_EFF(m))
            {
                if (ELMT(m, i, j) != ELMT(m, j, i))
                {
                    symetric = false;
                }
                j++;
            }
            i++;
        }
        return symetric;
    }
    else
    {
        return false;
    }
}
boolean isIdentity(Matrix m)
{
    /* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan
       setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
    if (isSquare(m))
    {
        boolean res = true;
        for (int i = 0; i < ROW_EFF(m); i++)
        {
            for (int j = 0; j < COL_EFF(m); j++)
            {
                if (i == j)
                {
                    if (getElmtDiagonal(m, i) != 1)
                        res = false;
                }
                else
                {
                    if (ELMT(m, i, j) != 0)
                        res = false;
                }
            }
        }
        return res;
    }
    else
    {
        return false;
    }
}

boolean isSparse(Matrix m)
{
    /* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi:
       hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
    int i, j, count_not_0 = 0;
    int max_el = countElmt(m);
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < ROW_EFF(m); j++)
        {
            if (ELMT(m, i, j) != 0)
            {
                count_not_0++;
            }
        }
    }
    return ((((float)count_not_0) / ((float)max_el) * 100) <= 5);
}

Matrix negation(Matrix m)
{
    /* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
    return (multiplyByConst(m, -1));
}

void pNegation(Matrix *m)
{
    /* I.S. m terdefinisi */
    /* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
    pMultiplyByConst(m, -1);
}

float determinant(Matrix m)
{
    /* Prekondisi: isSquare(m) */
    /* Menghitung nilai determinan m */

    float fm[ROW_CAP][ROW_CAP];
    for (int i = 0; i < ROW_EFF(m); i++)
    {
        for (int j = 0; j < ROW_EFF(m); j++)
        {
            fm[i][j] = ELMT(m, i, j);
        }
    }

    float factor;
    for (int i = 0; i < ROW_EFF(m); i++)
    {
        for (int j = i + 1; j < ROW_EFF(m); j++)
        {
            float num = fm[j][i];
            float denum = fm[i][i];
            if (denum == 0)
            {
                factor = 1;
            }
            else
            {
                factor = num / denum;
            }
            for (int k = 0; k < COL_EFF(m); k++)
            {
                fm[j][k] = fm[j][k] - fm[i][k] * factor;
            }
        }
    }
    float result = 1;
    for (int i = 0; i < ROW_EFF(m); i++)
    {
        result *= fm[i][i];
    }
    if (result == (-0))
        result = 0;

    return result;
}

Matrix transpose(Matrix m)
{
    /* I.S. m terdefinisi dan IsSquare(m) */
    /* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
    if (isSquare(m))
    {
        Matrix m2;
        createMatrix(ROW_EFF(m), COL_EFF(m), &m2);
        int i, j;
        for (i = 0; i < ROW_EFF(m); i++)
        {
            for (j = 0; j < ROW_EFF(m); j++)
            {
                ELMT(m2, i, j) = ELMT(m, j, i);
            }
        }
        return m2;
    }
}

void pTranspose(Matrix *m)
{
    /* I.S. m terdefinisi dan IsSquare(m) */
    /* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
    Matrix res;
    createMatrix(ROW_EFF(*m), COL_EFF(*m), &res);
    int i, j;
    for (i = 0; i < ROW_EFF(*m); i++)
    {
        for (j = 0; j < ROW_EFF(*m); j++)
        {
            ELMT(res, i, j) = ELMT(*m, j, i);
        }
    }
    *m = res;
}

float AvgRow(Matrix M, IdxType i){
    int total = COL_EFF(M);
    int sum = 0;
    for (int j = 0; j < COL_EFF(M); j++){
        sum += ELMT(M, i, j);
    }
    return ((float) sum / (float) total);
}

/* Menghasilkan rata-rata dari elemen pada baris ke-i */

/* Prekondisi: i adalah indeks baris efektif dari M */


float AvgCol(Matrix M, IdxType j){
    int total = ROW_EFF(M);
    int sum = 0;
    for (int i = 0; i < ROW_EFF(M); i++){
        sum += ELMT(M, i, j);
    }
    return ((float) sum / (float) total);
}

/* Menghasilkan rata-rata dari elemen pada kolom ke-j */

/* Prekondisi: j adalah indeks kolom efektif dari M */


void MinMaxRow(Matrix M, IdxType i, ElType * max, ElType * min){
    *max = ELMT(M, i, 0);
    *min = ELMT(M, i, 0);
    for (int j = 0; j < COL_EFF(M); j++){
        if (*max < ELMT(M, i, j)) *max = ELMT(M, i, j);
        if (*min > ELMT(M, i, j)) *min = ELMT(M, i, j);
    }
}

/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */

/* F.S. max berisi elemen maksimum pada baris i dari M

min berisi elemen minimum pada baris i dari M */


void MinMaxCol(Matrix M, IdxType j, ElType * max, ElType * min){
    *max = ELMT(M, 0, j);
    *min = ELMT(M, 0, j);
    for (int i = 0; i < ROW_EFF(M); i++){
        if (*max < ELMT(M, i, j)) *max = ELMT(M, i, j);
        if (*min > ELMT(M, i, j)) *min = ELMT(M, i, j);
    }
}

/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */

/* F.S. max berisi elemen maksimum pada kolom j dari M

min berisi elemen minimum pada kolom j dari M */


int CountNumRow(Matrix M, IdxType i, ElType X){
    int sum = 0;
    for (int j = 0; j < COL_EFF(M); j++){
        if (ELMT(M, i, j) == X) sum++;
    }
    return sum;
}

/* Menghasilkan banyaknya kemunculan X pada baris i dari M */


int CountNumCol(Matrix M, IdxType j, ElType X){
    int sum = 0;
    for (int i = 0; i < ROW_EFF(M); i++){
        if (ELMT(M, i, j) == X) sum++;
    }
    return sum;
}

/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */


void RotateMat(Matrix *m){
    int row = 0, col = 0;
    int prev, curr;
    int l = ROW_EFF(*m), n = COL_EFF(*m);

      while (row < l && col < n)
    {
 
        if (row + 1 == l || col + 1 == n)
            break;
 
        // Store the first element of next row, this
        // element will replace first element of current
        // row
        prev = m->mem[row + 1][col];
 
        /* Move elements of first row from the remaining rows */
        for (int i = col; i < n; i++)
        {
            curr = m->mem[row][i];
            m->mem[row][i] = prev;
            prev = curr;
        }
        row++;
 
        /* Move elements of last column from the remaining columns */
        for (int i = row; i < l; i++)
        {
            curr = m->mem[i][n-1];
            m->mem[i][n-1] = prev;
            prev = curr;
        }
        n--;
 
        /* Move elements of last row from the remaining rows */
        if (row < l)
        {
            for (int i = n-1; i >= col; i--)
            {
                curr = m->mem[l-1][i];
                m->mem[l-1][i] = prev;
                prev = curr;
            }
        }
        l--;
 
        /* Move elements of first column from the remaining rows */
        if (col < n)
        {
            for (int i = l-1; i >= row; i--)
            {
                curr = m->mem[i][col];
                m->mem[i][col] = prev;
                prev = curr;
            }
        }
        col++;
    }
}

/* I.S. m terdefinisi dan IsSquare(m) */

/* F.S. m "di-rotasi" searah jarum jam */
