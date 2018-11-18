#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct ENTITE {
    char NomE[12];
    char TypeE[10];
    int TailleE;
  	char State[10];
    int Position;
    struct ENTITE* SVT;
};

void Insert(struct ENTITE** Tete,char NomE[12],char TypeE[12],int TailleE,char State[10],int Position){
 	struct ENTITE* Parcourir;
    Parcourir=*Tete;
    struct ENTITE* NewE;
    NewE=NULL;
   if(Parcourir!=NULL){
	   	while((*Parcourir).SVT!=NULL){
	        Parcourir=(*Parcourir).SVT;
	    }
	    NewE=malloc(sizeof(struct ENTITE));
	    strcpy((*NewE).NomE,NomE);
	    strcpy((*NewE).TypeE,TypeE);
	    (*NewE).TailleE=TailleE;
	    strcpy((*NewE).State,State);
	    (*NewE).Position=Position;
	    (*NewE).SVT=NULL;
	    (*Parcourir).SVT=NewE;
	}else{
	   	*Tete=malloc(sizeof(struct ENTITE));
	    strcpy((**Tete).NomE,NomE);
	    strcpy((**Tete).TypeE,TypeE);
	    (**Tete).TailleE=TailleE;
	    strcpy((**Tete).State,State);
	    (**Tete).Position=Position;
	    (**Tete).SVT=NULL;
   }
}
int Search(struct ENTITE** Tete,char NomE[12]){
	struct ENTITE* Parcourir;
	Parcourir= *Tete;
	if(Parcourir!=NULL){ 
	 	while(Parcourir!=NULL && strcmp((*Parcourir).NomE,NomE)!=0){
	 		Parcourir=(*Parcourir).SVT;
	  	}
	  	if(Parcourir==NULL) return 0;
	  	else return 1; 
	}
	return 0;
}
void Show(struct ENTITE** Tete){
    struct ENTITE* Parcourir;
    Parcourir= *Tete;
    FILE* File=NULL;
    char type[10]; char VC[10];
    File=fopen("Table.txt","w+");
   	fprintf(File,"_________________________________________________________________________________________________________________________________\n");
    fprintf(File,"|			IDENTIFIANT			|			TYPE 			|			TAILLE 			|			VAR/CONST |\n");
    if(File==NULL)
    	printf("Echec :( \n");
    else{
    	while(Parcourir!=NULL){
		    if(strcmp((*Parcourir).TypeE,"entier")==0) 
		     	strcpy(type,"entier");
		    else
		     	strcpy(type,"reel");
		    if(strcmp((*Parcourir).State,"VAR")==0)
		    	strcpy(VC,"VAR");
		    else
		      	strcpy(VC,"CONST");
   			fprintf(File,"_________________________________________________________________________________________________________________________________\n");
			fprintf(File,"|	%s   						| %s      					| %d     					|  %s 				  |\n",(*Parcourir).NomE,type,(*Parcourir).TailleE,VC);
		        Parcourir=(*Parcourir).SVT;
    	}
    	fprintf(File,"_________________________________________________________________________________________________________________________________\n");
    	fclose(File); 
    }
}