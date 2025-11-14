//
//  DSTT.h
//  AlgorithmsAndDataStructure
//
//  Created by Elpulga Nguyen on 11/11/25.
//

#ifndef DSTT_H
#define DSTT_H

const int MAXLIST = 1000;

struct LIST {
    int n;
    int *nodes[MAXLIST];
} LIST;

struct SV
{
  int maso;
  char ho[50];
  char ten[10];
};

struct ListSV {
    int n = 0;
    SV *nodes = nullptr;
};

struct danhsach
{
  int n = 0;
  int nodes[MAXLIST];
};

int kiemTraRong(danhsach &ds);
int kiemTraDay(danhsach &ds);
int insertItem(danhsach &ds, int i, int info);
int deleteIndex(danhsach &ds, int i);
int traverse(danhsach &ds);
int search_info(danhsach &ds, int info);
void createList(danhsach &ds);
int insert_item_sorted(danhsach &ds, int info);
void bubble_sort(danhsach &ds);
void selection_sort(danhsach &ds);
void sinhvienInitiatier(ListSV &ds);
void releaseNodeSV(ListSV &ds);
void traverseSV(ListSV &ds);
int findSV(ListSV &ds, string info);
void checkRepeate();
int menus();

// Kiểm tra số nguyên dương trùng lặp
void checkDuplicatePositiveInteger(vector<int> ds);

#endif
