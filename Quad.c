#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct QUAD{
    char OPR1[20];
    char OPR2[20];
    char OPR3[20];
    char RESULT[20];
    int QN;
    struct QUAD* SVT;
};
void InsertQ(struct QUAD** Tete, char OPR1[20],char OPR2[20],char OPR3[20],char RESULT[20],int QN){
  struct QUAD* Parcourir;
  Parcourir=*Tete;
  struct QUAD* NewQ;
  NewQ=NULL;
  if(Parcourir!=NULL){
    while((*Parcourir).SVT!=NULL){
      Parcourir=(*Parcourir).SVT;
    }
    NewQ=malloc(sizeof(struct QUAD));
    strcpy((*NewQ).OPR1,OPR1);
    strcpy((*NewQ).OPR2,OPR2);
    strcpy((*NewQ).OPR3,OPR3); 
    strcpy((*NewQ).RESULT,RESULT);
    (*NewQ).QN=QN;
    (*NewQ).SVT=NULL;
    (*Parcourir).SVT=NewQ;
  }else{
    *Tete=malloc(sizeof(struct QUAD));
    strcpy((**Tete).OPR1,OPR1);
    strcpy((**Tete).OPR2,OPR2);
    strcpy((**Tete).OPR3,OPR3); 
    strcpy((**Tete).RESULT,RESULT);
    (**Tete).QN=QN;
    (**Tete).SVT=NULL;
  }
}
void ShowQ(struct QUAD** Tete){
  struct QUAD* Parcourir;
  Parcourir=*Tete;
  FILE* File=NULL;
  File=fopen("quad.txt","w+");
  while(Parcourir!=NULL){
    fprintf(File," %d-(%s,%s,%s,%s)\n",(*Parcourir).QN,(*Parcourir).OPR1,(*Parcourir).OPR2,(*Parcourir).OPR3,(*Parcourir).RESULT);
    Parcourir=(*Parcourir).SVT;
  }
  fclose(File);
}
void MAJQ(struct QUAD** Tete,int QN,int QFin){
  struct QUAD* Parcourir=*Tete;
  char *Chaine;
  Chaine=malloc(sizeof(10));
  while((*Parcourir).QN!=QN){
  Parcourir=(*Parcourir).SVT;
  }
  sprintf(Chaine,"%d",QFin);
  strcpy((*Parcourir).OPR2,Chaine);
}