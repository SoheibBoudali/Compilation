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
    File=fopen("TableS.txt","w+");
   	fprintf(File,"_________________________________________________________________________________________________________________________________\n");
    fprintf(File,"|			IDENTIFIANT			|			TYPE 			|			TAILLE 				|			NATURE |\n");
    if(File==NULL)
    	printf("Echec :( \n");
    else{
    	while(Parcourir!=NULL){
		    if(strcmp((*Parcourir).TypeE,"Integer")==0) 
		     	strcpy(type,"Entier");
		    else
		     	strcpy(type,"Real");
		    if(strcmp((*Parcourir).State,"VAR")==0)
		    	strcpy(VC,"VAR");
		    else{ if (strcmp((*Parcourir).State,"CONST")==0) strcpy(VC,"CONST");
		    	 else strcpy(VC,"TAB");}
   			fprintf(File,"_________________________________________________________________________________________________________________________________\n");
			fprintf(File,"|	%s   						| %s      					| %d     					|  %s 				  |\n",(*Parcourir).NomE,type,(*Parcourir).TailleE,VC);
		        Parcourir=(*Parcourir).SVT;
    	}
    	fprintf(File,"_________________________________________________________________________________________________________________________________\n");
    	fclose(File); 
    }
}
int CheckTab(struct ENTITE** Tete, char NomE[12]){
	struct ENTITE* Parcourir;
	Parcourir = *Tete;
	if (Parcourir!=NULL){
		while(Parcourir!=NULL ){
			if(strcmp((*Parcourir).State,"TAB")==0 && strcmp((*Parcourir).NomE,NomE)==0){
				return 1;
				break;
			}else
				Parcourir=(*Parcourir).SVT;
		}	
	}
	return 0;
}
int CheckTabSize(struct ENTITE** Tete, char NomE[12]){
	struct ENTITE* Parcourir;
	Parcourir = *Tete;
	if (Parcourir!=NULL){
		while(Parcourir!=NULL){
			if(strcmp((*Parcourir).NomE,NomE)==0){
				return (*Parcourir).TailleE;
				break;
			}else
			Parcourir=(*Parcourir).SVT;
		}
	}
	return 0;
}
char* GetType (struct ENTITE** Tete, char NomE[12]){
	struct ENTITE* Parcourir;
	Parcourir = *Tete;
	if (Parcourir!=NULL){
		while(Parcourir!=NULL){
			if(strcmp((*Parcourir).NomE,NomE)==0){
				return (*Parcourir).TypeE;
				break;
			}else
				Parcourir=(*Parcourir).SVT;
		}	
	}
	return "";
}
int GetLine(struct ENTITE** Tete , char NomE [12]){
	struct ENTITE* Parcourir;
	Parcourir = *Tete;
	if (Parcourir!=NULL){
		while(Parcourir!=NULL){
			if(strcmp((*Parcourir).NomE,NomE)==0){
				return (*Parcourir).Position;
				break;
			}else
				Parcourir=(*Parcourir).SVT;
		}	
	}
	return 0;
}
typedef struct BIB {
    char NomB[12];
    int Position;
    struct BIB* SVTB;
};

void InsertBib(struct BIB** TeteB, char NomB[20] , int Position){
	struct BIB* ParcourirB;
	ParcourirB=*TeteB;
	struct  BIB* NewB;
	NewB=NULL;
	   if(ParcourirB!=NULL){
	   	while((*ParcourirB).SVTB!=NULL){
	        ParcourirB=(*ParcourirB).SVTB;
	    }
	    NewB=malloc(sizeof(struct BIB));
	    strcpy((*NewB).NomB,NomB);
	    (*NewB).Position=Position;
	    (*NewB).SVTB=NULL;
	    (*ParcourirB).SVTB=NewB;
	}else{
	   	*TeteB=malloc(sizeof(struct BIB));
	    strcpy((**TeteB).NomB,NomB);
	    (**TeteB).Position=Position;
	    (**TeteB).SVTB=NULL;
   }
}

int SearchB (struct BIB** TeteB,char NomB[12]){
	struct BIB* ParcourirB;
	ParcourirB= *TeteB;
	if(ParcourirB!=NULL){ 
	 	while(ParcourirB!=NULL && strcmp((*ParcourirB).NomB,NomB)!=0){
	 		ParcourirB=(*ParcourirB).SVTB;
	  	}
	  	if(ParcourirB==NULL) return 0;
	  	else return 1; 
	}
	return 0;
}

void ShowB(struct BIB** TeteB){
    struct BIB* ParcourirB;
    ParcourirB= *TeteB;
    FILE* File=NULL;
    File=fopen("TableB.txt","w+");
   	fprintf(File,"_______________________________\n");
    fprintf(File,"|			Bibliotheque		|\n");
    if(File==NULL)
    	printf("Echec :( \n");
    else{
    	while(ParcourirB!=NULL){
    		fprintf(File,"_______________________________\n");
			fprintf(File,"|	%s   						|\n",(*ParcourirB).NomB);
		        ParcourirB=(*ParcourirB).SVTB;
    	}
   		fprintf(File,"_______________________________\n");
    	fclose(File); 
    }
}