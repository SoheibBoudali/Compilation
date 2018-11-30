%{
#include<stdio.h>
extern FILE* yyin;
extern int NL,NC;
#include"TableS.h"
struct ENTITE *TS;
struct  BIB *TB;
char Type[10]="";
char CurrentType[10]="";
%}
%union
{
char *chaine;
int entier;
float reel;
}
%token '{' '}' '(' ')' ':' ';' ',' '+' '*' '-' '/' '[' ']' 
%token Programme While EXECUT IF Real Integer BOUCLE TAB Calcul CONST EGAL SEP 
%token <chaine> IDF
%token <chaine> OPR
%token <entier> ENTIER
%token <reel> REEL
%%

Start : Bibliotheque Programme IDF '{' DECLARATION  INSTRUCTION '}' {printf("Programme  syntaxiquement correct\n");};

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

AFFECTATION : IDFA EGAL EXP ';' {strcpy(CurrentType,"");} 
;

EXP : EXP '+' EXPPRIO 
     | EXP '-' EXPPRIO 
     | EXPPRIO 
;

EXPPRIO : EXPPRIO '*' AFF  
        | EXPPRIO '/' AFF 
        | AFF
;

AFF : IDF { if(!Search(&TS,$1)) printf("Erreur a la ligne %d : IDF non declaré\n " ,NL); 
            if(strcmp(CurrentType,"")!=0){
              if(strcmp(CurrentType,GetType(&TS,$1))!=0) {printf("Erreur a la ligne %d : Incompatibilité de type \n",NL);}
            }else{
              strcpy(CurrentType,GetType(&TS,$1));
            } 
          } 
    | IDF '['ENTIER']' { if(!Search(&TS,$1)) {
                            printf("Erreur a la ligne %d :IDF non declaré\n",NL);
                          }else{
                            if(!CheckTab(&TS,$1)) printf("Erreur a la ligne %d : IDF n'est pas un tableau\n",NL);
                          }
                          if($3>CheckTabSize(&TS,$1)) printf("Erreur a la ligne %d : Debordement \n",NL);
                          if(strcmp(CurrentType,"")!=0){
                            if(strcmp(CurrentType,GetType(&TS,$1))!=0) printf("Erreur a la ligne %d : Incompatibilité de type \n",NL);
                          }else{
                            strcpy(CurrentType,GetType(&TS,$1));
                          }
                        } 
    | ENTIER { if(strcmp(CurrentType,"")!=0) {
                  if(strcmp(CurrentType,"Integer")!=0) {printf("Erreur a la ligne %d : Incompatibilité de type \n",NL);}
                }else{
                  strcpy(CurrentType,"Integer");
                }  
              }
    | REEL  { if(strcmp(CurrentType,"")!=0) {
                if(strcmp(CurrentType,"Real")!=0) {printf("Erreur a la ligne %d : Incompatibilité de type \n",NL);}
                }else{
                  strcpy(CurrentType,"Real");
              }  
            }
;

IDFA: IDF { strcpy(CurrentType,GetType(&TS,$1));  
            if(!Search(&TS,$1)) printf("Erreur a la ligne %d : IDF non declaré\n",NL); 
          } 
    | IDF '['ENTIER']'  { strcpy(CurrentType,GetType(&TS,$1)); 
                          if($3>CheckTabSize(&TS,$1)) printf("Erreur a la ligne %d : Debordement \n",NL);
                          if(!Search(&TS,$1)) {
                            printf("Erreur a la ligne %d : IDF non declaré\n",NL);
                          }else{
                            if(!CheckTab(&TS,$1)) printf("Erreur a la ligne %d : IDF n'est pas un tableau\n" , NL);
                          }
                        }
;

LOOP: While '(' EXP OPR EXP ')' '{' INSTRUCTION '}'
    | While '(' EXP ')' '{' INSTRUCTION '}'
;

CONDITION: EXECUT INSTRUCTION IF '(' EXP OPR EXP ')' 
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
