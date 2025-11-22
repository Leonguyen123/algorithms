//
//  STACK.h
//  AlgorithmsAndDataStructure
//
//  Created by Elpulga Nguyen on 13/11/25.
//

#ifndef STACK_H
#define STACK_H

#define STACKSIZE 6

// Khai báo cấu trúc của stack
struct Stack {
    int nodes[STACKSIZE]; // mảng chứa các phần tử của stack
    int sp; // stack pointer – con trỏ đỉnh, khởi tạo tại đây
};

// Stack rỗng: khi sp = -1; nếu = 0 thì sẽ là phần tử thứ 0 nodes[0]
// Stack đầy: khi sp = STACKSIZE - 1;

void initStack(Stack &st);
bool checkEmpty(Stack &st);
bool checkFull(Stack &st);
int push(Stack &st, int x); // Thêm phần tử vào stack
int pop(Stack &st, int x); // loại bỏ phần tử
int insertFunction(Stack &st);
int menusStack();
void traverseFromTop(Stack &st);

#endif
