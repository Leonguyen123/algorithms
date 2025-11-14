
//  main-stack.cpp
//  AlgorithmsAndDataStructure
//
//  Created by Elpulga Nguyen on 13/11/25.

/*
 FIFO – First In First Out
 - Queue là một danh sách hạn chế.
 - Thêm vào được thực hiện ở đầu danh sách
 - Loại bỏ được thực hiện ở đầu còn lại.
 - Front trỏ đến node đầu (để pop (xóa) nhanh hơn)
 - Rear trỏ đến node cuối (push(thêm) nhanh hơn)
 */

#include <iostream>
#include "QUEUE.h"

using namespace std;

void intitQueue(Queue &q){
    q.front = q.rear = -1;
}

bool isFull(Queue &q){
    return q.rear == MAX_QUEUE - 1;
}

bool isEmpty(Queue &q){
    return q.rear == -1;
}

int endqueue(Queue &q, int x){
    if (isFull(q)) return 0;
    
    // Nếu queue đang rỗng -> tăng font là 0
    if (isEmpty(q)) {
       q.front = 0;
    }
    
    q.data[++q.rear] = x;
    
    return 1;
}

int dequeue(Queue &q, int x){
    if(isEmpty(q)) return 0;
    
    int value = q.data[q.front];
    
    // Nếu chỉ còn một phần tử, thì front và rear sẽ chạm nhau.
    if(q.front == q.rear){
        q.front = q.rear = -1;
    }else{
        q.front++;
    }
    
    return value;
}

int main(){
    
    Queue q;
    intitQueue(q);
    
    bool loop = true;
    
    while(loop)  {
            default:
                break;
        }
    }
    
    return 1;
}
