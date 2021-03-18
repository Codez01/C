#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
const int MAX_NUMS = 20;
const int MAX_DEC_NUMBER = 255;
#define DEC 10
#define BIN 2
#define OCT 8

int main()
{

     int currBase = DEC;
     int numScan;

     int counter1 = 0;

     int numsArr[MAX_NUMS];
     char numStr[20];

     char number_str[20];
     int number;

     int numScan2;
     int numScan3;
     int totalNums = 0;

     //----------------------------METHODS-----------------------------------------

     int charToInt(char c)
     {//this method takes a character and changes it to int
          if (c < 48 || c > 57)
               return -1;
          int res = c - 48;
          return res;
     }

     //----------------------------------------------------------------

     //digit counter method
     int digit_counter(int number)//it counts the digit of a number
     {

          int counter = 0;
          while (number != 0)
          {

               number /= 10;
               counter++;
          }
          return counter;
     }
     //---------------------------------------------------

     int pow(int x, int y)
     {//it returns x power y
          int z = 1;

          for (int i = 0; i < y; i++)
          {
               z *= x;
          }
          return z;
     }

     //method 2
     int stringToInt(char number[], int base)
     {//it changes the string from the base specified(octacl/binary ) to a decimal number

          if (base == DEC)
          {
               int res = 0;
               for (int i = 0; i < strlen(number); i++)
               {
                    if (charToInt(number[i]) == -1)
                         return -1;
                    res = res * 10 + charToInt(number[i]);
               }
               return res;
          }
          if (base == BIN)
          {
               int length = strlen(number) - 1;
               int res = 0;
               for (int i = 0; i < strlen(number); i++)
               {
                    if (charToInt(number[i]) < 0 || charToInt(number[i]) > 1)
                         return -1;
                    res += charToInt(number[i]) * pow(BIN, length);
                    length--;
               }
               return res;
          }
          if (base == OCT)
          {
               int length = strlen(number) - 1;
               int res = 0;
               for (int i = 0; i < strlen(number); i++)
               {
                    if (charToInt(number[i]) < 0 || charToInt(number[i]) > 8)
                         return -1;
                    res += charToInt(number[i]) * pow(OCT, length);
                    length--;
               }
               return res;
          }
     }

     //------------------------------------------------------------------

     int intToString(int num, char numStr[], int base)
     { // from decimal to base(binary / octal)

          if (num <= MAX_DEC_NUMBER)
          { //if the number is less than 255 decimal

               if (base == OCT)
               { // if the base that we want to go to is Octal
                    int octalNumber = 0, i = 1;

                    while (num != 0)
                    {
                         octalNumber += (num % 8) * i;
                         num /= 8;
                         i *= 10;
                    }
                    *numStr = (char)octalNumber;

                    return octalNumber;
               }
               if (base == BIN)
               { // if the base was binary
                    int BinarNumber = 0, i = 1;

                    while (num != 0)
                    {
                         BinarNumber += (num % 2) * i;
                         num /= 2;
                         i *= 10;
                    }

                    *numStr = (char)BinarNumber;
                    
                    return BinarNumber;
               }
               if (base == DEC)
               {
                    return num;
               }
          }
          else
          {

               return -1;
          }
     }

     int isValidDigit(int digit, int base)
     {//if the number is valid it returns 1 else:0

          int mod;
          bool valid = true;

          while (digit != 0)
          {

               mod = digit % 10;

               if (mod >= base)
               {

                    valid = false;
                    break;
               }
               digit /= 10;
          }

          if (valid == true)
          {

               return TRUE;
          }
          else
          {

               return FALSE;
          }
     }

     //------------------------------------------------------------------------
     void printMenu(int base)
     {//prints the menu

          if (base == OCT)
          {
               currBase = OCT;
               printf("you are in Octal mode ");
          }
          if (base == DEC)
          {
               currBase = DEC;
               printf("you are in Decimal mode ");
          }
          if (base == BIN)
          {
               currBase = BIN;

               printf("you are in Binary mode ");
          }

          printf("\n");
          printf("1. Change Base.");
          printf("\n");
          printf("2. Enter a number. ");
          printf("\n");
          printf("3. Find a number.");
          printf("\n");
          printf("4. Get the amount  of even numbers.");
          printf("\n");
          printf("5. Print.");
          printf("\n");
          printf("6. Exit.");
          printf("\n");
     }

     int OutOfRange(int number, int base)
     { //checks if the number is out of range {
          if (base == DEC)
          {

               if (number > 255)
               {

                    return 1;
               }
               else
               {
                    return 0;
               }
          }

          if (base == OCT)
          {
               if (number > 1515)
               {

                    return 1;
               }
               else
               {
                    return 0;
               }
          }
          if (base == BIN)
          {

               if (number > 11111111)
               {
                    return 1;
               }
               else
               {
                    return 0;
               }
          }
     }

     int enterNumber(int numbers[], int totalNums, int base)
     {//it stores the entered number in the array numsArr if the number meets the rules

          int i = 0;
          scanf("%d", &numScan2);

          while (i != -1)
          {

               if (counter1 >= MAX_NUMS)
               {

                    printf("the array is full");
                    break;
               }

               if (isValidDigit(numScan2, base) == 1 && OutOfRange(numScan2, base) == 0)
               {
                    numbers[totalNums] = numScan2;

                    i = -1;
                    counter1++;

                    return TRUE;
               }

               if (isValidDigit(numScan2, base) == 0 && OutOfRange(numScan2, base) == 0)
               {

                    if (base == OCT)
                    {
                         printf("please enter a number in base : octal\n ");
                    }

                    if (base == DEC)
                    {
                         printf("please enter a number in base : decimal\n ");
                    }
                    if (base == BIN)
                    {
                         printf("please enter a number in base : Binary\n");
                    }
               }

               if (OutOfRange(numScan2, base) == 1)
               {

                    printf("the number is not in range \n");

                    printf("please enter a Number in range : ");
               }

               scanf("%d", &numScan2);
          }

          for (int j = totalNums; j < totalNums + 1; j++)
          {
               numsArr[j] = numbers[j];
          }
     }

     int find(int numbers[], int numKey, int totalNums)
     {//this method  finds a specific number in the array specified

          bool found = false;

          for (int i = 0; i < totalNums; i++)
          {

               if (numKey == numbers[i])
               {

                    found = true;
               }
               if (found == true)
               {

                    return TRUE;
                    break;
               }
          }
          return FALSE;
     }

     int ArraySize(int *Array)//it returns the size of an array
     {

          return (sizeof(Array) / sizeof(int));
     }

     int howManyEven(int numbers[], int totalNums)
     {


          int odd = 0;

          for (int i = 0; i < totalNums; i++)
          {

               odd += (numbers[i] & 1);
          }
          int even = totalNums - odd;
          return even;
     }
     
    
     void printArray(int numbers[], int totalNums)
     {//this method prints the following : dec , bin and octal

          printf("\t List of Numbers \n");
          printf("\t = = = = = = = = =\n");
          printf("\tDEC \tBIN \tOCT\n");

          for (int i = 0; i < totalNums; i++)
          {

               if (currBase == DEC)
               {
                    number = numbers[i];
                    sprintf(number_str, "%d", number);

                    printf("\t%s \t%08d \t%d \n",  number_str , intToString(stringToInt(number_str, DEC), numStr, BIN), stringToInt(number_str, OCT));
                    printf("\n\n");
               }
               if (currBase == BIN)
               {

                    number = numbers[i];
                    sprintf(number_str, "%d", number);

                   printf("\t%d \t%08d \t%d \n", stringToInt(number_str, BIN) , numbers[i] , intToString(stringToInt(number_str, BIN), numStr, OCT) );






                   // printf("\t%d \t%d \t%d ", stringToInt(number_str, BIN) ,numbers[0] ,intToString((stringToInt(number_str, BIN)), numsArr, OCT)) );
                    printf("\n\n");
               }
               if (currBase == OCT)
               {
                    number = numbers[i];
                    sprintf(number_str, "%d", number);

                   printf("\t%d \t%08d \t%s \n", stringToInt(number_str, 8) , intToString(stringToInt(number_str, 8), numStr, BIN),number_str );

               }
          }
     }

     // //---------------------------------------------------main

     int k = 0;
     int h = 0;
     int enter;
     int enter2;
      char StringEnter[1];
     while (k != -1)
     {
          printMenu(currBase);
          printf("choose an option (1-6)\n");

          scanf("%s",&StringEnter);//Scan into the string
          getchar();
        enter=stringToInt(StringEnter,DEC);//Convert to decimal number from string
        if(enter==0||enter>6||enter==-1)//if the enter was not from the one above
        {
            continue;
        }
          if (enter == 1)
          {
               printf("1.Decimal\n");
               printf("2.Binary\n");
               printf("3.Octal\n");
               printf("choose an option (1-3)\n ");
                scanf("%s",&StringEnter);//Scans the string
            enter2=stringToInt(StringEnter,DEC);//Convert to decimal number from string
            if(enter2==0||enter2>6||enter2==-1)//if enter wasn't any of the above
            {
            continue;
            }
               while (h != -1)
               {

                    if (enter2 == 1)
                    {

                         currBase = DEC;


                         break;
                    }
                    if (enter2 == 2)
                    {
                         currBase = BIN;
                       

                         break;
                    }
                    if (enter2 == 3)
                    {
                         currBase = OCT;
                        

                         break;
                    }
                    else
                    {
                         printf("please enter a valid number : ");
                         scanf("%d", &enter2);
                    }
               }


          }

          if (enter == 2)
          {

               printf("please enter a number: \n");

               printf("%d \n \n", enterNumber(numsArr, totalNums, currBase)); //total nums of the array adds 1 when any number is registered in the array
               totalNums++;
          }

          if (enter == 3)
          {
               printf("please write a number: ");
               scanf("%d", &numScan3);

               if (find(numsArr, numScan3, totalNums) == 1)
               {
                    printf("the number was found! \n\n\n");
               }
               else
               {
                    printf("the number was not found ! \n\n\n");
               }
          }

          if (enter == 4)
          {

               printf("The amount of even numbers : %d", howManyEven(numsArr, totalNums));
               printf("\n\n");
          }

          if (enter == 5)
          {

               printArray(numsArr, totalNums);
          }
          if(enter == 6){

k= -1;
break;

          }

     }

     printf("\n");

     return 0;
}