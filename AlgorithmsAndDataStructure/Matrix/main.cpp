////
////  main.cpp
////  AlgorithmsAndDataStructure
////
////  Created by Elpulga Nguyen on 10/11/25.
////
//#include <iostream>
//#include "Matrix.h"
//#include <vector>
//
//using namespace std;
//
///*
// * Các bài toán về ma trận vuông
// * Mọi thứ bên trong ký hiệu này sẽ được bỏ qua
// * Bạn có thể viết cả bài văn vào đây...
// */
//
//// Trị tuyệt đối của đường chéo chính phụ
//int absoluteDifferenceDiagonal(const vector<vector<int>> &arr){
//    int mainDiag = 0, subDiag = 0;
//    for (int i = 0; i < arr.size(); ++i) {
//        mainDiag += arr[i][i];
//        subDiag += arr[i][arr.size() - i - 1];
//    }
//    
//    int sum = mainDiag - subDiag;
//    
//    return sum < 0 ? sum * -1 : sum;
//}
//
//// Cầu thang đi lên
//int stairCase(int n){
//    for (int i = 0; i <= n; i++) {
//        for (int j = 0; j < n; j++) {
//            if(j >= n - i) {
//                cout << "*";
//            }else{
//                cout << " ";
//            }
//        }
//        cout << endl;
//    }
//    return 1;
//}
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
//// menu ma trận vuông
//int main() {
//    
//    // Kiểm tra tần xuất xuất hiện của integer?
//    vector<int> ds = {1, 2, 3, 2, 4, 5, 3, 3, 1};
//    checkDuplicatePositiveInteger(ds);
//    vector<vector<int>> arr;
//    
//    int n, m;
//    cout << "Nhap so dong: ";
//    cin >> n;
//    cout << "Nhap so cot: ";
//    cin >> m;
//
//    if (n != m) {
//        cout << "Chi tinh duoc cho ma tran vuong (n == m)!\n";
//        return 0;
//    }
//
//    
//    for (int i = 0; i < n; i++) {
//        vector<int> row;
//        for (int j = 0; j < n; j++) {
//            cout << "Nhập vị trí thứ: a[" << i <<","<< j << "]: " ;
//            int x;
//            cin >> x;
//            row.push_back(x);
//        }
//        arr.push_back(row); // thêm dòng vào ma trận
//    }
//    
//    // Xuất ma trận
//    cout << "\nMa tran vua nhap la:" << endl;
//    for (int i = 0; i < arr.size(); ++i) {
//        for (int j = 0; j < arr[i].size(); ++j) {
//            cout << arr[i][j] << "\t";
//        }
//        cout << endl;
//    }
//    
//    cout << "\nKết quả của tổng tuyệt đối của hai đường chéo chính phụ: " << absoluteDifferenceDiagonal(arr) <<endl;
//    
//    stairCase(6);
//
//    return 0;
//}
