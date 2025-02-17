#include <stdio.h>
#define SIZE 5  // Define the maximum size of the queue

// Queue structure
struct Queue {
    int items[SIZE];  // Array to store queue elements
    int front;  // Index of the front element
    int rear;   // Index of the rear element
};

// Function to initialize the queue
void initializeQueue(struct Queue *q) {
    q->front = -1;  // Indicates the queue is empty
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(struct Queue *q) {
    return q->rear == SIZE - 1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

// Function to enqueue (insert) an element into the queue
void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d.\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;  // Set front to 0 when inserting first element
    }
    q->rear++;  // Move rear forward
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to dequeue (remove) an element from the queue
void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }
    printf("Dequeued: %d\n", q->items[q->front]);
    q->front++;  // Move front forward
}

// Function to display the queue elements
void displayQueue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;  // Declare a queue instance
    initializeQueue(&q);  // Initialize the queue

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);  // Should print queue is full

    displayQueue(&q);  // Display current queue

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    
    displayQueue(&q);  // Display queue after dequeuing
    
    return 0;
}
