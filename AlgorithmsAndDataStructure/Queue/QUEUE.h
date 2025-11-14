//
//  STACK.h
//  AlgorithmsAndDataStructure
//
//  Created by Elpulga Nguyen on 13/11/25.
//

/*
 - Queue là một danh sách hạn chế.
 - Thêm vào được thực hiện ở đầu danh sách
 - Loại bỏ được thực hiện ở đầu còn lại.
 - Vị trí để loại bỏ được gọi là Front(Vị trí xóa)
 - Vi trí thêm vào được gọi là Rear (thêm)
 */

#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 100

struct Queue {
    int data[MAX_QUEUE];
    int front;
    int rear;
};


int dequeue(Queue &q);
int enqueue(Queue &q);
bool isFull(Queue &q);
bool isEmpty(Queue &q);
void intitQueue(Queue &q);

#endif
