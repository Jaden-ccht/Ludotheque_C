#include "projet.h"

void global (void)
{   
    Jeux *tabJeux[50];      //Chargement tableau des Jeux
    int tailleLogJeux;
    tailleLogJeux=globalTab(tabJeux);
    /*----------------------------------------------------------------------------*/
    Liste l;                        // Chargement Tableau des emprunts
    l=chargementEmprunt(l);
    /*----------------------------------------------------------------------------*/
    ListeAD AD;
    AD=ChargementAdherent(AD);     //Chargement tableau des adherents
    /*----------------------------------------------------------------------------*/           
                                   // Chargement Tableau des reservations
    ListeReserv r;
    r=testReservation(r);
    /*----------------------------------------------------------------------------*/
    choixMenu(tabJeux,tailleLogJeux,l,AD,r);            //Lancement du menu
}


// -------------------------------------- Menu et sous menu ------------------------------------------

/*Auteur commentaire : Arthur LASHERMES
Cette fonction nous permet d'obtenir la fonctionalité demandé par l'utilisateur*/

int choixMenu (Jeux *tabJeux[],int tailleLogJeux,Liste l,ListeAD AD,ListeReserv r)
{
    int choix, error;
    int a;
    do
    {
    	error = 0;
        affichageMenu();//affichage du menu
    	printf("\n \t Selectionner un bouton du menu :");
    	scanf("%d", &choix);
        if(choix<1 || choix >8){
        	error = 1;
        	printf("\n\tErreur lors du choix du menu, veuillez reessayer :"); //gestion des erreurs lors du choix de la fonctionnalités
        }
        while (getchar() != '\n');
    } while(error == 1);
    switch (choix)
    {
    case 1:
        system("cls");      //l'écran est vidé
        afficherJeux(tabJeux,tailleLogJeux);        //la fonctionnalité est lancé
        sousMenu(tabJeux,tailleLogJeux,l,AD,r);     // le sous menu apparaitra apres que la fonctionalité soi fini
        break;
    case 2:
        system("cls");
        afficherListe(l,tabJeux,tailleLogJeux,AD);
        sousMenu(tabJeux,tailleLogJeux,l,AD,r);
        break;
    case 3:
        system("cls");
        affichageReservation(r,tabJeux,tailleLogJeux);
        sousMenu(tabJeux,tailleLogJeux,l,AD,r);
        break;
    case 4:
        system("cls");
        globalNouvEnreg(tabJeux,tailleLogJeux,l,AD,r);
        sousMenu(tabJeux,tailleLogJeux,l,AD,r);
        break;
    case 5:
        system("cls");
        retourJeux (AD,r,l,tabJeux,tailleLogJeux);
        sousMenu(tabJeux,tailleLogJeux,l,AD,r);
        break;
    case 6:
        system("cls");
        affichageNbReservation (tabJeux,tailleLogJeux,AD,l,r);
        sousMenu(tabJeux,tailleLogJeux,l,AD,r);
        break;
    case 7:
        sauvegardeEmprunts(l);
        sauvegarderJeux(tabJeux, tailleLogJeux); // On quitte est sauvegarde tous
        sauvegardeReserv(r);
        sauvegardeAD(AD);
        break;
    case 8:
        system("cls");
        afficherJeux(tabJeux,tailleLogJeux);
        printf("\n");
        afficherListeTemp(l);
        printf("\n");
        afficherListeADtempo(AD);
        printf("\n");
        afficherListeReservtempo(r);
        printf("\n");
        sousMenu(tabJeux,tailleLogJeux,l,AD,r);
        break;
    default:
        break;
    }
    return choix;
}

/*Auteur commentaire : Arthur LASHERMES
Cette fonction de sous menu nous sert pour proposer soi de quitter ou de revenir au menu à la fin de l'utilisation d'une fonctionnalité*/

void sousMenu(Jeux *tabJeux[],int tailleLogJeux,Liste l,ListeAD AD,ListeReserv r)
{
    int choix2, error;
    do
    {
        error = 0;
        printf("\nSelectionner un bouton du menu :\n\n1 Retour au menu\t\t2 Quitter\n");
        scanf("%d", &choix2);
        if(choix2!=1 && choix2!=2){
            error = 1;
            printf("\n\tErreur lors du choix du menu, veuillez reessayer :\n"); // Gestion des erreurs seul 2 choix sont possible 1 ou 2
        }
        while (getchar() != '\n');
    } while(error == 1);
    switch (choix2)
    {
    case 1:
        choixMenu(tabJeux,tailleLogJeux,l,AD,r);    //Ici on reviens au menu classique c'est le choix 1 
        break;
    case 2:
        sauvegardeEmprunts(l);
        sauvegarderJeux(tabJeux, tailleLogJeux);
        sauvegardeReserv(r);
        sauvegardeAD(AD);
        break;
    default:
        break;
    }
}

void affichageMenu(void)// Auteur commentaire : Arthur LASHERMES Cette fonction permet juste l'affichage de tous les choix possible dans notre menu
{
    system("cls");
    printf("\n \n \n ");
    printf("\t 1. Affichage de la liste des jeux \n");
    printf("\t 2. Affichage de la liste des emprunts en cours \n");
    printf("\t 3. Affichage de la reservation pour un jeu donne \n");
    printf("\t 4. Saisie et enregistrement d'un nouvel emprunt/reservation \n");
    printf("\t 5. Retour d'un jeu \n");
    printf("\t 6. Annulation d'une reservation \n");
    printf("\t 7. Quitter l'application et sauvegarder \n");
    printf("\t (8. Afichage des listes) \n");
}


//------------------------------------------------------- Fonctions d'affichage bonus ---------------------------------------------

/*Auteur du commentaire :Arthur LASHERMES
Cette fonction n'était pas demander mais on a choisi de la laisser car elle nous a permis tous au long de code de vérifier si les modifications 
que l'on faisait donnait bien le bon résulat cette fonction est pratique elle est disponible au numero 8 du menu*/

void afficherListeTemp(Liste l)
{
    printf("Idemp\tIDad\tIDjeu\tdateEmp\n");
    l=l->suiv;//Pour ne pas afficher la premier ligne de 0
    while (l!=NULL)  // On parcours la liste classiquement et on affiche
    {   
        printf("%04d\t%04d\t%03d\t",l->idEmprunt,l->idAdherent,l->idJeu);     //les %04d permette d'afficher le résulat avec cette forme 0004 car de base à l'affichage on a 4 or les ID on 4 chiffres. 
        printf("%02d/%02d/%d\t\n", l->jour,l->mois,l->annees);
        l = l->suiv;
    }
}

void afficherListeADtempo(ListeAD AD)
{
    printf("IDAD civ Nom\t\t\tdate\n");
    while (AD!=NULL)
    {   
        printf("%04d %s %s\t%02d/%02d/%d\t\n",AD->idAdherent,AD->civ,AD->prenomNom, AD->jour,AD->mois,AD->annees);
        AD = AD->s;
    }
}

void afficherListeReservtempo(ListeReserv r)
{
    printf("IDres\tIDAD\tIDjeu\tdate\n");
    r = r->next;    //Pour ne pas afficher la premier ligne de 0
    while (r!=NULL)
    {   
        printf("%02d\t%04d\t%d\t%02d/%02d/%d\n",r->idResa,r->idAdherent,r->idJeu,r->jour,r->mois,r->annees);
        r = r->next;
    }
}


// ------------------------------------------------ Chargement et tri du fichier jeu en mémoire ----------------------------------------------------------

/*Finalité : Appel les fonctions remplirTab et TriTab en affectant la tailleLogique de tabJeux a tailleLogJeux
*/

int globalTab(Jeux *tabJeux[])
{    
    int tailleLogJeux;
    tailleLogJeux=remplirTab(tabJeux,50);
    triTabJeux(tabJeux,tailleLogJeux);
    return tailleLogJeux;
}

/*Finalité : Remplissage du tableau tabJeu et affectation de la taille Logique du tableau a la variable tailleLogJeux en la retournant a la fin de la fonction
    Description : -Ouverture du fichier ficjeux.txt en lecture
                  -Affectation a la structure m les données de la première ligne du fichier via l'appel de la fonction LireJeux
                  -Parcours du fichier ficjeux.txt, vérification que la tailleLogJeux n'est pas égal à la taillePhyJeux 
                  -Le malloc permet de réservé la place nécéssaire a une structure de type Jeux, on test si le malloc a bien fonctionné 
                  -Puis via le while, on remplit chaque case du tableau tabJeux avec la structure  Jeux m, on indente tailleLogJeux pour passer a la case suivante du tableau et on effectue une lecture de la ligne suivante du fichier
    Variable : Jeux m -> Création d'une structure de type Jeux 
*/

int remplirTab(Jeux *tabJeux[],int taillePhyJeux)
{    
    Jeux m;
    int tailleLogJeux=0;
    FILE *flot;
    flot=fopen("ficjeux.txt","r");
    if(flot== NULL)
    {
        printf("Erreur de chargement du ficjeux.txt\n");
        return -1;
    }
    m = LireJeux(flot);
    while(!feof(flot))
    {    
        if (tailleLogJeux==taillePhyJeux)
        {
            printf("Manque de place dans le tableau de Jeux\n");
            return -2;
        }
        tabJeux[tailleLogJeux] =(Jeux*) malloc(sizeof(Jeux));
        if (tabJeux[tailleLogJeux]==NULL)
        {
            printf("Problème d'allocation du tableau jeux\n");
            fclose(flot);
            return -3;
        }
        *tabJeux[tailleLogJeux]=m;
        tailleLogJeux=tailleLogJeux+1;
        m = LireJeux(flot);
    }
    fclose(flot);
    return tailleLogJeux;
}

/* Finalité : Permet de scanner une ligne du fichier passé en paramètre (ici ficjeux.txt) et les rentrer dans la structure a de type Jeux */

Jeux LireJeux (FILE *flot)
{
    Jeux a;
    fscanf(flot,"%d",&a.id);
    fscanf(flot,"%s",a.type);
    fscanf(flot,"%d%*c",&a.nbExemplaire);
    fgets(a.nom,29,flot);
    a.nom[strlen(a.nom)-1] = '\0';
    return a;

}

/* Finalité: Tri le tableau tabJeux selon le type puis le nom du jeu de manière alphabétique
    Description : -Création d'une pointeur tmp de type Jeux 
                  - On parcourt le tableau tabJeux avec les conditions for 
                  - Si le type de la case j est inférieure au type de la case i lexicographiquement parlant, on échange le contenu des deux case via la fonction copyJeu
                  - Si le type de la case j est égal au type de la case i, on effectue une deuxième verification qui permet de les trier cette fois selon leur nom de Jeu
                  - Si le nomduJeu de la case j est inférieur au nomduJeu de la case i, alors on échange le contenu des deux cases. 
*/

void triTabJeux(Jeux *tabJeux[], int tailleLogJeux)
{
    int i, j;
    Jeux *tmp;
    for(i=0;i<tailleLogJeux;i++)
    {
        for(j=i+1 ; j<tailleLogJeux ; j++)
        {
            if((strcmp(tabJeux[j]->type, tabJeux[i]->type))<0)
            {
                tmp=copyJeu(tabJeux[i]);
                tabJeux[i]=tabJeux[j];
                tabJeux[j]=tmp;
            } 
            if((strcmp(tabJeux[j]->type, tabJeux[i]->type))==0)
            {
                if((strcmp(tabJeux[j]->nom, tabJeux[i]->nom))<0)
                {
                    tmp=copyJeu(tabJeux[i]);
                    tabJeux[i]=tabJeux[j];
                    tabJeux[j]=tmp;
                }
            }
        }
    }
}

/* Finalité : Permet de mettre toute les variables d'une strucutre dans une strucutre temporaire 
    Description : - Le malloc permet de réservé la place nécéssaire a une structure de type Jeux, on test si le malloc a bien fonctionné
                  - on rentre ensuite toute les données dans le pointeur copie de type Jeu et on return copie
*/

Jeux* copyJeu(Jeux *Jeu)
{
    Jeux *copie;
    copie=(Jeux*) malloc(sizeof(Jeux));
    if (copie==NULL)
    {
        printf("Pb malloc\n");
        exit(1);
    }
    copie->id=Jeu->id;
    strcpy(copie->nom,Jeu->nom);
    copie->nbExemplaire=Jeu->nbExemplaire;
    strcpy(copie->type,Jeu->type);
    return copie;
}


//------------------------------------------- Création de la liste d'emprunt ---------------------------------------------

/*Auteur du commentaire : Arthur LASHERMES
Ici on va créer la liste des emprunt la remplir et la trier par date à partir du fichier Emprunts.txt
*/


Liste chargementEmprunt (Liste l)
{   
    Maillon f;          // On creer un maillon
    FILE* flux;
    flux=fopen("Emprunts.txt","r");
    if(flux == NULL)
    {
        printf("Problème d'ouverture du fichier d'emprunt");
        exit(1);
    }
    l=listenouv();  //On met null dans la nouvelle liste
    while(!feof(flux))
    {
        fscanf(flux,"%d%d%d%d%d%d%*c",&f.idEmprunt,&f.idAdherent,&f.idJeu,&f.jour,&f.mois,&f.annees); //On remplit le maillon
        l=insertionCroissante(l,f); // Ici on insert le maillon tous en le triant par date
    }
    fclose(flux);
    return l;
}

Liste listenouv(void)
{
    return NULL;// permet de creer un nouvel liste et qui permet délimiter la fin d'une liste
}

Liste insertionEnTete(Liste l,Maillon f)// InsertionEnTete est utilisé pour l'insertionCroissante
{   
    Maillon * m;
    m = (Maillon*)malloc(sizeof(Maillon)); //on alloue dynamiquement un maillon
    if (m==NULL)    //ici on gere les erreurs
    {
        printf("Pb malloc\n");
        exit(1);
    }
    m->idEmprunt = f.idEmprunt;         // On met les données du maillon du scanf dans le maillon aloué dynamiquement 
    m->idAdherent = f.idAdherent;
    m->idJeu = f.idJeu;
    m->jour = f.jour;
    m->mois = f.mois;
    m->annees = f.annees;
    m->suiv = l;        //On ajoute en tete de liste le maillon que l'on viens de creer
    return m;
}

Liste insertionCroissante(Liste l, Maillon f) // Ici on va trier la liste l par date 
{
    if(l==NULL)
        return insertionEnTete(l,f); //Cas d'arret 
    if(f.annees<l->annees)
        return insertionEnTete(l,f);    //Le premier trie par années
    if(f.annees==l->annees)
    {
        if(f.mois<l->mois)
            return insertionEnTete(l,f);        //Le deuxieme si l'années est égal on utilise alors le mois
        if(f.mois==l->mois)                 // Enfin si l'années, le mois sont égaux c'est le jour qui trie 
        {
            if(f.jour<l->jour)
                return insertionEnTete(l,f);
        }
    }
    l->suiv=insertionCroissante(l->suiv,f);         // Récursivité
    return l;
}



//------------------------------------------- Création de la liste d'adhérents ---------------------------------------------

/*Auteur du commentaire : Arthur LASHERMES
Ici on va créer la liste des adherent la remplir et la trier selon l'idAdherent à partir du fichier Adherent.txt
*/

ListeAD listenouvAD(void)
{
    ListeAD l; // permet de creer un nouvel liste et qui permet délimiter la fin d'une liste
    l=NULL;
    return l;
}

ListeAD ChargementAdherent (ListeAD l)
{   
    MaillonAD f;        // On creer un maillon
    FILE* flex;
    flex=fopen("Adherent.txt","r");
    if(flex == NULL)        //ici on gere les erreurs
    {
        printf("Problème d'ouverture du fichier d'emprunt");
        exit(1);
    }
    l=listenouvAD();        //On met null dans la nouvelle liste
    while(!feof(flex))
    {
        fscanf(flex,"%d %d %d %d %s%*c", &f.idAdherent, &f.jour, &f.mois, &f.annees, f.civ);        //On remplit le maillon
        fgets(f.prenomNom,40,flex);
        f.prenomNom[strlen(f.prenomNom)-1] = '\0';
        l=insertionCroissanteAD(l,f);   // Ici on insert le maillon tous en le triant selon idAdherent
    }
    fclose(flex);
    return l;
}

ListeAD insertionEnTeteAD(ListeAD l,MaillonAD f)// InsertionEnTete est utilisé pour l'insertionCroissanteAD
{   
    MaillonAD *m;       //on alloue dynamiquement un maillon
    m = (MaillonAD*)malloc(sizeof(MaillonAD));
    if (m==NULL)
    {
        printf("Pb malloc\n");
        exit(1);
    }
    m->idAdherent = f.idAdherent;        // On met les données du maillon du scanf dans le maillon aloué dynamiquement 
    strcpy(m->civ,f.civ);
    strcpy(m->prenomNom,f.prenomNom);
    m->jour = f.jour;
    m->mois = f.mois;
    m->annees = f.annees;
    m->s = l;           //On ajoute en tete de liste le maillon que l'on viens de creer
    return m;
}

ListeAD insertionCroissanteAD(ListeAD l,MaillonAD f) // Ici on va trier la liste l par idAdherent
{
    if(l==NULL)             //Cas d'arret
        return insertionEnTeteAD(l,f);
    if(f.idAdherent<l->idAdherent)          // comparaison pour le trie 
        return insertionEnTeteAD(l,f);
    l->s=insertionCroissanteAD(l->s,f);
    return l;
}

//------------------------------- Création de la liste de réservation ---------------------------------------

/*Auteur du commentaire : Arthur LASHERMES
Ici on va créer la liste des adherent la remplir et la trier selon l'idAdherent à partir du fichier Adherent.txt
*/

ListeReserv testReservation (ListeReserv r)
{   
    MaillonReserv res;              //on creer un maillon
    FILE* flux;
    flux=fopen("Reservation.txt","r");
    if(flux == NULL)            // on gere l'erreur
    {
        printf("Problème d'ouverture du fichier reservation");
        exit(1);
    }
    r=listenouvReserv();            //creation d'une nouvelle liste en ajoutant null en fil
    while(!feof(flux))
    {
        fscanf(flux,"%d%d%d%d%d%d%*c",&res.idResa,&res.idAdherent,&res.idJeu,&res.jour,&res.mois,&res.annees);      //remplissage du maillon
        r=insertionCroissanteReserv(r,res);
    }
    fclose(flux);
    return r;
}

ListeReserv listenouvReserv(void)
{
    ListeReserv l;
    l=NULL;         // permet de creer un nouvel liste et qui permet délimiter la fin d'une liste
    return l;
}

ListeReserv insertionEnTeteReserv(ListeReserv r,MaillonReserv res)
{   
    MaillonReserv *m;           //Création d'un maillon
    m = (MaillonReserv*)malloc(sizeof(MaillonReserv));      // Allocation dynamique de ce maillon
    if (m==NULL)
    {
        printf("Pb malloc\n");
        exit(1);
    }
    m->idResa = res.idResa;             // remplissage de ce maillon
    m->idAdherent = res.idAdherent;
    m->idJeu = res.idJeu;
    m->jour = res.jour;
    m->mois = res.mois;
    m->annees = res.annees;
    m->next = r;        // Ajoute du maillon à la suite de la liste
    return m;
}

ListeReserv insertionCroissanteReserv(ListeReserv r, MaillonReserv mRES)     // Ici on va trier la liste l par date 
{
    if(r==NULL)
        return insertionEnTeteReserv(r,mRES);           //cas d'arret
    if(mRES.annees<r->annees)
        return insertionEnTeteReserv(r,mRES);           //Le premier trie par années
    if(mRES.annees==r->annees)
    {
        if(mRES.mois<r->mois)
            return insertionEnTeteReserv(r,mRES);        //Le deuxieme si l'années est égal on utilise alors le mois
        if(mRES.mois==r->mois)
        {                               
            if(mRES.jour<r->jour)                        // Enfin si l'années, le mois sont égaux c'est le jour qui trie 
                return insertionEnTeteReserv(r,mRES);
        }
    }
    r->next=insertionCroissanteReserv(r->next,mRES);        //récursivité 
    return r;
}

// ------------------------------- Fonction 1 : affichage des jeux disponibles ---------------------------------------------------



void afficherJeux( Jeux *tabJeux[], int tailleLogJeux)
{    
    printf("idJeux\ttypeJeux\tNombres d'exemplaires\tnomJeux\n"); // On affiche simplement le tableau triée par type de Jeux, puis par ordre alphabétique
    for (int i = 0; i < tailleLogJeux; ++i)                     //de leur nom
    {
        printf("%03d\t%s\t%d\t\t\t%s\n",tabJeux[i]->id,tabJeux[i]->type,tabJeux[i]->nbExemplaire,tabJeux[i]->nom);
    }
}


// ------------------------------- Fonction 2 : affichage de la liste d'emprunts en cours ---------------------------------



void afficherListe(Liste l, Jeux *tabJeux[], int tailleLogJeux,ListeAD AD)
{
    printf("Identite de l'emprunteur\tDate de l'emprunt\tNom du jeu\t\t\n\n");
    l=l->suiv;
    while (!vide(l))
    {
        affichageIdentiteAD(AD,l->idAdherent);
        printf("%02d/%02d/%d\t\t", l->jour,l->mois,l->annees);
        for (int i = 0; i < tailleLogJeux; i++)
            if (tabJeux[i]->id==l->idJeu)
                printf("%s\t\n",tabJeux[i]->nom );
        l = l->suiv;
    }
}

void affichageIdentiteAD(ListeAD AD, int idAD)
{
    while(AD!=NULL)
    {
        if (idAD==AD->idAdherent)
        {
            printf("%04d %s %s\t\t",AD->idAdherent,AD->civ,AD->prenomNom);
        }
        AD=AD->s;
    }
}

Booleen vide(Liste l)
{
    if(l==NULL)
        return vrai;
    return faux;
}


//---------------------------- Fonction 3 : affichage des réservations d'un jeu ------------------------------------

/*Auteur du commentaire : Arthur LASHERMES
Le but de cette fonction est d'afficher la liste des réservations pour un jeu donné 
*/

void affichageReservation (ListeReserv r,Jeux *tabJeux[], int tailleLogJeux)
{   
    char nomJeux[20];
    int trouve;
    int i;
    int id;
    printf("Quel est le jeux que vous souhaitez afficher parmis la liste suivante?\n\n");
    for (int i = 0; i < tailleLogJeux; ++i)
    {
        printf("%s\n",tabJeux[i]->nom);
    }
    printf("\nChoix : ");
    fgets(nomJeux,20,stdin); // ici on saisie le jeux à afficher
    nomJeux[strlen(nomJeux)-1] = '\0';
    i=rechercheRangAvecLeNomJeux(nomJeux,tabJeux,&trouve,tailleLogJeux); // Cette fonction donne trouve=1 lorsque le nom du jeux
    if (trouve==1)                                                      // existe dans le fichier jeux cela permet de gerer les erreurs
    {                                                                  // cette fonction permet aussi de retourner le rang i donc de retouver son id.
        id=tabJeux[i]->id;                                            
        rechPuisAffichage(r,nomJeux,id,trouve);  //rechPuisAffichage permet la recherche dans les reseravtion et l'affichage global en meme temps.        
    }
    else
    {   
        printf("\n");
        printf("Le jeu %s n'est pas reference dans les jeux dont dispose la ludotheque !\n\n",nomJeux);
    }
}

int rechercheRangAvecLeNomJeux (char nomJeux[], Jeux *tabJeux[],int *trouve,int tailleLogJeux)
{   
    int i=0;
    while(i<tailleLogJeux)
    {
        if (strcmp(nomJeux,tabJeux[i]->nom)==0)
        {
            *trouve=1;
            return i;
        }
        i++;
    }
    *trouve=0;
    return i;
}

int rechPuisAffichage (ListeReserv r,char nomJeux[], int idJeux,int erreur)
{   
    int i=0;
    int a;
    a=reservoupas(r,nomJeux,idJeux); // Cette fonction sert à déterminer si il existe des réservations pour le jeu donné 
    printf("\n");                   // dans ce cas là a sera égal = 1 sinon a sera égal à 0
    if (a!=0)
    {
        printf("idReservation\tidAdherent\tidJeux\tJJ/MM/AAAA \n\n");
        while (!videReserv(r)) //On parcours la liste r
        {   
            if(idJeux==r->idJeu) //Si une reservation correspond à l'id du jeu demandé on affiche cette reservation
            {   
                printf("%03d\t\t%04d\t\t%d\t%02d/%02d/%04d\n\n",r->idResa,r->idAdherent,r->idJeu,r->jour,r->mois,r->annees);
                i++;
            }
            r = r->next;
        }
        printf("Il y a un total de %d reservation(s) pour le jeu ""%s""\n",i,nomJeux); // grace à l'indentation de i on donne le total des jeux
    }
    else
        printf("%s n'est reserve par personne !\n\n",nomJeux);        
}

int reservoupas(ListeReserv r,char nomJeux[], int idJeux)
{
    int a=0;
    while(r!=NULL)
    {
        if(idJeux==r->idJeu)
            a=1;
        r = r->next;
    }
    return a;
}

Booleen videReserv(ListeReserv r)
{

    if(r==NULL)
        return vrai;
    return faux;
}


//--------------------- Fonction 4 : Saisie et enregistrement d'un nouvel emprunt/reservation -----------------------------

/*
    Fonction globalNouvEnreg
    Finalité : Création d'un adhérent si nouveau
                Enregistrement de l'emprunt d'un jeu si possible
                Réservation sinon
    Description : Demande si déjà adhérent
                  Si non, appel de la fonction creationAdherent
                  Si oui, demande le prenom et le nom jusqu'a ce qu'il corresponde au nom de la liste ListeAD
                  Demande le jeu à emprunter
                  Affiche le contenu du tableau des jeux avec la fonction afficherJeux
                  Tant que le jeu demandé  ne correspond à aucun de celui du tableau, redemande le jeu souhaité
                        Si la disponibilité est égale à 0 : demande si on souhaite le réserver
                                Si oui : appel de la fonction nouvelleReservation
                                Si non : fin de cette fonction
                        Si la disponibilité est supérieure à 0 : appel de la fonction nouvelEmprunt
                                Le nombre d'exemplaires disponibles a été au préalable changé pour n-1 si ça disponibilité n'était pas égale à 0
                        fin de cette fonction

*/

int globalNouvEnreg(Jeux *tabJeux[],int tailleLogJeux,Liste l,ListeAD AD, ListeReserv r)
{
    int existe, trouve=0, i;
    int dispo, choix;
    int IDAD, IDjeu;
    char c;
    char prenomNomExistant[20], nomJeux[20];

    printf("Etes-vous deja adherent a notre ludotheque ?\n");
    printf("\n\n1 Oui\t\t2 Non\n");
    scanf("%d", &existe);
    system("cls");
    while(existe<1 || existe >2)
    {
        printf("\n\tErreur lors du choix, veuillez reessayer :");
        scanf("%d",&existe);
    }
    if(existe==2)
    {
        IDAD=creationAdherent(AD);
        printf("Vous etes desormais adherent a notre ludotheque\n");
    }
    else
    {
        printf("Veuillez saisir votre prenom et votre nom\n");
        c=getchar();
        fgets(prenomNomExistant,40,stdin);
        prenomNomExistant[strlen(prenomNomExistant)-1] = '\0';
        printf("\n");
        IDAD=rechercheIDAD(prenomNomExistant,AD);
        if (IDAD==0)
        {
            printf("Aucun adherent correspondant a ce nom\n");
            return 1;
        }
    }
    printf("Quel jeu souhaitez vous emprunter parmis la liste suivante ?\n\n");
    afficherJeux(tabJeux,tailleLogJeux);
    printf("\n\nChoix : ");
    fgets(nomJeux,20,stdin);
    nomJeux[strlen(nomJeux)-1] = '\0';
    printf("\n");
    for (i = 0; i < tailleLogJeux; i++)
    {
        if (strcmp(tabJeux[i]->nom,nomJeux)==0)
        {
            trouve=1;
            IDjeu=tabJeux[i]->id;
            dispo=tabJeux[i]->nbExemplaire;
            if (tabJeux[i]->nbExemplaire!=0)
            {
                tabJeux[i]->nbExemplaire=tabJeux[i]->nbExemplaire-1;
            }
        }
    }
    while(trouve==0)
    {
        printf("Ce jeu ne fait pas partie de la liste, veuillez resaisir :\n");
        fgets(nomJeux,20,stdin);
        nomJeux[strlen(nomJeux)-1] = '\0';
        printf("\n");
        for (i = 0; i < tailleLogJeux; i++)
        {
            if (strcmp(tabJeux[i]->nom,nomJeux)==0)
            {
                trouve=1;
                IDjeu=tabJeux[i]->id;
                dispo=tabJeux[i]->nbExemplaire;
                if (tabJeux[i]->nbExemplaire!=0)
                {
                    tabJeux[i]->nbExemplaire=tabJeux[i]->nbExemplaire-1;
                }
            }
        }
    }
    if (dispo==0)
    {
        printf("Jeu actuellement indisponible, souhaitez-vous le reserver ?\n");
        printf("\n\n1 Oui\t\t2 Non\n");
        scanf("%d", &choix);
        while(choix!=1 && choix!=2)
        {
            printf("\n\tErreur lors du choix, veuillez reessayer :");
            scanf("%d",&choix);
        }
        if (choix==1)
        {
            nouvelleReservation(r, IDjeu, IDAD);
            printf("Reservation enregistree !\n");
        }
    }
    else
    {
        nouvelEmprunt(l, IDjeu, IDAD);
        printf("\nEmprunt enregistre !\n");
    }
}

/*
    Fonction IDAD
    Finalité : retourner l'ID correspondant au nom entré dans la fonction globalNouvEnreg
    Description :initialisation de l'IDAD a retourner égal à 0
                 parcourt la liste AD
                 si le nom entré correspond à un nom de la liste, la fonction retourne l'IDAD correspondant
                 elle retourne 0 sinon
*/

int rechercheIDAD(char prenomNomExistant[], ListeAD AD)
{
    int IDAD=0;
    while(AD!=NULL)
    {
        if(strcmp(prenomNomExistant,AD->prenomNom)==0)
            IDAD=AD->idAdherent;
        AD=AD->s;
    }
    return IDAD;
}

/*
    Fonction nouvelIDAD
    Finalité : créer un ID pour un nouvel adhérent
    Description :  parcourt la liste AD afin d'obtenir le dernier ID
                   la liste étant triée par ordre croissant des ID, le nouvel ID sera la valeur du dernier +1
                   retourne cette valeur
*/

int nouvelIDAD(ListeAD AD)
{
    int nouvIDAD;
    while(AD!=NULL)
        {
            nouvIDAD=AD->idAdherent;
            AD=AD->s;
        }
    nouvIDAD=nouvIDAD+1;
    return nouvIDAD;
}

/*
    Fonction creationAdherent
    Finalité : ajouter un nouvel adhérent à la liste AD
    Description : remplit la struct tm (librairie <time.h>) avec la date systeme
                  initialisation d'un MaillonAD
                  intialisation d'un nouvel IDAD
                  demande un nom et prénom et le place dans le maillon
                  demande la civilité tant qu'elle ne correspond pas à Mr ou Mme et la place dans le maillon
                  remplit le maillon avec la valeur de temps de la struc tm
                  le nouvel IDAD prend la valeur retournée par la fonction nouvelIDAD
                  insertion du MaillonAD a la liste AD avec la fonction insertionCroissanteAD
                  retourne le nouvelIDAD
*/

int creationAdherent(ListeAD AD)
{
    time_t secondes;
    struct tm instant;
    time(&secondes);
    instant=*localtime(&secondes);

    int nouvIDAD;
    char c;
    MaillonAD mAD;
    printf("Veuillez saisir votre prenom et votre nom (exemple : Prenom NOM)\n");
    c=getchar();
    fgets(mAD.prenomNom,40,stdin);
    mAD.prenomNom[strlen(mAD.prenomNom)-1] = '\0';
    printf("Veuillez saisir votre civilite (Mr ou Mme)\n");
    scanf("%s",mAD.civ);
    while(strcmp(mAD.civ,"Mr")!=0 && strcmp(mAD.civ,"Mme")!=0)
    {
        printf("Veuillez resaisir\n");
        scanf("%s",mAD.civ);
    }
    c=getchar();
    mAD.jour=instant.tm_mday;
    mAD.mois=instant.tm_mon+1;
    mAD.annees=instant.tm_year+1900;
    nouvIDAD=nouvelIDAD(AD);
    mAD.idAdherent=nouvIDAD;
    AD=insertionCroissanteAD(AD,mAD);
    return nouvIDAD;
}

/*
    Fonction nouvelIDEmp
    Finalité : créer un ID pour un nouvel emprunt
    Description :  parcourt la liste d'emprunts afin d'obtenir le dernier ID
                   la liste étant triée par ordre croissant, le nouvel ID sera la valeur du dernier +1
                   retourne cette valeur
*/

int nouvelIDEmp(Liste e)
{
    int nouvIDEmp;
    while(e!=NULL)
        {
            nouvIDEmp=e->idEmprunt;
            e=e->suiv;
        }
    nouvIDEmp=nouvIDEmp+1;
    return nouvIDEmp;
}

/*
    Fonction nouvelEmprunt
    Finalité : ajouter un nouvel emprunt à la liste des emprunts
    Description : remplit la struct tm (librairie <time.h>) avec la date systeme
                  initialisation d'un Maillon
                  le nouvel IDEmp prend la valeur retournée par la fonction nouvelIDEmp
                  remplit le maillon avec les valeurs IDAD, IDjeu et la date de la struc tm
                  insertion du Maillon a la liste des emprunts avec la fonction insertionCroissante
*/

void nouvelEmprunt(Liste e, int IDjeu, int IDAD)
{
    time_t secondes;
    struct tm instant;
    time(&secondes);
    instant=*localtime(&secondes);

    Maillon m;
    m.idEmprunt=nouvelIDEmp(e);
    m.idAdherent=IDAD;
    m.idJeu=IDjeu;
    m.jour=instant.tm_mday;
    m.mois=instant.tm_mon+1;
    m.annees=instant.tm_year+1900;
    e=insertionCroissante(e,m);
}

/*
    Fonction nouvelIDRes
    Finalité : créer un ID pour une nouvelle réservation
    Description :  parcourt la liste des réservations afin d'obtenir le dernier ID
                   la liste étant triée par ordre croissant, le nouvel ID sera la valeur du dernier +1
                   retourne cette valeur
*/

int nouvelIDRes(ListeReserv r)
{
    int nouvIDRes;
    while(r!=NULL)
        {
            nouvIDRes=r->idResa;
            r=r->next;
        }
    nouvIDRes=nouvIDRes+1;
    return nouvIDRes;
}

/*
    Fonction nouvelleReservvation
    Finalité : ajouter une nouvelle réservation à la liste des réservations
    Description : remplit la struct tm (librairie <time.h>) avec la date systeme
                  initialisation d'un MaillonReserv
                  le nouvel IDResa prend la valeur retournée par la fonction nouvelIDRes
                  remplit le maillon avec les valeurs IDAD, IDjeu et la date de la struc tm
                  insertion du MaillonReserv a la liste des réservations avec la fonction insertionCroissanteReserv
*/

void nouvelleReservation(ListeReserv r, int IDjeu,int IDAD)
{
    time_t secondes;
    struct tm instant;
    time(&secondes);
    instant=*localtime(&secondes);

    MaillonReserv m;
    m.idResa=nouvelIDRes(r);
    m.idAdherent=IDAD;
    m.idJeu=IDjeu;
    m.jour=instant.tm_mday;
    m.mois=instant.tm_mon+1;
    m.annees=instant.tm_year+1900;
    r=insertionCroissanteReserv(r,m);
}


//--------------------------- Fonction 5 : retour d'un jeu ------------------------------

//Auteur du commentaire : Arthur LASHERMES
/*Le but de cette fonctionnalité est que un utilisateur rend un jeu qu'il avait emprunter, dans le cas où ce jeu est 
reserver on doit transformer cette reservation en emprunt donc supprimer la réservation en question dans le fichier 
reservation puis modifier l'ancien emprunt pour le mettre à jour avec le nouveau idadherent et la nouvelle date
sinon on doit supprimer cette emprunt dans le fichier emprunt et ajouter un examplaire du livre dans le fichier jeux*/

void retourJeux (ListeAD AD,ListeReserv r,Liste l,Jeux *tabJeux[],int tailleLogJeux)
{   
    int c;
    int idBackAD;
    int i;
    int idJeux;
    int idADnew;
    int a;
    int verif;
    char jeuxBack[20],nomPrenom[20];
    printf("Quelle est le jeu que vous voulez rendre ?\n");
    fgets(jeuxBack,20,stdin);
    jeuxBack[strlen(jeuxBack)-1] = '\0'; // On récupère le jeux rendu
    idJeux=rechercheIDv4(jeuxBack,tabJeux,tailleLogJeux); //On cherche idJeux à partir du nom du Jeux
    while(idJeux==-1)
    {
        printf("Jeu inexistant.\nVeuillez resaisir : ");
        printf("Quelle est le jeu que vous voulez rendre ?\n");
        fgets(jeuxBack,20,stdin);
        jeuxBack[strlen(jeuxBack)-1] = '\0';
        idJeux=rechercheIDv4(jeuxBack,tabJeux,tailleLogJeux);
    }

    printf("Donnez votre prenom et votre nom (Prenom NOM):\n");   
    fgets(nomPrenom,20,stdin);
    nomPrenom[strlen(nomPrenom)-1] = '\0'; // On récupère le nom prenom de l'utilisateur qui rend le jeux
    retourIDv2(nomPrenom,AD,&verif,&idBackAD); // On recherche l'idAdherent par rapport au nom prenom renseigner plus haut
    while(verif==0)
    {
        printf("Adherent inexistant.\nVeuillez resaisir : ");
        fgets(nomPrenom,20,stdin);
        nomPrenom[strlen(nomPrenom)-1] = '\0';
        retourIDv2(nomPrenom,AD,&verif,&idBackAD);
    }

    verif=verificationJeux(l,idJeux,idBackAD);

    if(verif==-1)
        printf("Ce jeu n'est pas dans votre liste des emprunts ou n'existe pas\n");
    else
    {
        printf("Vous avez ete identifie au %04d\n",idBackAD);
        idADnew=affectationReserv(r,idJeux,&a);
        printf("\n");
        if (a==1)
        {   
            r=supprimer(r,idADnew,idJeux); //suppression de la réservation puis on modifie celle de l'utilisateur qui rend
            l=ajoutEmprunt(l,idADnew,idJeux,idBackAD); //le jeu réservé devient un emprunt
        }
        else
        {
            l=supprimerEmp(l,idBackAD,idJeux); //dans ce cas on supprime juste l'emprunt car le jeu n'est pas réservé
            for (int j = 0; j < tailleLogJeux; j++) // on ajoute 1 à la disponibilité du jeu
            {
                if (tabJeux[j]->id==idJeux)
                {
                    tabJeux[j]->nbExemplaire=tabJeux[j]->nbExemplaire+1;
                }
            }
        }
        printf("Vous avez bien rendu le jeux %s, merci\n",jeuxBack);
    }
}

int rechercheIDv4 (char nomJeux[], Jeux *tabJeux[],int tailleLogJeux)
{
    for (int i = 0; i < tailleLogJeux; ++i)
    {
        if(strcmp(nomJeux,tabJeux[i]->nom)==0)
        {   

            return tabJeux[i]->id;
        }
    }
    return -1;
}

int verificationJeux(Liste l,int idJeux, int IDAD)
{   
    int verif;
    while(l!=NULL)
    {
        if (l->idJeu == idJeux && IDAD == l->idAdherent )
        {
            return 0;
        }
        l=l->suiv;
    }
    return -1;
}

void retourIDv2(char nomPrenom[],ListeAD AD,int *i,int *idBack)
{   
    *i=0;
    while(!videAD(AD))
    {
        if(strcmp(nomPrenom,AD->prenomNom)==0)
        {
            *idBack=AD->idAdherent;
            *i=1;
        }
        AD=AD->s;
    }
}

Booleen videAD(ListeAD AD)
{
    if(AD==NULL)
        return vrai;
    return faux;
}

int affectationReserv(ListeReserv r,int id,int *a)
{
    while(!videReserv(r))
    {
        if(r->idJeu==id)
        {
            *a=1;
            return r->idAdherent;
        }
        r=r->next;
    }
    *a=0;
    return 0;
}

ListeReserv supprimer(ListeReserv r, int x, int idJeux)
{   
    if (r==NULL)
    {
        return r;
    }
    if (x == r->idAdherent)
        if(r->idJeu == idJeux)
            return supprimerEnTete(r);             
    r->next = supprimer(r->next, x,idJeux);
    return r;
}

ListeReserv supprimerEnTete(ListeReserv r)
{
  MaillonReserv *o;
  if (r==NULL)
  {
      printf("Operation interdite\n");
      exit (1);
  }
  o=r;
  r=r->next;
  free(o);
  return r;
}


Liste ajoutEmprunt(Liste l,int idADnew,int idJeux,int idBackAD)
{
    time_t secondes;
    struct tm instant;
    time(&secondes);
    instant=*localtime(&secondes);
    while(!vide(l))
    {
        if(l->idAdherent==idBackAD && l->idJeu==idJeux)
        {   
            l->idAdherent=idADnew;
            l->jour=instant.tm_mday;
            l->mois=instant.tm_mon+1;
            l->annees=instant.tm_year+1900;
        }
    l=l->suiv;
    }
    return l;
}

Liste supprimerEmp(Liste l,int idBackAD,int idJeux)
{
    if (l==NULL)
    {
        return l;
    }
    if (idJeux == l->idJeu)
        if (idBackAD == l->idAdherent)
            return supprimerEnTeteEmp(l);  
    l->suiv = supprimerEmp(l->suiv, idBackAD, idJeux);
    return l;
}

Liste supprimerEnTeteEmp(Liste l)
{
    Maillon *m;
    if (l==NULL)
    {
        printf("Operation interdite.\n");
        exit(1);
    }
    m = l;
    l = l->suiv;
    free(m);
    return l;
}

//--------------------- Fonction 6 : annulation d'une réservation ---------------------

/*Finalité : Demander le prenom et Nom de la personne, rechercher son ID Adherent via son nom puis rechercher la/les reservation(s) en cours en affichant les jeux reserver puis lui demander si il souhaite annuler la/les reservation(s)//
    Description : - Saisie du nom/prenom puis recherche de l'ID correspondant au nom prenom entré
                  - Test des différents cas de figure : - si trouve = 0, l'adherent n'existe pas
                                                        - si trouve = 1, l'adherent existe
                  - Affichage des reservation de l'adherent avec appel de la fonction rechJeuCorrespondant
                  - Affectation à la variable nbReservation le nombre de reservation que possède l'adherent via la fonction nbReserv
                  - Test des différents cas de figure : - si nbReservation = 0, l'adherent ne possède aucune reservation en cours et retour au Menu de l'application
                                                        - si nbReservation >1 , Même principe, affectation à nomJeu puis suppression 
    Variables : jeuSupp -> Jeu à supprimer // trouve -> Variable permettant de confirmer si l'adherent existe ou non
                saisieID -> Variable qui contient l'ID de l'adhérent par l'intermédiaire de son nom ou par saisie dans le terminal*/

void affichageNbReservation (Jeux *tabJeux[], int tailleLogJeux,ListeAD AD,Liste l,ListeReserv r)
{
    int i, idAdherent,trouve, nbReservation, jeuSupp;
    char nomPrenom[20], nomJeu[20];
    char choix;
    int saisieID;
    printf("Saisissez votre prenom et votre nom en majuscule : (ex : Prenom NOM) \n");
    fgets(nomPrenom,20,stdin);
    nomPrenom[strlen(nomPrenom)-1] = '\0';
    saisieID=rechercheIdAdherent(nomPrenom, AD, &trouve, saisieID);
    if(trouve==0)
    {
            printf("%s ne correspond pas a un adherent de la ludotheque\n",nomPrenom);
    }
    else 
    {
        if(trouve>=1)
        {
            printf("Reservation de %s :\n", nomPrenom);
            rechJeuCorrespondant(tabJeux, r, saisieID, tailleLogJeux);
            nbReservation=nbReserv(r, saisieID);
            if(nbReservation==0)
            {
                printf("Vous n'avez aucune reservation en cours \n");
            }
            else if(nbReservation>=1)
            {

                printf("Saississez le jeu dont vous voulez supprimer la reservation \n");
                fgets(nomJeu,20,stdin);
                nomJeu[strlen(nomJeu)-1] = '\0';
                jeuSupp=findJeu(r, nomJeu, tabJeux, tailleLogJeux, l, AD, saisieID);
                supprimerReservation(r, saisieID,jeuSupp);
            }
        }
    }
}

/*Finalité : retourner le nombre de reservation selon l'ID de l'adherent 
  Description : - initialisation de la variable nbReservation 
                - Parcours de la liste reservation jusqu'a ce que r pointe vers NULL
                - Recherche de la correspondance entre saisieID et l'ID adherent 
                - si on rentre dans la condition, on rajoute 1 a nbReservation
                - si non on passe au prochain maillon
*/

int nbReserv(ListeReserv r, int saisieID)
{
    int nbReservation=0;
    while(r!=NULL)
    {
        if (saisieID==r->idAdherent)
            nbReservation++;
        r=r->next;
    }
    return nbReservation;
}

/*Finalité : Recherche de l'ID adherent via le prenom/Nom entré dans le terminal
    Description : - Initialiation du pointeur trouve à 0
                  - Parcours de la liste AD jusqu'a ce qu'elle pointe vers NULL
                  - Si on trouve une correspondance entre le nomPrenom et le nomPrenom present dans la liste AD, on affecte a la variable saisieID l'ID adherent present dans le bon maillon et on indente trouve
                  - Si non, on passe au prochain maillon 
                  - On retourne saisieID quand on a parcouru toute la liste chainée
    Variable : *trouve -> Permet de savoir si l'adherent a été trouvé ou non ( prend la valeur 1 si oui 0 si non)
*/

int rechercheIdAdherent(char nomPrenom[],ListeAD AD,int *trouve,int saisieID)
{   
    *trouve=0;
    while(AD!=NULL)
    {
        if(strcmp(nomPrenom,AD->prenomNom)==0)
            {
            saisieID=AD->idAdherent;
            *trouve=*trouve+1;
            }
        AD=AD->s;
    }
    return saisieID;
}

/* Finalité : Recherche le jeu correspondant dans le tableau tabJeux et affiche le nom du jeu pour clarifier la suppression de la reservation
    Description : - Parcours la liste reservation
                  - Si il y a correspondance entre la saisie ID et l'id Adherent de la liste reservation, on affecte a JeuBon le bon Id du jeu.
                  - On parcourt ensuite le tableau tabJeux avec la boucle for et on vérifie la correspondance entre l'id de JeuBon et l'id dans le tabJeux 
                  - si il y a correspondance, on affiche le Nom du Jeu
                  - si non on passe au prochain maillon
    Variable : idJeubon -> Id du jeu qui est possédé par l'adherent souhaitant supprimer une reservation
*/

void rechJeuCorrespondant(Jeux *tabJeux[], ListeReserv r, int saisieID, int tailleLogJeux)
{
    
    
    int j;
    int idJeubon;
    while(r !=NULL)
    {
        if(saisieID==r->idAdherent)
        {
            idJeubon=r->idJeu;
            for(j=0; j<tailleLogJeux; j++)
            {
                if(tabJeux[j]->id == idJeubon)
                     printf("Nom du jeu : %s \n \n", tabJeux[j]->nom);    
            } 
        }
        r=r->next;
    }
}

/* Finalité : Permet de supprimer en Tete la valeur present dans le maillon o en utilisant "free(o)"
    Description : - Créer un pointeur o de type MaillonReserv 
                  - CONDITION : la Liste reserv r ne doit pas être nul sinon supprimer n'a pas de sens d'où la vérification
                  - On rempli le maillon o avec les données du maillon r que l'on veut supprimer, r pointe vers le maillon suivant et on supprime o
                  - On retourne la liste actualisée 
*/

ListeReserv supprimerEnTeteRes(ListeReserv r)
{
  MaillonReserv *o;
  if (r==NULL)
  {
      printf("Operation interdite\n");
      exit (1);
  }
  o=r;
  r=r->next;
  free(o);
  return r;
}

/*Finalité : Appel de la fonction supprimer en tete une fois les correspondances vérifiées grâce aux parcours de la liste r avec la récursivité 
  Description : -Cas d'arret avec le premier if qui permet de stopper la recursivité et de retourner la liste r si r pointe vers NULL
                - Vérifier la correspondance entre la saisieID et l'Id adherent de la liste r puis vérification que jeuSupp est égal à l'idJeu de la liste r
                - Si les deux conditions sont vérifiées, on appelle la fonction supprimerEnTeteRes au maillon que l'on veut supprimer. 
*/

ListeReserv supprimerReservation(ListeReserv r, int saisieID, int jeuSupp)
{
    if(r==NULL)
        return r;
    if(saisieID==r->idAdherent)
        if(jeuSupp==r->idJeu)
            return supprimerEnTeteRes(r);
    r->next=supprimerReservation(r->next,saisieID, jeuSupp);
    return r;
}

/*Finalité : Affecter à la variable jeuSupp l'ID du jeu correspondant a supprimer et le retourner 
    Description : Parcours du tableau tabJeux 
                - Chercher via la condition le rang dans le tableau tabJeux la correspondance entre le nomJeu entré par l'utilisateur 
                  et le nom dans les différentes case du tableau tabJeu
                - Affecter a la variable JeuSupp l'id du Jeu présent dans le tableau au bon rang
                -retourner la variable jeuSupp
Variables : jeuSupp = Jeu à Supprimer
*/

int findJeu (ListeReserv r, char nomJeu[20], Jeux *tabJeux[], int tailleLogJeux, Liste l, ListeAD AD, int saisieID)
{
    int i, jeuSupp;
    char c;
    for(i=0; i<tailleLogJeux;i++)
    {    
        if(strcmp(tabJeux[i]->nom, nomJeu)==0)
        {
            jeuSupp=tabJeux[i]->id;
            return jeuSupp;
        }
    }
    //Verification que le jeu entre dans le terminal correspond bien a un jeu reservé par la personne, si non, on redemande a l'utilisateur d'entre le nom du Jeu 
    //et on rappelle la fonction par recursivité
    printf("Le jeu %s n'est pas present dans notre Ludotheque, voici la liste de vos reservations : \n \n", nomJeu);
    rechJeuCorrespondant(tabJeux, r, saisieID, tailleLogJeux);
    printf("Veuillez a nouveau entrer le jeu dont vous souhaitez supprimer la reservation : \n");
    fgets(nomJeu,20,stdin);
    nomJeu[strlen(nomJeu)-1] = '\0';
    return findJeu(r,nomJeu,tabJeux, tailleLogJeux, l, AD, saisieID);
}

//----------------------- Fonction de sauvegarde ------------------------------

/* Finalité: Sauvegarde de la Liste l des emprunts dans le fichier Emprunts.txt en écrasant dans celui-ci les données déjà présentes
    Description: - Ouverture du fichier en écriture pour le vider, vérification que l'ouverture s'est bien passée
                 - Ecriture des données du premier maillon dans le fichier, on pointe le maillon l vers le maillon suivant et on parcourt la liste chaînée via le while
                 - Même procédure, on écrit les données en parcourant la liste petit à petit jusqu'a arriver à la fin de la liste ou l'on ferme le flot. 
*/

void sauvegardeEmprunts (Liste l)
{   
    int i=0;
    FILE *flot;
    flot=fopen("Emprunts.txt","w");
    if(flot == NULL)
    {
        printf("Problème d'ouverture du fichier\n");
        exit(1);
    }
    fprintf(flot,"%04d %04d %03d %02d %02d %04d",l->idEmprunt,l->idAdherent,l->idJeu,l->jour,l->mois,l->annees);
    l=l->suiv;
    while(l!=NULL)
    {   
        fprintf(flot,"\n");
        fprintf(flot,"%04d %04d %03d %02d %02d %04d",l->idEmprunt,l->idAdherent,l->idJeu,l->jour,l->mois,l->annees);
        l=l->suiv; 
    }
    fclose(flot);
}

/*  Finalité: Sauvegarde du tableau de jeu dans le fichier ficjeux.txt en écransant son contenu
    Description : -Ouverture du fichier "ficjeux.txt" en écriture permettant de le vider
                -Vérification que l'ouverture du fichier s'est bien déroulée
                - Parcours du tableau Jeu et écriture dans le fichier avec chaque valeur pour chaque case du tableau.
*/

void sauvegarderJeux(Jeux *tabJeux[], int tailleLogJeux)
{
    FILE *flot;
    int i;
    flot=fopen("ficjeux.txt", "w");
    if(flot==NULL)
        {
            printf("Erreur lors de l'ouverture du fichier ficjeux.txt en ecriture \n");
            exit(1);
        }
    for(i=0; i<tailleLogJeux; i++)
    {
        fprintf(flot,"%03d %s %d %s\n", tabJeux[i]->id, tabJeux[i]->type, tabJeux[i]->nbExemplaire, tabJeux[i]->nom);
    }
    fclose(flot);
}

/* Finalité : Sauvegarde de la liste reservation dans le fichier Reservation.txt en écrasant dans celui-ci les données déjà présentes
    Description : Ouverture du fichier en écriture pour le vider, vérification que l'ouverture s'est bien passée
                 - Ecriture des données du premier maillon dans le fichier, on pointe le maillon r vers le maillon suivant et on parcourt la liste chaînée via le while
                 - Même procédure, on écrit les données en parcourant la liste petit à petit jusqu'a arriver à la fin de la liste ou l'on ferme le flot. 
*/

void sauvegardeReserv(ListeReserv r)
{   
    int i=0;
    FILE *flot;
    flot=fopen("Reservation.txt","w");
    if(flot == NULL)
    {
        printf("Problème d'ouverture du fichier\n");
        exit(1);
    }
    fprintf(flot,"%03d %04d %03d %02d %02d %0004d",r->idResa,r->idAdherent,r->idJeu,r->jour,r->mois,r->annees);
    r=r->next;
    while(r!=NULL)
    {   
        fprintf(flot,"\n");
        fprintf(flot,"%03d %04d %03d %02d %02d %0004d",r->idResa,r->idAdherent,r->idJeu,r->jour,r->mois,r->annees);
        r=r->next; 
    }
    fclose(flot);
}

/*Finalité : Sauvegarde de la liste adherent AD dans le fichier adherent.txt en écrasant dans celui-ci les données déjà présentes
    Description : Ouverture du fichier en écriture pour le vider, vérification que l'ouverture s'est bien passée
                 - Ecriture des données du premier maillon dans le fichier, on pointe le maillon AD vers le maillon suivant et on parcourt la liste chaînée via le while
                 - Même procédure, on écrit les données en parcourant la liste petit à petit jusqu'a arriver à la fin de la liste ou l'on ferme le flot. 
*/

void sauvegardeAD(ListeAD AD)
{   
    int i=0;
    FILE *flot;
    flot=fopen("Adherent.txt","w");
    if(flot == NULL)
    {
        printf("Problème d'ouverture du fichier\n");
        exit(1);
    }
    while(AD->s!=NULL)
    {   
        fprintf(flot,"%04d %02d %02d %04d %s %s",AD->idAdherent, AD->jour,AD->mois,AD->annees,AD->civ,AD->prenomNom);
        fprintf(flot,"\n");
        AD = AD->s;
    }
    fprintf(flot,"%04d %02d %02d %04d %s %s ",AD->idAdherent, AD->jour,AD->mois,AD->annees,AD->civ,AD->prenomNom);
    fclose(flot);
}