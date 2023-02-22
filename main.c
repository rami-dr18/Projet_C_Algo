#include<stdio.h>
#include<string.h>
#include<ctype.h>
int k;
typedef struct {
    char nom[20];
    double note_cc;
    double note_ex;
    double coe_cc,coe_ex,moy;
}matiere;

typedef struct{
int j;
int m;
int y;
}date;

typedef struct {
int id;
char nom[20];
char prenom[20];
date date_de_naissance;
double moy_general;
matiere m[20];
int nb_mat;
}etudiant;
void interface()
{
    do{
    system("cls");
    printf("[ 1 ] > Affichager tous les etudiants\n");
    printf("[ 2 ] > Ajouter des etudiants\n");
    printf("[ 3 ] > Rechercher un etudiant\n");
    printf("[ 4 ] > Chercher un etudiant\n");
    printf("[ 5 ] > Modifier une note\n");
    printf("[ 6 ] > Informations du etuiant qui a la moyenne plus elevee\n");
    printf("[ 7 ] > Quitter le programme\n");
    scanf("%d",&k);}
    while(!((k>=1) && (k<=7)));
}
void affiche_etu(int n,etudiant t[])
{
    int i,c;
    system("cls");
    printf("Identifiant    Nom    Prenom \n:");
    printf("------------------------------\n");
    for(i=1;i<=n;i++)
    {
        printf("%d| %s | %s\n",t[i].id,t[i].nom,t[i].prenom);
    }
    do{
    printf(">tapez 2 pour retour\n");
    scanf("%d",&c);
    }while(c!=2);
}
void sasie_note(int n,etudiant *t)
{
    int c;
    for (int i=1;i<=n;i++){
    system("cls");
    printf("> sasie le nom de la matiere: \n");
    scanf("%s",&t->m[i].nom);
    do{
        printf("> donner la note de controle continue :\n");
        scanf("%lf",&t->m[i].note_cc);
    }while(!((t->m[i].note_cc>=0)&&(t->m[i].note_cc<=20)));
    do{
        printf("> donner la note de note examen :\n");
        scanf("%lf",&t->m[i].note_ex);
    }while(!((t->m[i].note_ex>=0)&&(t->m[i].note_ex<=20)));
    do{
        printf("sasisr le coefficient de la note de controle continue :\n");
        scanf("%lf",&t->m[i].coe_cc);
        printf("sasisr le coefficient de la note d examen :\n");
        scanf("%lf",&t->m[i].coe_ex);
    }while(!((t->m[i].coe_cc+t->m[i].coe_ex)==1));
    t->m[i].moy=t->m[i].note_cc*t->m[i].coe_cc+t->m[i].note_ex*t->m[i].coe_ex;
    printf("La moyenne de la matiere est %.2lf\n",t->m[i].moy);
    char p;
    printf("tapez un charactere pour continuer \n");
    scanf("%s",&p);
    }
    do{
    printf(">tapez 2 pour retour\n");
    scanf("%d",&c);
    }while(c!=2);
}
int moy_gen(double n,etudiant *t)
{
    system("cls");
    double sum=0;
    for (int i=1;i<=n;i++)
    {
        sum=sum+t->m[i].moy;
    }
    return sum/n;
}
int verif_id(int n,etudiant t[],int k)
{
    int nb=0;
  for(int j=1;j<=n;j++)
  {
        if(t[j].id==k)
            nb+=1;
  }
  if (nb>1)
    return 1;
}
void Ajout_etu(int n,etudiant t[])
{
    int i,c;
    for(i=1;i<=n;i++)
    {
        system("cls");
        do{
        printf("> identifiant: ");
        scanf("%d",&t[i].id);
        }while(verif_id(n,t,t[i].id)==1);
        printf("> Nom : ");
        scanf("%s",t[i].nom);
        printf("> Prenom :");
        scanf("%s",t[i].prenom);
        printf("> Date de naissance : ");
        scanf("%d%d%d",&t[i].date_de_naissance.j,&t[i].date_de_naissance.m,&t[i].date_de_naissance.y);
        printf("> Nombre des matiere : \n");
        scanf("%d",&t[i].nb_mat);
        sasie_note(t[i].nb_mat,&t[i]);
        t[i].moy_general=moy_gen(t[i].nb_mat,&t[i]);
        printf("la moyenen general de l etudiant %s est %.2d\n",t[i].nom,moy_gen(t[i].nb_mat,&t[i]));
    }
    do{
    printf(">tapez 2 pour retour\n");
    scanf("%d",&c);
    }while(c!=2);
}
void recherche_et(int n,etudiant t[])
{ int v;
    do{
    system("cls");
    printf("[ 1 ] > recherhce par ID\n");
    printf("[ 2 ] > recherche par Nom\n");
    printf("[ 3 ] > Rechercher par Prenom\n");
    printf("[ 4 ] > Chercher par date de naissance\n");
    scanf("%d",&v);}
    while(!((v>=1) && (v<=4)));
    switch(v){
case 1:
    {
    int ident;
    int i,nb=0;
    printf("Donner l ID de l etudiant\n");
    scanf("%d",&ident);
    for (i=1;i<=n;i++)
    {
        if(ident==t[i].id)
        {printf("Nom: %s\n",t[i].nom);
        printf("Prenom: %s\n",t[i].prenom);
        printf("date de naissance : %d/%d/%d\n",t[i].date_de_naissance.j,t[i].date_de_naissance.m,t[i].date_de_naissance.y);
            nb+=1;}

    }
    if(nb==0)
            printf("l etudiant n existe pas\n");
    do{
    printf("[2] > Pour retourner\n");
    scanf("%d",&v);
    }
    while(v!=2);
}
        break;
    case 2:
        {
    char ch[25];
    int i,nb=0;
    printf("Donner le nom de l etudiant\n");
    scanf("%s",&ch);
    for (i=1;i<=n;i++)
    {
        if (strcmp(ch,t[i].nom)==0)
        {printf("Nom: %s\n",t[i].nom);
        printf("Prenom: %s\n",t[i].prenom);
        printf("date de naissance : %d/%d/%d\n",t[i].date_de_naissance.j,t[i].date_de_naissance.m,t[i].date_de_naissance.y);
           nb+=1; }

    }
    if(nb==0)
            printf("aucun etudiant ne porte ce nom\n");

    do{
    printf("[2] > Pour retourner\n");
    scanf("%d",&v);
    }
    while(v!=2);
    }
        break;
    case 3:
        {
    char ch[25];
    int i,nb=0;
    printf("Donner le prenom de l etudiant\n");
    scanf("%s",&ch);
    for (i=1;i<=n;i++)
    {
        if (strcmp(ch,t[i].prenom)==0)
        {printf("Nom: %s\n",t[i].nom);
        printf("Prenom: %s\n",t[i].prenom);
        printf("date de naissance : %d/%d/%d\n",t[i].date_de_naissance.j,t[i].date_de_naissance.m,t[i].date_de_naissance.y);
            nb+=1;}
    }
    if(nb==0)
            printf("aucun etudiant ne porte ce prenom\n");
    do{
    printf("[2] > Pour retourner\n");
    scanf("%d",&v);
    }
    while(v!=2);
    }
        break;
    case 4:
        {
    int jour,mois,anne;
    int i,nb=0;
    printf("Donner la date de naissance de l etudiant : \n");
    scanf("%d%d%d",&jour,&mois,&anne);
    for (i=1;i<=n;i++)
    {
        if((jour==t[i].date_de_naissance.j)&&(mois==t[i].date_de_naissance.m)&&(anne==t[i].date_de_naissance.y))
        {printf("Nom: %s\n",t[i].nom);
        printf("Prenom: %s\n",t[i].prenom);
            nb+=1;}

    }
    if(nb==0)
            printf("l etudiant n existe pas\n");
    do{
    printf("[2] > Pour retourner\n");
    scanf("%d",&v);
    }
    while(v!=2);
}
        break;
    }
}
int compare_date(date d1,date d2)
{
   int n1,n2;
   n1=d1.y*10000+d1.m*100+d1.j;
   n2=d2.y*10000+d2.m*100+d2.j;
    if(n1<n2)
        return -1;
    else
        if(n1>n2)
            return 1;
        else
            return 0;
}
void recherche_age(int n , etudiant t[])
{int v;
    do{
    system("cls");
    printf("[ 1 ] > le plus age\n");
    printf("[ 2 ] > le moins age\n");
    scanf("%d",&v);}
    while(!((v>=1) && (v<=2)));
    switch(v){
case 1:
    {
        date max_age;
        max_age.j=t[1].date_de_naissance.j;
        max_age.m=t[1].date_de_naissance.m;
        max_age.y=t[1].date_de_naissance.y;
        for(int i=2;i<=n;i++)
        {
            if(compare_date(t[i].date_de_naissance,max_age)==-1){
                max_age.j=t[i].date_de_naissance.j;
                max_age.m=t[i].date_de_naissance.m;
                max_age.y=t[i].date_de_naissance.y;
            }
        }
        for(int j=1;j<=n;j++)
        {
            if(compare_date(t[j].date_de_naissance,max_age)==0)
            {
                printf("l identifiant d etudiant le plus age est : %d\n",t[j].id);
                printf("le nom d etudiant le plus age est : %s\n",t[j].nom);
                printf("le prenom d etudiant le plus age est : %s\n",t[j].prenom);
            }
        }
            do{
    printf("[2] > Pour retourner\n");
    scanf("%d",&v);
    }
    while(v!=2);
    }
    break;
case 2:
    {
        date min_age;
        min_age.j=t[1].date_de_naissance.j;
        min_age.m=t[1].date_de_naissance.m;
        min_age.y=t[1].date_de_naissance.y;
        for(int i=2;i<=n;i++)
        {
            if(compare_date(t[i].date_de_naissance,min_age)==1){
                min_age.j=t[i].date_de_naissance.j;
                min_age.m=t[i].date_de_naissance.m;
                min_age.y=t[i].date_de_naissance.y;
            }
        }
        for(int j=1;j<=n;j++)
        {
            if(compare_date(t[j].date_de_naissance,min_age)==0)
            {
                printf("l identifiant d etudiant le moins age est : %d\n",t[j].id);
                printf("le nom d etudiant le moins age est : %s\n",t[j].nom);
                printf("le prenom d etudiant le moins age est : %s\n",t[j].prenom);
            }
        }
            do{
    printf("[2] > Pour retourner\n");
    scanf("%d",&v);
    }
    while(v!=2);

    }
    break;
}
}
void modif_note(int n , etudiant t[])
{
    system("cls");
    int note_id,v,indice;
    printf("> donner l identifiant de l ietudiant que vous voulez modifier les notes: \n");
    scanf("%d",&note_id);
    for(int i=1;i<=n;i++)
    {
        if(t[i].id==note_id)
        {
            sasie_note(t[i].nb_mat,&t[i]);
            moy_gen(t[i].nb_mat,&t[i]);
            t[i].moy_general=moy_gen(t[i].nb_mat,&t[i]);
            indice =i;
            break;
        }

    }
    printf("la modification de moyenne est effecte avec succes\nla novelle moyenne de l etudiant %s d identifiant %d est %d\n",t[indice].nom,t[indice].id,moy_gen(t[indice].nb_mat,&t[indice]));
    do{
    printf("[2] > Pour retourner\n");
    scanf("%d",&v);
    }
    while(v!=2);
}
void  meilleur_note(int n,etudiant t[])
{
    int index,v;
    double max_moy;
    max_moy=t[1].moy_general;
    for (int i=2;i<=n;i++)
    {
        if(t[i].moy_general>max_moy){
            max_moy=t[i].moy_general;
            index=i;
        }
    }
    printf("les informations de l’etudiant ayant la moyenne la plus elevee sont:\nIdentifiant: %d\n",t[index].id);
    printf("Nom: %s\n",t[index].nom);
    printf("Prenom: %s\n",t[index].prenom);
    printf("date de naissance: %d/%d/%d\n",t[index].date_de_naissance.j,t[index].date_de_naissance.m,t[index].date_de_naissance.y);
    do{
    printf("[2] > Pour retourner\n");
    scanf("%d",&v);
    }
    while(v!=2);
}
int main()
{
    int m;
    etudiant et[30];
do{
printf("> Veuillez saisir le nombre des etudiant a gere :\n");
scanf("%d",&m);
}while(!((m>=1)&&(m<=30)));
do{
interface();
switch(k){
case 1:
    affiche_etu(m,et);
    break;
case 2:
    Ajout_etu(m,et);
    break;
case 3:
    recherche_et(m,et);
    break;
case 4:
    recherche_age(m,et);
    break;
case 5:
    modif_note(m,et);
    break;
case 6:
    meilleur_note(m,et);
    break;
}
}while(k!=7);
return 0;
}
