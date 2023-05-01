#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct deque {
    int data[MAX_SIZE];
    int front;
    int rear;
};

void init(struct deque* q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(struct deque* q) {
    return (q->front == 0 && q->rear == MAX_SIZE - 1) || q->front == q->rear + 1;
}

int isEmpty(struct deque* q) {
    return q->front == -1;
}

void insertFront(struct deque* q, int data) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
        q->rear = 0;
    } else if (q->front == 0) {
        q->front = MAX_SIZE - 1;
    } else {
        q->front--;
    }
    q->data[q->front] = data;
}

void insertRear(struct deque* q, int data) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
        q->rear = 0;
    } else if (q->rear == MAX_SIZE - 1) {
        q->rear = 0;
    } else {
        q->rear++;
    }
    q->data[q->rear] = data;
}

int deleteFront(struct deque* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int data = q->data[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else if (q->front == MAX_SIZE - 1) {
        q->front = 0;
    } else {
        q->front++;
    }
    return data;
}

int deleteRear(struct deque* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int data = q->data[q->rear];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else if (q->rear == 0) {
        q->rear = MAX_SIZE - 1;
    } else {
        q->rear--;
    }
    return data;
}

int main() {
    struct deque q;
    init(&q);

    insertFront(&q, 1);
    insertFront(&q, 2);
    insertRear(&q, 3);
    insertRear(&q, 4);
    printf("%d ", deleteFront(&q));
    printf("%d ", deleteRear(&q));
    printf("%d ", deleteFront(&q));
    printf("%d ", deleteRear(&q));
    printf("\n");

    return 0;
}
