#include <stdio.h>

int main() {
    
    
 char first[2];// the first String
 char sec[2];//the second string
 int edge;// the edge number
 
 printf(" Please enter the first character: ");
 scanf("%s" , &first);
  printf(" Please enter the second character: ");
 scanf("%s" , &sec);
 
  printf(" Please enter the edge size: ");
 scanf("%d" , &edge);

  if(edge > 1){//the minimum edge number should be 2 
  if( edge%2 == 0){//if it is even
  for(int i = 1 ; i<= edge; i++){
      
      for(int j = (i-1)-((edge/2)-1); j<= edge-j; j++){
          
          
          printf("%s",first);
      }
        int edge2 = edge-i;
        
        
      while(edge2!=edge){
          
          printf("%s", sec);
          
          edge2++;
          
          
          
      }
      

      printf("\n");
         
      
      
      
  }
  }else{// if the edge number is odd
  for(int i = 1 ; i<= edge; i++){
      
      for(int j = (i-1)-(edge/2); j<= edge-j; j++){
          
          
          printf("%s",first);
      }
       int edge2 = edge-i;
       
        
        
      while(edge2!=edge){
          
          printf("%s",sec);
          
          edge2++;
          
          
          
      }
    
      printf("\n");
         
      
      
      
  }
  }
  }
   
    
    return 0;
                }