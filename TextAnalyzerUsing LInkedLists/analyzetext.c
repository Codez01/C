#include"worldlist.h"
#include<stdio.h>

int main()
{
    WordList* list = createList();
    addSorted(list, "abc");
    printList(list);

    return 0;
}
