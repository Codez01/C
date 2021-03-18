#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>




int word_counter(char*str){//this method is for counting words 
    int wordCounter=0;
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {

        if((str[i]!=' ' && str[i+1]==' ')||(str[i+1]=='\0' && str[i]!=' '))
        {

            wordCounter++;




        }



    }

    return wordCounter;


}
void word_letter_printer (char*str){//this method is for counting letters in each word

    int i = 0;
    int charCounter=0;


    for (i = 0; str[i] != '\0'; i++)
    {

        if((str[i]!=' ' && str[i+1]==' ')||(str[i+1]=='\0' && str[i]!=' '))
        {//when it reaches the last letter in each word 


            charCounter++;
            printf("%c", str[i]);//prints the last letter
            printf(": %d \n", charCounter);
            charCounter=0;


        }
        else if(str[i]!=' ' ){//if the str is not blank
            printf("%c", str[i]);//every letter except for the last
            charCounter++;

        }
    }

}

int main()
{
    char *str;
    int i = 0;
    int charCounter=0;
    bool end_loop=false;



    str=(char*)malloc(510*sizeof(char));//allocating memory
    if(str == NULL){
      exit(1); //if any error has occured
    }

    while(1){
        printf("Enter a string: ");//gets an input
        fgets(str, 510, stdin);//gets 510 char at max 
        str[strlen(str) - 1] = '\0';//gets the input without the enter input
        if(strcmp(str,"end")==10){

            break;
        }
        if(word_counter(str)!=0){// if the input was NULL then don't print anything
        printf("The number of words = %d \n", word_counter(str));
        }
        word_letter_printer(str);


    }
    free(str);//free memory



    return 0;
}