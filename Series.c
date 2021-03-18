#include <stdio.h>


int main(){
    int First;// the first number 
    int Sec; // the second number , they always change.
    printf("Please enter a series of positive numbers (ending with a negative number):\n");
    scanf("%d %d \n",&First,&Sec);// enter the numbers
    
   
    if(First>=0){
        
    while(Sec >= 0){
			
    printf("%d ",(Sec-First));// print sec - first
    First=Sec;
    
    scanf("%d",&Sec);
    }
        
      }
    return 0;
}
