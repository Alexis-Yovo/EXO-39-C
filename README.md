### Code C : Définition de structures et déclaration de variables (Code à utiliser)

```c
typedef struct info {
    int iAge;
    char* sNom;
} info;

typedef struct cellule {
    struct info individu;
    struct cellule *suivant;
} *liste;

/* Déclaration de variable */
liste prem;
int AGEMAX = 125;
