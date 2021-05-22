#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include <pthread.h>



int j = 0;
int HowManyX =0;
int Evalnum;
//gets the input
//x^3 + 2x + 34, 5     answer = 169
//x^6 + 4x^5 + 2x^2 + 6x + 334, 1   answer = 347
int Pow(int base, int exponent)
{
    int result=1;
    int i =0;
    for (i = exponent; i>0; i--)
    {
        result = result * base;
    }

    return result;
}
void toArrayCopier(char * polynom, char * Polyarr[], char * evalNum, int length) {

    int i;

    char * stored;

    stored = (char * ) malloc(length * sizeof(char)); //allocating memory for the string
    if (stored == NULL) {
        exit(1); //if any error has occured
    }

    strcpy(stored, "");
    evalNum = (char * ) malloc(length * sizeof(char)); //allocating memory for the string
    if (evalNum == NULL) {
        exit(1); //if any error has occured
    }

    strcpy(evalNum, "");

    for (i = 0; i < length; i++) {

        if (polynom[i] != '+' && polynom[i] != ' ' && polynom[i] != '^' && polynom[i] != ',' && polynom[i] != '*') {
            strncat(stored, & polynom[i], 1);

        }

        if (polynom[i] == ',') {

            Polyarr[j] = (char * ) malloc(strlen(stored) + 1 * sizeof(char)); //allocating memory for the string
            if (Polyarr[j] == NULL) {
                exit(1); //if any error has occured
            }

            strcpy(Polyarr[j], stored);
            if(strstr(stored, "x")){
                HowManyX++;
            }

            strcpy(stored, "");

        }

        if (polynom[i] == '^') {

        }
        if (polynom[i] == '*') {

        }
        if (polynom[i] == ' ') {

            if (polynom[i - 1] == ',') {
                for (i = i; i < length; i++) {

                    strncat(evalNum, & polynom[i], 1);

                }
                Evalnum = atoi(evalNum);

                break;

            } else {

            }

        }

        if (polynom[i] == '+') {

            Polyarr[j] = (char * ) malloc(strlen(stored) * sizeof(char) + 1); //allocating memory for the string
            if (Polyarr[j] == NULL) {
                exit(1); //if any error has occured
            }

            strcpy(Polyarr[j], stored);
            if(strstr(stored, "x")){
                HowManyX++;
            }
            j++;
            strcpy(stored, "");

        }

    }

}
void* evaluater(void* equation){

    char * subEq = ((char*)equation);
    char*coeffNum;
    int number =0;
    char*Power=0;
    coeffNum = (char *) malloc(strlen(subEq)+1 * sizeof(char));//allocating memory for the string
    if (coeffNum == NULL) {
        exit(1); //if any error has occured
    }
    Power = (char *) malloc(strlen(subEq)+1 * sizeof(char));//allocating memory for the string
    if (Power == NULL) {
        exit(1); //if any error has occured
    }

    int power;
    strcpy(Power, "");
    strcpy(coeffNum, "");
    int length = strlen(subEq) ;
    int i;

    int *res = malloc(sizeof(int));








    for( i = 0; i < length; i++ ){








        if(subEq[i] != 'x'){

            strncat(coeffNum, &subEq[i] , 1);

        }

        else{



            if(i == 0){

                for( i = 1; i < length ; i++ ){

                    strncat(Power, &subEq[i] , 1);

                }
                if(length!=1){
                    power = atoi(Power);
                    int x_After_power = Pow(Evalnum, power);
                    int answer = x_After_power;
                    *res = answer;

                    return ((void*)res);
                }

                else{
                    int answer = Evalnum;
                    *res = answer;

                    return ((void*)res);
                }


            }else{
                int answer;

                number = atoi(coeffNum);

                i++;

                if(i!= length){
                    for( i = i; i < length ; i++ ){

                        strncat(Power, &subEq[i] , 1);

                    }

                    power = atoi(Power);
                    int x_After_power = Pow(Evalnum, power);
                    answer =x_After_power * number;
                }
                else{

                    answer = Evalnum * number;



                }


                *res = answer;


                return ((void*)res);


            }








        }
    }








    return NULL;
}


void ToNewArray_Only_with_x(char * Arr[] , char *Arr2 [] ){
    int i ;
    int k = 0;




    for( i = 0; i<= j ; i++ ){


        if(strstr(Arr[i], "x")){

            Arr2[k] = (char * ) malloc(strlen(Arr[i]) + 1 * sizeof(char) ); //allocating memory for the string
            if (Arr2[k] == NULL) {
                exit(1); //if any error has occured
            }

            strcpy(Arr2[k], Arr[i]);


            k++;



        }


    }
}
void toArray_Only_with_numbers(char * Arr[] , int * Arr2[]){


    int i ;
    int k =0;
    for ( i = 0; i <=j; i++){


        if(!strstr(Arr[i], "x")){
            Arr2[k] = (int* ) malloc(sizeof(int));
            if( Arr2[k] == NULL){
                exit(1);
            }
            int number = atoi(Arr[i]);
            *Arr2[k] = number;

            k++;


        }
    }

}

int NUMarr_Sumer(int*arr[] , int length){
    int i;
    int sum =0;
    for (i = 0; i< length ; i++){

        sum += *arr[i];

    }
    return sum;



}



//**********MAIN*************

int main() {

    while (1) {

        char polynom[510];
        char * evalNum;
        int length;
        int i;

        fgets(polynom, 510, stdin);
        polynom[strlen(polynom) - 1] = '\0';
        if (strcmp(polynom, "done") == 0) {
            break;
        } else {
            length = strlen(polynom);
            char * Polyarr[length];

            toArrayCopier(polynom, Polyarr, evalNum, length);
            char* Polyarr_With_x_only[HowManyX];

            int lengthOfNumArray =j-HowManyX+1;
            int* NUMarray[lengthOfNumArray];

            ToNewArray_Only_with_x(Polyarr , Polyarr_With_x_only);


            toArray_Only_with_numbers(Polyarr, NUMarray);



            int threadNum = HowManyX;

            j = 0;


            //threads starts here

            int i, status, * res;
            int sum = 0;
            pthread_t thread_data[threadNum];

            for (i = 0; i < threadNum; i++) {

                status = pthread_create( & thread_data[i], NULL, evaluater, (void * ) Polyarr_With_x_only[i]);

                if (status != 0) {
                    fputs("failed to create thread", stderr);
                    exit(EXIT_FAILURE);
                }
            }
            for (i = 0; i < threadNum; i++) {

                pthread_join(thread_data[i], (void ** ) &res);

                sum += * res;

                free(res);

            }
            sum = sum + NUMarr_Sumer(NUMarray, lengthOfNumArray);
            printf("%d\n", sum);

        }
        HowManyX =0;

    }

    return 0;
}
