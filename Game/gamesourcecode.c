#include <stdio.h>
#include <stdlib.h>


int rejouer()
{
	int rejouer = -1;
	printf("Rejouer ? (0 pour quitter, 1 pour rejouer)\n");
	scanf_s("%d", &rejouer);
	if (rejouer == 0)
	{
		return 0;
	}
	else if (rejouer == 1)
	{
		main();
	}
	else
	{
		printf("Cette touche n'est pas valide, merci d'entrer 0 ou 1 selon votre choix\n");
	}
}

int main()
{
	printf("### Bienvenue sur GuessTN ###\n");
	printf("Pour l'utilisation de ce logiciel, merci de vous referer au fichier manual.txt fourni avec le logiciel\n");
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

	while (entree_joueur_2 != a_deviner && nombre_de_vies != 0) /*tant que l'entree du joueur 2 ne correspond pas au chiffre
																a deviner du joueur 1 et qu'il reste des vies au joueur 2*/
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
		rejouer();
	}
	else
	{
		nombre_de_coups -= nombre_de_vies;
		printf("Bravo, vous avez trouve !!\n");
		printf("Il vous aura fallu %d tentatives\n", nombre_de_coups + 1);
		rejouer();
	}
}