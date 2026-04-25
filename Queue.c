#include <stdio.h>
#include <stdlib.h>
#define max_size 5
int queue[max_size], front = -1, rare = -1;
void insert(int value) {
if (rare == max_size - 1) {
    printf("\n\tQueue is overflow\n");
}
    else {
        if (front == -1) {
            front = 0;
        }
        queue[++rare] = value;
        printf("\n\t%d has been inserted into the queue\n", value);
    }
}
void delete() {
if (front == -1 || front > rare) {
    printf("\n\tQueue is underflow\n");
    }
    else {
        printf("\n\t%d has been deleted from the queue\n", queue[front++]);
        if (front > rare) {
            front = rare = -1;
        }
    }
}
void display() {
if (front == -1 || front > rare) {
    printf("\n\tQueue is empty\n");
}
else {
    printf("\n\tThe elements in the queue are : \n");
    for (int i = front; i <= rare; i++) {
        printf("\t%d\n", queue[i]);
    }
}
}
int main() {
int choice, x;
printf("\n\t Queue operations using Array");
printf("\n\t----\n");
do {
printf("\n\t1. Insert\n\t2. Delete\n\t3. Display\n\t4. Exit\n");
printf("\n\t Enter the choice : ");
scanf("%d", &choice);
switch (choice) {
    case 1:
    printf("\n\tEnter a value to be inserted : ");
    scanf("%d", &x);
    insert(x);
    break;
    case 2:
    delete();
    break;
    case 3:
    display();
    break;
    case 4:
    printf("\n\t Exit Point\n");
    break;
    default:
    printf("\n\t Please Enter a valid choice 1/2/3/4\n");
    }
}
while (choice != 4);
return 0;
}
