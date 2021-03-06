
#include "stack.h"

node *createNode(cache element){
	node *temp = (node *) malloc(sizeof(node));
	if (temp == NULL) {
		fprintf(stderr, "\n (!) Memory allocation not successed\n");
		return NULL;
	}
	temp->action = element;
	temp->next = NULL;
	return temp;
}
void initStack(node **top) {
	*top = NULL;
}
int isEmpty(node *top) {
	return (top == NULL);
}
void push(node **top, cache element) {
	node *new = createNode(element);
	if (*top == NULL) {
		*top = new;
	} else {
		new->next = *top;
		*top = new;
	}
}
cache pop(node **top) {
	if (isEmpty(*top)) {
		fprintf(stderr, "\n (!) No longer take action to undo.\n");
        cache empty;
        empty.direc = -1;
        empty.boxMove = -1;
        return empty;
	}
	node *del = *top;
	*top = (*top)->next;
	cache temp = del->action;
	return temp;
}
void freeStack(node *top) {
    node *del = top;
    while (top != NULL) {
        top = top->next;
        free(del);
        del = top;
    }
}
