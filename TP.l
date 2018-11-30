%{
	#include<stdio.h>
	#include<string.h>
	#include<stdlib.h>
	#include "TP.tab.h"
	extern FILE * yyin;
	int NL=1,NC=1;
	extern YYSTYPE yylval;
%}
IDF [A-Z][A-Za-z0-9]*
ENTIER [-]?[0-9]+
REEL   [-]?[0-9]+[/.][0-9]+
OPR  ("=="|"<"|">"|"<="|">="|"!=")
SEP "||"
%%
{SEP} {NC=NC+2; return SEP;}
" " {NC++;}
"//"(.)*"//" {NC=NC+strlen(yytext);}
":=" {NC=NC+2; return EGAL;}
"]" {NC++; return ']';}
"[" {NC++; return '[';}
"{" {NC++;return'{';}
"}" {NC++;return'}';}
"," {NC++; return ',';}
"+" {NC++; return '+';}
"-" {NC++; return '-'; }
"*" {NC++; return '*'; }
"/" {NC++; return '/'; }
"#BOUCLE\n" {NC=NC+7;NL++;NC=1;return BOUCLE;}
"#TAB\n" {NC=NC+strlen(yytext);NL++;NC=1;return TAB;}
"#Calcul\n" {NC=NC+strlen(yytext);NL++;NC=1;return Calcul;}
"(" {NC++;return '(';}
")" {NC++;return ')';}
";" {NC++;return ';';}
"\n" {NC=1;NL++;}
"\t" {NC=NC+1;}
"Programme" {NC=NC+strlen(yytext);return Programme;}
"Real" {NC=NC+strlen(yytext); return Real;}
"Integer" {NC=NC+strlen(yytext);return Integer;}
"CONST" {NC=NC+strlen(yytext);return CONST;}
"While" {NC=NC+strlen(yytext);return While;}
"EXECUT" {NC=NC+strlen(yytext); return EXECUT;}
"IF" {NC=NC+strlen(yytext); return IF;}
{IDF} {
    if(strlen(yytext)>12){
    	printf("Erreur! l'identifiant %s est trop long (Taille maximum 12 caractere)\n",yytext);}										
       	NC=NC+strlen(yytext); yylval.chaine=strdup(yytext); return IDF;
    }
{ENTIER} {NC=NC+strlen(yytext);yylval.entier=atoi(yytext); return ENTIER;}
{REEL} {NC=NC+strlen(yytext);yylval.reel=atof(yytext); return REEL;}
{OPR} {NC=NC+strlen(yytext);return OPR; }
. {printf("Erreur lexicale ligne %d colonne %d ======> %s Inconnu \n",NL,NC,yytext);}
%%
	int yywrap()
	{
	return 1;
	}
