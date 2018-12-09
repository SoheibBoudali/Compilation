%{
#include<stdio.h>
extern FILE* yyin;
extern int NL,NC;
#include"TableS.h"
#include"Quad.c"
#include"Pile.c"
struct ENTITE *TS;
struct  BIB *TB;
char Type[10]="";
struct QUAD *Q=NULL;
int num=1;
int temp=1;
char * tempc;
struct PILE *Pile;
%}
%union
{
char *chaine;
int entier;
float reel;
struct s {char * val; char * type;}s;
}
%token '{' '}' '(' ')' ':' ';' ',' '+' '*' '-' '/' '[' ']' 
%token Programme While EXECUT IF Real Integer BOUCLE TAB Calcul CONST EGAL SEP 
%token <chaine> IDF
%token <chaine> OPR
%token <entier> ENTIER
%token <reel> REEL
%type <s> IDFA EXP EXPPRIO AFF
%%

Start : Bibliotheque Programme IDF '{' DECLARATION  INSTRUCTION '}' {printf("Programme  syntaxiquement correct\n");ShowQ(&Q);};

Bibliotheque : Bib Bibliotheque 
            |  Bib 
;

Bib : Calcul  { if(SearchB(&TB,"Calcul")){printf("Erreur a la ligne %d : Bibliotheque  Calcul déja declarée  \n", NL); 
                }else
                InsertBib(&TB,"Calcul",NL);   
              }
     | TAB    { if(SearchB(&TB,"TAB")) {printf("Erreur a la ligne %d : Bibliotheque TAB déja declarée \n",NL); 
                }else
                InsertBib(&TB,"TAB",NL);   
              }
     | BOUCLE { if(SearchB(&TB,"BOUCLE")) {printf("Erreur a la ligne %d : Bibliotheque BOUCLE déja declarée \n",NL);
                }else
                InsertBib(&TB,"BOUCLE",NL);
              }
;

DECLARATION : TYPE  Val DECLARATION
  | TYPE  Val
;

Val : DecVar
  | DecTab  { if(!SearchB(&TB,"TAB")) printf("Erreur a la ligne %d : Bibliothéque TAB non Déclarée!\n",NL); };
  | CONST DecConst
;

DecVar: IDF SEP DecVar  { if(!Search(&TS,$1)) Insert(&TS,$1,Type,1,"VAR",NL); 
                          else{ 
                            if(GetLine(&TS,$1)==NL) printf("Erreur a la ligne %d : Double declaration d'IDF dans la meme ligne %d \n",NL,NL);
                            else printf("Erreur a la ligne %d : IDF deja declaré a la ligne %d \n",NL,GetLine(&TS,$1));
                          }
                        }      
       | IDF ';'  { if(!Search(&TS,$1)) Insert(&TS,$1,Type,1,"VAR",NL); 
                      else{ 
                        if(GetLine(&TS,$1)==NL) printf("Erreur a la ligne %d : Double declaration d'IDF dans la meme ligne %d \n",NL,NL);
                        else printf("Erreur a la ligne %d : IDF deja declaré a la ligne %d \n",NL,GetLine(&TS,$1));
                      }
                  }       
;
 
DecConst: IDF SEP DecConst  { if(!Search(&TS,$1)) Insert(&TS,$1,Type,1,"CONST",NL);
                              else{
                                if(GetLine(&TS,$1)==NL) printf("Erreur a la ligne %d : Double declaration de la Constate dans la meme ligne %d \n",NL,NL);
                                else printf("Erreur a la ligne %d : Constate deja definie a la ligne %d \n",NL,GetLine(&TS,$1));
                              }
                            }
        | IDF ';' { if(!Search(&TS,$1)) Insert(&TS,$1,Type,1,"CONST",NL);
                    else{
                      if(GetLine(&TS,$1)==NL) printf("Erreur a la ligne %d : Double declaration de la Constate dans la meme ligne %d \n",NL,NL);
                      else printf("Erreur a la ligne %d : Constate deja definiea la ligne %d \n",NL,GetLine(&TS,$1));
                    }
                  }      
;

DecTab: IDF '[' ENTIER ']' ';'  { if(!Search(&TS,$1)) Insert(&TS,$1,Type,$3,"TAB",NL);
                                  else{
                                    if(GetLine(&TS,$1)==NL) printf("Erreur a la ligne %d : Double declaration du tableau dans la meme ligne %d \n",NL,NL);
                                    else  printf("Erreur a la ligne %d : Tableau deja declaré\n",NL);
                                  }
                                }    
;

TYPE: Real  {strcpy(Type,"Real");}
    | Integer {strcpy(Type,"Integer");}
;

INSTRUCTION: TypeInstruction INSTRUCTION
    |TypeInstruction
;

TypeInstruction: LOOP { if(!SearchB(&TB,"BOUCLE")) printf("Erreur a la ligne %d : Bibliothéque BOUCLE non Déclarée!\n",NL);} 
                | CONDITION 
                | AFFECTATION { if(!SearchB(&TB,"Calcul")) printf("Erreur a la ligne %d : Bibliothéque Calcul non Déclarée!\n",NL);}
;

AFFECTATION : IDFA EGAL EXP ';' { if(strcmp($1.type,$3.type)!=0){
                                    printf("Erreur d'incompatibilité de type a la ligne %d\n",NL);
                                  }
                                  InsertQ(&Q,"=",$3.val,"",$1.val,num);
                                  num++;
                                }
;

EXP : EXP  '+'  EXPPRIO { char tempc[100];
                          sprintf(tempc,"T%d",temp);
                          temp++;
                          InsertQ(&Q,"+",$1.val,$3.val,tempc,num);

                          num++;
                          strcpy($$.val,tempc);

                          if(strcmp($1.type,$3.type)!=0){
                            printf("Erreur d'incompatibilité de type a la ligne %d\n",NL);
                          }                                                                              

                        }
     | EXP '-' EXPPRIO {  char* tempc=malloc(sizeof(10));   
                          sprintf(tempc,"T%d",temp);
                          temp++; 
                          InsertQ(&Q,"-",$1.val,$3.val,tempc,num);
                          num++;  
                          strcpy($$.val,tempc);
                          if(strcmp($1.type,$3.type)!=0){
                            printf("Erreur d'incompatibilité de type a la ligne %d\n",NL);
                          }
                        }
     | EXPPRIO {  
      $$.type=malloc(20*sizeof(char));
                $$.val=malloc(20*sizeof(char));

                strcpy($$.type,$1.type); 
                strcpy($$.val,$1.val);
              }
;

EXPPRIO : EXPPRIO '*' AFF { char* tempc=malloc(sizeof(10));   
                            sprintf(tempc,"T%d",temp);
                            temp++; 
                            InsertQ(&Q,"*",$1.val,$3.val,tempc,num);
                            num++;  
                            strcpy($$.val,tempc);
                            if(strcmp($1.type,$3.type)!=0){
                            printf("Erreur d'incompatibilité de type a la ligne %d\n",NL);
                            }
                          }
        | EXPPRIO '/' AFF { char* tempc=malloc(sizeof(10));   
                            sprintf(tempc,"T%d",temp);
                            temp++; 
                            InsertQ(&Q,"/",$1.val,$3.val,tempc,num);
                            num++;  
                            strcpy($$.val,tempc);
                            if(strcmp($1.type,$3.type)!=0){
                              printf("Erreur d'incompatibilité de type a la ligne %d\n",NL);
                            }
                          } 
        | AFF { $$.type=strdup($1.type);
                $$.val=strdup($1.val);
              }
;

AFF : IDF {  if(!Search(&TS,$1))  {                           
printf("Erreur a la ligne %d : IDF non declaré3\n " ,NL); }
            else{
              $$.type=malloc(20*sizeof(char));
              strcpy($$.type,GetType(&TS,$1)); 
              $$.val=malloc(20*sizeof(char));
              sprintf($$.val,"%s",$1);
            }
          } 
    | IDF '['ENTIER']' { if(!Search(&TS,$1)) {
                            printf("Erreur a la ligne %d :IDF non declaré4\n",NL);
                          }else{
                            if(!CheckTab(&TS,$1)) printf("Erreur a la ligne %d : IDF n'est pas un tableau\n",NL);
                          }
                          if($3>CheckTabSize(&TS,$1)) printf("Erreur a la ligne %d : Debordement \n",NL);
                          $$.type=malloc(20*sizeof(char));
                          strcpy($$.type,GetType(&TS,$1)); 
                          $$.val=malloc(20*sizeof(char));
                          sprintf($$.val,"%s [ %d ]",$1,$3);
                        } 
    | ENTIER {$$.type=malloc(20*sizeof(char));
              strcpy($$.type,"Integer"); 
              $$.val=malloc(20*sizeof(char));
              sprintf($$.val,"%d",$1);  
              }
    | REEL  { $$.type=malloc(20*sizeof(char));
              strcpy($$.type,"Real"); 
              $$.val=malloc(20*sizeof(char));
              sprintf($$.val,"%f",$1);  
            }
;

IDFA: IDF { if(!Search(&TS,$1)) printf("Erreur a la ligne %d : IDF non declaré1\n",NL); 
            else{
              $$.type=malloc(20*sizeof(char));
              strcpy($$.type,GetType(&TS,$1)); 
              $$.val=malloc(20*sizeof(char));
              sprintf($$.val,"%s",$1);
            }
          } 
    | IDF '['ENTIER']'  { if($3>CheckTabSize(&TS,$1)) printf("Erreur a la ligne %d : Debordement \n",NL);
                          if(!Search(&TS,$1)) {
                            printf("Erreur a la ligne %d : IDF non declaré2\n",NL);
                          }else{
                            if(!CheckTab(&TS,$1)) printf("Erreur a la ligne %d : IDF n'est pas un tableau\n" , NL);
                          }
                          $$.type=malloc(20*sizeof(char));
                          strcpy($$.type,GetType(&TS,$1)); 
                          $$.val=malloc(20*sizeof(char));
                          sprintf($$.val,"%s [ %d ]",$1,$3);
                        }
;
LOOP: A '{' INSTRUCTION '}' { 
                              int x=PULL(&Pile);
                              char *tempc;
                              tempc=malloc(20*sizeof(char));
                              sprintf(tempc,"%d",x);
                              InsertQ(&Q,"BR",tempc,"","",num);
                              num++;
                              MAJQ(&Q,x,num);
                              }
;
A : While '('  EXP OPR EXP ')' {PUSH(&Pile,num);
                                if(strcmp($4,"<")==0){
                                InsertQ(&Q,"BGE","",$3.val,$5.val,num);
                                num++;
                                }
                                if(strcmp($4,"==")==0) {
                                  InsertQ(&Q,"BNE","",$3.val,$5.val,num);
                                  num++;
                                }
                                if(strcmp($4,"!=")==0) {
                                  InsertQ(&Q,"BE","",$3.val,$5.val,num);  
                                  num++;
                                }
                                if(strcmp($4,">")==0){
                                  InsertQ(&Q,"BLE","",$3.val,$5.val,num); 
                                  num++;

                                }
                                if(strcmp($4,"<=")==0){
                                  InsertQ(&Q,"BG","",$3.val,$5.val,num);
                                  num++;
                                }
                                if(strcmp($4,">=")==0){
                                  InsertQ(&Q,"BL","",$3.val,$5.val,num);
                                  num++;
                                }
                              }
;
CONDITION: execut condition
;
execut : EXECUT { InsertQ(&Q,"BR","","","",num);
                  PUSH(&Pile,num);
                  num++;
                  PUSH(&Pile,num);
                }
;
condition : CondInst IF '(' EXP OPR EXP ')' {  MAJQ(&Q,PULL(&Pile),num+1);
                                                int x;
                                                x=PULL(&Pile);
                                                char *tempc;
                                                tempc=malloc(20*sizeof(char));
                                                sprintf(tempc,"%d",x);   
                                                if(strcmp($5,"<")==0) {
                                                  InsertQ(&Q,"BL",tempc,$4.val,$6.val,num);
                                                  MAJQ(&Q,PULL(&Pile),num);num++;
                                                }
                                                if(strcmp($5,"==")==0) {
                                                  InsertQ(&Q,"BE",tempc,$4.val,$6.val,num);
                                                  MAJQ(&Q,PULL(&Pile),num);num++;
                                                }
                                                if(strcmp($5,"!=")==0) {
                                                  InsertQ(&Q,"BNE",tempc,$4.val,$6.val,num);  
                                                  MAJQ(&Q,PULL(&Pile),num);num++;
                                                }
                                                if(strcmp($5,">")==0){
                                                  InsertQ(&Q,"BG",tempc,$4.val,$6.val,num); 
                                                  MAJQ(&Q,PULL(&Pile),num);num++;
                                                }
                                                if(strcmp($5,"<=")==0){
                                                  InsertQ(&Q,"BNE",tempc,$4.val,$6.val,num);
                                                  MAJQ(&Q,PULL(&Pile),num);num++;
                                                }
                                                if(strcmp($5,">=")==0){
                                                  InsertQ(&Q,"BGE",tempc,$4.val,$6.val,num);
                                                  MAJQ(&Q,PULL(&Pile),num);num++;
                                                }
                                              } 
;
CondInst:INSTRUCTION { InsertQ(&Q,"BR","","","",num);
                        PUSH(&Pile,num);
                        num++;
                      } 
;
%%
int yyerror(char* msg)
{
printf("Erreur syntaxique a la ligne %d colonne %d\n",NL,NC);
return 1;
}
int main()
{
yyin=fopen("Test.txt","r");
yyparse();
Show(&TS);
ShowB(&TB);
return 0;
}