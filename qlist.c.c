#include <stdio.h> 
#include <stdlib.h> 
 
struct Node { 
    int data; 
    struct Node* next; 
}; 
 
struct Node* front = NULL; 
struct Node* rear = NULL; 
 
int isEmpty() { 
    return front == NULL; 
} 
 
int isFull() { 
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
    if (temp == NULL) 
        return 1; 
    free(temp); 
    return 0; 
} 
 
void enqueue(int value) { 
    if (isFull()) { 
        printf("Queue Overflow! Cannot enqueue %d\n", value); 
        return; 
    } 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = value; 
    newNode->next = NULL; 
    if (rear == NULL) { 
        front = rear = newNode; 
    } else { 
        rear->next = newNode; 
        rear = newNode; 
    } 
    printf("%d enqueued to queue\n", value); 
} 
  
void dequeue() { 
    if (isEmpty()) { 
        printf("Queue Underflow! Queue is empty.\n"); 
    } else { 
        struct Node* temp = front; 
        printf("%d dequeued from queue\n", front->data); 
        front = front->next; 
        free(temp); 
        if (front == NULL) 
            rear = NULL; 
    } 
} 
 
void peek() { 
    if (isEmpty()) 
        printf("Queue is empty!\n"); 
    else 
        printf("Front element is: %d\n", front->data); 
} 
  
void display() { 
    if (isEmpty()) { 
        printf("Queue is empty!\n"); 
    } else { 
        struct Node* temp = front; 
        printf("Queue (linked list form):\nFront -> "); 
        while (temp != NULL) { 
            printf("%d -> ", temp->data); 
            temp = temp->next; 
        } 
        printf("NULL\n"); 
    } 
} 
 
int main() { 
    int choice, value; 
    while (1) { 
        printf("\n----- QUEUE MENU -----\n"); 
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. isEmpty\n5. isFull\n6. Display\n7. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter value to enqueue: "); 
                scanf("%d", &value); 
                enqueue(value); 
                break; 
            case 2: 
                dequeue(); 
                break; 
            case 3: 
                peek(); 
                break; 
            case 4: 
                if (isEmpty()) 
                    printf("Queue is empty\n"); 
                else 
                    printf("Queue is not empty\n"); 
                break; 
            case 5: 
                if (isFull()) 
                    printf("Queue is full (memory not available)\n"); 
                else 
                    printf("Queue is not full\n"); 
                break; 
            case 6: 
                display(); 
                break; 
            case 7: 
                printf("Exiting program...\n"); 
                exit(0); 
            default: 
                printf("Invalid choice! Try again.\n"); 
        } 
    } 
    return 0; 
}