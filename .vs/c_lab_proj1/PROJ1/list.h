#ifndef LIST_H
#define LIST_H
typedef struct Node
{
	int data;
	struct Node* next;
} node;typedef struct LinkedList {
	node *head;
} LinkedList;void addNodeAtStart(LinkedList *list, int newData);void addNodeAtEnd(LinkedList *list, int newData);void addNodeIAfterJ(LinkedList *list, int i, int j);void printIndexNodeI(LinkedList *list, int I);void deleteIndex(LinkedList *list, int index);void printList(LinkedList *list);void exitProgram(LinkedList *list);#endif