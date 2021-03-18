#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
int main()
{
    int counter=0;
    char str[MAX];
    char Fword[MAX];
    printf("write the word that you wanna search for : \n");
    fgets(str,MAX,stdin);

    str[strlen(str)-1]='\0';

    printf("\n");

    FILE * filepointer;

    filepointer=fopen("neww.txt","r");

    if(filepointer==NULL){
        printf("File wasn't found \n");
        exit(1);
    }

     while(fscanf(filepointer, "%s", Fword)!=EOF){

        if(strcmp( str, Fword) == 0)
            counter++;
    }
    printf("\n");
    printf("The word %s was found %d times \n",str,counter);

    fclose(filepointer);
    return 0;
}
