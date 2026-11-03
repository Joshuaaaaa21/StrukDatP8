#include "list2.h" 

/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E} */
address Alokasi(infotype E) {
    //kamus lokal
    address P;
    //algoritma 
    P = (address) malloc(sizeof(Elm2)); //casting
    if (P != NULL ) {
        info(P) = E;
        next(P) = NIL;
    }
    return P;
}
