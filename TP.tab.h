/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     Programme = 258,
     While = 259,
     EXECUT = 260,
     IF = 261,
     Real = 262,
     Integer = 263,
     BOUCLE = 264,
     TAB = 265,
     Calcul = 266,
     CONST = 267,
     EGAL = 268,
     SEP = 269,
     IDF = 270,
     OPR = 271,
     ENTIER = 272,
     REEL = 273
   };
#endif
/* Tokens.  */
#define Programme 258
#define While 259
#define EXECUT 260
#define IF 261
#define Real 262
#define Integer 263
#define BOUCLE 264
#define TAB 265
#define Calcul 266
#define CONST 267
#define EGAL 268
#define SEP 269
#define IDF 270
#define OPR 271
#define ENTIER 272
#define REEL 273




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 18 "tp.y"
typedef union YYSTYPE {
char *chaine;
int entier;
float reel;
struct s {char * val; char * type;}s;
} YYSTYPE;
/* Line 1447 of yacc.c.  */
#line 81 "tp.tab.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



