%{
#include<stdio.h>
extern FILE* yyin;
extern int nbl,nbc;
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

Bib : Calcul {if(SearchB(&TB,"Calcul")){printf("Bibliotheque  Calcul déja declarée \n"); return 0;}  
              else
                InsertBib(&TB,"Calcul");   
}
     | TAB   {if(SearchB(&TB,"TAB")) {printf("Bibliotheque TAB déja declarée \n"); return 0;}
              else
                InsertBib(&TB,"TAB");   
}
     | BOUCLE {if(SearchB(&TB,"BOUCLE")) {printf("Bibliotheque BOUCLE déja declarée \n"); return 0;}
              else
                InsertBib(&TB,"BOUCLE");   
}
;

DECLARATION : TYPE  Val DECLARATION
  | TYPE  Val
;

Val : DecVar
  | DecTab {if(!SearchB(&TB,"TAB")){ printf("Erreur ===> Bibliothéque TAB non Déclarée!\n"); return 0;} };
  | CONST DecConst
;

DecVar: IDF SEP DecVar
 {if(!Search(&TS,$1)) Insert(&TS,$1,Type,1,"VAR"); else printf("IDF deja declaré ailleur\n");}      
       | IDF ';'
 {if(!Search(&TS,$1)) Insert(&TS,$1,Type,1,"VAR"); else printf("IDF deja declaré ailleur\n");}       
;

DecConst: IDF SEP DecConst  
{if(!Search(&TS,$1)) Insert(&TS,$1,Type,1,"CONST");else { printf("Constate deja definie\n");}}
        | IDF ';'
{if(!Search(&TS,$1)) Insert(&TS,$1,Type,1,"CONST");else { printf("Constate deja definie\n");}}      
;

DecTab: IDF '[' ENTIER ']' ';' 
{if(!Search(&TS,$1)) Insert(&TS,$1,"Integer",$3,"TAB");else { printf("tableau deja declaré\n");}}    
;

TYPE: Real  {strcpy(Type,"Real");}
      | Integer {strcpy(Type,"Integer");}
;

INSTRUCTION: TypeInstruction INSTRUCTION
    |TypeInstruction
;

TypeInstruction: LOOP {if(!SearchB(&TB,"BOUCLE")){ printf("Erreur ===> Bibliothéque BOUCLE non Déclarée!\n"); return 0;} };
                | CONDITION 
                | AFFECTATION {if(!SearchB(&TB,"Calcul")){ printf("Erreur ===> Bibliothéque Calcul non Déclarée!\n"); return 0;} };
;

AFFECTATION : IDFA EGAL EXP ';' 
;

EXP : EXP '+' EXPPRIO 
     | EXP '-' EXPPRIO 
     | EXPPRIO 
;

EXPPRIO :  EXPPRIO '*' AFF  
     | EXPPRIO '/' AFF 
     | AFF
;

AFF : IDF {if(!Search(&TS,$1)) printf("IDF non declaré\n"); if(strcmp(CurrentType,GetType(&TS,$1))!=0) printf("Erreur Incompatibilité de type \n");} 
     | IDF '['ENTIER']' {if(!Search(&TS,$1)) printf("IDF non declaré\n"); if(strcmp(CurrentType,GetType(&TS,$1))!=0) printf("Erreur Incompatibilité de type \n");} 
     | ENTIER {if(strcmp(CurrentType,"Integer")!=0) printf("Erreur Incompatibilité de type \n");} 
     | REEL  {if(strcmp(CurrentType,"Real")!=0) printf("Erreur Incompatibilité de type \n");}
;

IDFA: IDF {  strcpy(CurrentType,GetType(&TS,$1));  if(!Search(&TS,$1)) printf("IDF non declaré\n"); } 
    | IDF '['ENTIER']' {  strcpy(CurrentType,GetType(&TS,$1));
                          if(!Search(&TS,$1)) {printf("IDF non declaré\n");} 
                          else{
                            if(!CheckTab(&TS,$1)) printf("IDF n'est pas un tableau\n");
                          }
                        }
;

LOOP: While '(' EXP OPR EXP ')' '{' INSTRUCTION '}'
;

CONDITION: EXECUT INSTRUCTION IF '(' EXP OPR EXP ')' 
;

%%
int yyerror(char* msg)
{
printf("Erreur syntaxique a la ligne %d colonne %d\n",nbl,nbc);
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
