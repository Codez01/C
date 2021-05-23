#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include <pthread.h>


int j = 0; //the length of the array conataining all the x objects and numbers
int HowManyX = 0; //how many x'es are there in the polynom
int Evalnum; //stores the number we wannna evaluate

//gets the input, for example
//x^3 + 2x + 34, 5     answer = 169
//x^6 + 4x^5 + 2x^2 + 6x + 334, 1   answer = 347

int Pow(int base, int exponent) { //power function
  int result = 1;
  int i = 0;
  for (i = exponent; i > 0; i--) {
    result = result * base;
  }

  return result;
}
void toArrayCopier(char * polynom, char * Polyarr[], char * evalNum, int length) { //it copies the polynom elements to an array each index is seperated when + is found

  int i;

  char * stored; //stores each element before +

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
      if (strstr(stored, "x")) {
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
      if (strstr(stored, "x")) {
        HowManyX++;
      }
      j++;
      strcpy(stored, "");

    }

  }
  free(stored); //free
  free(evalNum); //free

}
void * evaluator(void * equation) { //thread function for evaluating a specific polynom using a specific given array index each time

  char * subEq = ((char * ) equation);
  char * coeffNum;
  int number = 0;
  char * Power = 0;
  coeffNum = (char * ) malloc(strlen(subEq) + 1 * sizeof(char)); //allocating memory for the string
  if (coeffNum == NULL) {
    exit(1); //if any error has occured
  }
  Power = (char * ) malloc(strlen(subEq) + 1 * sizeof(char)); //allocating memory for the string
  if (Power == NULL) {
    exit(1); //if any error has occured
  }

  int power;
  strcpy(Power, "");
  strcpy(coeffNum, "");
  int length = strlen(subEq);
  int i;

  int * res = malloc(sizeof(int));

  for (i = 0; i < length; i++) {

    if (subEq[i] != 'x') { //if the first char was numbers not x

      strncat(coeffNum, & subEq[i], 1);

    } else {

      if (i == 0) { //if x was the first char

        for (i = 1; i < length; i++) {

          strncat(Power, & subEq[i], 1);

        }
        if (length != 1) {
          power = atoi(Power);
          int x_After_power = Pow(Evalnum, power);
          int answer = x_After_power;
          * res = answer;

          free(coeffNum);
          free(Power);
          return ((void * ) res);
        } else {
          int answer = Evalnum;
          * res = answer;

          free(coeffNum);
          free(Power);
          return ((void * ) res);
        }

      } else {
        int answer;

        number = atoi(coeffNum);

        i++;

        if (i != length) { //take all the power of x 
          for (i = i; i < length; i++) {

            strncat(Power, & subEq[i], 1);

          }

          power = atoi(Power);
          int x_After_power = Pow(Evalnum, power);
          answer = x_After_power * number;
        } else {

          answer = Evalnum * number;

        }

        * res = answer;

        free(coeffNum);
        free(Power);

        return ((void * ) res);

      }

    }
  }

  return NULL;
}

void ToNewArray_Only_with_x(char * Arr[], char * Arr2[]) { //move all x elements to an array

  int i;
  int k = 0;

  for (i = 0; i <= j; i++) {

    if (strstr(Arr[i], "x")) {

      Arr2[k] = (char * ) malloc(strlen(Arr[i]) + 1 * sizeof(char)); //allocating memory for the string
      if (Arr2[k] == NULL) {
        exit(1); //if any error has occured
      }

      strcpy(Arr2[k], Arr[i]);

      k++;

    }

  }
}
void toArray_Only_with_numbers(char * Arr[], int * Arr2[]) { //move all number elements to another array

  int i;
  int k = 0;
  for (i = 0; i <= j; i++) {

    if (!strstr(Arr[i], "x")) {
      Arr2[k] = (int * ) malloc(sizeof(int));
      if (Arr2[k] == NULL) {
        exit(1);
      }
      int number = atoi(Arr[i]);
      * Arr2[k] = number;

      k++;

    }
  }

}

int NUMarr_Sumer(int * arr[], int length) { //it sums all the numbers in a polynom using the  number array.

  int i;
  int sum = 0;
  for (i = 0; i < length; i++) {

    sum += * arr[i];

  }
  return sum;

}

//**********MAIN*************

int main() {

  while (1) {

    char polynom[510]; //polynom that we get from the input
    char * evalNum; // it contains the number we wanna evaluate in a polynom
    int length; //the length of the polynom
    int i;

    fgets(polynom, 510, stdin); //get from the user

    polynom[strlen(polynom) - 1] = '\0'; //dont get the space

    if (strcmp(polynom, "done") == 0) {

      break;
    } else {
      length = strlen(polynom);
      char * Polyarr[length]; //array of the polynom elements 

      toArrayCopier(polynom, Polyarr, evalNum, length); //copy all the elements to the polyarr array

      char * Polyarr_With_x_only[HowManyX]; //an array holding all the x containing elements

      int lengthOfNumArray = j - HowManyX + 1; //the length of the number array

      int * NUMarray[lengthOfNumArray]; //an array of the number elements only

      ToNewArray_Only_with_x(Polyarr, Polyarr_With_x_only); // copying the elements that contain x only to the Polyarr_With_x_only array

      toArray_Only_with_numbers(Polyarr, NUMarray); // copying the elements that contain numbers only to an array

      int threadNum = HowManyX; //thread numbers 

      //threads starts here

      int i, status, * res;
      int sum = 0;
      pthread_t thread_data[threadNum]; //creating threads 

      for (i = 0; i < threadNum; i++) {

        status = pthread_create( & thread_data[i], NULL, evaluator, (void * ) Polyarr_With_x_only[i]); //directing the threads

        if (status != 0) {
          fputs("failed to create thread", stderr);
          exit(EXIT_FAILURE);
        }
      }
      for (i = 0; i < threadNum; i++) {

        pthread_join(thread_data[i], (void ** ) & res); //gettting the answer from each thread

        sum += * res; //sum all the evaluations of the x array 

        free(res);

      }
      sum = sum + NUMarr_Sumer(NUMarray, lengthOfNumArray); //sum the final answer of the x evaluations with the final answer of the numbers sum.

      printf("%d\n", sum);

      for (i = 0; i <= j; i++) {//free space

        free(Polyarr[i]);

      }
      for (i = 0; i < HowManyX; i++) {//free space

        free(Polyarr_With_x_only[i]);

      }
      for (i = 0; i < lengthOfNumArray; i++) {//free space

        free(NUMarray[i]);

      }

    }

    j = 0; //resetting the length of the general array
    HowManyX = 0; //resetting 

  }

  return 0;
}
