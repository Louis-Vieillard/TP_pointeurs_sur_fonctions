#include <stdio.h>
#include "functions.h"

//multiplie par 2
void fois_deux(int* entier) {
    *entier = 2 * (*entier);
    printf("%d ",*entier);
}

//divise par 2
void divise_deux(int* entier) {
    (*entier) = (*entier) / 2;
    printf("%d ",*entier);
}

//applique la function au tableau
void apply(int* tab, void (*func)(int*)) {
    for(int i=0; i<4; i++) {
        func(tab + i);
    }
}

int main() {
    
    //on défini le tableau
    int tab[] = {3, 4, 5, 6};
    
    //on affiche le tableau multiplié par 2
    printf("Tableau fois_deux :\n");
    apply(tab, fois_deux);
    
    //on affiche le tableau divisé par 2
    printf("Tableau divise_deux :\n");
    apply(tab, divise_deux);
    
    return 0;
}