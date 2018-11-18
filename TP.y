%{
#include<stdio.h>
extern FILE* yyin;
extern int nbl,nbc;
#include"TableS.h"
struct ENTITE *TS;
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

Start : Bibliotheque Programme IDF '{' DECLARATION  INSTRUCTION '}' {printf("programme correct syntaxiquement\n");} ;

Bibliotheque : Bib Bibliotheque 
            |  Bib 
;

Bib : Calcul 
     | TAB   
     | BOUCLE 
;

DECLARATION : TYPE Val DECLARATION
  | TYPE Val
;

Val : DecVar
  | DecTab
  | CONST DecConst
;

DecVar: IDF SEP DecVar      
       | IDF ';'       
;

DecConst: IDF SEP DecConst  
        | IDF ';'      
;

DecTab: IDF '[' ENTIER ']' ';'     
;

TYPE: Real  
      | Integer
;

INSTRUCTION: TypeInstruction INSTRUCTION
    |TypeInstruction
;

TypeInstruction: LOOP
                | CONDITION
                | AFFECTATION
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

AFF : IDF 
     | IDF '['ENTIER']'  
     | ENTIER 
     | REEL  
;

IDFA: IDF 
        | IDF '['ENTIER']'  
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
return 0;
}
