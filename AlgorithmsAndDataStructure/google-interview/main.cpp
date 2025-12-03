//
//  main.cpp
//  AlgorithmsAndDataStructure
//
//  Created by Elpulga Nguyen on 3/12/25.
//

#include <iostream>
#include <unordered_map>
#include "google.h"

using namespace std;


// Kém hiệu quả, 0(n^2)
pair<int,int> twoSum(vector<int> &A, int target) {
    // Add your logic here
    pair<int,int> vec = {-1, -1};
    int findValue;
    
    for (int i = 0; i < A.size(); i++) {
        if(A[i] >= target){
            continue;
        }
        if(A[i] < target){
            vec.first = i;
            findValue = target - A[i];
            for (int j = 0; j < A.size(); j++) {
                if( j == i) continue;
                if(A[j] == findValue){
                    vec.second = j;
                    return vec;
                }
            }
        }
    }
    
    return vec;
}
// Liên quan đến hash table, độ phức tạp giảm còn 0(n)
pair<int,int> twoSumAdvance(vector<int> &A, int target) {
    // Add your logic here
    unordered_map<int,int> mp;
    int findValue;
    
    for (int i = 0; i < A.size(); i++) {
        findValue = target - A[i];
        
        if(mp.count(findValue)){
            return {mp[findValue], i};
        }
        
        mp[A[i]] = i;
    }
    
    return {-1, -1};
}

// Độ phức tạp giảm còn 0(n^2)
pair<int,int> twoSum2(vector<int> &A, int target) {
   pair<int, int> indicesOfSum = {-1, -1};
   for (int i = 0; i < A.size(); i++) {
       for (int j = i + 1; j < A.size(); j++) {
           if(A[i] + A[j] == target) {
               return {i, j};
           }
       }
   }
   return indicesOfSum;
}

int main(){
    cout << "Kết quả là : "<< endl;
    vector<int> v = {8, 4, 10, 2, 1, 3};
    pair<int,int> vec = twoSum2(v, 5);
    cout << vec.first << " " << vec.second << endl;
    return 1;
}
