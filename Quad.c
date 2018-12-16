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
  File=fopen("QUAD.txt","w+");
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


void  Opt1(struct QUAD** TeteQ,struct ENTITE** TeteTS){
  struct QUAD *Parcourir = *TeteQ;
  while (Parcourir != NULL){ 
    if (strcmp((*Parcourir).OPR1, "=") == 0 && strcmp((*Parcourir).OPR3, "") == 0 && Search(TeteTS, (*Parcourir).RESULT)){
      struct QUAD *Continue = (*Parcourir).SVT;
      while (Continue != NULL && strcmp((*Continue).RESULT, (*Parcourir).OPR2) != 0 && strcmp((*Continue).RESULT, (*Parcourir).RESULT) != 0){
        if (strcmp((*Continue).OPR1, "BGE") != 0 && strcmp((*Continue).OPR1, "BLE") != 0 && strcmp((*Continue).OPR1, "BNE") != 0 && strcmp((*Continue).OPR1, "BG") != 0 && strcmp((*Continue).OPR1, "BE") != 0 && strcmp((*Continue).OPR1, "BL") != 0 && strcmp((*Continue).OPR1, "BR") != 0){
          if (strcmp((*Continue).OPR2, (*Parcourir).RESULT) == 0){
            strcpy((*Continue).OPR2, (*Parcourir).OPR2);
          }else{
            if (strcmp((*Continue).OPR3, (*Parcourir).RESULT) == 0){
              strcpy((*Continue).OPR3, (*Parcourir).OPR2);
            }
          }
        }
        Continue = (*Continue).SVT;
      }
    }
    Parcourir = (*Parcourir).SVT;
  }
}
void  Useless(struct QUAD** TeteQ, struct ENTITE** TeteTS){
  struct QUAD* Parcourir =*TeteQ;
  struct QUAD* Pere = NULL;
  while(Parcourir != NULL){
    if(strcmp((*Parcourir).OPR1,"=")==0 && Search(TeteTS,(*Parcourir).RESULT)){
      struct QUAD* Continue =(*Parcourir).SVT;
      while(Continue != NULL && strcmp((*Parcourir).RESULT,(*Continue).OPR2)!=0 && strcmp((*Parcourir).RESULT,(*Continue).OPR3)!=0 && strcmp((*Continue).OPR1, "BGE") != 0 && strcmp((*Continue).OPR1, "BLE") != 0 && strcmp((*Continue).OPR1, "BNE") != 0 && strcmp((*Continue).OPR1, "BG") != 0 && strcmp((*Continue).OPR1, "BE") != 0 && strcmp((*Continue).OPR1, "BL") != 0 || (Continue != NULL && !(strcmp((*Continue).OPR1, "BGE") != 0 && strcmp((*Continue).OPR1, "BLE") != 0 && strcmp((*Continue).OPR1, "BNE") != 0 && strcmp((*Continue).OPR1, "BG") != 0 && strcmp((*Continue).OPR1, "BE") != 0 && strcmp((*Continue).OPR1, "BL") != 0))){
        Continue=(*Continue).SVT;
      }
      if(Continue==NULL){
        if(Pere==NULL){
          *TeteQ=(**TeteQ).SVT;
          struct  QUAD* Change = (*Parcourir).SVT;
          while(Change!= NULL){
            if(strcmp((*Change).OPR1, "BGE") != 0 && strcmp((*Change).OPR1, "BLE") != 0 && strcmp((*Change).OPR1, "BNE") != 0 && strcmp((*Change).OPR1, "BG") != 0 && strcmp((*Change).OPR1, "BE") != 0 && strcmp((*Change).OPR1, "BL") != 0  && strcmp((*Change).OPR1, "BR") != 0){
              (*Change).QN--;
            }else{
              (*Change).QN--;
              if(atoi((*Change).OPR2)>(*Parcourir).QN){
              int n=atoi((*Change).OPR2)-1;
              sprintf((*Change).OPR2,"%d",n);
              }
            }
            Change=(*Change).SVT;
          }
        }else{
          (*Pere).SVT=(*Parcourir).SVT;
          Parcourir=Pere;
          struct  QUAD* Change = (*Parcourir).SVT;
          while(Change!= NULL){
            if(strcmp((*Change).OPR1, "BGE") != 0 && strcmp((*Change).OPR1, "BLE") != 0 && strcmp((*Change).OPR1, "BNE") != 0 && strcmp((*Change).OPR1, "BG") != 0 && strcmp((*Change).OPR1, "BE") != 0 && strcmp((*Change).OPR1, "BL") != 0  && strcmp((*Change).OPR1, "BR") != 0){
              (*Change).QN--;
            }else{
              (*Change).QN--;
              if(atoi((*Change).OPR2)>(*Parcourir).QN){
              int n=atoi((*Change).OPR2)-1;
              sprintf((*Change).OPR2,"%d",n);
              }
            }
            Change=(*Change).SVT;
          }
        }
      }
    }
    Pere = Parcourir;
    Parcourir=(*Parcourir).SVT;
  }
}
/*
/* Generation code objet*/
void Machine(struct QUAD** TeteQ, struct ENTITE** TeteTS){
  FILE* File=NULL;
  File=fopen("CODEMACHINE.txt","w+");
  struct ENTITE* ParcourirTS =*TeteTS;
  struct QUAD* ParcourirQ =*TeteQ;
  fprintf(File, "     DATA SEGMENT \n");
  while (ParcourirTS != NULL){
    if (strcmp((*ParcourirTS).TailleE,'1')!=0){
      fprintf(File, "       %s   DW   %s   DUP ( ? ) \n", (*ParcourirTS).NomE, (*ParcourirTS).TailleE);
    }else{
      if (strcmp((*ParcourirTS).State,"VAR")==0) {
        if (strcmp((*ParcourirTS).TypeE,"Integer")){
          fprintf(File, "      %s   DW   ?\n", (*ParcourirTS).NomE);
        }else {
          fprintf(File, "      %s   DD   ?\n", (*ParcourirTS).NomE);
        }
      }else{
          fprintf(File, "      %s   EQU (Valeur de la constante non recupéré) \n", (*ParcourirTS).NomE);
      }
    }
    ParcourirTS = (*ParcourirTS).SVT;
  }
  fprintf(File, "     DATA ENDS\n");
  fprintf(File,"\n\n");
  fprintf(File, "     PILE SEGMENT STACK\n");
  fprintf(File, "       DW 1000 DUP(?)\n");
  fprintf(File, "       TOS LABEL WORD\n");
  fprintf(File, "     PILE ENDS\n");
  fprintf(File,"\n\n");
  fprintf(File, "     CODE SEGEMENT\n");
  fprintf(File, "        ASSUME CS:CODE, DS:DATA SS:PILE\n");
  fprintf(File, "        PROG_PRINCIPAL :\n");
  fprintf(File, "        MOV AX , DATA\n");
  fprintf(File, "        MOV DS , AX\n");
  fprintf(File, "        MOV AX , PILE\n");
  fprintf(File, "        MOV SS , AX\n");
  fprintf(File, "        MOV SP , OFFSET TOS\n");
  fprintf(File, "        MOV BP , OFFSET TOS\n\n\n\n");
  int Change;
  int num=0;
  while (ParcourirQ != NULL){ 
    fprintf(File,"\n     etiq %d :\n\n",(*ParcourirQ).QN);
    if (strcmp((*ParcourirQ).OPR1, "BGE") != 0 && strcmp((*ParcourirQ).OPR1, "BLE") != 0 && strcmp((*ParcourirQ).OPR1, "BNE") != 0 && strcmp((*ParcourirQ).OPR1, "BG") != 0 && strcmp((*ParcourirQ).OPR1, "BE") != 0 && strcmp((*ParcourirQ).OPR1, "BL") != 0  && strcmp((*ParcourirQ).OPR1, "BR") != 0){ 
      if (strcmp((*ParcourirQ).OPR1, "+") == 0){
        if ((*ParcourirQ).OPR2[0] != 'T' && ((*ParcourirQ).OPR3[0] != 'T')){
            fprintf(File, "        MOV AX , %s\n", (*ParcourirQ).OPR2);
            fprintf(File, "        ADD AX , %s\n", (*ParcourirQ).OPR3);
            fprintf(File, "        PUSH AX \n");
        }else{
          if ((*ParcourirQ).OPR2[0] == 'T' && ((*ParcourirQ).OPR3[0] == 'T')){
            fprintf(File, "        MOV BX , SP\n");
            Change = (*ParcourirQ).OPR2[1]-'0'; 
            Change *= 2;
            fprintf(File, "        MOV SP , BP - %d\n", Change);
            fprintf(File, "        POP AX \n");
            Change = (*ParcourirQ).OPR3[1]-'0';
            Change *= 2;
            fprintf(File, "        MOV SP , BP - %d\n", Change);
            fprintf(File, "        POP DX \n");
            fprintf(File, "        ADD AX , DX \n");
            fprintf(File, "        MOV SP , BX\n");
            fprintf(File, "        PUSH AX \n");
          }else{
            if((*ParcourirQ).OPR2[0] == 'T'){
              fprintf(File, "        MOV BX , SP\n");
              Change = (*ParcourirQ).OPR2[1]-'0';
              Change *= 2;
              fprintf(File, "        MOV SP , BP - %d \n", Change);
              fprintf(File, "        POP AX \n");
              fprintf(File, "        MOV SP , BX\n");
              fprintf(File, "        ADD AX , %s \n",(*ParcourirQ).OPR3);          
              if((strcmp((*ParcourirQ).OPR2,(*ParcourirQ).RESULT)!=0)) {   
                fprintf(File, "        PUSH AX \n");
              }else{
                fprintf(File, "        MOV [ BP - %d ] , AX \n",Change);
              } 
            }
            else{
            fprintf(File, "        MOV AX , %s \n",(*ParcourirQ).OPR2);
            fprintf(File, "        MOV BX , SP\n");
            Change = (*ParcourirQ).OPR3[1]-'0';
            Change *= 2;
            fprintf(File, "        MOV SP , BP - %d \n", Change);
            fprintf(File, "        POP DX \n");
            fprintf(File, "        MOV SP , BX\n");
            fprintf(File, "        ADD AX , DX \n");
            fprintf(File, "        PUSH AX \n");
            }
          }
        }
      }  
      if (strcmp((*ParcourirQ).OPR1, "-") == 0){
        if ((*ParcourirQ).OPR2[0] != 'T' && (*ParcourirQ).OPR3[0] != 'T'){
            fprintf(File, "        MOV AX , %s\n", (*ParcourirQ).OPR2);
            fprintf(File, "        SUB AX , %s\n", (*ParcourirQ).OPR3);
            fprintf(File, "        PUSH AX \n");
        }else{
          if ((*ParcourirQ).OPR2[0] == 'T' && ((*ParcourirQ).OPR3[0] == 'T')){
            fprintf(File, "        MOV BX , SP\n");
            Change =(*ParcourirQ).OPR2[1]-'0';
            Change *= 2;
            fprintf(File, "        MOV SP , BP - %d\n", Change);
            fprintf(File, "        POP AX \n");
            Change =(*ParcourirQ).OPR3[1]-'0';
            Change *= 2;
            fprintf(File, "        MOV SP , BP - %d\n", Change);
            fprintf(File, "        POP DX \n");
            fprintf(File, "        SUB AX , DX \n");
            fprintf(File, "        MOV SP , BX\n");
            fprintf(File, "        PUSH AX \n");
          }else{
            if((*ParcourirQ).OPR2[0] == 'T'){
            fprintf(File, "        MOV BX , SP\n");
            Change =(*ParcourirQ).OPR2[1]-'0';
            Change *= 2;
            fprintf(File, "        MOV SP , BP - %d \n", Change);
            fprintf(File, "        POP AX \n");
            fprintf(File, "        MOV SP , BX\n");
            fprintf(File, "        SUB AX , %s \n",(*ParcourirQ).OPR3);
            fprintf(File, "        PUSH AX \n");
            }else{
            fprintf(File, "        MOV AX , %s \n",(*ParcourirQ).OPR2);
            fprintf(File, "        MOV BX , SP\n");
            Change = (*ParcourirQ).OPR3[1]-'0';
            Change *= 2;
            fprintf(File, "        MOV SP , BP - %d \n", Change);
            fprintf(File, "        POP DX \n");
            fprintf(File, "        MOV SP , BX\n");
            fprintf(File, "        SUB AX , DX \n");
            fprintf(File, "        PUSH AX \n"); 
            }
          }
        }
      } 
      if (strcmp((*ParcourirQ).OPR1, "*") == 0){
        if ((*ParcourirQ).OPR2[0] != 'T' && (*ParcourirQ).OPR3[0] != 'T'){
            fprintf(File, "        MOV  AX , %s\n", (*ParcourirQ).OPR2);
            fprintf(File, "        MULT AX , %s\n", (*ParcourirQ).OPR3);
            fprintf(File, "        PUSH AX \n");
          }
        else{
          if ((*ParcourirQ).OPR2[0] == 'T' && ((*ParcourirQ).OPR3[0] == 'T')){
            fprintf(File, "        MOV BX , SP\n");
            Change = (*ParcourirQ).OPR2[1]-'0';
            Change *= 2;
            fprintf(File, "        MOV SP , BP - %d\n", Change);
            fprintf(File, "        POP AX \n");
            Change =(*ParcourirQ).OPR3[1]-'0';
            Change *= 2;
            fprintf(File, "        MOV SP , BP - %d\n", Change);
            fprintf(File, "        POP DX \n");
            fprintf(File, "        MULT AX , DX \n");
            fprintf(File, "        MOV SP , BX\n");
            fprintf(File, "        PUSH AX \n");
          }else{
            if((*ParcourirQ).OPR2[0] == 'T'){
            fprintf(File, "        MOV BX , SP\n");
            Change =(*ParcourirQ).OPR2[1]-'0';
            Change *= 2;
            fprintf(File, "        MOV SP , BP - %d \n", Change);
            fprintf(File, "        POP AX \n");
            fprintf(File, "        MOV SP , BX\n");
            fprintf(File, "        MULT AX , %s \n",(*ParcourirQ).OPR3);
            fprintf(File, "        PUSH AX \n");
            }
            else{
            fprintf(File, "        MOV AX , %s \n",(*ParcourirQ).OPR2);
            fprintf(File, "        MOV BX , SP\n");
            Change =(*ParcourirQ).OPR3[1]-'0';
            Change *= 2;
            fprintf(File, "        MOV SP , BP - %d \n", Change);
            fprintf(File, "        POP DX \n");
            fprintf(File, "        MOV SP , BX\n");
            fprintf(File, "        MULT AX , DX \n");
            fprintf(File, "        PUSH AX \n");
            }
          }
        }
      }  
      if (strcmp((*ParcourirQ).OPR1, "/") == 0){
        if ((*ParcourirQ).OPR2[0] != 'T' && (*ParcourirQ).OPR3[0] != 'T'){
            fprintf(File, "        MOV AX , %s\n", (*ParcourirQ).OPR2);
            fprintf(File, "        DIV AX , %s\n", (*ParcourirQ).OPR3);
            fprintf(File, "        PUSH AX \n");
          }else{
            if ((*ParcourirQ).OPR2[0] == 'T' && ((*ParcourirQ).OPR3[0] == 'T')){
              fprintf(File, "        MOV BX , SP\n");
              Change = (*ParcourirQ).OPR2[1]-'0';
              Change *= 2;
              fprintf(File, "        MOV SP , BP - %d\n", Change);
              fprintf(File, "        POP AX \n");
              Change = (*ParcourirQ).OPR3[1]-'0';
              Change *= 2;
              fprintf(File, "        MOV SP , BP - %d\n", Change);
              fprintf(File, "        POP DX \n");
              fprintf(File, "        DIV AX , DX \n");
              fprintf(File, "        MOV SP , BX\n");
              fprintf(File, "        PUSH AX \n");
            }else {
              if((*ParcourirQ).OPR2[0] == 'T'){
              fprintf(File, "        MOV BX , SP\n");
              Change = (*ParcourirQ).OPR2[1]-'0';
              Change *= 2;
              fprintf(File, "        MOV SP , BP - %d \n", Change);
              fprintf(File, "        POP AX \n");
              fprintf(File, "        MOV SP , BX\n");
              fprintf(File, "        DIV AX , %s \n",(*ParcourirQ).OPR3);
              fprintf(File, "        PUSH AX \n");
              }else{
                fprintf(File, "        MOV AX , %s \n",(*ParcourirQ).OPR2);
                fprintf(File, "        MOV BX , SP\n");
                Change = (*ParcourirQ).OPR3[1]-'0';
                Change *= 2;
                fprintf(File, "        MOV SP , BP - %d \n", Change);
                fprintf(File, "        POP DX \n");
                fprintf(File, "        MOV SP , BX\n");
                fprintf(File, "        DIV AX , DX \n");
                fprintf(File, "        PUSH AX \n");
              }
            }
          } 
        } 
      }else{
        if(strcmp((*ParcourirQ).OPR1,"BR")==0){
          fprintf(File,"       JMP etiq %s \n",(*ParcourirQ).OPR2); 
        }else{
          if(strcmp((*ParcourirQ).OPR1,"BNE")==0){
            if ((*ParcourirQ).RESULT[0] != 'T' && (*ParcourirQ).OPR3[0] != 'T'){
              fprintf(File,"       CMP %s , %s \n",(*ParcourirQ).OPR3,(*ParcourirQ).RESULT);
              fprintf(File,"       JNE etiq %s \n",(*ParcourirQ).OPR2);
             }else{
                if ((*ParcourirQ).RESULT[0] == 'T' && ((*ParcourirQ).OPR3[0] == 'T')){
                  fprintf(File, "        MOV BX , SP\n");
                  Change = (*ParcourirQ).OPR3[1]-'0';
                  Change *= 2;
                  fprintf(File, "       MOV SP , BP - %d\n", Change);
                  fprintf(File, "       POP AX \n");
                  Change = (*ParcourirQ).RESULT[1]-'0';
                  Change *= 2;
                  fprintf(File, "       MOV SP , BP - %d\n", Change);
                  fprintf(File, "       POP DX \n");
                  fprintf(File, "       MOV SP , BX\n");
                  fprintf(File, "       CMP AX , DX \n");
                  fprintf(File,"       JNE etiq %s \n",(*ParcourirQ).OPR2);
               }else{
                  if((*ParcourirQ).OPR3[0] == 'T'){
                    fprintf(File, "       MOV BX , SP\n");
                    Change = (*ParcourirQ).OPR3[1]-'0';
                    Change *= 2;
                    fprintf(File, "       MOV SP , BP - %d \n", Change);
                    fprintf(File, "       POP AX \n");
                    fprintf(File, "       MOV SP , BX\n");
                    fprintf(File, "       CMP AX , %s \n",(*ParcourirQ).RESULT);
                    fprintf(File,"       JNE etiq %s \n",(*ParcourirQ).OPR2);
                  }else{
                    fprintf(File, "       MOV BX , SP\n");
                    Change = (*ParcourirQ).RESULT[1]-'0';
                    Change *= 2;
                    fprintf(File, "       MOV SP , BP - %d \n", Change);
                    fprintf(File, "       POP DX \n");
                    fprintf(File, "       MOV SP , BX\n");
                    fprintf(File, "       MOV AX , %s \n",(*ParcourirQ).OPR3);
                    fprintf(File, "       CMP AX , DX \n");
                    fprintf(File,"       JNE etiq %s \n",(*ParcourirQ).OPR2);
                  }
                }
              } 
            }
            if(strcmp((*ParcourirQ).OPR1,"BE")==0){
              if ((*ParcourirQ).RESULT[0] != 'T' && (*ParcourirQ).OPR3[0] != 'T')       {
                fprintf(File,"       CMP %s , %s \n",(*ParcourirQ).OPR3,(*ParcourirQ).RESULT);
                fprintf(File,"       JE etiq %s \n",(*ParcourirQ).OPR2);
              }else{
                if ((*ParcourirQ).RESULT[0] == 'T' && ((*ParcourirQ).OPR3[0] == 'T')){
                  fprintf(File, "       MOV BX , SP\n");
                  Change = (*ParcourirQ).OPR3[1]-'0';
                  Change *= 2;
                  fprintf(File, "       MOV SP , BP - %d\n", Change);
                  fprintf(File, "       POP AX \n");
                  Change = (*ParcourirQ).RESULT[1]-'0';
                  Change *= 2;
                  fprintf(File, "       MOV SP , BP - %d\n", Change);
                  fprintf(File, "       POP DX \n");
                  fprintf(File, "       MOV SP , BX\n");
                  fprintf(File, "       CMP AX , DX \n");
                  fprintf(File,"       JE etiq %s \n",(*ParcourirQ).OPR2);
                }else{
                  if((*ParcourirQ).OPR3[0] == 'T'){
                    fprintf(File, "       MOV BX , SP\n");
                    Change = (*ParcourirQ).OPR3[1]-'0';
                    Change *= 2;
                    fprintf(File, "       MOV SP , BP - %d \n", Change);
                    fprintf(File, "       POP AX \n");
                    fprintf(File, "       MOV SP , BX\n");
                    fprintf(File, "       CMP AX , %s \n",(*ParcourirQ).RESULT);
                    fprintf(File,"       JE etiq %s \n",(*ParcourirQ).OPR2);
                  }else{
                    fprintf(File, "       MOV BX , SP\n");
                    Change = (*ParcourirQ).RESULT[1]-'0';
                    Change *= 2;
                    fprintf(File, "       MOV SP , BP - %d \n", Change);
                    fprintf(File, "       POP DX \n");
                    fprintf(File, "       MOV SP , BX\n");
                    fprintf(File, "       MOV AX , %s \n",(*ParcourirQ).OPR3);
                    fprintf(File, "       CMP AX , DX \n");
                    fprintf(File,"       JE etiq %s \n",(*ParcourirQ).OPR2);
                  }
                }  
              } 
            }
            if(strcmp((*ParcourirQ).OPR1,"BGE")==0){
            if ((*ParcourirQ).RESULT[0] != 'T' && (*ParcourirQ).OPR3[0] != 'T'){
              fprintf(File,"       CMP %s , %s \n",(*ParcourirQ).OPR3,(*ParcourirQ).RESULT);
              fprintf(File,"       JGE etiq %s \n",(*ParcourirQ).OPR2);
            }else{
              if ((*ParcourirQ).RESULT[0] == 'T' && ((*ParcourirQ).OPR3[0] == 'T')){
                fprintf(File, "       MOV BX , SP\n");
                Change = (*ParcourirQ).OPR3[1]-'0';
                Change *= 2;
                fprintf(File, "       MOV SP , BP - %d\n", Change);
                fprintf(File, "       POP AX \n");
                Change = (*ParcourirQ).RESULT[1]-'0';
                Change *= 2;
                fprintf(File, "       MOV SP , BP - %d\n", Change);
                fprintf(File, "       POP DX \n");
                fprintf(File, "       MOV SP , BX\n");
                fprintf(File, "       CMP AX , DX \n");
                fprintf(File,"       JGE etiq %s \n",(*ParcourirQ).OPR2);
              }else{
                if((*ParcourirQ).OPR3[0] == 'T'){
                  fprintf(File, "       MOV BX , SP\n");
                  Change = (*ParcourirQ).OPR3[1]-'0';
                  Change *= 2;
                  fprintf(File, "       MOV SP , BP - %d \n", Change);
                  fprintf(File, "       POP AX \n");
                  fprintf(File, "       MOV SP , BX\n");
                  fprintf(File, "       CMP AX , %s \n",(*ParcourirQ).RESULT);
                  fprintf(File,"       JGE etiq %s \n",(*ParcourirQ).OPR2);
                }else{
                  fprintf(File, "       MOV BX , SP\n");
                  Change = (*ParcourirQ).RESULT[1]-'0';
                  Change *= 2;
                  fprintf(File, "       MOV SP , BP - %d \n", Change);
                  fprintf(File, "       POP DX \n");
                  fprintf(File, "       MOV SP , BX\n");
                  fprintf(File, "       MOV AX , %s \n",(*ParcourirQ).OPR3);
                  fprintf(File, "       CMP AX , DX \n");
                  fprintf(File,"       JGE etiq %s \n",(*ParcourirQ).OPR2);
                }
              }
            }  
          }
          if(strcmp((*ParcourirQ).OPR1,"BG")==0){
            if ((*ParcourirQ).RESULT[0] != 'T' && (*ParcourirQ).OPR3[0] != 'T'){
              fprintf(File,"       CMP %s , %s \n",(*ParcourirQ).OPR3,(*ParcourirQ).RESULT);
              fprintf(File,"       JG etiq %s \n",(*ParcourirQ).OPR2);
            }else{
              if ((*ParcourirQ).RESULT[0] == 'T' && ((*ParcourirQ).OPR3[0] == 'T')){
                fprintf(File, "       MOV BX , SP\n");
                Change = (*ParcourirQ).OPR3[1]-'0';
                Change *= 2;
                fprintf(File, "       MOV SP , BP - %d\n", Change);
                fprintf(File, "       POP AX \n");
                Change = (*ParcourirQ).RESULT[1]-'0';
                Change *= 2;
                fprintf(File, "       MOV SP , BP - %d\n", Change);
                fprintf(File, "       POP DX \n");
                fprintf(File, "       MOV SP , BX\n");
                fprintf(File, "       CMP AX , DX \n");
                fprintf(File,"       JG etiq %s \n",(*ParcourirQ).OPR2);
              }else{
                if((*ParcourirQ).OPR3[0] == 'T'){
                  fprintf(File, "       MOV BX , SP\n");
                  Change = (*ParcourirQ).OPR3[1]-'0';
                  Change *= 2;
                  fprintf(File, "       MOV SP , BP - %d \n", Change);
                  fprintf(File, "       POP AX \n");
                  fprintf(File, "       MOV SP , BX\n");
                  fprintf(File, "       CMP AX , %s \n",(*ParcourirQ).RESULT);
                  fprintf(File,"       JG etiq %s \n",(*ParcourirQ).OPR2);
                  }else{
                    fprintf(File, "       MOV BX , SP\n");
                    Change = (*ParcourirQ).RESULT[1]-'0';
                    Change *= 2;
                    fprintf(File, "       MOV SP , BP - %d \n", Change);
                    fprintf(File, "       POP DX \n");
                    fprintf(File, "       MOV SP , BX\n");
                    fprintf(File, "       MOV AX , %s \n",(*ParcourirQ).OPR3);
                    fprintf(File, "       CMP AX , DX \n");
                    fprintf(File,"       JG etiq %s \n",(*ParcourirQ).OPR2);
                  }
                }
              } 
            }
            if(strcmp((*ParcourirQ).OPR1,"BLE")==0){
              if ((*ParcourirQ).RESULT[0] != 'T' && (*ParcourirQ).OPR3[0] != 'T'){
                fprintf(File,"       CMP %s , %s \n",(*ParcourirQ).OPR3,(*ParcourirQ).RESULT);
                fprintf(File,"       JLE etiq %s \n",(*ParcourirQ).OPR2);
              }else{
                if ((*ParcourirQ).RESULT[0] == 'T' && ((*ParcourirQ).OPR3[0] == 'T')){
                  fprintf(File, "       MOV BX , SP\n");
                  Change = (*ParcourirQ).OPR3[1]-'0';
                  Change *= 2;
                  fprintf(File, "       MOV SP , BP - %d\n", Change);
                  fprintf(File, "       POP AX \n");
                  Change = (*ParcourirQ).RESULT[1]-'0';
                  Change *= 2;
                  fprintf(File, "       MOV SP , BP - %d\n", Change);
                  fprintf(File, "       POP DX \n");
                  fprintf(File, "       MOV SP , BX\n");
                  fprintf(File, "       CMP AX , DX \n");
                  fprintf(File,"       JLE etiq %s \n",(*ParcourirQ).OPR2);
                }else{
                  if((*ParcourirQ).OPR3[0] == 'T'){
                    fprintf(File, "       MOV BX , SP\n");
                    Change = (*ParcourirQ).OPR3[1]-'0';
                    Change *= 2;
                    fprintf(File, "       MOV SP , BP - %d \n", Change);
                    fprintf(File, "       POP AX \n");
                    fprintf(File, "       MOV SP , BX\n");
                    fprintf(File, "       CMP AX , %s \n",(*ParcourirQ).RESULT);
                    fprintf(File,"       JLE etiq %s \n",(*ParcourirQ).OPR2);
                  }else{
                    fprintf(File, "       MOV BX , SP\n");
                    Change = (*ParcourirQ).RESULT[1]-'0';
                    Change *= 2;
                    fprintf(File, "       MOV SP , BP - %d \n", Change);
                    fprintf(File, "       POP DX \n");
                    fprintf(File, "       MOV SP , BX\n");
                    fprintf(File, "       MOV AX , %s \n",(*ParcourirQ).OPR3);
                    fprintf(File, "       CMP AX , DX \n");
                    fprintf(File,"       JLE etiq %s \n",(*ParcourirQ).OPR2);
                  }
                }
              } 
            }
            if(strcmp((*ParcourirQ).OPR1,"BL")==0){
              if ((*ParcourirQ).RESULT[0] != 'T' && (*ParcourirQ).OPR3[0] != 'T')       {
                fprintf(File,"       CMP %s , %s \n",(*ParcourirQ).OPR3,(*ParcourirQ).RESULT);
                fprintf(File,"       JL etiq %s \n",(*ParcourirQ).OPR2);
              }else{
                if ((*ParcourirQ).RESULT[0] == 'T' && ((*ParcourirQ).OPR3[0] == 'T')){
                  fprintf(File, "       MOV BX , SP\n");
                  Change = (*ParcourirQ).OPR3[1]-'0';
                  Change *= 2;
                  fprintf(File, "       MOV SP , BP - %d\n", Change);
                  fprintf(File, "       POP AX \n");
                  Change = (*ParcourirQ).RESULT[1]-'0';
                  Change *= 2;
                  fprintf(File, "       MOV SP , BP - %d\n", Change);
                  fprintf(File, "       POP DX \n");
                  fprintf(File, "       MOV SP , BX\n");
                  fprintf(File, "       CMP AX , DX \n");
                  fprintf(File,"       JL etiq %s \n",(*ParcourirQ).OPR2);
               }else{
                  if((*ParcourirQ).OPR3[0] == 'T'){
                    fprintf(File, "       MOV BX , SP\n");
                    Change = (*ParcourirQ).OPR3[1]-'0';
                    Change *= 2;
                    fprintf(File, "       MOV SP , BP - %d \n", Change);
                    fprintf(File, "       POP AX \n");
                    fprintf(File, "       MOV SP , BX\n");
                    fprintf(File, "       CMP AX , %s \n",(*ParcourirQ).RESULT);
                    fprintf(File,"       JL etiq %s \n",(*ParcourirQ).OPR2);
                  }else{
                    fprintf(File, "       MOV BX , SP\n");
                    Change = (*ParcourirQ).RESULT[1]-'0';
                    Change *= 2;
                    fprintf(File, "       MOV SP , BP - %d \n", Change);
                    fprintf(File, "       POP DX \n");
                    fprintf(File, "       MOV SP , BX\n");
                    fprintf(File, "       MOV AX , %s \n",(*ParcourirQ).OPR3);
                    fprintf(File, "       CMP AX , DX \n");
                    fprintf(File,"       JL etiq %s \n",(*ParcourirQ).OPR2);
                  }
                }
              } 
            }
          }    
        } 
        num=(*ParcourirQ).QN;
        ParcourirQ = (*ParcourirQ).SVT;
      } 
        fprintf(File, "\n     etiq %d:\n\n",num+1);
        fprintf(File, "       MOV AH,4CH\n");
        fprintf(File, "       INT 21h\n");
        fprintf(File, "       CODE ENDS\n");
        fprintf(File, "       END PROG_PRINCIPAL\n");
        fclose(File);
    }
*/