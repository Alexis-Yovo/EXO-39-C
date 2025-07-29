#include <stdio.h>
#include <stdlib.h>

// Définition du type individu
typedef struct info {
    int iAge;
    char* sNom;
} individu;

// Définition du type cellule
typedef struct cellule {
    individu info;
    struct cellule *suivant;
} cellule;

// Type alias pour la liste
typedef cellule *liste;

// Variables globales pour les deux listes résultantes
liste jeunes = NULL;
liste vieux = NULL;

// Fonction pour séparer la liste
void separation(int iAgeMaxJeune) {
    cellule *courant = prem; // Pointeur pour parcourir la liste
    cellule *precedent = NULL; // Pointeur pour garder la référence sur la dernière cellule ajoutée

    // Tant qu'il y a des éléments dans la liste
    while (courant != NULL) {
        if (courant->info.iAge < iAgeMaxJeune) {
            // Ajouter à la liste des jeunes
            if (jeunes == NULL) {
                jeunes = courant; // Première cellule de la liste des jeunes
            } else {
                precedent->suivant = courant; // Relier la dernière cellule ajoutée à la nouvelle
            }
            precedent = courant; // Mettre à jour le précédent
        } else {
            // Ajouter à la liste des vieux
            if (vieux == NULL) {
                vieux = courant; // Première cellule de la liste des vieux
            } else {
                precedent->suivant = courant; // Relier la dernière cellule ajoutée à la nouvelle
            }
            precedent = courant; // Mettre à jour le précédent
        }

        // Avancer au prochain élément
        courant = courant->suivant;
    }

    // Couper les liens entre les deux listes
    if (jeunes != NULL) {
        precedent->suivant = NULL; // Terminer la liste des jeunes
    }
    if (vieux != NULL) {
        precedent->suivant = NULL; // Terminer la liste des vieux
    }

    // Réinitialiser la liste originale
    prem = NULL;
}

// Fonction principale pour tester
int main() {
    // Création d'une liste avec quelques éléments
    liste prem = malloc(sizeof(cellule));
    prem->info.iAge = 25;
    prem->info.sNom = "Alice";
    prem->suivant = malloc(sizeof(cellule));
    prem->suivant->info.iAge = 30;
    prem->suivant->info.sNom = "Bob";
    prem->suivant->suivant = malloc(sizeof(cellule));
    prem->suivant->suivant->info.iAge = 35;
    prem->suivant->suivant->info.sNom = "Charlie";
    prem->suivant->suivant->suivant = NULL;

    // Valeur maximale pour les jeunes
    int AGEMAX_JEUNE = 30;

    // Appeler la fonction separation
    separation(AGEMAX_JEUNE);

    // Afficher les deux listes résultantes
    printf("Liste des jeunes :\n");
    afficher(jeunes);

    printf("\nListe des vieux :\n");
    afficher(vieux);

    // Libérer la mémoire allouée
    cellule *temp;
    while (jeunes != NULL) {
        temp = jeunes;
        jeunes = jeunes->suivant;
        free(temp);
    }
    while (vieux != NULL) {
        temp = vieux;
        vieux = vieux->suivant;
        free(temp);
    }

    return 0;
}
