//
//  DSLK1.h
//  AlgorithmsAndDataStructure
//
//  Created by Elpulga Nguyen on 10/11/25.
//

#ifndef DSLK1_H
#define DSLK1_H

using namespace std;

struct Sinhvien {
    int maso;
    char firstName[40];
    char lastName[8];
    char mapb[20];
    double luong;
};

struct Node {
    Sinhvien sv;
    Node *next;
};

typedef Node *PTRSV;

int menusDSLK1(); // in ra menu danh sách liên kết.
void initializer(PTRSV &First); // Khởi tạo danh sách liên kết.
bool checkEmpty(PTRSV &First);
int traverseDSLKD1(PTRSV &First); // Duyệt danh sách liên kết đơn.
int insertFirst(PTRSV &First, Sinhvien x);
void swapNode(PTRSV &A, PTRSV &B);
void sortListByName(Node* head);

#endif
