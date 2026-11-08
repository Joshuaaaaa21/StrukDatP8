/* File : List2.c */
/* Deskripsi : realisasi body list berkait SIRKULAR dengan representasi fisik pointer */
/* NIM & Nama : 24060125120048 & Joshua Briliant Suryana */
/* Tanggal : 2 November 2026*/
#include <stdio.h>
#include <stdlib.h>
#include "list2.h" 

/****************** Manajemen Memori ******************/
/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E} */
address Alokasi(infotype E) {
    //kamus lokal
    address P;
    //algoritma 
    P = (address) malloc(sizeof(Elm)); //casting
    if (P != NIL) {
        info(P) = E;
        next(P) = NIL;
    }
    return P;
}
 
/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address *P){
    //kamus lokal
	//algoritma
	if ( P != NIL && *P != NIL ) {
		next(*P) = NIL;
		free(*P);
		*P = NIL;
	} else {
		
	}
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List2)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List2 *L){
    //kamus lokal

	//algoritma
	First(*L) = NIL;
}

/****************** TEST KONDISI LIST ******************/
/* function IsEmptyList(L:List2) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List2 L){
    //kamus lokal
    //algoritma
    return (First(L) == NIL);
}

/* function IsOneElm(L:List2) --> boolean 
   {mengembalikan true bila list L hanya punya satu elemen} */
boolean IsOneElm (List2 L){
    //kamus lokal
    //algoritma
    return (First(L) != NIL) && (next(First(L)) == First(L));
}

/*********** PENELUSURAN ***********/
/*procedure PrintList(input L:List2)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List2 L){
    //kamus lokal
    address P;
    //algoritma
    P = First(L);
    if (!IsEmptyList(L)) {
		printf("\nElemen = ");
		do {
			printf("\t%c", info(P));
			P = next(P);
		} while( P != First(L) );
	} else {
		printf("\nList kosong\n");
	}
}

/*function NbElm(L:List2) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List2 L){
    //kamus lokal
	address P;
	int tot;
	//algoritma
	P = First(L);
	tot = 0;
	if(!IsEmptyList(L)){
		do {
			tot = tot + 1;
			P = next(P);
		} while ( P != First(L) );
	} else {
		// List kosong, jumlah elemen tetap 0
	}
	return tot;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List2 *L, infotype V ){
    //kamus lokal
    address P,Q;
    //algoritma
    Q = Alokasi(V);
    if (Q != NIL) {
        if (IsEmptyList(*L)) {
            First(*L) = Q;
            next(Q) = Q; // Elemen tunggal menunjuk ke dirinya sendiri
        } else {
            P = First(*L);
            while (next(P) != First(*L)) { // Cari elemen paling belakang (last element)
                P = next(P);
            }
            
            next(Q) = First(*L); // 1. Elemen baru (Q) menunjuk ke elemen pertama yang lama
            next(P) = Q;         // 2. Elemen terakhir (P) menunjuk ke elemen baru (Q)
            First(*L) = Q;       // 3. Pindahkan penanda First ke elemen baru
        }   
    }
}

/*Procedure InsertVLast(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V, next(P)=First(L)}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List2 *L, infotype V ){
    //kamus lokal
    address P,Q;
    //algoritma
    Q = Alokasi(V);
    if (Q != NIL) {
        if (IsEmptyList(*L)) {
            First(*L) = Q;
            next(Q) = Q; // Elemen tunggal menunjuk ke dirinya sendiri
        } else {
            P = First(*L);
            while (next(P) != First(*L)) { // Cari elemen paling belakang (last element)
                P = next(P);
            }
            
            next(Q) = First(*L); // 1. Elemen baru (Q) menunjuk ke elemen pertama yang lama
            next(P) = Q;         // 2. Elemen terakhir (P) menunjuk ke elemen baru (Q)
        }   
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List2, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List2 L, infotype X, address *A){
    //kamus lokal
	address P;
	//algoritma
	P = First(L);
	*A = NIL;
    if (!IsEmptyList(L)){
        do{
            if(info(P) == X){
                *A = P;
            }
            P = next(P);
        } while ( (P != First(L)) && (*A == NIL) );
    }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List2, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List2 *L, infotype X, infotype Y){
    //kamus lokal
    address P;
    //algoritma
    if(!IsEmptyList(*L)){
		SearchX(*L, X, &P);
		if( P != NIL ){
			info(P) = Y;
		} else {
			// Elemen bernilai X tidak ditemukan dalam list
		}
	} else {
		// List kosong, tidak ada elemen yang dapat di-update
	}
}

/*Procedure Invers(input/output L:List2)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik, 
misal {'A','B','C'} menjadi {'C','B','A'} }*/
void Invers(List2 *L){
    //kamus lokal
	address Prev, Curr, NextI, Last; //Prev = Sebelumnya | Curr = Sekarang | NextI = Berikutnya
	//algoritma
	if (!IsEmptyList(*L) && !IsOneElm(*L)) {
        Curr = First(*L);
        NextI = NIL;
        
        Last = First(*L); //Cari elemen terakhir terlebih dahulu terus disimpan Address ke Last
        while (next(Last) != First(*L)) {
            Last = next(Last);
        }
        
        Prev = Last; // Atur Prev awal berada di elemen terakhir
        
        do { // Balikkan arah pointer setiap elemen
            NextI = next(Curr);    // Amankan pointer ke elemen selanjutnya
            next(Curr) = Prev;     // Putar arah: elemen saat ini menunjuk ke belakang
            Prev = Curr;          // Geser Prev maju
            Curr = NextI;       // Geser Curr maju
        } while (Curr != First(*L)); // Berhenti ketika sudah 1 putaran penuh
        
        First(*L) = Prev; //Pindahkan First ke elemen terakhir yang lama (sekarang menjadi elemen pertama)
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen pertama list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List2 *L, infotype *V){
    //kamus lokal
    address P, Last;
    //algoritma
    *V = '#';
    if (First(*L) != NIL) {
        P = First(*L);
        *V = info(P);
        if (IsOneElm(*L)) {
            First(*L) = NIL;
            Dealokasi(&P);
        } else {
            Last = First(*L);
            while (next(Last) != First(*L)) {
                Last = next(Last);
            }
            First(*L) = next(P);
            next(Last) = First(*L);
            Dealokasi(&P);
        }
    }
}

/*Procedure DeleteVLast(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List2 *L, infotype *V){
    // kamus lokal
    address P, Last;
    // algoritma
    *V = '#';
    if (First(*L) != NIL) {
        if (IsOneElm(*L)) {
            Last = First(*L);
            *V = info(Last);
            First(*L) = NIL; 
            Dealokasi(&Last); 
        } else {
            P = NIL;
            Last = First(*L);
            
            while ( next(Last) != First(*L) ) {
                P = Last;
                Last = next(Last);
            }
            *V = info(Last);
            next(P) = First(*L);
            Dealokasi(&Last);
        }
    }
}

/*Procedure DeleteX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong, X terdefinisi }
{ F.S. Elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteX(List2 *L, infotype X){
    //kamus lokal
    address P, Q;
    infotype T; //tempat sampah
    //algoritma
    if ( !IsEmptyList(*L) ){
        if( info(First(*L)) == X ){
            DeleteVFirst(L, &T);
        } else {
            P = First(*L);
            Q = next(P);
            while ( (Q != First(*L)) && (info(Q) != X) ){
                P = Q;
                Q = next(Q);
            }
            if ( info(Q) == X ){
                next(P) = next(Q);
                Dealokasi(&Q);
            } else {
                // Elemen bernilai X tidak ditemukan dalam list
            }
        }
    } else {
        // List kosong, tidak ada elemen yang dihapus
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(L:List2, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List2 L, infotype X){
    //kamus lokal
    address P;
    int total;
    //algoritma
    total = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            if (info(P) == X) {
                total = total + 1;
            } else {
                // info(P) tidak sama dengan X, tidak dihitung
            }
            P = next(P);
        } while (P != First(L));
    } else {
        // List kosong, jumlah kemunculan X bernilai 0
    }
    return total; // banyaknya karakter X
}

/*function FrekuensiX(L:List2, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List2 L, infotype X){
    //kamus lokal
    int count;
    int total;
    //algoritma
    total = NbElm(L);
    if (total > 0) {
        count = CountX(L, X);
        return ((float)count / (float)total);
    } else {
        // List kosong, frekuensi bernilai 0.0
        return 0.0f;
    }
}

/*function CountVocal(L:List2) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List2 L){
    //kamus lokal
    int count;
    address P;
    char c;
    //algoritma
    count = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            c = info(P);
            // Memeriksa apakah karakter adalah huruf vokal
            if ( c == 'A' || c == 'a' || c == 'I' || c == 'i' ||
                 c == 'U' || c == 'u' || c == 'E' || c == 'e' ||
                 c == 'O' || c == 'o' ) {
                count = count + 1;
            } else {
                // Karakter bukan huruf vokal
            }
            P = next(P);
        } while ( P != First(L) );
    } else {
        // List kosong, jumlah huruf vokal tetap 0
    }
    return count; // banyaknya huruf vokal
}

/*function CountAU(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf A yang langsung diikuti huruf U dalam list L}*/
int CountAU(List2 L){
    //kamus lokal
    int count;
    address P;
    //algoritma
    count = 0;
    if ( !IsEmptyList(L) && !IsOneElm(L) ) {
        P = First(L);
        do {
            if ( (info(P) == 'A' || info(P) == 'a') && 
                 (info(next(P)) == 'U' || info(next(P)) == 'u') ) {
                count = count + 1;
            } else {
                // Bukan pasangan huruf A yang diikuti U
            }
            P = next(P);
        } while ( P != First(L) );
    } else {
        // List kosong atau hanya 1 elemen, tidak ada pasangan AU
    }
    return count;
}

/*Procedure SearchAllX(input L:List2, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List2 L, infotype X){
    //kamus lokal
    address P;
    int pos;
    boolean found;
    //algoritma
    pos = 1;
    found = false;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            if (info(P) == X) {
                if (found) {
                    printf(",%d", pos);
                } else {
                    printf("%d", pos);
                    found = true;
                }
            } else {
                // info(P) != X, tidak dicetak
            }
            pos = pos + 1;
            P = next(P);
        } while (P != First(L));
        if (!found) {
            printf("0");
        } else {
            // Elemen ditemukan minimal pada 1 posisi
        }
    } else {
        printf("0");
    }
}

/*Procedure InsertVAfterX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List2 *L, infotype X, infotype V){
    //kamus lokal
    address P, Q, T;
    //algoritma
    if (!IsEmptyList(*L)) {
        SearchX(*L, X, &P);
        if (P != NIL) {
            T = Alokasi(V);
            if (T != NIL) {
                Q = next(P);
                next(T) = Q;
                next(P) = T;
            } else {
                // Alokasi gagal
            }
        } else {
            // Elemen X tidak ditemukan
        }
    } else {
        // List kosong, tidak ada elemen X
    }
}

/*Procedure InsertVBeforeX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List2 *L, infotype X, infotype V){
    //kamus lokal
    address P, Pos, T;
    //algoritma
    if (!IsEmptyList(*L)) {
        SearchX(*L, X, &P);
        if (P != NIL) {
            if (P == First(*L)) {
                InsertVFirst(L, V);
            } else {
                Pos = First(*L);
                while (next(Pos) != P) {
                    Pos = next(Pos);
                }
                T = Alokasi(V);
                if (T != NIL) {
                    next(T) = P;
                    next(Pos) = T;
                } else {
                    // Alokasi gagal
                }
            }
        } else {
            // Elemen X tidak ditemukan
        }
    } else {
        // List kosong, tidak ada elemen X
    }
}

/*Procedure DeleteVAfterX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List2 *L, infotype X, infotype *V){
    //kamus lokal
    address P, Q;
    //algoritma
    *V = '#';
    if (!IsEmptyList(*L)) {
        SearchX(*L, X, &P);
        if (P != NIL) {
            if (IsOneElm(*L)) {
                DeleteVFirst(L, V);
            } else {
                Q = next(P);
                *V = info(Q);
                if (Q == First(*L)) {
                    First(*L) = next(Q);
                }
                next(P) = next(Q);
                Dealokasi(&Q);
            }
        } else {
            // Elemen X tidak ditemukan
        }
    } else {
        // List kosong
    }
}

/*Procedure DeleteVBeforeX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List2 *L, infotype X, infotype *V){
    //kamus lokal
    address P, Pos, Q;
    //algoritma
    *V = '#';
    if (!IsEmptyList(*L)) {
        SearchX(*L, X, &P);
        if (P != NIL) {
            if (IsOneElm(*L)) {
                DeleteVFirst(L, V);
            } else {
                Pos = First(*L);
                while (next(next(Pos)) != P) {
                    Pos = next(Pos);
                }
                Q = next(Pos);
                *V = info(Q);
                if (Q == First(*L)) {
                    First(*L) = P;
                }
                next(Pos) = P;
                Dealokasi(&Q);
            }
        } else {
            // Elemen X tidak ditemukan
        }
    } else {
        // List kosong
    }
}

/*Procedure DeleteAllX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Semua elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteAllX(List2 *L, infotype X){
    //kamus lokal
    address A;
    //algoritma
    if (!IsEmptyList(*L)) {
        SearchX(*L, X, &A);
        while (A != NIL && !IsEmptyList(*L)) {
            DeleteX(L, X);
            SearchX(*L, X, &A);
        }
    } else {
        // List kosong
    }
}

/*function Modus(L:List2) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List2 L){
    //kamus lokal
    address P;
    char modus;
    int max, c;
    //algoritma
    modus = '#'; // default bila list kosong
    max = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            c = CountX(L, info(P));
            if ( c > max ) {
                max = c;
                modus = info(P);
            } else {
                // Frekuensi tidak melebihi max, modus tidak berubah
            }
            P = next(P);
        } while ( P != First(L) );
    } else {
        // List kosong, modus bernilai '#'
    }
    return modus;
}

/*function MaxMember(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List2 L){
    //kamus lokal
    address P;
    int max, c;
    //algoritma
    max = 0; // bernilai 0 bila list kosong
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            c = CountX(L, info(P));
            if ( c > max ) {
                max = c;
            } else {
                // Frekuensi tidak melebihi max, max tidak berubah
            }
            P = next(P);
        } while ( P != First(L) );
    } else {
        // List kosong, max bernilai 0
    }
    return max;
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List2, input L2:List2, output L:List2)
{I.S.: L1,L2 terdefinisi ; 
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List2 L1, List2 L2, List2 *L){
    //kamus lokal
    address Last1, Last2;
    //algoritma
    CreateList(L);
    if (IsEmptyList(L1)) {
        if (!IsEmptyList(L2)) {
            First(*L) = First(L2);
        } else {
            // L1 dan L2 kosong, L tetap kosong
        }
    } else {
        First(*L) = First(L1);
        if (!IsEmptyList(L2)) {
            Last1 = First(L1);
            while (next(Last1) != First(L1)) {
                Last1 = next(Last1);
            }
            Last2 = First(L2);
            while (next(Last2) != First(L2)) {
                Last2 = next(Last2);
            }
            next(Last1) = First(L2);
            next(Last2) = First(*L);
        } else {
            // L2 kosong, L hanya berisi elemen L1
        }
    }
}

/*Procedure SplitList(input L:List2, output L1:List2, output L2:List2)
{I.S.: L terdefinisi ; 
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List2 L, List2 *L1, List2 *L2){
    //kamus lokal
    address P, Last;
    int n, k, i;
    //algoritma
    CreateList(L1);
    CreateList(L2);
    if (!IsEmptyList(L)) {
        n = NbElm(L);
        k = (n + 1) / 2; // kelebihan 1 elemen jatuh ke L1
        P = First(L);
        i = 1;
        while (i < k) {
            P = next(P);
            i = i + 1;
        }
        // P sekarang menunjuk elemen ke-k (elemen terakhir milik L1)
        if (n == 1) {
            First(*L1) = First(L);
        } else {
            Last = First(L);
            while (next(Last) != First(L)) {
                Last = next(Last);
            }
            First(*L2) = next(P);   // awal bagian kedua
            next(P) = First(L);     // menutup circular list L1
            First(*L1) = First(L);
            next(Last) = First(*L2); // menutup circular list L2
        }
    } else {
        // List L kosong, L1 dan L2 tetap list kosong
    }
}

/*Procedure CopyList(input L1:List2, output L2:List2)
{I.S.: L1 terdefinisi;  
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List2 L1, List2 *L2){
    //kamus lokal
    address P;
    //algoritma
    CreateList(L2);
    if (!IsEmptyList(L1)) {
        P = First(L1);
        do {
            InsertVLast(L2, info(P));
            P = next(P);
        } while (P != First(L1));
    } else {
        // L1 kosong, L2 tetap berupa list kosong
    }
}
