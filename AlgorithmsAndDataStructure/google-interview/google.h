//
//  google.h
//  AlgorithmsAndDataStructure
//
//  Created by Elpulga Nguyen on 3/12/25.
//

#include <utility> // chứa pair
#include <vector>
using namespace std;

#ifndef GOOGLE_H
#define GOOGLE_H

/*
 Given an array A and an integer target, find the indices of the two numbers in the array whose sum is equal to the given target.

 Note: The problem has exactly one solution. Do not use the same element twice.
 */
pair<int,int> twoSum(vector<int> &A, int target);

#endif
