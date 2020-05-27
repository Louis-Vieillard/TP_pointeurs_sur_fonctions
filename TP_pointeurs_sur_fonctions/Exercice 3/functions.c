#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

/**//**/// Fonctions de comparaison  ///**//**//**/
/**/
/**/    //compare les entiers
/**/    int compareEntiers(void* A, void* B) {
/**/        int* A_ = (int*) A;
/**/        int* B_ = (int*) B;
/**/        
/**/        return *A_ > *B_? 1:0;
/**/    }
/**/
/**/    //compare les flottants
/**/    int compareFlottants(void* A, void* B) {
/**/        float* A_ = (float*) A;
/**/        float* B_ = (float*) B;
/**/    
/**/        return *A_ > *B_? 1:0;
/**/    }
/**/
/**/    //compare les caractères
/**/    int compareCaracteres(void* A, void* B) {
/**/        char* A_ = (char*) A;
/**/        char* B_ = (char*) B;
/**/    
/**/        return *A_ > *B_? 1:0;
/**/    }
/**/
/**//**//**//**//**//**//**//**//**//**//**//**//**/


/**//**/// Fonctions d affichage /**//**//**//**//**/
/**/
/**/    //affiche le tableau d entiers
/**/    void afficherTabEntiers(int* tab, int size) {
/**/        for(int i=0; i<size; i++) {
/**/            printf("%d ",tab[i]);
/**/        }
/**/    }
/**/
/**/    //affiche le tableau de flottants
/**/    void afficherTabFlottants(float* tab, int size) {
/**/        for(int i=0; i<size; i++) {
/**/            printf("%f ",tab[i]);
/**/        }
/**/    }
/**/
/**//**//**//**//**//**//**//**//**//**//**//**//**/


//fonction de tri
void tri(void* tab, int size, int elementSize,int (*compare)(void*, void*) ) {
    void* tmp = malloc(elementSize);
    void* element;
    void* nextElement;
    
    for(int i=0; i<size; i++) {
        
        for(int j=0; j < (size-1-i); j++) {
        
            element = tab + (j * elementSize);
            nextElement = tab + (j+1) * elementSize ;
            
            if(compare(element, nextElement)) {
            
                memcpy(tmp,element, elementSize);
                memcpy(element, nextElement, elementSize);
                memcpy(nextElement,tmp, elementSize);
                
            }
        }
    }
    free(tmp);
}



int main() {
    
    int tabEntiers[] = {14, 9, 3, -8, -3, 1};
    float tabFlottants[] = {5.7894, 6.5466, 0.65463, -12.65432, 2.0};
    char tabCaracteres[] = "lsdkheg";
    
    //tableaux d entiers
    printf("        **ENTIERS**\n");
    printf("\nOn affiche le tableau d'entiers: \n");
    afficherTabEntiers(tabEntiers, 6); 
    tri(tabEntiers, 6,sizeof(int),compareEntiers);
    printf("\n\nOn affiche le tableau d'entiers triés: \n");
    afficherTabEntiers(tabEntiers, 6);
    
    //tableaux de flottants
    printf("\n\n        **FLOTTANTS**\n");
    printf("\nOn affiche le tableau de flottants: \n");
    afficherTabFlottants(tabFlottants, 5); 
    tri(tabFlottants, 5,sizeof(float),compareFlottants);
    printf("\n\nOn affiche le tableau de flottants triés: \n");
    afficherTabFlottants(tabFlottants, 5);  
    
    //tableaux de caracteres
    printf("\n\n        **CARACTERES**\n");
    printf("\nOn affiche le tableau de caractères:\n %s",tabCaracteres);
    tri(tabCaracteres, 7,sizeof(char),compareCaracteres );
    printf("\nOn affiche le tableau de caractères triés:\n %s",tabCaracteres);
    

    return 0;
}
