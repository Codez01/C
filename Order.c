#include <stdio.h>
int first;
int sec;
int third;
int array[3];
int max = 0;
int min =0;
int mid;
int order3(num);




int order3(int num){//this method sorts the a 3 digit number 
    
    if(((num/1000)==0)&&((num/100)!=0)&&((num/10)!=0)){//if the number is a 3 digit number only
   first =num/100;//first number
   sec = (num/10)%10;//sec number
   third = num%10;//third number
   
  array[0]=first;//it stores it into an array 
  array[1]= sec;
  array[2]=third;
  
  for(int i= 1 ; i< 3 ; i++){//checks the max number the min number and the mid number
      
      if( array[i] > array[max]){
          max = i;
      }
      if(array[i] < array[min]){
          min = i;
      }
      
  }
  if( first!= array[max] && first!= array[min]){ // sorts the numbers into --> minimum ,mid , max
      mid =first;
  }
    if( sec!= array[max] && sec!=  array[min]){
      mid =sec;
  }
    if( third!= array[max] && third!=  array[min]){
      mid =third;
  }
  printf("%d%d%d",array[min],mid,array[max]);
  
  
    
    
    }
    
    
    
    
}



                



//-----------------------------------------------------------------------------------------------------------------------------------------------




int k=0;
int number;

int main() {
    
    while(k!=-1){// if the number isn't  negative 
    
    printf("please enter a number with 3 digits :");
    scanf("%d" , &number);
    if(number>0){
        
        
        order3(number);//calls the function that sorts
        printf("\n");
        k++;
    }else{
        //if the number was negative 
        printf("End");
        k=-1;
    }
    
    
    
    }
    





return 0;


    
    
    
    
}


