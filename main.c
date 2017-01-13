#include <stdio.h>
#include <stdlib.h>


int ** allocation(int n)
{
    int **a,i,j;
    a=malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
        a[i]=malloc(n*sizeof(int)); //on alloue de la mémoire

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            a[i][j]=0;
    return a;
}

//fonction pour remplir le tableau lorsque l'utilisateur rentre 5
void remplir5(int **tableau,int n)
{
    if(n==5){
    int i=n % 2,j=n/2;//pour placer le 1 au nord du milieu
    int k;
    tableau[i][j]=1;
    for(k=2;k<=n*n;k++){
        if(tableau[(i+1)%n][(j+1)%n]==0){ //avancement des cases
            i=(i+1)%n;
            j=(j+1)%n;
        }else //si la place est déjà prise, avancement nord-ouest
            if(i==0)
                i=n-1;
            else
                i=i-1;
        tableau[i][j]=k;
        }
    }
}

//fonction pour remplir le tableau lorsque l'utilisateur rentre 7
void remplir7(int **tableau,int n)
{
    if(n==7){
    int i=n-5,j=n/2;//pour placer le 1 au nord du milieu
    int k;
    tableau[i][j]=1;
    for(k=2;k<=n*n;k++){
        if(tableau[(i+1)%n][(j+1)%n]==0){//avancement des cases
            i=(i+1)%n;
            j=(j+1)%n;
        }else //si la place est déjà prise, avancement nord-ouest
            if(i==0)
                i=n-1;
            else
                i=i-1;
        tableau[i][j]=k;
        }
    }
}

//affiche le carré magique
void afficher(int **m,int n)
{
    int i,j;
    printf("valeur du carre magique %d \n\n",n);
    for(i=0;i<n;i++)
    {
        printf("\t");
        for(j=0;j<n;j++)
            printf("%d      ",m[i][j]);
        printf("\n\n\n");
    }
}

main()
{
    int n,**carre;
    do
    {
        printf("Entrez la valeur du carre magique voulu \n");//demande la valeur à l'utilisateur
        scanf("%d",&n);
        if(n%2==0)// dans le cas ou l'utilisateur ne rentre pas la bonne valeur
            printf("Entrez soit 5, soit 7\n");
        printf("\n");
    }
    while(n%2==0);
    carre=allocation(n);
    remplir5(carre,n);
    remplir7(carre,n);
    afficher(carre,n);
}


