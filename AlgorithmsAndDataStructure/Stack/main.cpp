
//  main-stack.cpp
//  AlgorithmsAndDataStructure
//
//  Created by Elpulga Nguyen on 13/11/25.

#include <iostream>
#include "STACK.h"

using namespace std;

void initStack(Stack &st){
    st.sp = -1;
}

bool checkEmpty(Stack &st){
    return st.sp == -1;
}

bool checkFull(Stack &st){
    return st.sp == STACKSIZE - 1;
}

int push (Stack &st, int x)
{
   if(checkFull(st))  return 0;
   st.nodes[++(st.sp)] = x;
   return 1;
}

int pop(Stack &st, int &x)
{
   if(checkEmpty(st))  return 0;
   x=st.nodes[(st.sp)--];
   return 1;
}

int insertFunction(Stack &st){
    int value;
    char c;
    
    do {
        if(checkFull(st)){
            cout << "Stack đã đầy !";
            return 1;
        }
        
        cout << "Nhập giá trị vào stack: " << endl;
        cin >> value;
        
        int insertValue = push(st, value);
        cout << "Giá trị vừa được thêm vào là: " << insertValue << endl;
        
        cout << "Bạn có muốn tiếp tục không y/n ? ";
        cin >> c;
        
    } while (c == 'y');
    
    return 1;
}

void traverseFromTop(Stack &s) {
    if (checkEmpty(s)){
        cout << "Stack rong!\n";
        return;
    }

    cout << "Cac phan tu (tu dinh xuong day): ";
    for (int i = s.sp; i >= 0; i--) {
        cout << s.nodes[i] << " ";
    }
    cout << endl;
}


int menusStack(){
    int menu;
    cout << endl;
    cout << "0. Thoát chương trình" << endl;
    cout << "1. Nhập stack" << endl;
    cout << "2. Xem stack" << endl;
    
    cout << "Nhập chức năng: ";
    cin >> menu;
    
    return menu;
}

int main(){
    
    Stack st;
    initStack(st);
    
    bool loop = true;
    
    while(loop)  {
         int menu = menusStack();
        switch (menu) {
            case 0:
                loop = false;
                break;
            case 1:
                insertFunction(st);
                break;
            case 2:
                traverseFromTop(st);
                break;
            default:
                break;
        }
    }
    
    return 1;
}
