
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

void raler(int retour, char const* desc){
  if(retour==-1){
    perror(desc);
    exit(EXIT_FAILURE);
  }
}
/*
//convertion d'un string en int
int toInt(char* str){
  if(str[9]<"0" || str[9]>"9"){
    perror("NaN");
    printf("-i attend un entier");
    return(-1);
  }
  else return atoi(str);
}
*/


/*
//permet de reveiller
void reveil(int signum){}

//fonction de dodo
void sleep(int nsec)
{
	if(signal(SIGALRM, reveil)==SIG_ERR)….
	alarm(nsec) ;
	Pause() ;
}

//execution du programme ici
int fonction2(char* programme, char* tabArg[], int retours, int temps, char* format){
  int err;
  err = execlp(programme, programme, )
}

//fonction appelée par detecter, permet de lancer le programme, et ensuite de dormir pendant 'interval' secondes
int fonction1(char* programme, char* tabArg[], int interval, int retours, int temps, char* format){
  fonction2(programme, retours, temps, format);
  sleep(interval);
}
*/

//première fonction appelée par la main: permet de lancer le programme à l'infini ou un nombre défini de fois
int detecter(char* programme, char* tabArg[], int interval, int lancement, int retours, int temps, char* format){
  printf("%s\n", programme);	//test
  /*
  int i;
  //si un certain nombre de lancements
  if(interval>0){
    for(i=lancement; i>=0; i--){
      fonction1(programme, interval,retours, temps, format);
      }
    }
  }else{
  //sinon boucle infinie
    while(1)
      fonction1(interval, retours, temps, format);
  }
  return 0;
*/
}

int main(int argc,char* argv[]){

  int interval = 10000;	//interval de temps entre 2 lancements
  int lancement = 0;	//limite de lancements 0= infini, sinon le nbr entré
  int retours = 0;	//checker les codes de retour ou pas
  int temps = 0;	//afficher l'heure à chaque lancement
  char* format = malloc(10*sizeof(char));	//format de l'heure
  char c;		//sert pour getopt
  int nOpt=0;		//décalage entre argv[0] et le programme et ses options
  int i, ind = 0;	
  char** tabArg;	//tableau des arguments du programme à lancer

	
//ici on récupère les options
  while((c = getopt(argc, argv, "+t:i:l:c"))!= -1)
    switch(c){
      case 'i':
        nOpt+=2;
        interval = atoi(optarg);
        printf("option i, argument %d\n", atoi(optarg));
        break;
      case 't':
        nOpt+=2;
        format = optarg;
        printf("options t, argument: %s\n", format);
        break;
      case 'l':
        nOpt+=2;
        lancement = atoi(optarg);
        printf("option l, argument %s\n", lancement);
        break;
      case 'c':
        nOpt++;
        printf("option c\n");
        break;
      case '?':
        printf("Argument non reconnu");
        break;
      default:
        printf("fonction normale\n");
        break;
  }
	//tests des arguments entrés
  for(i=0; i<nOpt; i++)
    printf("%s,", argv[i]);
  printf("\n");
  if(argc<=nOpt+1)
    printf("saisir le nom du programme\n");	//test si il y a le un programme ou pas
  else{
    ind=0;
    tabArg=malloc((argc-nOpt)*sizeof(char*));	//on range les arguments du programme à executer dans un tableau
    for(i=nOpt+1; i<argc; i++){
      tabArg[ind]=malloc(strlen(argv[i])*sizeof(char)+1);
      tabArg[ind]=argv[i];
      ind++;
    }
    detecter(argv[nOpt+1], tabArg, interval, lancement, retours, temps, format); //on lance le programme à proprement parler
  }
	//ajouter les free
  return 0;
}
