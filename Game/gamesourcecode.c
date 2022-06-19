#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("###Bienvenue sur le jeu###\n");
	int a_deviner = 0;
	int nombre_de_coups = 10;
	int nombre_de_vies = 10;
	printf("Joueur 1, entrez un nombre compris entre 1 et 100\n");
	scanf_s("%d", &a_deviner);
	while (a_deviner < 1 || a_deviner > 100)
	{
		printf("Ce nombre n'est pas valide, merci d'entrer un nombre compris entre 1 et 100\n");
		scanf_s("%d", &a_deviner);
	}
	int entree_joueur_2 = 0;

	while (entree_joueur_2 != a_deviner && nombre_de_vies != 0)
	{
		printf("Joueur 2, cherchez le nombre mystere (compris entre 1 et 100)\n");
		scanf_s("%d", &entree_joueur_2);
		if ((a_deviner - entree_joueur_2 <= 5 && a_deviner - entree_joueur_2 > 0 && entree_joueur_2 != a_deviner) || (a_deviner - entree_joueur_2 < 0 && a_deviner - entree_joueur_2 >= -5 && entree_joueur_2 != a_deviner))
		{
			nombre_de_vies -= 1;
			printf("Chaud bouillant !\n");
			printf("Il vous reste %d vie(s)\n", nombre_de_vies);
		}
		else if ((a_deviner - entree_joueur_2 <= 10 && a_deviner - entree_joueur_2 > 0 && entree_joueur_2 != a_deviner) || (a_deviner - entree_joueur_2 < 0 && a_deviner - entree_joueur_2 >= -10 && entree_joueur_2 != a_deviner))
		{
			nombre_de_vies -= 1;
			printf("Chaud\n");
			printf("Il vous reste %d vie(s)\n", nombre_de_vies);
		}
		else if (entree_joueur_2 == a_deviner)
		{
			nombre_de_vies += 0;
		}
		else
		{
			nombre_de_vies -= 1;
			printf("Froid\n");
			printf("Il vous reste %d vie(s)\n", nombre_de_vies);
		}
	}

	if (nombre_de_vies == 0)
	{
		printf("Dommage, le nombre mystere etait %d\n", a_deviner);
	}
	else
	{
		nombre_de_coups -= nombre_de_vies;
		printf("Bravo, vous avez trouve !!\n");
		printf("Il vous aura fallu %d tentatives", nombre_de_coups + 1);
	}
	return 0;
}