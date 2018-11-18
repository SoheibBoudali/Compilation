%{
	#include<stdio.h>
	#include<string.h>
	#include<stdlib.h>
	#include "TP.tab.h"
	extern FILE * yyin;
	int nbl=1,nbc=1;
	extern YYSTYPE yylval;
%}
IDF [A-Z][A-Za-z0-9]*
ENTIER [-]?[0-9]+
REEL   ENTIER"."[0-9]+
OPR  ("=="|"<"|">"|"<="|">="|"!=")
SEP "||"
%%
{SEP} {nbc=nbc+2; return SEP;}
" " {nbc++;}
"//"(.)*"//" {nbc=nbc+strlen(yytext);}
":=" {nbc=nbc+2; return EGAL;}
"]" {nbc++; return ']';}
"[" {nbc++; return '[';}
"{" {nbc++;return'{';}
"}" {nbc++;return'}';}
"," {nbc++; return ',';}
"+" {nbc++; return '+';}
"-" {nbc++; return '-'; }
"*" {nbc++; return '*'; }
"/" {nbc++; return '/'; }
"#BOUCLE\n" {nbc=nbc+7;nbl++;nbc=1;return BOUCLE;}
"#TAB\n" {nbc=nbc+strlen(yytext);nbl++;nbc=1;return TAB;}
"#Calcul\n" {nbc=nbc+strlen(yytext);nbl++;nbc=1;return Calcul;}
"(" {nbc++;return '(';}
")" {nbc++;return ')';}
";" {nbc++;return ';';}
"\n" {nbc=1;nbl++;}
"\t" {nbc=nbc+1;}
"Programme" {nbc=nbc+strlen(yytext);return Programme;}
"Real" {nbc=nbc+strlen(yytext); return Real;}
"Integer" {nbc=nbc+strlen(yytext);return Integer;}
"CONST" {nbc=nbc+strlen(yytext);return CONST;}
"While" {nbc=nbc+strlen(yytext);return While;}
"EXECUT" {nbc=nbc+strlen(yytext); return EXECUT;}
"IF" {nbc=nbc+strlen(yytext); return IF;}
{IDF} {
    if(strlen(yytext)>12){
    	printf("Erreur! l'identifiant %s est trop long (Taille maximum 12 caractere)\n",yytext);}										
       	nbc=nbc+strlen(yytext); yylval.chaine=strdup(yytext); return IDF;
    }
{ENTIER} {nbc=nbc+strlen(yytext);yylval.entier=atoi(yytext); return ENTIER;}
{REEL} {nbc=nbc+strlen(yytext);yylval.reel=atof(yytext); return REEL;}
{OPR} {nbc=nbc+strlen(yytext);return OPR; }
. {printf("Erreur lexicale ligne %d colonne %d ======> %s Inconnu \n",nbl,nbc,yytext);}
%%
	int yywrap()
	{
	return 1;
	}
