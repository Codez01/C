// wordlist.h
#ifndef WORD_LIST_H
#define WORD_LIST_H
typedef struct {
	char *data;
	int occurrences;
}Word;
typedef struct wordnode {
	Word wordData;
	struct wordnode *next;
}WordNode;
typedef struct {
	WordNode* head;
}WordList;

WordList* createList();
void addSorted(WordList* list, char* data);
void printList(WordList* list);

#endif
