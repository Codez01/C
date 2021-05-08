#include <pwd.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include <sys/wait.h>
#include <stdbool.h>

char *store;// string to store each command to the argv array
char *argv[512];// stores each command , each one in an individual index



//new for ex3 (pipes)
char *argv1[512];// stores each command , each one in an individual index
char *argv2[512];// stores each command , each one in an individual index
char *argv3[512];// stores each command , each one in an individual index
bool isPipe = false;//checks if there is a pipe in the main array
int pipecounter=0;//counts how many pipes are there in the commands
int argv3Length;//length of the first array
int argv2Length;//length of the second array
int argv1Length;//length of the third array
int prevCharCounter;//it counts how many char are there before using any methods
int iAtSecPipe;//the index of the sec pipe

//new for ex4
pid_t childcopy ;
pid_t f;

void handler(int sig){

    childcopy = f;

}
void handler2(int sig){

    kill(childcopy , SIGTSTP);

}







int charCounter_original = 0; // gets all the letters counted ,starts from 4 to add the length of "done" every time
int cmdCounter = 0;// commands counter


//EDITED EX1


int word_counter(char *str) {//this method is for counting words
    int wordCounter = 0;
    int i;

    for (i = 0; str[i] != '\0'; i++) {

        if ((str[i] != ' ' && str[i + 1] == ' ') || (str[i + 1] == '\0' && str[i] != ' ')) {

            wordCounter++;


        }


    }

    return wordCounter;


}



void word_letter_printer(char *str) {//this method is for counting letters in each word

    int i ;
    int j = 0;



    store = (char *) malloc(512 * sizeof(char));//allocating memory for the string
    if (store == NULL) {
        exit(1); //if any error has occured
    }


    for (i = 0; str[i] != '\0'; i++) {


        if(str[i] == '|'){
            pipecounter++;//counts pipes

        }

        if ((str[i] != ' ' && str[i + 1] == ' ') ||
            (str[i + 1] == '\0' && str[i] != ' ')) {





            //when it reaches the last letter in each word


            charCounter_original++;


            strncat(store, &str[i], 1);//adds the char to the string "store"


            argv[j] = (char *) malloc(
                    sizeof(char) * strlen(store) + 1);
            if (argv[j] == NULL) {
                printf("couldn't allocate memory \n");
                exit(1);
            } // allocating space for the whole word from store

            strcpy(argv[j], store);//copying the word from "store" to the allocated separate index in the array
            j++;

            strcpy(store, "");//store becomes empty waiting to store the next word in the next iteration






        } else if (str[i] != ' ' ) {//if the str is not blank



            strncat(store, &str[i], 1);// store the the whole word without the last char




            charCounter_original++;// add 1 to the word counter

        } else if (str[i] == ' ') {//if it was a space

            charCounter_original++;//we have to count the spaces too , so we add 1 to the char counter
        }
    }


}




void FindSecPipe(int length){// this method is for finding the index of the second pipe if there is...
    int pipCounter =0;
    int i;

    for(  i = 0; i < length ; i++){
        if(strcmp(argv[i], "|")==0){

            pipCounter++;

            if(pipCounter == 2){


                iAtSecPipe = i;
            }

        }








    }





}


void copyToArgv(int length){//method for copying elements for 2 arrays if there is only 1 pipe
    if(pipecounter >=2 ){

        int j = 0;
        int k =0;

        int pipCounter=0;
        int i;


        for ( i = 0; i < length; i++) {// free memory for argv's array





            if(strcmp(argv[i], "|")==0 && i!= length-1){
                isPipe =true;
                pipCounter++;

                i++;



                while(1){
                    if ( i == length){
                        break;
                    }


                    argv2[j] = (char *) malloc(
                            sizeof(char) * strlen(argv[i]) + 1); // allocating space for the whole word from store
                    if (argv2[j] == NULL) {
                        printf("couldn't allocate memory \n");
                        exit(1);
                    }



                    strcpy(argv2[j], argv[i]);


                    j++;
                    i++;
                    argv2Length = j;






                }

            }else{

                argv1[k] = (char *) malloc(
                        sizeof(char) * strlen(argv[i]) + 1); // allocating space
                if (argv1[k] == NULL) {
                    printf("couldn't allocate memory \n");
                    exit(1);
                }



                strcpy(argv1[k], argv[i]);


                k++;
                argv1Length = k;




            }



        }






    }else{
        int j = 0;
        int k =0;
        int i ;




        for ( i = 0; i < length; i++) {





            if(strcmp(argv[i], "|")==0 && i!= length-1){
                isPipe =true;

                i++;



                while(1){
                    if ( i == length){
                        break;
                    }


                    argv2[j] = (char *) malloc(
                            sizeof(char) * strlen(argv[i]) + 1); // allocating space
                    if (argv2[j] == NULL) {
                        printf("couldn't allocate memory \n");
                        exit(1);
                    }



                    strcpy(argv2[j], argv[i]);


                    j++;
                    i++;
                    argv2Length = j;






                }

            }else{

                argv1[k] = (char *) malloc(
                        sizeof(char) * strlen(argv[i]) + 1); // allocating space
                if (argv1[k] == NULL) {
                    printf("couldn't allocate memory \n");
                    exit(1);
                }



                strcpy(argv1[k], argv[i]);


                k++;
                argv1Length = k;




            }



        }





    }
}


void copyToArgv2(int length){// method for copying elemts for 3 arrays if there are 2 pipes

    int j = 0;
    int k =0;
    int x=0;
    int pipeCount =0;
    int i ;


    for ( i = 0; i < length; i++) {// free memory for argv's array





        if(strcmp(argv[i], "|")==0 && i!= length-1){
            isPipe =true;
            pipeCount++;

            i++;



            while(1){
                if ( i == iAtSecPipe){
                    break;
                }


                argv2[j] = (char *) malloc(
                        sizeof(char) * strlen(argv[i]) + 1); // allocating space
                if (argv2[j] == NULL) {
                    printf("couldn't allocate memory \n");
                    exit(1);
                }



                strcpy(argv2[j], argv[i]);


                j++;
                i++;
                argv2Length = j;






            }
            i++;
            while(1){
                if ( i == length){
                    break;
                }

                argv3[x] = (char *) malloc(
                        sizeof(char) * strlen(argv[i]) + 1); // allocating space
                if (argv3[x] == NULL) {
                    printf("couldn't allocate memory \n");
                    exit(1);
                }



                strcpy(argv3[x], argv[i]);



                x++;
                i++;
                argv3Length = x;






            }

        }else{

            argv1[k] = (char *) malloc(
                    sizeof(char) * strlen(argv[i]) + 1); // allocating space
            if (argv1[j] == NULL) {
                printf("couldn't allocate memory \n");
                exit(1);
            }



            strcpy(argv1[k], argv[i]);


            k++;
            argv1Length = k;




        }



    }





}




void seperator(char* string, int length ){//method for seperating pipes from commands

    char* strnew;
    char space=' ';
    char pipe = '|';
    strnew = (char *) malloc(
            sizeof(char) * 512 ); //
    if (strnew == NULL) {
        printf("couldn't allocate memory \n");
        exit(1);
    }
    int i;

    for (  i=0 ; i < length; i++){
        if(string[i] != '|'){


            strncat(strnew, &string[i],1);
        }if(string[i]== '|'){
            strncat(strnew,&space ,1);
            strncat(strnew, &pipe,1);
            strncat(strnew,&space ,1);
        }



    }


    strcpy(string, strnew);
    free(strnew);










}
void quotationsRemover(char * str ){//method for removing quotations if there any were found within a specific command




    int writer = 0, index = 0;
    char quotation = '"';

    while (str[index])
    {
        if (str[index]!=quotation )
        {
            str[writer++] = str[index];
        }

        index++;
    }

    str[writer]=0;
}

void CharCounter(char *string){
    int i;
    for( i =0 ; string[i]!='\0'; i++ ){
        prevCharCounter ++;



    }






}

//**

void prompt() {// prints out the prompt

    struct passwd *pw;
    pw = getpwuid(getuid());// get the user's name

    char *buf;
    buf = (char *) malloc(
            512 * sizeof(char));//allocating memory for the string that is gonna contain the path of the file


    if (buf == NULL) {
        printf("failed to get directory \n");
        exit(1);
    }

    getcwd(buf, 512);//get the path of the program
    printf("%s@%s>", pw->pw_name, buf);//new designed prompt
    free(buf);//free memory

}



void commands(char *args[]) {// executes the given commands within the array args




    pid_t leftpid,midpid, rightpid;
    int pipefd[2];
    int pipefd2[2];
    int status;



    if ( (isPipe== true ) && (iAtSecPipe != 0) ){// if there were two pipes



        if (pipe(pipefd) != 0 || pipe(pipefd2) != 0)
        {
            perror("pipe failed");
            exit(1);

        }

        if ((leftpid = fork()) ==0) {
            dup2(pipefd[1], 1);
            close(pipefd[0]);
            close(pipefd[1]);
            close(pipefd2[0]);
            close(pipefd2[1]);
            execvp(argv1[0], argv1  );
            fprintf(stdout, "Piping failed \n");
            exit(1);

        }
        else if ((midpid = fork()) ==0) {
            dup2(pipefd[0], 0);
            dup2(pipefd2[1], 1);
            close(pipefd[0]);
            close(pipefd[1]);
            close(pipefd2[0]);
            close(pipefd2[1]);
            execvp(argv2[0], argv2 );
            fprintf(stdout, "Piping failed \n");
            exit(1);

        }
        else if ((rightpid = fork()) ==0) {
            dup2(pipefd2[0], 0);
            close(pipefd[0]);
            close(pipefd[1]);
            close(pipefd2[0]);
            close(pipefd2[1]);
            execvp(argv3[0], argv3 );
            fprintf(stdout, "Piping failed \n");
            exit(1);

        } else {
            close(pipefd[0]);
            close(pipefd[1]);
            close(pipefd2[0]);
            close(pipefd2[1]);
            wait(NULL);
            wait(NULL);
            wait(NULL);


        }
    }

    if ((isPipe == true) && (iAtSecPipe ==0)){//if there was one pipe


        if (pipe(pipefd) != 0)
        {
            perror("pipe failed");
            exit(1);

        }
        if ((leftpid = fork()) ==0) {
            dup2(pipefd[1], STDOUT_FILENO);
            close(pipefd[0]);
            close(pipefd[1]);
            execvp(argv1[0], argv1  );
            fprintf(stdout, "Piping failed \n");
            exit(1);

        }
        else if ((rightpid = fork()) ==0) {
            dup2(pipefd[0], STDIN_FILENO);
            close(pipefd[0]);
            close(pipefd[1]);
            execvp(argv2[0], argv2 );
            fprintf(stdout, "Piping failed \n");
            exit(1);

        } else {
            close(pipefd[0]);
            close(pipefd[1]);
            wait(NULL);
            wait(NULL);

        }




    } if(isPipe == false){

        f = fork();




/* Child... */
        if (f == 0) {

signal(SIGTSTP , handler2);






            if (strcmp(args[0], "cd") == 0) {// if the command was cd
                printf("Command not supported (Yet) \n");

                 exit(1);

            } else {

                execvp(args[0], args);//execute command
                fprintf(stdout, "There's no such a command\n");// if execvp failed
                exit(1);//exit

            }


/* Parent... */
        } else if (f != -1) {

            waitpid(f ,  NULL , WUNTRACED);


        } else {// if fork has failed
            perror("Error while calling the fork function");
            exit(1);

        }

    }
}



//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%MAIN%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int main() {

 signal(SIGTSTP , handler );

    char *str;// string to store the input from user
    int lengthofarray;// length of argv array


    while (1) {
        prompt();// prints the prompt each iterate


        str = (char *) malloc(512 * sizeof(char));//allocating memory
        if (str == NULL) {
            exit(1); //if any error has occured
        }






        fgets(str, 512, stdin);//gets 512 char at max


        str[strlen(str) - 1] = '\0';//gets the input without the enter input


        CharCounter(str);
        seperator(str, prevCharCounter);
        quotationsRemover(str);




        cmdCounter++;//counting the commands


        if (strstr(str, "done")) {// if the input contains done then stop then exit the program with the following results


            cmdCounter--;

            printf("Number of commands : %d\n", cmdCounter);
            printf("Number of Pipes : %d \n ", pipecounter);

            printf("See you later! ");
            break;
        }

        if(strcmp(str , "fg" ) == 0){

            kill(childcopy , SIGCONT);
            waitpid(childcopy , NULL , WUNTRACED);

        }else {


            int length = word_counter(str);//length of argv
            lengthofarray = length;


            word_letter_printer(str);


            FindSecPipe(length);

            if (iAtSecPipe == 0) {
                copyToArgv(length);

            } else {


                copyToArgv2(length);


            }


            commands(argv);//execute the command using argv array that stores the commands
        }

        isPipe= false;

        int length = word_counter(str);//length of argv

        int i ;

        for (i = 0; i < length; i++) {// makes all the previous indexes null to excute new commands without storing any from the previous..

            argv[i] = NULL;

        }
        for ( i = 0; i < argv2Length; i++) {// makes all the previous indexes null to excute new commands without storing any from the previous..

            argv2[i] = NULL;

        }
        for (i = 0; i < argv1Length; i++) {// makes all the previous indexes null to excute new commands without storing any from the previous..

            argv1[i] = NULL;

        }

        for (i = 0; i < argv3Length; i++) {// makes all the previous indexes null to excute new commands without storing any from the previous..

            argv3[i] = NULL;

        }


        prevCharCounter=0;
        iAtSecPipe=0;





    }


    int i;
    int length = word_counter(str);//length of argv

    for (i = 0; i < length; i++) {// freeing array

        free(argv[i]);

    }
    for ( i = 0; i < argv2Length; i++) {// freeing array

        free(argv2[i]);

    }
    for (i = 0; i < argv1Length; i++) {// freeing array
        free(argv1[i]);

    }

    for (i = 0; i < argv3Length; i++) {// freeing array
        free(argv3[i]);

    }


    free(store);

    for ( i = 0; i < lengthofarray; i++) {// free memory for argv's array
        free(argv[i]);

    }
    free(str);//free memory


    return 0;
}
