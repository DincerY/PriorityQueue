#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
    int value;
    struct Queue * next;
} queue;

queue * createNewQueue(int value){
    queue *newQueue;
    newQueue = (queue *)malloc(sizeof(queue));
    newQueue->value = value;
    newQueue->next = NULL;
    return newQueue;
}

queue * insert(queue * q,int value){
    queue * result = q;
    if(q == NULL){
        return createNewQueue(value);
    }
    else if(q->next == NULL){
        if(q->value >= value){
            q->next = createNewQueue(value);
        }
        else{
            queue * created = createNewQueue(value);
            created->next = q;
            return created;
        }
    }
    else{
        while(q->next != NULL){
            queue * dummyNode = createNewQueue(0);
            dummyNode->next = q;
            queue * left = dummyNode;
            queue * right = dummyNode->next;
            while(right != NULL && right->value > value){
                left = right;
                right = right->next;
            }

            queue * temp = left->next;
            queue * created= createNewQueue(value);
            left->next = created;
            created->next = temp;
            return dummyNode->next;
        }
    }

    return result;

}

void printLinkedListValue(queue * q){
    while (q!=NULL){
        printf("%d\n",q->value);
        q = q->next;
    }
}

queue * dequeue(queue* q){
    q = q->next;
    return q;
}

int main() {

    queue * head = NULL;
    head = insert(head,10);
    head = insert(head,15);
    head = insert(head,20);
    head = insert(head,12);
    head = insert(head,5);
    head = insert(head,3);
    head = insert(head,2);
    head = insert(head,8);
    head = insert(head,7);
    printLinkedListValue(head);

    head = dequeue(head);
    head = dequeue(head);
    head = dequeue(head);

    printf("after removed\n");
    printLinkedListValue(head);

    return 0;
}
