void afficherTabEntier(int* tab, int size); //affiche le tableau d entiers

void afficherTabFlottants(float* tab, int size); //affiche le tableau de flottants

int compareEntiers(void* A, void* B); //compare les entiers

int compareFlottants(void* A, void* B); //compare les flottants

int compareCaracteres(void* A, void* B); //compare les caracteres

void tri(void* tab, int size, int elementSize,int (*compare)(void*, void*) ); //fonction de tri
