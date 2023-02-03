#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>


typedef struct arbre {
   char mot [26]; 
   int position [2000];
   struct arbre *FG;
   struct arbre *FD;
}arbre;


arbre *node(char mot[26],int phrase){
    arbre *nouv  = malloc(sizeof(arbre));
  
    strcpy(nouv->mot,mot);
    nouv->position[phrase]=1;
    nouv->FD=NULL;
    nouv->FG=NULL;
    return nouv;
}


arbre * insert(arbre *root,char tab[26],int phrases){
  arbre * nouv=node (tab,phrases);
  if (root==NULL){
    root=nouv;
    return root;
  }
  else {
    int comparaison = strcmp(tab,root->mot);
        
  if(comparaison < 0){
    if(root->FG==NULL ){
      root->FG=nouv;
      }
      else
        insert(root->FG,tab,phrases);
    }
    else if (comparaison >0){
    if (root->FD==NULL){
        root->FD=nouv;
    }
        else insert(root->FD,tab,phrases);
    }
    else {
      root->position[phrases]=1;
      return;
    }
        }
    }



arbre * mot(arbre * abr) {
  char tab[26];
  int phrase = 1;
  FILE * ptr = fopen("fishier.txt", "r");
  if (ptr == NULL) {
    printf("Unable to open file.\n");
    exit(EXIT_FAILURE);
  }
  char ch;
  char temp[26];
  int cpt = 0;
  //char check[]={' ','?','!',',','.'};
  arbre * Noeud = abr;

  while ((ch = fgetc(ptr)) != EOF) {
     
      if ((ch == '?') || (ch == '!') || (ch == '.') || (ch == 39) ) {
        tab[cpt] = '\0';
        Noeud = insert(abr, tab, phrase);
        phrase++;
        cpt = 0;
      } 
      else if ((ch==' ') || (ch==',')){
        tab[cpt] = '\0';
        if (abr == NULL) {

          abr = insert(abr, tab, 1);

          Noeud = abr;
        } 
        else {
          Noeud = insert(abr, tab, phrase);
        }
      
      cpt = 0;
      } 
      else if (ch!=10){
    tab[cpt] = ch;
    cpt++;
    }
  }
  //printf("%d",phrase);
  return abr;
}


void afficher_arbre1(arbre *arbre){
    
    if (arbre == NULL){                   // si l'arbre est vide, ne fait rien
        return;
    }
    
    printf("Mot: %s", arbre->mot);       // affiche d'abord le mot du noeud courant
    printf(" \tpositions: ");
    //afficherPos(arbre->position);

    printf("\n");
    
    afficher_arbre(arbre->FG);           // affiche ensuite les sous-arbres
    afficher_arbre(arbre->FD);  
}

void aficher_position(arbre * root){
  for(int i=0; i<2000;i++){
    if (root->position[i]==1){
      printf("|%d| ",i);
    }
    
  }
  }

void afficher_arbre(arbre * root){
  if (root==NULL){
    return;
  }
  afficher_arbre(root->FG);
  printf("MOT = %s",root->mot);
  printf(" \tpositions: ");
  aficher_position(root);
  printf("\n");
  afficher_arbre(root->FD);
  

}
int * rch_mot(char mot[200],arbre *root){
  
  if (root==NULL) return NULL;                            //MOT INTROUVABLE 
  if(strcmp(mot,root->mot)>0) return rch_mot(mot,root->FD); // (ascci(mot) > ascci(racine-mot)->mot dans la droite
  if(strcmp(mot,root->mot)<0) return rch_mot(mot,root->FG);// (ascci(mot) < ascci(racine-mot)->mot dans la gauche
  if (strcmp(mot,root->mot)==0) return (root->position);   //MOT TROUVE 

}

void intersection(int *tab1,int *tab2){
  
  for (int i=0;i<2000;i++){
    
    tab2[i]=((tab1[i]) && (tab2[i]));
  }
  
}
void rechrchePH(arbre *root,char words[200][200]){
  int temp1[2000];

  for(int i=0;i<2000;i++){temp1[i]=1;} //initialiser le tab pour lintersection


  for(int i=0;words[i][0]!=NULL;i++) intersection(rch_mot(&words[i][0],root),temp1);

    if (temp1==NULL) printf("LA PHRASE NEXISTE PAS ");
    else {
      printf (" \n voici la positions de  cette phrase : ");
  for(int i=0;i<20;i++){
  if(temp1[i]!=0){
    printf("%d",i);
  }
  }
  }
  
}

int main()  {
   char fs="fishier.txt";
   
    arbre *root =NULL;
    
    root = mot(root);
    
    afficher_arbre(root);

    printf("   === Recherche idex%c dans un fichier === \n-ENTREZ LA PHRASE: ",130); 

    char words[200];
    gets(words);
    char word[200][200];
    int j=0;
    int i=0;
  for(int s=0;words[s]!='\0';s++)// words
{   
  if (words[s]==' '){
    word[j][i]='\0';
    i=0;j++;
  }
  else {
    word[j][i]=words[s];
    i++;
  }
}
  

  
 
  rechrchePH(root,word);
 
 
}