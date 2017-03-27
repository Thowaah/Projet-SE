
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
void reveil(int signum){}

void sleep(int nsec)
{
	if(signal(SIGALRM, reveil)==SIG_ERR)….
	alarm(nsec) ;
	Pause() ;
}

int fonction2(char* programme, char* tabArg[], int retours, int temps, char* format){
  int err;
  err = execlp(programme, programme, )
}

int fonction1(char* programme, char* tabArg[], int interval, int retours, int temps, char* format){
  fonction2(programme, retours, temps, format);
  sleep(interval);
}
*/
int detecter(char* programme, char* tabArg[], int interval, int lancement, int retours, int temps, char* format){
  printf("%s\n", programme);
  /*
  int i;
  if(interval>0){
    for(i=lancement; i>=0; i--){
      fonction1(programme, interval,retours, temps, format);
      }
    }
  }else{
    while(1)
      fonction1(interval, retours, temps, format);
  }
  return 0;
*/
}

int main(int argc,char* argv[]){

  int interval = 10000;
  int lancement = 0;
  int retours = 0;
  int temps = 0;
  char* format = malloc(10*sizeof(char));
  char c;
  int nOpt=0;
  int i, ind = 0;
  char** tabArg;

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
  for(i=0; i<nOpt; i++)
    printf("%s,", argv[i]);
  printf("\n");
  if(argc<=nOpt+1)
    printf("saisir le nom du programme\n");
  else{
    ind=0;
    tabArg=malloc((argc-nOpt)*sizeof(char*));
    for(i=nOpt+1; i<argc; i++){
      tabArg[ind]=malloc(strlen(argv[i])*sizeof(char)+1);
      tabArg[ind]=argv[i];
      ind++;
    }
    detecter(argv[nOpt+1], tabArg, interval, lancement, retours, temps, format);
  }
  return 0;
}
