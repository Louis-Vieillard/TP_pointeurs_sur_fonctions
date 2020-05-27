#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

int pair(int entier) {
    return (entier % 2);
}

int premier(int entier) {
    
    if (entier % 2 == 0) {
        return (entier == 2);
    }
    for(int i=3; i * i <= entier; i +=2) {
        if (entier % i == 0) {
          return 0;
        }
    }
    return 1;
}


int negatif(int entier) {
    if(entier<0) {
        return 1;
    }
    return 0;
}


void supprimer(int* tab, int size) {
    
    //on supprime les nombres paires
    for(int i = 0; i < size; i++) {

        int entier = tab[i];
        
        int test = pair(entier);
        
        if (test == 0) {
            size--;
            for (int j = i; j < size+1; j++) {
                if (j < size)
                {
                    tab[j] = tab[j+1];
                }
                else {
                    tab[j] = 0;
                }
            }
        }
    }
    
    //on affiche le tableau apres la suppression des nombres paires
    printf("\nApres la suppression des nombres paires:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", tab[i]);
    }

    //on supprime les nombres premiers
    for(int i = 0; i < size; i++) {

        int entier = tab[i];
        
        int test = premier(entier);
        
        if (test == 1) {
            size--;
            for (int j = i; j < size+1; j++) {
                if (j < size)
                {
                    tab[j] = tab[j+1];
                }
                else {
                    tab[j] = 0;
                }
            }
        }
    }
    
    //on affiche le tableau apres la suppression des nombres premiers
    printf("\nApres la suppression des nombres premiers:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", tab[i]);
    }

    //on supprime les nombres negatifs
    for(int i = 0; i < size; i++) {

        int entier = tab[i];
        
        int test = negatif(entier);
        
        if (test == 1) {
            size--;
            for (int j = i; j < size+1; j++) {
                if (j < size)
                {
                    tab[j] = tab[j+1];
                }
                else {
                    tab[j] = 0;
                }
            }
        }
    }
    
    //on affiche le tableau apres la suppression des nombres premiers
    printf("\nApres la suppression des nombres negatifs:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", tab[i]);
    }
}


int main() {
    
    int tab[] = {7, 2, 57, 23, -57};
    int size = 5;
    
    printf("\nOn affiche le tableau:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", tab[i]);
    }

    supprimer(tab, size);

    return 0;
}

