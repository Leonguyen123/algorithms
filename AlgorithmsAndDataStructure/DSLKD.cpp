//
//  DSLKD.cpp
//  AlgorithmsAndDataStructure
//
//  Created by Elpulga Nguyen on 27/10/25.
//

#include <iostream>
using namespace std;

// Khai báo struct, bao gồm 2 thông tin là info chứa giá trị, next chứa địa chỉ tiếp theo.
struct node {
    int info;
    node *next;
};

typedef node* PTR; // Khai báo một con trỏ có kiểu là node có tên là PTR;

void initializer(PTR &First){
    First = NULL;
}

void insert_First(PTR &First, int info){
    PTR p = new node;
    p->info = info;
    p->next = First; // Tại vì cần trỏ đến địa chỉ vùng nhớ của next hiện tại.
    First = p; // Sau đó gán địa chỉ First bằng địa chỉ của p hiện tại.
}

int delete_First(PTR &First){
    if(First == NULL) return 0;
    
    PTR p = First;
    First = p->next;
    delete p;
    
    return 1;
}

int insert_after(PTR p, int x){
    
    if(p == NULL) return 0;
    
    PTR q = new node;
    q->info = x;
    q->next = p->next;
    p->next = q;
    
    return 1;
}

int delete_after(PTR p){
    if(p == NULL) return 0;
    
    PTR q = p->next;
    p->next = q->next;
    
    delete q;
    
    return 1;
}

PTR search(PTR First, int info){
    for(PTR p = First; p != NULL; p=p->next){
        if(p->info == info) return p;
    }
    return NULL;
}
