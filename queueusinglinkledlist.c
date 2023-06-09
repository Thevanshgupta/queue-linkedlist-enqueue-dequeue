#include <stdio.h>
#include <stdlib.h>
struct Node {
int data;
struct Node* next;
};
struct Queue {
struct Node* front;
struct Node* rear;
};
struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
return newNode;
}
struct Queue* createQueue() {
struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
queue->front = queue->rear = NULL;
return queue;
}
int isEmpty(struct Queue* queue) {
return (queue->front == NULL);
}
void enqueue(struct Queue* queue, int data) {
struct Node* newNode = createNode(data);

if (isEmpty(queue)) {
    queue->front = queue->rear = newNode;
} else {
    queue->rear->next = newNode;
    queue->rear = newNode;
}

printf("Enqueued: %d\n", data);
}
void dequeue(struct Queue* queue) {
if (isEmpty(queue)) {
printf("Queue is empty. Cannot dequeue.\n");
return;
}
struct Node* temp = queue->front;
queue->front = queue->front->next;

if (queue->front == NULL) {
    queue->rear = NULL;
}
printf("Dequeued: %d\n", temp->data);
free(temp);
}
int main() {
struct Queue* queue = createQueue();
int choice, data;

while (1) {
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter the element to enqueue: ");
            scanf("%d", &data);
            enqueue(queue, data);
            break;

        case 2:
            dequeue(queue);
            break;

        case 3:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
    }

    printf("\n");
}
return 0;
}