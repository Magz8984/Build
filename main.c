#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define len(x) (sizeof(x)/sizeof(x[0]))

typedef struct build{
  char *name;
  char *dir;
}build;


void saveCommands (char * command);
void performTask(){
  build *tool;
  char command[200]="mkdir ";
  tool=(build*)malloc(sizeof(build));
  tool->name=(char*)malloc(40*sizeof(char));
  tool->dir=(char*)malloc(40*sizeof(char));

  printf("Enter app name\n");
  scanf("%s",tool->dir);
  printf("Entry Main Class Name:\t");
  scanf("%s",tool->name);
  strcat(command,tool->dir);
  system(command);
  strcpy(command,"\0");
  strcpy(command,"cd ");
  strcat(command,tool->dir);
  strcat(command," && touch build.gradle");
  system(command);

  strcpy(command,"\0");
  strcpy(command,"cd ");
  strcat(command,tool->dir);
  strcat(command," && mkdir src && cd src && mkdir main  && cd main && mkdir java && cd java && touch ");
  strcat(command,tool->name);
  strcat(command,".java");
  system(command);
  
  strcpy(command,"cd ");
  strcat(command,tool->dir);
  strcat(command," && cd src && mkdir test && cd test && mkdir java && cd java && touch  test.java");
  system(command);
  free(tool);
}

int main(int args,char *argv[],char *env[]){
  if(!(args==1)){
    if(strcmp(argv[1],"-v")==0){
      printf("Build version 1.0\n");
      printf("Author : Collins Magondu :  @ Moringa\n");
    }
    else if(strcmp(argv[1],"build")==0){
      performTask();
    }
  }
  
  return 0;
}