/* File : mainlist2.c */
/* Deskripsi : aplikasi driver ADT list berkait SIRKULAR dengan representasi fisik pointer */
/* NIM & Nama : 24060125120048 & Joshua Briliant Suryana */
/* Tanggal : 2 November 2026 */

#include <stdio.h>
#include <stdlib.h>
#include "list2.h"

int main() {
    /* Kamus */
    List2 L, Lcopy, L1, L2, Lconcat;
    address foundAddr;
    infotype val, X, V, Y;
    int n, i;

    /* Algoritma */
    printf("========================================================\n");
    printf("     DRIVER ADT LIST BERKAIT SIRKULAR (POINTER) - LIST2 \n");
    printf("========================================================\n\n");

    /* --- 1. PENGUJIAN CREATELIST & ISEMPTYLIST --- */
    printf("--- 1. Pengujian CreateList & IsEmptyList ---\n");
    CreateList(&L);
    printf("Setelah CreateList(&L):\n");
    printf("  IsEmptyList(L) : %s\n", IsEmptyList(L) ? "TRUE" : "FALSE");
    printf("  NbElm(L)       : %d\n", NbElm(L));
    printf("  PrintList(L)   :");
    PrintList(L);
    printf("\n\n");

    /* --- 2. INPUT ELEMEN AWAL LIST DARI USER --- */
    printf("--- 2. Input Elemen Awal List dari User ---\n");
    printf("Berapa banyak elemen yang ingin dimasukkan? ");
    if (scanf("%d", &n) != 1 || n < 0) {
        n = 0;
    }

    for (i = 1; i <= n; i++) {
        printf("  Masukkan elemen ke-%d: ", i);
        scanf(" %c", &val);
        InsertVLast(&L, val);
    }

    printf("\nIsi list L setelah pengisian awal:");
    PrintList(L);
    printf("\n  NbElm(L)       : %d\n", NbElm(L));
    printf("  IsOneElm(L)    : %s\n\n", IsOneElm(L) ? "TRUE" : "FALSE");

    /* --- 3. ANALISIS ELEMEN AWAL --- */
    printf("--- 3. Analisis Elemen List Awal ---\n");
    printf("  Jumlah Huruf Vokal (CountVocal)       : %d\n", CountVocal(L));
    printf("  Kemunculan pasangan 'AU' (CountAU)    : %d\n", CountAU(L));
    printf("  Modus (huruf terbanyak muncul)        : %c\n", Modus(L));
    printf("  MaxMember (frekuensi kemunculan modus): %d\n\n", MaxMember(L));

    /* --- 4. PENGUJIAN PENCARIAN & FREKUENSI ELEMEN --- */
    printf("--- 4. Pengujian Pencarian & Frekuensi Elemen ---\n");
    printf("Masukkan karakter X yang ingin dicari: ");
    scanf(" %c", &X);

    SearchX(L, X, &foundAddr);
    if (foundAddr != NIL) {
        printf("  SearchX: elemen '%c' DITEMUKAN pada address %i\n", X, (void*)foundAddr);
    } else {
        printf("  SearchX: elemen '%c' TIDAK DITEMUKAN\n", X);
    }

    printf("  SearchAllX (posisi-posisi '%c'): ", X);
    SearchAllX(L, X);
    printf("\n");
    printf("  CountX (banyaknya '%c')        : %d\n", X, CountX(L, X));
    printf("  FrekuensiX (rasio '%c')       : %.2f\n\n", X, FrekuensiX(L, X));

    /* --- 5. PENGUJIAN PENYISIPAN ELEMEN --- */
    printf("--- 5. Pengujian Penyisipan Elemen (InsertVFirst, InsertVLast, InsertVAfterX, InsertVBeforeX) ---\n");
    
    /* 5.1 InsertVFirst */
    printf("[5.1] Pengujian InsertVFirst (sisip di awal):\n");
    printf("  Masukkan karakter V untuk disisipkan di awal: ");
    scanf(" %c", &V);
    InsertVFirst(&L, V);
    printf("  -> Karakter '%c' berhasil disisipkan di awal list.\n", V);
    printf("  Isi list L setelah InsertVFirst:");
    PrintList(L);
    printf("\n  NbElm(L)      : %d\n", NbElm(L));
    printf("  Modus(L)      : %c (frekuensi: %d)\n", Modus(L), MaxMember(L));
    printf("  CountVocal(L) : %d\n", CountVocal(L));
    printf("  CountAU(L)    : %d\n\n", CountAU(L));

    /* 5.2 InsertVLast */
    printf("[5.2] Pengujian InsertVLast (sisip di akhir):\n");
    printf("  Masukkan karakter V untuk disisipkan di akhir: ");
    scanf(" %c", &V);
    InsertVLast(&L, V);
    printf("  -> Karakter '%c' berhasil disisipkan di akhir list.\n", V);
    printf("  Isi list L setelah InsertVLast:");
    PrintList(L);
    printf("\n  NbElm(L)      : %d\n", NbElm(L));
    printf("  Modus(L)      : %c (frekuensi: %d)\n", Modus(L), MaxMember(L));
    printf("  CountVocal(L) : %d\n", CountVocal(L));
    printf("  CountAU(L)    : %d\n\n", CountAU(L));

    /* 5.3 InsertVAfterX */
    printf("[5.3] Pengujian InsertVAfterX (sisip sesudah elemen acuan):\n");
    printf("  List saat ini:");
    PrintList(L);
    printf("\n  Masukkan karakter acuan X: ");
    scanf(" %c", &X);
    printf("  Masukkan karakter baru V yang akan disisipkan setelah '%c': ", X);
    scanf(" %c", &V);
    SearchX(L, X, &foundAddr);
    if (foundAddr != NIL) {
        InsertVAfterX(&L, X, V);
        printf("  -> Karakter '%c' BERHASIL disisipkan setelah '%c'.\n", V, X);
    } else {
        printf("  -> PERHATIAN: Karakter acuan '%c' TIDAK DITEMUKAN dalam list!\n", X);
        printf("     Sesuai aturan ADT, elemen '%c' tidak disisipkan dan list tidak berubah.\n", V);
    }
    printf("  Isi list L setelah InsertVAfterX:");
    PrintList(L);
    printf("\n  NbElm(L)      : %d\n", NbElm(L));
    printf("  Modus(L)      : %c (frekuensi: %d)\n", Modus(L), MaxMember(L));
    printf("  CountVocal(L) : %d\n", CountVocal(L));
    printf("  CountAU(L)    : %d\n\n", CountAU(L));

    /* 5.4 InsertVBeforeX */
    printf("[5.4] Pengujian InsertVBeforeX (sisip sebelum elemen acuan):\n");
    printf("  List saat ini:");
    PrintList(L);
    printf("\n  Masukkan karakter acuan X: ");
    scanf(" %c", &X);
    printf("  Masukkan karakter baru V yang akan disisipkan sebelum '%c': ", X);
    scanf(" %c", &V);
    SearchX(L, X, &foundAddr);
    if (foundAddr != NIL) {
        InsertVBeforeX(&L, X, V);
        printf("  -> Karakter '%c' BERHASIL disisipkan sebelum '%c'.\n", V, X);
    } else {
        printf("  -> PERHATIAN: Karakter acuan '%c' TIDAK DITEMUKAN dalam list!\n", X);
        printf("     Sesuai aturan ADT, elemen '%c' tidak disisipkan dan list tidak berubah.\n", V);
    }
    printf("  Isi list L setelah InsertVBeforeX:");
    PrintList(L);
    printf("\n  NbElm(L)      : %d\n", NbElm(L));
    printf("  Modus(L)      : %c (frekuensi: %d)\n", Modus(L), MaxMember(L));
    printf("  CountVocal(L) : %d\n", CountVocal(L));
    printf("  CountAU(L)    : %d\n\n", CountAU(L));

    /* --- 6. PENGUJIAN UPDATE ELEMEN (UpdateX) --- */
    printf("--- 6. Pengujian UpdateX ---\n");
    printf("List saat ini:");
    PrintList(L);
    printf("\nMasukkan karakter X yang ingin diubah: ");
    scanf(" %c", &X);
    printf("Masukkan karakter pengganti Y: ");
    scanf(" %c", &Y);
    SearchX(L, X, &foundAddr);
    if (foundAddr != NIL) {
        UpdateX(&L, X, Y);
        printf("  -> Karakter '%c' BERHASIL diubah menjadi '%c'.\n", X, Y);
    } else {
        printf("  -> PERHATIAN: Karakter '%c' TIDAK DITEMUKAN dalam list! List tidak berubah.\n", X);
    }
    printf("  Isi list setelah UpdateX:");
    PrintList(L);
    printf("\n  NbElm(L)      : %d\n", NbElm(L));
    printf("  Modus(L)      : %c (frekuensi: %d)\n", Modus(L), MaxMember(L));
    printf("  CountVocal(L) : %d\n", CountVocal(L));
    printf("  CountAU(L)    : %d\n\n", CountAU(L));

    /* --- 7. PENGUJIAN PENGHAPUSAN KHUSUS --- */
    printf("--- 7. Pengujian Penghapusan Elemen (DeleteVAfterX, DeleteVBeforeX, DeleteX, DeleteAllX) ---\n");
    
    /* 7.1 DeleteVAfterX */
    printf("[7.1] DeleteVAfterX:\n");
    printf("  List saat ini:");
    PrintList(L);
    printf("\n  Masukkan karakter acuan X: ");
    scanf(" %c", &X);
    SearchX(L, X, &foundAddr);
    if (foundAddr != NIL) {
        DeleteVAfterX(&L, X, &val);
        printf("  -> DeleteVAfterX BERHASIL: elemen sesudah '%c' yang dihapus adalah '%c'\n", X, val);
    } else {
        printf("  -> PERHATIAN: Karakter acuan '%c' TIDAK DITEMUKAN dalam list! Tidak ada elemen yang dihapus.\n", X);
    }
    printf("  Isi list sekarang:");
    PrintList(L);
    printf("\n  NbElm(L)      : %d\n\n", NbElm(L));

    /* 7.2 DeleteVBeforeX */
    printf("[7.2] DeleteVBeforeX:\n");
    printf("  List saat ini:");
    PrintList(L);
    printf("\n  Masukkan karakter acuan X: ");
    scanf(" %c", &X);
    SearchX(L, X, &foundAddr);
    if (foundAddr != NIL) {
        DeleteVBeforeX(&L, X, &val);
        printf("  -> DeleteVBeforeX BERHASIL: elemen sebelum '%c' yang dihapus adalah '%c'\n", X, val);
    } else {
        printf("  -> PERHATIAN: Karakter acuan '%c' TIDAK DITEMUKAN dalam list! Tidak ada elemen yang dihapus.\n", X);
    }
    printf("  Isi list sekarang:");
    PrintList(L);
    printf("\n  NbElm(L)      : %d\n\n", NbElm(L));

    /* 7.3 DeleteX */
    printf("[7.3] DeleteX (hapus 1 kemunculan):\n");
    printf("  List saat ini:");
    PrintList(L);
    printf("\n  Masukkan karakter X untuk DeleteX: ");
    scanf(" %c", &X);
    SearchX(L, X, &foundAddr);
    if (foundAddr != NIL) {
        DeleteX(&L, X);
        printf("  -> DeleteX BERHASIL: satu elemen '%c' berhasil dihapus.\n", X);
    } else {
        printf("  -> PERHATIAN: Karakter '%c' TIDAK DITEMUKAN dalam list! Tidak ada elemen yang dihapus.\n", X);
    }
    printf("  Isi list sekarang:");
    PrintList(L);
    printf("\n  NbElm(L)      : %d\n\n", NbElm(L));

    /* 7.4 DeleteAllX */
    printf("[7.4] DeleteAllX (hapus semua kemunculan):\n");
    printf("  List saat ini:");
    PrintList(L);
    printf("\n  Masukkan karakter X untuk DeleteAllX: ");
    scanf(" %c", &X);
    SearchX(L, X, &foundAddr);
    if (foundAddr != NIL) {
        DeleteAllX(&L, X);
        printf("  -> DeleteAllX BERHASIL: semua kemunculan '%c' berhasil dihapus.\n", X);
    } else {
        printf("  -> PERHATIAN: Karakter '%c' TIDAK DITEMUKAN dalam list! Tidak ada elemen yang dihapus.\n", X);
    }
    printf("  Isi list setelah DeleteAllX:");
    PrintList(L);
    printf("\n  NbElm(L)      : %d\n", NbElm(L));
    printf("  Modus(L)      : %c (frekuensi: %d)\n", Modus(L), MaxMember(L));
    printf("  CountVocal(L) : %d\n", CountVocal(L));
    printf("  CountAU(L)    : %d\n\n", CountAU(L));

    /* --- 8. PENGUJIAN INVERS --- */
    printf("--- 8. Pengujian Invers (Membalik List) ---\n");
    printf("Isi list L sebelum di-invers:");
    PrintList(L);
    Invers(&L);
    printf("\nIsi list L setelah di-invers :");
    PrintList(L);
    printf("\n\n");

    /* --- 9. PENGUJIAN COPYLIST --- */
    printf("--- 9. Pengujian CopyList ---\n");
    CopyList(L, &Lcopy);
    printf("Isi Lcopy (salinan dari L):");
    PrintList(Lcopy);
    printf("\nVerifikasi independensi alamat (First berbeda alamat):\n");
    printf("  Address First(L)     : %p\n", (void*)First(L));
    printf("  Address First(Lcopy) : %p\n", (void*)First(Lcopy));
    if (First(L) != NIL && First(Lcopy) != NIL) {
        if (First(L) != First(Lcopy)) {
            printf("  -> Benar, L dan Lcopy mandiri dengan alamat memori berbeda!\n\n");
        } else {
            printf("  -> Alamat masih sama!\n\n");
        }
    } else {
        printf("  -> List kosong.\n\n");
    }

    /* --- 10. PENGUJIAN SPLITLIST --- */
    printf("--- 10. Pengujian SplitList ---\n");
    printf("Memecah Lcopy (NbElm = %d) menjadi L1 dan L2:\n", NbElm(Lcopy));
    SplitList(Lcopy, &L1, &L2);
    printf("  L1 (NbElm = %d) :", NbElm(L1));
    PrintList(L1);
    printf("\n  L2 (NbElm = %d) :", NbElm(L2));
    PrintList(L2);
    printf("\n\n");

    /* --- 11. PENGUJIAN CONCATLIST --- */
    printf("--- 11. Pengujian ConcatList ---\n");
    printf("Menggabungkan kembali L1 dan L2 menjadi Lconcat:\n");
    ConcatList(L1, L2, &Lconcat);
    printf("  Lconcat (gabungan):");
    PrintList(Lconcat);
    printf("\n  NbElm(Lconcat)   : %d\n\n", NbElm(Lconcat));

    /* --- 12. PENGUJIAN DELETE DASAR (DeleteVFirst & DeleteVLast) --- */
    printf("--- 12. Pengujian Delete Dasar (DeleteVFirst & DeleteVLast) ---\n");
    printf("Isi list L sebelum delete:");
    PrintList(L);
    printf("\n");

    DeleteVFirst(&L, &val);
    printf("DeleteVFirst -> elemen terhapus: '%c'\n", val);
    printf("  Isi L:");
    PrintList(L);
    printf("\n  NbElm(L): %d\n", NbElm(L));

    DeleteVLast(&L, &val);
    printf("\nDeleteVLast -> elemen terhapus: '%c'\n", val);
    printf("  Isi L:");
    PrintList(L);
    printf("\n  NbElm(L): %d\n", NbElm(L));

    printf("\nMenghapus sisa elemen hingga list L kosong:\n");
    while (!IsEmptyList(L)) {
        DeleteVLast(&L, &val);
        printf("  DeleteVLast -> terhapus '%c', sisa NbElm: %d\n", val, NbElm(L));
    }
    printf("List L sekarang kosong: IsEmptyList(L) = %s\n", IsEmptyList(L) ? "TRUE" : "FALSE");

    printf("\n========================================================\n");
    printf("                   PENGUJIAN SELESAI                    \n");
    printf("========================================================\n");

    return 0;
}
