#include <pwd.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include <sys/wait.h>


char *store;// string to store each command to the argv array
char *argv[512];// stores each command , each one in an individual index
int charCounter_original = 4; // gets all the letters counted ,starts from 4 to add the length of "done" every time
int cmdCounter = 0;// commands counter

char * path_original;



//****************EDITED EX1**********************


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

    int i = 0;
    int j = 0;


    store = (char *) malloc(512 * sizeof(char));//allocating memory for the string
    if (store == NULL) {
        exit(1); //if any error has occured
    }


    for (i = 0; str[i] != '\0'; i++) {


        if ((str[i] != ' ' && str[i + 1] == ' ') ||
            (str[i + 1] == '\0' && str[i] != ' ')) {//when it reaches the last letter in each word


            charCounter_original++;


            strncat(store, &str[i], 1);//adds the char to the string "store"

            argv[j] = (char *) malloc(
                    sizeof(char) * strlen(store) + 1); // allocating space for the whole word from store

            strcpy(argv[j], store);//copying the word from "store" to the allocated separate index in the array
            j++;

            strcpy(store, "");//store becomes empty waiting to store the next word in the next iteration




        } else if (str[i] != ' ') {//if the str is not blank



            strncat(store, &str[i], 1);// store the the whole word without the last char




            charCounter_original++;// add 1 to the word counter

        } else if (str[i] == ' ') {//if it was a space

            charCounter_original++;//we have to count the spaces too , so we add 1 to the char counter
        }
    }


}

//**************************************

void prompt() {// prints out the prompt

    struct passwd *pw;
    pw = getpwuid(getuid());// get the user's name

    char *buf;
    buf = (char* )malloc(512*sizeof(char));


    if (buf == NULL) {
        printf("failed to get directory \n");
        exit(1);
    }


    getcwd(buf, 512);//get the path of the program

    strcpy(path_original, buf);
    printf("%s@%s>", pw->pw_name, buf);//new designed prompt
    free(buf);//free memory

}

void commands(char *args[]) {// executes the given commands within the array args


    pid_t f[2];

    f[0] = fork();



/* Child... */
    if (f[0] == 0) {

        if (strcmp(args[0], "cd") == 0) {// if the command was cd

            printf("Command not supported (Yet) \n");
            exit(1);

        } else {


            chdir(path_original);
            execvp(args[0], args);//execute command
            fprintf(stderr, "There's no such a command\n");// if execvp failed
            exit(1);//exit




        }



    }
/* Parent... */
    else if (f[0] != -1) {

        f[1] = fork();
        if(f[1]==0){
            if (strcmp(args[0], "cd") == 0) {// if the command was cd
                exit(1);

            }
            else {

                char *path;
                path = (char *) malloc(
                        512 *
                        sizeof(char));//allocating memory for the string that is gonna contain the path of the file
                if (path == NULL) {
                    exit(1); //if any error has occured
                }
                char *pid;
                pid = (char *) malloc(
                        512 *
                        sizeof(char));//allocating memory for the string that is gonna contain the path of the file
                if (pid == NULL) {
                    exit(1); //if any error has occured
                }

                sprintf(pid, "%d", f[0]);

                strcpy(path, "/proc/");

                strcat(path, pid);


                chdir(path);//change directory

                char *sched[] = {"cat", "sched", NULL};


                execvp(sched[0], sched);//execute command
                fprintf(stderr, "Cannot show its schedule \n");// if execvp failed
                exit(1);//exit






            }

        }
        int status;
        for(int i=0; i<2; i++) {//waiting for the two forks
            waitpid(f[i], &status, 0);
        }









    } else {// if fork has failed
        perror("Error while calling the fork function");
        exit(1);

    }
}


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%MAIN%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int main() {

    char *str;// string to store the input from user
    int lengthofarray;// length of argv array



    path_original = (char* )malloc(512*sizeof(char));//!!!!!!!!!!!!!!!!!!!!
    getcwd(path_original, 512);//get the path of the program


    while (1) {




        prompt();
        str = (char *) malloc(512 * sizeof(char));//allocating memory
        if (str == NULL) {
            exit(1); //if any error has occured
        }


        fgets(str, 512, stdin);//gets 512 char at max


        str[strlen(str) - 1] = '\0';//gets the input without the enter input


        cmdCounter++;//counting the commands


        if (strstr(str, "done")) {// if the input contains done then stop then exit the program with the following results {// if the input equals done then stop then exit the program with the following results
            double average = (double)charCounter_original / (double ) cmdCounter;

            printf("Number of commands : %d\n", cmdCounter);
            printf("total length of all commands : %d \n ", charCounter_original);
            printf("average number of all commands : %f \n", average);
            printf("See you later! ");
            break;
        }

        word_letter_printer(str);

        int length = word_counter(str);//length of argv
        lengthofarray = length;



        commands(argv);//execute the command using argv array that stores the commands

        for (int i = 0; i <
                        length; i++) {// makes all the previous indexes null to excute new commands without storing any from the previous..

            argv[i] = NULL;

        }


    }

    free(store);
    for (int i = 0; i < lengthofarray; i++) {// free memory for argv's array
        free(argv[i]);

    }
    free(str);//free memory

    return 0;
}
