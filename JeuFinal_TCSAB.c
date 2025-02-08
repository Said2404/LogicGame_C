#include <stdio.h>                                               //Inclusion de la bibliothèque d'entrées/sorties
#include <stdlib.h>                                              //Inclusion de la bibliothèque de gestion dynamique de mémoire, interaction avec l'OS, etc...
#include <string.h>                                              //Inclusion de la bibliothèque de gestion des chaines de caractères et de blocs de mémoire
#include <time.h>                                                //Inclusion de la bibliothèque de gestion de dates, temps, et intervalles


void reglesSuiteMystere();                                       //Prédéfinition des fonctions suivantes :
void reglesNombreCache();
void reglesMastermind();
void afficherMenu();
int suiteMystere();
int nombreCache();
int mastermind();

int main()                                                       //Programme principal
{
    int score1 = 0;                                              
    int bestScore1 = 2000;                                       //Initialise le meilleur score du jeu Suite Mystère à 2000 (comme ça on est sur qu'il soit plus grand)
    int nbParties1 = 0;                                          
    int score2 = 0;                                              
    int bestScore2 = 2000;                                       //Initialise le meilleur score du jeu Nombre Caché à 2000 (comme ça on est sur qu'il soit plus grand)
    int nbParties2 = 0;                                         
    int score3 = 0;                                             
    int bestScore3 = 2000;                                       //Initialise le meilleur score du jeu Mastermind à 2000 (comme ça on est sur qu'il soit plus grand)
    int nbParties3 = 0;                                         
    char reponse[2];                                             //Initialise la chaine de caractère contenant la réponse du joueur, de longueur 2
    int choixJeu = 0;                                          

    system("clear");                                             //Clear le terminal (+ésthétique)

    

    printf("\nBonjour et bienvenue sur le jeu en langage C développé par AIT BAHA Said et CHOLLET Thomas !\n");
    printf("Nous vous proposons de jouer à trois minijeux différents :\n\n");
    

    while (choixJeu != 5)                                        //Tant que le choix du jeu est différent de 5
    {
        if (choixJeu == 4)                                       //Si le jeu choisit est le 4, clear le terminal et affiche les règles des 3 minijeux
        {
            system("clear");                                  
            reglesSuiteMystere();                            
            reglesNombreCache();                             
            reglesMastermind();                                 
        }
        
        afficherMenu();                                          //Affiche le menu du jeu
        scanf("%s", reponse);                                    //Récupère la réponse du joueur (une chaine de caractères)

                                                                 //Si le premier caractère de la réponse donné par le joueur fait partie des caractères 1, 2, 3, 4, ou 5

        if (reponse[0] == '1' || reponse[0] == '2' || reponse[0] == '3' || reponse[0] == '4' || reponse[0] == '5')
        {
            choixJeu = reponse[0] - 48;                          //Met choixJeu égal au code ASCII du premier caractère de réponse - 48
            switch (choixJeu)                                    //Si choixJeu est égal à :...
            {
            case 1:                                              //...1
                score1 = suiteMystere();                         //Appelle la fonction suiteMystère et met le résultat du return dans score1
                nbParties1++;                                    
                if (score1 < bestScore1)                         //Si le score obtenu durant la partie est plus petit (meilleur) que le meilleur score1 précédent
                {
                    bestScore1 = score1;                        
                }



                printf("\n===== Statistiques Suite Mystère =====\n");
                printf("\nNombre de parties jouées       : %3i", nbParties1);
                printf("\nScore                          : %3i", score1);
                printf("\nMeilleur score                 : %3i", bestScore1);
                break;                                                          //Sort du switch
            case 2:                                              //...2
                score2 = nombreCache();                          //Appelle la fonction nombreCache et met le résultat du return dans score2
                nbParties2++;                                  
                if (score2 < bestScore2)                         //Si le score obtenu durant la partie est plus petit (meilleur) que le meilleur score2 précédent
                {
                    bestScore2 = score2;                   
                }

 

                printf("\n====== Statistiques Nombre Caché =====\n");
                printf("\nNombre de parties jouées       : %3i", nbParties2);
                printf("\nScore                          : %3i", score2);
                printf("\nMeilleur score                 : %3i", bestScore2);
                break;                                                          //Sort du switch
            case 3:                                              //...3
                score3 = mastermind();                           //Appelle la fonction mastermind et met le résultat du return dans score3
                nbParties3++;                                    
                if (score3 < bestScore3)                         //Si le score obtenu durant la partie est plus petit (meilleur) que le meilleur score3 précédent
                {
                    bestScore3 = score3;                      
                }

  

                printf("\n======= Statistiques Mastermind ======\n");
                printf("\nNombre de parties jouées       : %3i", nbParties3);
                printf("\nScore                          : %3i", score3);
                printf("\nMeilleur score                 : %3i", bestScore3);
                break;                                                          //Sort du switch
            case 4:                                              //...4
                break;                                           //Sort du switch (rien besoin de faire de plus)
            case 5:                                              //...5
                system("clear");                                 //Clear le terminal (+ésthétique)
                break;                                           //Sort du switch
            }
        }
        else                                                     //Sinon (si le premier caractère de la réponse donné par le joueur ne fait pas partie des caractères 1, 2, 3, 4, ou 5)
        {
            system("clear");                                     //Clear le terminal (+ésthétique)
            printf("\nVeuillez entrer 1, 2, 3, 4, ou 5 !\n");
            choixJeu = 0;                                        //Met choixJeu à 0
        }
        
                                                                 //Si on a finit un des 3 minijeux, ou qu'on veut arreter de jouer
                                                                 //Affiche le nombre de parties jouées au total, et le meilleur score de chaque minijeu 
                                                                 //si il a été joué une fois au moins

        if (choixJeu == 1 || choixJeu == 2 || choixJeu == 3 || choixJeu == 5)
        {
            printf("\n\n========== Meilleurs Scores ==========\n\n");
            printf("Nombre total de parties jouées : %3i", nbParties1+nbParties2+nbParties3);
            if (nbParties1 >= 1)
            {
                printf("\nSuite Mystère                  : %3i", bestScore1);
            }
            if (nbParties2 >= 1)
            {
                printf("\nNombre Caché                   : %3i", bestScore2);
            }
            if (nbParties3 >= 1)
            {
                printf("\nMastermind                     : %3i", bestScore3);
            }
            printf("\n\n======================================\n\n\n");
        }
    }

    return 0;                                                    //Arrete le programme
}


void reglesSuiteMystere()                                        //Fonction pour afficher les règles de la Suite Mystère
{
    printf("\nRègles de la Suite Mystère :\n");
    printf("Trois nombres compris entre 1 et 10 (inclus) sont générés aléatoirement et permettent de calculer les 4 premiers termes d'une suite.\n");
    printf("Les 3 premiers termes sont affichés, à vous de retrouver le quatrième terme en moins de 30 secondes.\n");
    printf("Attention, vous perdez si le nombre que vous donnez ne correspond pas au quatrième terme de la suite, ou si 30 secondes se sont écoulées sans que vous n'ayez répondu juste.\n");
    printf("Attention, prévoyez une calculatrice !\n\n");
}

void reglesNombreCache()                                         //Fonction pour afficher les règles du Nombre Caché
{
    printf("\nRègles du Nombre Caché :\n");
    printf("Un nombre compris entre 1 et 1000 (inclus) est généré aléatoirement, à vous de retrouver ce nombre en 10 essais maximum.\n");
    printf("Pour vous aider, quand vous proposez un nombre, l'ordinateur indique si le nombre proposé est plus petit ou plus grand que le nombre à deviner, et le nombre d'essais restant.\n\n");
}

void reglesMastermind()                                          //Fonction pour afficher les règles du Mastermind
{
    printf("\nRègles du Mastermind :\n");
    printf("Vous devez découvrir une combinaison de 4 voyelles majuscules distinctes, générée aléatoirement par l'ordinateur, en 10 essais maximum.\n");
    printf("À chaque proposition de combinaison que vous faites, l'ordinateur indique le nombre de voyelles bien placées, le nombre de voyelles mal placées, et le nombre d'essais restant.\n");
    printf("Votre score dépend du nombre d'essais que vous aurez mis pour trouver la bonne combinaison, mais aussi du temps que vous aurez mis pour trouver cette combinaison.\n\n");
}

void afficherMenu()                                              //Fonction pour afficher le menu
{
    printf("Veuillez entrer le chiffre correspondant au jeu auquel vous souhaitez jouer :\n\n");
    printf("1 - Suite Mystère\n");
    printf("2 - Nombre Caché\n");
    printf("3 - Mastermind\n");
    printf("4 - Afficher les règles\n");
    printf("5 - Quitter\n\n");
    printf("Votre choix : ");
}





int suiteMystere()                                               //Initialise la fonction du minijeu de la Suite Mystère
{
    system("clear");                                             //Clear le terminal (+ésthétique)
    int score = 0;                                               
    int a, b, c, u1, u2, u3, rep;                                
    int nombreValide;
    srand(time(NULL));                                           //Initialise le générateur de nombres aléatoires au moment actuel (valeurs aléatoires toujours différentes)
    a = rand() % 10 + 1;                                         
    b = rand() % 10 + 1;                                         //Met a, b, et c à des nombres aléatoires entre 1 et 10 (inclus)
    c = rand() % 10 + 1;                                         

    u1 = a*c+b;                                                  
    u2 = a*u1+b;                                                 //Calcule les termes u1, u2, et u3 (2ème, 3ème, et 4ème termes de la suite)
    u3 = a*u2+b;                                                 

                                                                 //Affiche le 1er, 2ème, et 3ème termes, et demande au joueur le 4ème terme

    printf("\nLa valeur du premier terme de la suite est %i", c);
    printf("\nLa valeur du deuxième terme de la suite est %i", u1);
    printf("\nLa valeur du troisième terme de la suite est %i", u2);
    printf("\n\nQuelle est la valeur du quatrième terme de la suite ? ");

    time_t begin = time(NULL);                                   //Pose une balise de temps nommée begin
    
    do                                                           //Tant qu'on entre une réponse invalide, on va afficher un message d'erreur et redemander une réponse
    {
        if (scanf("%i", &rep) == 1)  
        {
            nombreValide = 1;
        } 
        else
        {
            while (getchar() != '\n');
            printf("\nERREUR !\n");
            printf("Rentres un nombre !\n");
            printf("Quelle est la valeur du quatrième terme de la suite ? ");
            nombreValide = 0;
        }
    } while(!nombreValide);

    time_t end = time(NULL);                                     //Pose une balise de temps nommée begin
    int temps = (unsigned long int) difftime(end, begin);        //Calcule le temps mis pour répondre

    if (temps > 30)                                              //Si on a mis plus de 30 secondes pour répondre on perd
    {
        score = 60;
        printf("Vous n'avez pas réussi à trouver la bonne réponse qui était %i dans le temps imparti. Votre score est donc de %i.\n", u3, score);
    }
    else                                                         //Sinon on vérifie si la réponse est juste
    {
        if (rep == u3)                                           //Si oui, le score est égal au temps mis à trouver la réponse
        {
            score = temps;
            printf("Bravo, vous avez trouvé la bonne réponse qui était %i au bout de %i secondes, votre score est donc de %i !\n", u3, temps, score);
        }
        else                                                     //Sinon, on perd
        {
            score = 60;
            printf("Vous n'avez pas réussi à trouver la bonne réponse qui était %i. Votre score est donc de %i. Vous avez mis %i secondes.\n", u3, score, temps);
        }
    }

    return score;                                                //On termine le minijeu et on renvoie le score
}













int nombreCache()                                                //Initialise la fonction du minijeu du Nombre Caché
{
    system("clear");
    int score = 0;
    srand(time(NULL));                                           //Initialise le générateur de nombres aléatoires au moment actuel (valeurs aléatoires toujours différentes)
    int Nombre = rand() % 1000 + 1;                              //On initialise un nombre qui va prendre une valeur aléatoire entre 1 et 1000
    int rep;
    int nombreValide;
    int essaisRestant;

    for (essaisRestant = 10; essaisRestant > 0; --essaisRestant)        //Tant qu'on a des essais restant
    {
        ++score;
        printf("\nProposez un nombre entre 1 et 1000 (inclus) : ");
            
        do                                                       //Tant qu'on entre une réponse invalide, on va afficher un message d'erreur et redemander une réponse
        {
            if (scanf("%i", &rep) == 1)  {
                nombreValide = 1;

            } 
            else
            {
                while (getchar() != '\n');
                printf("\nERREUR !");
                printf("\nVeuillez écrire un nombre compris strictement entre 1 et 1000 !");
                printf("\nProposez un nombre entre 1 et 1000 (inclus) : ");
                nombreValide = 0;
            }
        } while(!nombreValide);

        if (rep >= 1 && rep <= 1000)                             //Si on entre une réponse valide et comprise entre 1 et 1000
        {
            if(rep == Nombre)                                    //Si la réponse est juste on donne le bon nombre, le score et on termine le jeu en retournant le score
            {
                printf("Bravo vous avez trouvé le bon nombre qui était %i, votre score est de %i.\n", Nombre, score);
                return score;
            }
            else if (rep < Nombre)                               //Si elle est trop petite on le dit au joueur ainsi que le nombre d'essais restant
            {
                printf("Le nombre que vous devez trouver est plus grand, il vous reste %i essais.\n", essaisRestant-1);
            }
            else if (rep > Nombre)                               //Si elle est trop grande on le dit au joueur ainsi que le nombre d'essais restant
            {
                printf("Le nombre que vous devez trouver est plus petit, il vous reste %i essais.\n", essaisRestant-1);
            }
        }
        else                                                     //Si on entre une réponse valide mais non comprise entre 1 et 1000 on affiche une erreur et on redemande une réponse
        {
            printf("\nERREUR !");
            printf("\nVeuillez écrire un nombre compris strictement entre 1 et 1000 !");            
            printf("Proposez un nombre entre 1 et 1000 (inclus) : ");
            essaisRestant++;
            score--;
        }

    }                                                            //En cas de défaite on fixe le score à 20, affiche le bon nombre, le score et on retourne le score
    score = 20;
    printf("Vous n'avez pas réussi à trouver le bon nombre qui était %i, votre score est de %i.\n\n", Nombre, score); 
    return score;
}















int mastermind()                                                 //Définit la fonction mastermind
{
    system("clear");                                             

    int score = 0;                                              
    int bienPlace;                                               //Définit la variable du nombre de lettres justes et bien placées
    int malPlace;                                                //Définit la variable du nombre de lettres justes mais mal placées

    int random;                                                  
    char caractere;                                            
    char combinaison[4];                                         //Définit la variable contenant la combinaison aléatoire (de longueur 4)
    char rep[5];                                                 //Définit la variable contenant la réponse du joueur (de longueur 5 car il y a le \n)
    char verif[4];                                               //Définit la variable contenant la combinaison après vérification (de longueur 4)

    int erreur = 0;                                            
    int malus = 200;                                          

    srand(time(NULL));                                           //Initialise le générateur de nombres aléatoires au moment actuel (valeurs aléatoires toujours différentes)
    char voyelles[] = "AEIOUY";                                  //Initialise un tableau de char nommé voyelles contenant les caractères A, E, I, O, U, et Y



    for (int i = 0; i < 4; i++)                                  //Remplit combinaison de voyelles aléatoires distinctes
    {
        do                                                      
        {
            random = rand() % 6;                                 
            caractere = voyelles[random];                       
        } while (strchr(combinaison, caractere) != NULL);       
        combinaison[i] = caractere;                              
    }
    


    printf("\n\n");
    for (int i = 0; i < 4; i++)                                  //Remplit verif pour qu'elle soit identique à combinaison
    {
        verif[i] = combinaison[i];
    }
    

    time_t begin = time(NULL);                                   //Pose une balise de temps nommée begin

    for (int essais = 0; essais < 10; essais++)                  //Fait jusqu'à ce que essais = 10 :
    {
        printf("\nProposez une combinaison : ");                 //Demande une réponse au joueur (une chaine de caractères)
        scanf("%s", rep);

        if(strlen(rep) != 4)                                     //Si la longueur de la réponse est différente de 4, demande d'entrer 4 voyelles majuscules et diminue essais de 1
        {
            printf("Entrez une combinaison de 4 voyelles majuscules\n");
            essais--;
        }
        else                                                     //Sinon (si la longueur de la réponse est bien de 4)
        {
            for (int i = 0; i < 4; i++)                          //Vérifie pour les 4 caractères de la chaine réponse...
            {
                switch (rep[i])                                  //...si tout les caractères sont bien des voyelles majuscules
                {
                case 'A':
                    break;
                case 'E':
                    break;
                case 'I':
                    break;
                case 'O':
                    break;
                case 'U':
                    break;
                case 'Y':
                    break;
                default:                                         //Si ce n'est pas le cas, met "erreur" à 1
                    erreur = 1;
                    break;
                }
            }



            //Paragraphes ci-dessous dans le cas où les voyelles de combinaison n'étaient pas forcément distinctes
            /*C'est ici que les choses se compliquent, ici on ne peut simplement vérifier si le ième carctère de la combinaison et le ième caractère de la réponse sont identiques, 
            et si non, vérifier si le ième caractère de la combinaison est présent dans la réponse, car si :

            combinaison = "AAAA"                   réponse = "AAAO"

            Le programme va trouver que combinaison[0]=réponse[0], que combinaison[1]=réponse[1], que combinaison[2]=réponse[2], 
            et que combinaison[3] est bel et bien présent dans la réponse, donc mettre bienPlace = 3 et malPlace = 1, 
            ce qui est faux et impossible. On doit donc trouver un moyen pour qu'un caractère ayant déjà vérifié une condition ne puisse plus en vérifier par la suite. 
            On va donc commencer par vérifier le nombre de caractères bien placés, remplacer les caractères bien placés dans la combinaison par des X, 
            et remplacer les caractères bien placés dans la réponse par des W.
            Une fois cela fait on va vérifier s'il y a des carctères justes mais mal placés, si oui, 
            on va exactement comme tout à l'heure les remplacer dans la combinaison par des X et dans la réponse par des W.
            De ce fait dans la configuration de tout à l'heure on aura :

            combinaison = "AAAA" --> "XXXA"        réponse = "AAAO" --> "WWWO"

            Et ainsi le programme affichera bel et bien bienPlace = 3 et malPlace = 0
            De même si on est dans la configuration où :

            combinaison = "OEAO"                   réponse = "AYOA"

            Car dans la configuration précédente le programme aurait affiché : bienPlace = 0 et malPlace = 3 (O, A, et O, alors qu'il n'y a qu'un seul O dans la réponse)
            Dans cette configuration il affichera bel et bien : bienPlace = 0 et malPlace = 2*/





            if (erreur == 0)                                     //Si erreur = 0 (donc que tout les caractères de la réponses sont des voyelles majuscules)
            {
                bienPlace = 0;                                   
                malPlace = 0;                                   
                for (int i = 0; i < 4; i++)                      
                {
                    if (verif[i] == rep[i])                      //Vérifie si le ième caractère de combinaison est égal au ième caractère de la réponse
                    {
                        bienPlace++;                             
                        verif[i] = 'X';                          //Remplace le ième caractère de verif par un X (le rend inutilisable à l'avenir)
                        rep[i] = 'W';                            //Remplace le ième caractère de rep par un W (le rend inutilisable à l'avenir)
                    }
                }

                for (int i = 0; i < 4; i++)                      //On va parcourir verif avec i...
                {
                    for (int j = 0; j < 4; j++)                  //...et rep pour chaque valeur de i, avec j
                    {
                        if (verif[i] == rep[j])                  //Si le ième caractère de verif est présent dans rep
                        {
                            malPlace++;                         
                            verif[i] = 'X';                      //Remplace le ième caractère de verif par un X (le rend inutilisable à l'avenir)
                            rep[j] = 'W';                        //Remplace le jème caractère de rep par un W (le rend inutilisable à l'avenir)
                            break;                               //Sort du for j, et continue le for i
                        }
                    }
                }





                for (int i = 0; i < 4; i++)                      //On enlève les X dans verif pour que la verification se passe sans encombre à la prochaine proposition
                {
                    verif[i] = combinaison[i];
                }

                                                                 //On écrit le nombre de voyelles bien placées, mal placées, et le nombre d'essais restant

                printf("Bien places : %i, Mal places : %i\n", bienPlace, malPlace);
                printf("Il vous reste %i essais", 10-(essais+1));

                if (bienPlace == 4)                              //Si la réponse donnée est juste
                {
                                                                 /*On place une deuxième balise de temps nommée end, et on calcule le temps entre begin et end,
                                                                 On calcule le score en fonction du nombre d'essais effectués et du temps mis pour trouver la bonne réponse,
                                                                 On écrit au bout de combien de temps et d'essais la réponse a été trouvée, et le score du joueur et on sort du
                                                                 for essais (sinon il redemande une combinaison)*/
                    time_t end = time(NULL);
                    int temps = (unsigned long int) difftime(end, begin);
                    score = (essais + 1) * 3 + temps;
                    printf("\n\nBravo, vous avez trouvé la bonne combinaison en %i secondes et %i essais !\nVotre score est donc de %i !\n", temps, essais+1, score);
                    break;
                }
                else if (essais == 9)                            //Sinon si essais = 9
                {
                                                                 /*On place une deuxième balise de temps nommée end, et on calcule le temps entre begin et end,
                                                                 On calcule le score en fonction du nombre d'essais effectués, du temps mis pour trouver la bonne réponse et d'un malus (vu qu'on a perdu), on montre au joueur la bonne combinaison, on lui dit le temps qu'il a mis, et son score.
                                                                 On ne met pas de break car dans ce cas essais = 10 donc on sort du for essais tout seul*/
                    time_t end = time(NULL);
                    int temps = (unsigned long int) difftime(end, begin);
                    score = (essais + 1) * 3 + temps + malus;
                    printf("\n\nDésolé, vous n'avez pas trouvé la bonne combinaison qui était : ");
                    for (int i = 0; i < 4; i++)
                    {
                        printf("%c", combinaison[i]);
                    }
                    printf(".\nVous avez mis %i secondes, votre score est donc de %i\n", temps, score);
                }

                printf("\n");
            }
            else                                                 //Si erreur = 1, demande d'entrer 4 voyelles majuscules et diminue essais de 1
            {
                printf("Entrez une combinaison de 4 voyelles majuscules\n");
                essais--;
            }
            
        }
        erreur = 0;                                              //On remet erreur à 0 après chaque vérification
    }
    printf("\n");
    return score;                                                //On fini le minijeu et on retourne le score
}