#include <stdio.h>
#include <stdlib.h>

/*****
This program implements a simple menu-driven queue using a linked list. The program defines a QUEUE structure that encapsulates a linked list of nodes. Each node contains an integer value and a pointer to the next node in the queue.

The program provides the following menu options:
1. Insert: Allows the user to insert an element into the queue.
2. Delete: Allows the user to delete an element from the front of the queue.
3. Print: Displays the elements in the queue.
0. Exit: Exits the program.

The main function initializes the queue, and a while loop presents the menu to the user. Depending on the user's choice, the corresponding function is called to perform the desired operation on the queue.

The insert function adds an element to the rear of the queue, delete function removes an element from the front, and printQueue function displays the elements in the queue.

The program continues to run until the user chooses to exit (option 0).
*****/

// Define the node structure
struct node {
    int info;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *NODEPTR;

// Define the QUEUE structure
typedef struct {
    NODEPTR front, rear;
} QUEUE;

// Function to insert an element into the queue
void insert(QUEUE *q, int elm) {
    NODEPTR newNode = (NODEPTR)malloc(sizeof(NODE));
    if (newNode == NULL) {
        printf("Memory allocation failed. Queue is full.\n");
        return;
    }
    newNode->info = elm;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Element %d inserted into the queue.\n", elm);
}

// Function to delete an element from the queue
int delete(QUEUE *q) {
    if (q->front == NULL) {
        printf("Queue is empty. Cannot delete.\n");
        return -1; // Return a sentinel value to indicate an empty queue
    }
    NODEPTR temp = q->front;
    int val = temp->info;

    q->front = q->front->next;
    free(temp);

    if (q->front == NULL) {
        q->rear = NULL;
    }

    return val;
}

// Function to print the elements in the queue
void printQueue(QUEUE q) {
    if (q.front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    NODEPTR temp = q.front;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    QUEUE q;
    q.front = q.rear = NULL;

    int menu, elm;
    // Display a menu for the user
    while (1) {
        printf("0. Exit\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print\n");
        printf("Enter your choice: ");
        scanf("%d", &menu);

        switch (menu) {
            case 0:
                exit(0); // Exit the program
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &elm);
                insert(&q, elm); // Call the insert function to add an element to the queue
                break;
            case 2:
                elm = delete(&q);  // Call the delete function to remove an element from the queue
                if (elm != -1) {
                    printf("Deleted element: %d\n", elm);
                }
                break;
            case 3:
                printQueue(q); // Call the printQueue function to display the elements in the queue
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}

/***

First Run ->

0. Exit
1. Insert
2. Delete
3. Print
Enter your choice: 1
Enter element to insert: 10
Element 10 inserted into the queue.
0. Exit
1. Insert
2. Delete
3. Print
Enter your choice: 1
Enter element to insert: 20
Element 20 inserted into the queue.
0. Exit
1. Insert
2. Delete
3. Print
Enter your choice: 3
Queue: 10 20 
0. Exit
1. Insert
2. Delete
3. Print
Enter your choice: 2
Deleted element: 10
0. Exit
1. Insert
2. Delete
3. Print
Enter your choice: 3
Queue: 20 
0. Exit
1. Insert
2. Delete
3. Print
Enter your choice: 0

***/

/***

Second Run ->

0. Exit
1. Insert
2. Delete
3. Print
Enter your choice: 1
Enter element to insert: 5
Element 5 inserted into the queue.
0. Exit
1. Insert
2. Delete
3. Print
Enter your choice: 1
Enter element to insert: 15
Element 15 inserted into the queue.
0. Exit
1. Insert
2. Delete
3. Print
Enter your choice: 3
Queue: 5 15 
0. Exit
1. Insert
2. Delete
3. Print
Enter your choice: 2
Deleted element: 5
0. Exit
1. Insert
2. Delete
3. Print
Enter your choice: 3
Queue: 15 
0. Exit
1. Insert
2. Delete
3. Print
Enter your choice: 0


***/