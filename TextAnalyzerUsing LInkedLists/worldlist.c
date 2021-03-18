#include"worldlist.h"
#include <string.h>
#include<stdio.h>

WordList* createList()
{
    WordList* temp=(WordList*)malloc(sizeof(WordList));
    temp->head=NULL;
    return temp;
}
void printList(WordList* list)
{
    if(list->head==NULL){
        printf("The List was destroy\n");
        return;
    }
    WordNode* temp=list->head;
    while(temp!=NULL)
    {
        printf("%s, %d\n",temp->wordData.data,temp->wordData.occurrences);
        temp=temp->next;
    }
}
void addSorted(WordList* list, char* data)
{
    if(list->head==NULL)
    {
        WordNode* temp=(WordNode*)malloc(sizeof(WordNode));
        temp->wordData.data=(char*)malloc(sizeof(char)*(strlen(data)+1));
        temp->wordData.occurrences=1;
        strcpy(temp->wordData.data, data);
        list->head=temp;
        temp->next=NULL;
        return;
    }
    if(strcmp(list->head->wordData.data,data)>=0)
    {
        if(strcmp(list->head->wordData.data,data)>0)
        {
            WordNode* temp=(WordNode*)malloc(sizeof(WordNode));
            temp->wordData.data=(char*)malloc(sizeof(char)*strlen(data)+1);
            temp->wordData.occurrences=1;
            strcpy(temp->wordData.data, data);
            temp->next=list->head;
            list->head=temp;
        }
        else
            list->head->wordData.occurrences= list->head->wordData.occurrences+1;
        return;
    }
    WordNode* temp=list->head;
    WordNode* prev=list->head;
    while(temp!=NULL)
    {
        if(strcmp(temp->wordData.data,data)>=0)
        {
            if(strcmp(temp->wordData.data,data)>0)
            {
                WordNode* new_node=(WordNode*)malloc(sizeof(WordNode));
                new_node->wordData.data=(char*)malloc(sizeof(char)*(strlen(data)+1));
                new_node->wordData.occurrences=1;
                strcpy(new_node->wordData.data, data);
                prev->next=new_node;
                new_node->next=temp;
            }
            else
                temp->wordData.occurrences= temp->wordData.occurrences+1;
            return;
        }
        prev=temp;
        temp=temp->next;
    }
    WordNode* new_node=(WordNode*)malloc(sizeof(WordNode));
    new_node->wordData.data=(char*)malloc(sizeof(char)*(strlen(data)+1));
    new_node->wordData.occurrences=1;
    strcpy(new_node->wordData.data, data);
    prev->next=new_node;
    new_node->next=NULL;
}