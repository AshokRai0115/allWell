#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
  int queue[MAX_SIZE];
  int front;
  int rear;
  int num_items;
} Queue;

Queue* create_queue() {
  Queue* q = (Queue*) malloc(sizeof(Queue));
  q->front = 0;
  q->rear = -1;
  q->num_items = 0;
  return q;
}

void enqueue(Queue* q, int value) {
  if (q->num_items == MAX_SIZE) {
    printf("Error: Queue is full\n");
  } else {
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->queue[q->rear] = value;
    q->num_items++;
  }
}

int dequeue(Queue* q) {
  if (q->num_items == 0) {
    printf("Error: Queue is empty\n");
    return -1;
  } else {
    int value = q->queue[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->num_items--;
//    return value;
    printf("Dequeued: %d \n", value);
  }
}

void print_queue(Queue* q) {
	int i;
  printf("Queue: ");
  for (i = q->front; i <= q->rear; i++) {
    printf("%d ", q->queue[i]);
  }
  printf("\n");
}

int main() {
  Queue* q = create_queue();
	int choice, value;

	printf("Enter 1 to enqueue:\n");
	printf("Enter 2 to dequeue:\n");
	printf("Enter 3 to Print queue:\n");
	printf("Enter 4 to exit:\n");
while(1){
	printf("Enter the choice: \n");
	scanf("%d", &choice);
	switch(choice){
	case 1:
		
		printf("Enter the value: ");
		scanf("%d", &value);
		enqueue(q, value);
		break;
	case 2:
		dequeue(q);
		break;
	case 3:
		print_queue(q);
		break;
	case 4:
		exit(1);
		break;
	default:
		printf("Enter the valid choice.");
	}
}


  return 0;
}

