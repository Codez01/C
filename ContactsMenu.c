#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


#define N 100
#define TRUE 1
#define FALSE 0
//-------------------------------------
char * contacts[N];
char str[50];
int icounter;
int i ;
int z;
int afterCounter =0;
int deletedCounter=0;
bool checker=false;
void ENTER();
void search(char*contacts[N] ,char name[50]);
void searchForDelete(char*contacts[N] ,char name[50]);
void delete(char*contacts[N] ,char name[50]);
void deleteContact(char*contacts[N] ,char name[50]);
void print(char*contacts[N]);
void printMenu();
void enterSpace();

//-------------------------------------------
int main()
{

  int na = 0;//k

     int enter;
     
    
     while (na != -1)
     {
          printMenu();
          
         scanf("%d", &enter);
         
         
          if (enter == 1)
          {

           enterSpace();
            ENTER();
               
          }

          if (enter == 2)
          {

            char searcher[50];
            scanf( "%s", searcher);
            search(contacts ,searcher);

          }

          if (enter == 3){
          
            char searcher[50];
            scanf( "%s", searcher);
              searchForDelete(contacts ,searcher);
            if(checker==true){

    delete(contacts ,searcher);
          i=i-(i-z);
     checker = false;
 
        }
          }

          if (enter == 4)
          {
char searcher[50];
            scanf( "%s", searcher);
              searchForDelete(contacts ,searcher);
              
 if(checker==true){

   deleteContact(contacts ,searcher);
     i=i-(i-z+1);
    checker = false;
 
 }
          }

          if (enter == 5)
          {
               
     print(contacts);
          }
          if(enter== 6){

            break;
          }
     }

return 0;
}
//--------------------------------------------------------



void ENTER(){


int counter1=0;
int counter2 = 0;
int counter3= 0;

if(i<=97){



if(i==97){//iza ==97

  printf("\nplease write a name\n");

 fgets(str , 50 ,stdin);



contacts[i] = (char*)malloc(sizeof(char)*strlen(str)+1 );
strcpy(contacts[i], str);
icounter =i;


int j=0;
i=i+2;







printf("please write one  email");

fgets(str , 50 ,stdin);
contacts[i] = (char*)malloc(sizeof(char)*strlen(str)+1 );

strcpy(contacts[i], str);




    

    //stores rakam b tani index mn icounter
    contacts[icounter+1] = (char*)malloc(sizeof(char)*strlen(str)+1 );

strcpy(contacts[icounter+1],"1");
printf("you can't write more emails than that!");


  
}
else{






//hoon il asli
printf("please write a name\n");

fgets(str , 50 ,stdin);
fgets(str , 50 ,stdin);


contacts[i] = (char*)malloc(sizeof(char)*strlen(str)+1 );
strcpy(contacts[i], str);
icounter =i;


int j=0;
i=i+2;


int endcounter= 97;

while(j!=-1){


printf("please write an email \n");

fgets(str , 50 ,stdin);


if(strcmp(str, "end")== 10){

  break;
}
if(i>100){
printf("\n you cant write more emails.. \n");
  break;
}


contacts[i] = (char*)malloc(sizeof(char)*strlen(str)+1 );

strcpy(contacts[i], str);

counter2++;
i++;


    }

    //stores rakam b tani index mn icounter
    contacts[icounter+1] = (char*)malloc(sizeof(char)*strlen(str)+1 );


 char buffer[20];



 sprintf(buffer, "%d", counter2);

strcpy(contacts[icounter+1],buffer);  





}

}
else{

printf("\nyou can't enter more users!\n");
}







 






  }

  void search(char*contacts[N] ,char name[50]){
    bool check =false;
   
    for(int k=0; k<i; k++){
      
       
      if(strcmp(contacts[k], name)-10==0 ){
         
      printf("\nUser: %s , is found! \n",name);
        check=true;
        checker=true;

      printf("%s's , email / emails : \n",name);
      
         int x = atoi(contacts[k+1]);
   
    for( int f=k+2; f<k+2+x; f++){
   
    printf("%s", contacts[f]);


        }
        
       
        break;




    }

    



  }
  if(check == false){
    printf("\nthe user is not found .. \n");

  }



  }
  void delete(char*contacts[N] ,char name[50]){
int X;
int K;


        bool check =false;
    for(int k=0; k<i; k++){

      if(strcmp(contacts[k], name)==10){
     
        check=true;
         
        int x = atoi(contacts[k+1]);// =3
        x=x+1;
        X=x;
        K=k; 
        z=i-x;      

        


    for( int f=k+1; f<=k+x; f++){
       free(contacts[f]);
       }
  }
    }
  int v =0;
while( v!=-1){


 
  if(K+X+1==i){
    break;
  }

contacts[K+1] = (char*)malloc(sizeof(char)*strlen(contacts[K+X+1])+1 );
strcpy(contacts[K+1],contacts[K+X+1]);
 afterCounter++; 
  free(contacts[K+X+1]);
  

K++;

}


}

  void searchForDelete(char*contacts[N] ,char name[50]){
    bool check =false;
   
    for(int k=0; k<i; k++){
      
       
      if(strcmp(contacts[k], name)-10==0 ){
         
   
        check=true;
        checker=true;

    
      
         int x = atoi(contacts[k+1]);
   
    for( int f=k+2; f<k+2+x; f++){
   
  


        }
        
       
        break;




    }

    



  }
  if(check == false){


  }



  }

void deleteContact(char*contacts[N] ,char name[50]){
int X;
int K;


        bool check =false;
    for(int k=0; k<i; k++){

      if(strcmp(contacts[k], name)==10){
     
        check=true;
        deletedCounter++;
     
     
        int x = atoi(contacts[k+1]);// =3

        if(x==0){


        x=x+1;
        X=x;
        K=k; 
        z=i-0;      

        


       free(contacts[k]);
       }


        
        else{


        x=x+1;
        X=x;
        K=k; 
        z=i-x;      

        


    for( int f=k; f<=k+x; f++){
       free(contacts[f]);
       }
  }
      }
    }
  int v =0;
while( v!=-1){


 if(X-1==0){
    if(K+1==i){
    break;
  }

contacts[K] = (char*)malloc(sizeof(char)*strlen(contacts[K+1])+1 );
strcpy(contacts[K],contacts[K+1]);
 afterCounter++; 
  free(contacts[K+1]);
  

K++;

 }
 else{
  if(K+X+1==i){
    break;
  }

contacts[K] = (char*)malloc(sizeof(char)*strlen(contacts[K+X+1])+1 );
strcpy(contacts[K],contacts[K+X+1]);
 afterCounter++; 
  free(contacts[K+X+1]);
  

K++;

}
}

}
























void print(char*contacts[N] ){



for(int n=0; n<i; n++){
   
   printf("%s \n", contacts[n]);

   }


}
void printMenu(){

printf("1. Enter new contact");
printf("\n");

printf("2. Search contact");
printf("\n");

printf("3. Delete mail from contact");
printf("\n");

printf("4. Delete Contact");
printf("\n");

printf("5. Print.");
printf("\n");

printf("6. Exit.");
printf("\n");






}
void enterSpace(){
  printf("\n");
}