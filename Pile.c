#include<stdio.h>
#include<stdlib.h>
typedef struct PILE{
  int val;
  struct PILE* SVT;
};
int PileVide(struct PILE** Tete){
  if(*Tete==NULL) return 1;
  else return 0;  
}
int PileSommet(struct PILE** Tete){
  if(PileVide(Tete)) return -1;
  else return (**Tete).val;
}
void PUSH(struct PILE** Tete , int val){
  if (PileVide(Tete)){
    *Tete=malloc(sizeof(struct PILE));
    (**Tete).val=val;
    (**Tete).SVT=NULL;
  }else{
    struct PILE* NewP;
    NewP=malloc(sizeof(struct PILE));
    (*NewP).val=val;
    (*NewP).SVT=*Tete;
    *Tete=NewP;
  }
}
int PULL(struct PILE** Tete ){
    int val=-1;
    if(!PileVide(Tete)){
        val=(**Tete).val;
    if((*Tete)->SVT==NULL) (*Tete)=NULL;
    else *Tete=(*Tete)->SVT;
    }return val;
}
