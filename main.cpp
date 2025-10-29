//
//  main.cpp
//  AlgorithmsAndDataStructure
//
//  Created by Elpulga Nguyen on 16/10/25.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include "mylib.h"
#include <unistd.h>  // cho sleep()

using namespace std;

const int MAXLIST = 2000;

const int so_item = 8;
const int dong = 5;
const int cot = 20;
const int Up = 72; // Extended code
const int Down = 80;

char thucdon[so_item][50] = {"1. Nhập danh sách học viên  ",
                             "2. Liệt kê danh sách        ",
                             "3. Tìm kiếm học viên theo mã",
                             "4. Xóa học viên theo tên    ",
                             "5. Ghi danh sách           ",
                             "6. Mở danh sách            ",
                             "7. Thêm sinh viên có thự tự theo mã",
                             "8. Thoát"};

struct Sinhvien
{
  int maso;
  char ho[50];
  char ten[10];
};
// đặc trưng của danh sách tuyến tính là phải có số n phần tử
struct list
{
  int n = 0;
  Sinhvien *nodes[MAXLIST];
};

void Normal()
{
  SetColor(15);  // white
  SetBGColor(0); // black
}
void HighLight()
{
  SetColor(15);
  SetBGColor(1); // blue
}
int MenuDongWindow(char td[so_item][50])
{

  Normal();
  system("cls");
  int chon = 0;
  int i;
  for (i = 0; i < so_item; i++)
  {
    gotoxy(cot, dong + i);
    cout << td[i];
  }
  HighLight();
  gotoxy(cot, dong + chon);
  cout << td[chon];
  char kytu;
  do
  {
    kytu = cin.get();
    if (kytu == 0)
    kytu = cin.get();
    switch (kytu)
    {
    case Up:
      if (chon > 0)
      {
        Normal();
        gotoxy(cot, dong + chon);
        cout << td[chon];
        chon--;
        HighLight();
        gotoxy(cot, dong + chon);
        cout << td[chon];
      }
      break;
    case Down:
      if (chon < so_item - 1)
      {
        Normal();
        gotoxy(cot, dong + chon);
        cout << td[chon];
        chon++;
        HighLight();
        gotoxy(cot, dong + chon);
        cout << td[chon];
      }
      break;
    case Enter:
      return chon + 1;
    } // end switch
  } while (1);
}

void menuCMDMacOS(){
    cout << "1. Nhap danh sach hoc vien  " << endl;
    cout << "2. Liet ke danh sach  " << endl;
    cout << "3. Tim kiem hoc vien theo ma" << endl;
    cout << "4. Xoa hoc vien theo ten" << endl;
    cout << "5. Ghi danh sach" << endl;
    cout << "6. Liet ke danh sach  " << endl;
    cout << "7. Them sv co thu tu theo ma" << endl;
    cout << "8. Ket thuc chuong trinh" << endl;
}

int Search(list &ds, int x)
{
  for (int i = 0; i < ds.n; i++)
    if (ds.nodes[i]->maso == x)
      return i;
  return -1;
}

void BaoLoi(char *s)
{
  int x = wherex(), y = wherey();
  gotoxy(10, 24);
  cout << s;
  sleep(2000);
  gotoxy(10, 24);
  clreol();
  gotoxy(x, y);
}
void NhapChuoi(char *tieude, char *S)
{
  cout << tieude;
  int x = wherex();
  gotoxy(x, wherey() + 1);
  fflush(stdin);
  do
  {
    gotoxy(x, wherey() - 1);
    gets(S);
    }
    while (strcasecmp(S,"")==0)  ;
}

int NhapSV(list &ds, Sinhvien &sv)
{
  while (true)
  {
    cout << "Nhap ma so (<=0 la ket thuc) : ";
    cin >> sv.maso;
    if (sv.maso <= 0)
      return 0;
    if (Search(ds, sv.maso) >= 0)
    {
      // BaoLoi("Ma so sinh vien bi trung");
      cout << "Mã số sinh viên bị trùng : ";
      continue;
    }
    NhapChuoi("Nhap Ho: ", sv.ho); // cout << "Ho : " ; gets(sv.ho);
    NhapChuoi("Nhap ten:", sv.ten);
    return 1;
  }
}
void NhapDSSV(list &ds, int flag)
{
  Sinhvien sv;

  if (flag == 0) // nhap moi tu dau
    while (ds.n > 0)
    {
      delete ds.nodes[ds.n - 1];
      ds.n--;
    }

  while (ds.n < MAXLIST)
  {
    if (NhapSV(ds, sv) == 0)
      return;
    ds.nodes[ds.n] = new Sinhvien;
    *ds.nodes[ds.n] = sv;
    ds.n++;
  }
  if (ds.n == MAXLIST)
    // BaoLoi("Danh sach day");
    cout << "Danh sách đầy !" << endl;

}
void LietKe(list ds)
{
  system("cls");
  printf("DANH SACH SINH VIEN \n");
  printf("   Ma so       Ho   va ten \n");
  for (int i = 0; i < ds.n; i++)
    printf("%8d %-30s%-10s\n", ds.nodes[i]->maso,
           ds.nodes[i]->ho, ds.nodes[i]->ten);
  // printf("So luong sinh vien :%d", ds.n);
  cout << "Số lượng sinh viên !" << endl;
  cin.get();
}

void ThongTinSv(list &ds, int maso)
{
  int i = Search(ds, maso);
  if (i == -1)
    // BaoLoi("Ma so sinh vien khong co trong danh sach");
    cout << "Mã số sinh viên không có trong danh sách" << endl;
  else
  {
    printf(" Ho ten sv : %30s%10s", ds.nodes[i]->ho, ds.nodes[i]->ten);
    cin.get();
  }
}
void SaveFile(list &ds, char *filename)
{
  FILE *f;
  if ((f = fopen(filename, "wb")) == NULL)
  {
    // BaoLoi("Loi mo file de ghi");
    cout << "Lỗi mở file để ghi" << endl;
    return;
  }

  for (int i = 0; i < ds.n; i++)
    fwrite(ds.nodes[i], sizeof(Sinhvien), 1, f);
  fclose(f);
  // BaoLoi("Da ghi xong danh sach vao file");
  cout << "Đã ghi xong danh sách vào file" << endl;
}
void OpenFile(list &ds, char *filename)
{
  FILE *f;
  Sinhvien sv;
  if ((f = fopen(filename, "rb")) == NULL)
  {
    // BaoLoi("Loi mo file de doc");
    cout << "Lỗi mở file để đọc !" << endl;
    return;
  }

  while (fread(&sv, sizeof(Sinhvien), 1, f) != 0)
  {
    ds.nodes[ds.n] = new Sinhvien;
    *ds.nodes[ds.n] = sv;
    ds.n++;
  }

  fclose(f);
  // BaoLoi("Da load xong danh sach vao bo nho");
    cout << "Đã load xong danh sách vào bộ nhớ !" << endl;
}
void DeleteItem(list &ds, int i)
{
  delete ds.nodes[i]; // chi dung trong mang con tro
  for (int j = i + 1; j < ds.n; j++)
    ds.nodes[j - 1] = ds.nodes[j];
  ds.n--;
}
int XoaSv(list &ds, int maso)
{
  int i = Search(ds, maso);
  if (i == -1)
    return 0;
  DeleteItem(ds, i);
  return 1;
}

int XoaSvTheoTen(list &ds, char *ten)
{
  int dem = 0;
  for (int i = 0; i < ds.n;)
      if (strcmp(ds.nodes[i]->ten, ten) == 0)
    {
      DeleteItem(ds, i);
      dem++;
    }
    else // lưu ý trường hợp else -> khi xóa lúc này danh sách giá trị sẽ được tịnh tiến về bên trái nhưng i chúng ta lại về phải, trường hợp các thông tin cần xóa nằm cạnh nhau sẽ gây ra thiếu sót trường hợp bị xóa.
      i++;
  return dem;
}
bool TestIncrease(list &ds)
{
  for (int i = 0; i < ds.n - 2; i++)
    if (ds.nodes[i]->maso > ds.nodes[i + 1]->maso)
      return false;
  return true;
}

int InsertOrder(list &ds, Sinhvien &sv)
{
  int i;
  if (ds.n == MAXLIST)
    return 0;
  // Thực hiện vòng lặp để chọn ra vị trí thứ i cần chèn
  for (i = 0; i < ds.n && ds.nodes[i]->maso < sv.maso; i++)
      
  // Chèn cuối
  if(i == ds.n - 1){
      ds.nodes[i + 1] = new Sinhvien;
      *ds.nodes[i + 1] = sv;
      ds.n++;
      return 1;
  }
    
  // Chèn giữa -> di chuyển tịnh tiến từ vị trí chèn
  for (int j = ds.n - 1; j >= i; j--){
     ds.nodes[j + 1] = ds.nodes[j];
  }
  ds.nodes[i] = new Sinhvien;
  *ds.nodes[i] = sv;
  ds.n++;
  return 1;
}
bool compareSV(Sinhvien *sv1, Sinhvien *sv2)
{
  int compareTen = strcmp(sv1->ten, sv2->ten);

  if (compareTen < 0)
  {
    return true;
  }
  else if (compareTen > 0)
  {
    return false;
  }
  else
  {
    return strcmp(sv1->ho, sv2->ho) < 0;
  }
}

void sort(list &list)
{
  int n = list.n;
  // Sinhvien* arr[n];
  // copy( list.nodes, list.nodes + n, arr);

  for (int i = 0; i < n - 1; ++i)
  {
    for (int j = 0; j < n - 1 - i; ++j)
    {
      if (!compareSV(list.nodes[j], list.nodes[j + 1]))
      {
        swap(list.nodes[j], list.nodes[j + 1]);
      }
    }
  }

  // copy(arr, arr + n, list.nodes);
}

// Bài tập buổi 3


int main(int argc, const char * argv[]) {
    system("cls");
    char filename[300] = "/Users/egitech/Desktop/Project-learning/Cplusplus/AlgorithmsAndDataStructure/AlgorithmsAndDataStructure/DSSV.txt";
    char ten[20];
    int chon;
    list ds;
    int maso;
    Sinhvien sv;
    OpenFile(ds, filename);
    do
    {
      // chon = MenuDongWindow(thucdon);
        menuCMDMacOS();
        cin >> chon;
      switch (chon)
      {
      case 1:
        NhapDSSV(ds, 1);
        break;
      case 2:
        LietKe(ds);
        break;
      case 3:
      {
        printf("\n Ban nhap ma so sinh vien : ");
        cin >> maso;
        ThongTinSv(ds, maso);
        break;
      };
      case 4:
      {
        NhapChuoi("Ban nhap ten sinh vien muon xoa : ", ten);
        cout << "Da xoa duoc " << XoaSvTheoTen(ds, ten) << " sinh vien.";
        cin.get();
        break;
      };
      case 5:
        SaveFile(ds, filename);
        break;
      // case 6: OpenFile(ds,filename); break;
      case 7:
      {
        if (TestIncrease(ds) == false)
          // BaoLoi("Danh sach sinh vien chua co thu tu tang theo ma nen khong the them");
          cout << "Danh sach sinh vien chua co thu tu tang theo ma nen khong the them";
        else if (NhapSV(ds, sv) == 1)
          InsertOrder(ds, sv);
        break;
      };

      case so_item:
      {
        SaveFile(ds, filename);
        return 0;
      }
      }
    } while (true);
    return 0;

}
