#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>



int counter=1;
char a[100], b[100];

void compress(char src[],char result[]);
void decompress(char src[],char result[]);

int charToInt(char c);





void compress(char src[],char result[]){
int len =strlen(src);//length of the string
int i;
int k=0;




//----------------------------------------------------
for(i=0;i<len;i++){
        if(src[i]==src[i+1]){
        counter++;
    }
else{
        if(counter==1){
        result[k]=src[i];
        k++;
        }
else{
            result[k]=src[i];
            result[k+1]=counter+'0';
            k+=2;
        }
        counter=1;
    }



    result[k]='\0';



}
}

//-----------------------------------------
int Chartoint(char c)
{
    if((c >= '0' && c <= '9'))
        return (c-'0');
    return -1;
}
//---------------------------------------------------------
void decompress(char src[],char result[]){
    int i;
    int k=0;

    int len=strlen(src); //length of the string
    for(i=0; i<len; i++){

if((src[i]>='a' && src[i]<='z')){
            result[k]=src[i];
            
        k++;
        }
else{
            int mem=Chartoint(src[i]);

while(mem != 1){
                result[k]=src[i-1];
                k++;
                mem=mem-1;
            }

        }
    }
    result[k]='\0';
}





int main() {

   printf("Enter string:\n");
   scanf("%s", a);
   compress(a, b);
   printf("The compressed string is: %s\n", b);
   decompress(b,a);
   printf("The original string is: %s\n", a);
   return 0;
}
