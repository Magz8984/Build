#define success "\x1B[32m"
FILE *file;
FILE *procfile;
int init(){
  file=fopen("build.gradle","wb");
  return 0;
}

int initProcFile(){
  procfile=fopen("Procfile","wb");
  return 0;
}

void createProcFile(char *appName){
 initProcFile();
 char *line=(char *)malloc(50 * sizeof(char));
 strcat(line,"web: ./build/install/");
 strcat(line,appName);
 strcat(line,"/bin/");
 strcat(line,appName);
 fprintf(procfile, "%s\n",line);
 printf("%s\n",line);
 fclose(procfile);
}

int getPluginNumber(char *item){
  int plugins;
  printf("Total %s : ",item);
  scanf("%d",&plugins);
  return plugins;
}

void applyPlugins(){
  char data[30]="apply plugin : ";
  char *line=(char *)malloc(30 * sizeof(char));
  printf("Add Plugin : ");
  scanf("%s",line);
  strcat(data,"'");
  strcat(data,line);
  strcat(data,"'");
  printf("\n");
  fprintf(file,"%s\n",data);
}

void addRepositories(int i){
    printf("Add Repository %d\n",i);
    char *line=(char *)malloc(30 * sizeof(char));
    scanf("%s",line);
    strcat(line,"()");
    fprintf(file, "%s\n",line);
}

int closeStream(){
    fclose(file); // Closes The File Stream
}

int applyTotalPlugins(int num){
  if(num<50){
    for(int i=0;i<num;i++){
      applyPlugins();
    }
    return 0;
  }
  else{
    printf("%s\n","Check The Number Type");
  }
  return 1;
}

void addExtras(char *item){
  char *line=(char *)malloc(30 * sizeof(char));
  char data[20];
  strcpy(line,item);
  printf("Add %s :",line);
  strcat(line,"=");
  scanf("%s",data);
  if(strcmp(item,"applicationName")==0){
    createProcFile(data);
  }
  strcat(line,"'");
  strcat(line,data);
  strcat(line,"'");
  fprintf(file, "%s\n",line);
}

void applyTotalRepositories(int num){
    char *line=(char *)malloc(30 * sizeof(char));
    strcpy(line,"repositories");
    strcat(line,"{");
    if(num<50){
      fprintf(file, "%s\n",line);
      for (int i = 1; i <= num; i++) {
         addRepositories(i);
         printf("\n");
      }
      fprintf(file, "%s\n","}");
    }
    else{
      printf("%s\n","Repositories exceed");
    }
}

void addDependencies(int i){
  printf("Add Dependency %d\n",i);
  char *command=(char *)malloc(30 * sizeof(char));
  char *type=(char *)malloc(30 * sizeof(char));
  char *group=(char *)malloc(30 * sizeof(char));
  char *name=(char *)malloc(30 * sizeof(char));
  char *version=(char *)malloc(30 * sizeof(char));
  printf("Enter Dependency Type :");
  scanf("%s",type);
  printf("\n");
  printf("Enter Group Id :");
  scanf("%s",group);
  printf("\n");
  printf("Enter Dependency name :");
  scanf("%s",name);
  printf("\n");
  printf("Enter Dependency version :");
  scanf("%s",version);
  printf("\n");
  strcat(command,type);
  strcat(command," ");
  strcat(command,"group :");
  strcat(command,"'");
  strcat(command,group);
  strcat(command,"'");
  strcat(command,", ");
  strcat(command,"name :");
  strcat(command,"'");
  strcat(command,name);
  strcat(command,"'");
  strcat(command,", ");
  strcat(command,"version :");
  strcat(command,"'");
  strcat(command,version);
  strcat(command,"'");
  fprintf(file, "%s\n",command);
}

void applyTotalDependencies(int num){
    char *line=(char *)malloc(30 * sizeof(char));
    strcpy(line,"dependencies");
    strcat(line,"{");
    if(num<50){
      fprintf(file, "%s\n",line);
      for (int i = 1; i <= num; i++) {
         addDependencies(i);
         printf("\n");
      }
      fprintf(file, "%s\n","}");
    }
    else{
      printf("%s\n","dependencies exceed");
    }
}

void addSpace(){
  printf("\n");
  fprintf(file, "%s","\n");
}

void addGradleRemove(){
  fprintf(file, "%s","defaultTasks=['clean']\n");
  fprintf(file, "%s","task stage(dependsOn:['clean','installApp'])\n");
}
