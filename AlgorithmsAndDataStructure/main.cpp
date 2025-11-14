////
////  main.cpp
////  AlgorithmsAndDataStructure
////
////  Created by Elpulga Nguyen on 10/11/25.
////
//#include <iostream>
//#include <cstring>
//#include "DSLK1.h"
//
//using namespace std;
///*
// * Các bài toán về danh sách liên kết đơn.
// * Mọi thứ bên trong ký hiệu này sẽ được bỏ qua
// * Bạn có thể viết cả bài văn vào đây...
// */
//
//void initializer(PTRSV &First){
//    First = NULL;
//};
//
//bool checkEmpty(PTRSV &First){
//    if (First == NULL) return 1;
//    return 0;
//}
//
//int insertFirst(PTRSV &First, Sinhvien sv){
//  
//    PTRSV p = new Node;
//    p->sv = sv;
//    p->next = First;
//    First = p;
//    
//    return 1;
//};
//
//// Duyệt danh sách liên kết
//int traverseDSLKD1(PTRSV &First){
//    if (checkEmpty(First)){
//        cout << "Danh sach rong: " << endl;
//        return 0;
//    }
//    
//    PTRSV p = First;
//    while (p != NULL) {
//        cout << "Sinh viên: " << p->sv.maso << " - " <<  p->sv.lastName << " " << p->sv.firstName << endl;
//        p=p->next;
//    }
//    
//    return 1;
//}
//
//// Swap node
//void swapNode(PTRSV &nodeA, PTRSV &nodeB){
//    Sinhvien temp = nodeA->sv;
//    nodeA->sv = nodeB->sv;
//    nodeB->sv = temp;
//}
//
//void selectionSort(PTRSV &First){
//    for (PTRSV p = First; p != NULL; p = p->next) {
//        PTRSV minNode = p;
//        for (PTRSV q = p->next; q != NULL; q = q->next) {
//            if(minNode->sv.maso > q->sv.maso){
//                minNode = q;
//            }
//        }
//        if(minNode != p){
//            swapNode(p, minNode);
//        }
//    }
//}
//
//int inserAfter(PTRSV &p, Sinhvien sv){
//    
//    PTRSV q = new Node;
//    q->sv = sv;
//    q->next = p->next;
//    p->next = q;
//    
//    return 1;
//}
//
//int insertOrder(PTRSV &First, Sinhvien sv){
//    
//    PTRSV p = new Node;
//    p->sv = sv;
//    p->next = NULL;
//    
//    // Kiểm tra nếu mảng rỗng thì assign First
//    if (checkEmpty(First)){
//        First = p;
//        return 1;
//    }
//    
//    // Kiểm tra nếu chèn đầu
//    if(First->sv.maso > sv.maso){
//        insertFirst(First, sv);
//        return 1;
//    }
//    
//    p = First;
//    
//    while (p->next != NULL && p->next->sv.maso < sv.maso) {
//        p=p->next;
//    }
//        
//    inserAfter(p, sv);
//
//    return 1;
//}
//
//// Sort sinh viên theo tên và họ
//void sortListByName(Node* First) {
//    if (!First) return;
//    bool swapped;
//    do {
//        swapped = false;
//        Node* p = First;
//        while (p->next) {
//            // So sánh theo tên
//            if (strcmp(p->sv.firstName, p->next->sv.firstName) > 0 ||
//                (strcmp(p->sv.firstName, p->next->sv.firstName) == 0 && strcmp(p->sv.lastName, p->next->sv.lastName) > 0)) {
//                swapNode(p, p->next);
//                swapped = true;
//            }
//            p = p->next;
//        }
//    } while (swapped);
//}
//
//
//bool checkDuplicate(PTRSV &First, int maso){
//    PTRSV p = First;
//    while (p != NULL) {
//        if(p->sv.maso == maso) return 1;
//        p=p->next;
//    }
//    return 0;
//}
//
//int menusDSLK1(){
//    int menu;
//    cout << endl;
//    cout << "0. Thoát chương trình" << endl;
//    cout << "1. Xem danh sách" << endl;
//    cout << "2. Thêm sinh viên vào danh sách liên kết đơn" << endl;
//    cout << "3. Sắp xếp sinh viên theo mã sinh viên" << endl;
//    cout << "4. Thêm sinh viên theo thứ tự" << endl;
//    cin >> menu;
//    
//    return menu;
//}
//
//
///*
// * Các bài toán về danh sách tuyến tính
// * Mọi thứ bên trong ký hiệu này sẽ được bỏ qua
// * Bạn có thể viết cả bài văn vào đây...
// */
//
//void checkDuplicatePositiveInteger(vector<int> ds){
//    int dup[6] = {0};
//    
//    for (int i = 0; i < ds.size(); i++) {
//        dup[ds[i]]++;
//    }
//    
//    for (int i = 0; i < 6; i++) {
//        cout << dup[i] << ",";
//    }
//}
//
//// Menu danh sách liên kết đơn
////int main(){
////    
////    bool loop = true;
////    PTRSV First;
////    initializer(First);
////    Sinhvien sv1 = {4, "An", "Nguyen", 1, 1};
////    Sinhvien sv2 = {1, "Binh", "Tran", 1, 1};
////    Sinhvien sv3 = {2, "Cuong", "Le", 1, 1};
////
////    insertFirst(First, sv1);
////    insertFirst(First, sv2);
////    insertFirst(First, sv3);
////    
////    while(loop)  {
////         int menu = menusDSLK1();
////         switch (menu) {
////             case 0:
////                 loop = false;
////                 break;
////             case 1:
////                 traverseDSLKD1(First);
////                 break;
////             case 2:
////                 Sinhvien sv;
////                 cout << "Nhập mã số sinh viên: ";
////                 cin >> sv.maso;
////                 cin.ignore();
////                 
////                 cout << "Nhập tên sinh viên: ";
////                 cin.getline(sv.firstName, 8);
////                 
////                 cout << "Nhập họ sinh viên: ";
////                 cin.getline(sv.lastName, 20);
////                 
////                 cout << "Nhập ma phong ban: ";
////                 cin.getline(sv.mapb, 8);
////                 
////                 cout << "Nhập ma luong: ";
////                 cin >> sv.luong;
////                 
////                 insertFirst(First, sv);
////                 
////                 break;
////             case 3:
////                 selectionSort(First);
////                 traverseDSLKD1(First);
////                 break;
////             case 4:
////                 Sinhvien sv4;
////                 cout << "Nhập mã số sinh viên: ";
////                 cin >> sv4.maso;
////                 cin.ignore();
////                 
////                 if(checkDuplicate(First, sv4.maso)){
////                     cout << "Mã số bị trùng: " << endl;
////                     break;
////                 }
////                 
////                 cout << "Nhập tên sinh viên: ";
////                 cin.getline(sv4.firstName, 8);
////                 
////                 cout << "Nhập họ sinh viên: ";
////                 cin.getline(sv4.lastName, 20);
////                 
////                 cout << "Nhập ma phong ban: ";
////                 cin.getline(sv4.mapb, 8);
////                 
////                 cout << "Nhập ma luong: ";
////                 cin >> sv4.luong;
////                 
////                 insertOrder(First, sv4);
////                 break;
////             default:
////                 break;
////         }
////     }
////    
////    return 1;
////}
