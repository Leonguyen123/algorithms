//
//  DSLK.h
//  AlgorithmsAndDataStructure
//
//  Created by Elpulga Nguyen on 16/10/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "mylib.h"
using namespace std;
 
struct Sinhvien {
  int maso;
  char ho [51];
  char ten[11];
  float dtb;
  int hang;
   
 };

 struct node {
  Sinhvien sv;
  node *next;
};
typedef  node* PTR;

//const int MAXLIST =100;

const int so_item = 16;
const int dong =5;
const int cot = 40 ;
char thucdon [so_item][50] = {"1. Nhap danh sach sinh vien         ",
                              "2. Liet ke danh sach                ",
                              "3. Them ve dau danh sach            ",
                              "4. Them sv o vi tri i               ",
                              "5. Xoa sinh vien theo ma so         ",
                              "6. Them 1 sv vao danh sach co thu tu",
                              "7. Loc SV trung theo ten            ",
                              "8. Sap xep dssv theo ma so tang dan ",
                              "9. Save DSSV                        ",
                              "10.Load DSSV                        ",
                              "11.Xep hang theo DTB                ",
                              "12.Xoa sinh vien theo ten           ",
                              "13.Dao nguoc danh sach              ",
                              "14.Copy danh sach                   ",
                              "15. In DSSV tang dan theo ten (giu nguyen ds)",
                              "16.Ket thuc chuong trinh            "};





int Insert_After(PTR p, Sinhvien x)
{
   PTR q;
   if(p == NULL)        return 0;	
      q =new node;
      q->sv = x;
      q->next = p->next ;
      p->next = q;
   return 1;
}


int Delete_First (PTR  &First)
{ PTR p;
   if (First == NULL)      return 0;
    p = First;    // nut can xoa la nut dau
    First = p->next;
    delete p;
    return 1;
}

                          
int Menu (char td [so_item][50]){
  system("cls");   int chon =0;
  int i;
  for ( i=0; i< so_item ; i++)
  { gotoxy(cot, dong +i);
    cout << td[i];
  }
Nhaplai:
  gotoxy (cot, dong + so_item);
  cout << "Ban chon 1 so (1.."<< so_item << ") :    ";
  gotoxy (wherex()-4, wherey());
  cin >> chon;
  if (chon <1 || chon >so_item) goto Nhaplai;
  return chon;

}

void BaoLoi (char *s){
  int x=wherex() , y=wherey();
  gotoxy (10,24);
  cout <<s;
  sleep(2000);
  gotoxy(10,24);
  clreol();
  gotoxy(x,y);
}
PTR Search(PTR First, int x)
{
    for (PTR p = First;  p  != NULL ; p=p->next )
              if ( p->sv.maso == x  ) return p;
    return NULL;
}



int NhapSV(PTR First , Sinhvien &sv){
 NhaplaiMaSV:
        cout << "\nMa so sinh vien (<=0 dung nhap):" ;
        cin >> sv.maso ;
        if (sv.maso <=0 ) return 0;
        if (Search (First, sv.maso)!= NULL)  {
            BaoLoi( "Ma so sinh vien bi trung. Ban nhap lai. ");
            goto NhaplaiMaSV;
        }
        fflush (stdin);
        cout << "Ho sinh vien  :" ; gets (sv.ho);
        fflush (stdin);
        cout << "Ten sinh vien :" ; gets (sv.ten);
        cout << "Diem TB :" ; cin >>sv.dtb;
        sv.hang =0;
        return 1;
}
void Insert_First(PTR &First,Sinhvien &sv){
        PTR p = new node ;
        p->sv = sv ;
        p->next=First;
        First = p;
}
void NhapSV_VeDau (PTR &First) {
    system ("cls");
    PTR p ; Sinhvien sv; int err;
    while (1) {
        err=NhapSV(First, sv) ;
        if (err==0) return;
        Insert_First(First,sv);
   }
}
void Nhap_DSSV (PTR &First) { // them ve cuoi
    system ("cls");
    PTR p, Last ; Sinhvien sv; int err;
    if(First !=NULL)
       for (Last = First ; Last->next !=NULL; Last=Last->next) ;
       
    while (true) {
        err=NhapSV(First, sv) ;
        if (err==0) return;
     
        p = new node ;
        p->sv = sv ; p->next=NULL;
        if (First==NULL) First = p;
        else Last -> next = p;
        Last = p;
   }
}

void LietKe (PTR First) {
    int dem =0 ; system ("cls");
    printf ("MaSV        Ho              Ten      DTB     Hang\n");
    for (PTR p = First ; p !=NULL; p=p->next)
    {    printf ("%5d %-20s %-10s %.1f %5d\n",
           p->sv.maso , p->sv.ho, p->sv.ten, p->sv.dtb, p->sv.hang );
        dem ++;
    
    }
    cout << "\nSo luong Sv =" <<dem;
    cin.get();
}

int Reccount (PTR First) {
    int dem =0 ;
    for (PTR p = First ; p !=NULL; p=p->next)
        dem ++;
    return dem;
}

int SaveFile (PTR First, char *tenfile) {
    FILE *f = fopen (tenfile, "wb");
    if (f==NULL) return 0;
    for (PTR p=First ; p!=NULL ; p=p->next)
      fwrite (&p->sv, sizeof (Sinhvien), 1, f);
    fclose (f);
    return 1;
}
void InsertLast (PTR &First , Sinhvien sv) {
        PTR p = new node ;
        p->sv = sv ; p->next=NULL;
        if (First==NULL) First = p;
        else { PTR Last;
               for (Last = First;Last->next !=NULL; Last=Last->next) ;
               Last->next = p;
             }
}

int OpenFile (PTR &First, char *tenfile) {
    PTR p;  Sinhvien sv ;
    FILE *f = fopen (tenfile, "rb");
    if (f==NULL) return 0; // mo file khong duoc
    
    while (First!= NULL) {
        p= First ; First = p->next ; delete p ;
    }
    while  (fread (&sv, sizeof (Sinhvien), 1, f)== 1 )
       InsertLast (First , sv);
    fclose (f);
    return 1;
}


bool XacNhan (char *S) {
    cout << S;  char kt;
    do {
        kt = toupper(cin.get());
    } while (kt!='Y' && kt !='N');
    cout <<kt  ;
    return kt=='Y';
}



void Insert_Order(PTR &First, Sinhvien x)
{
   PTR p, t, s;  // t la nut truoc, s la nut sau
   p=new node;
   p->sv=x;
   for(s = First; s != NULL && s->sv.maso < x.maso  ; t=s, s = s->next)   ;
   if(s == First)  // them nut vao dau danh sach lien ket
   {
      p->next = First;
      First = p;
   }
   else           // them nut p vao truoc nut s
   {
      p->next= s;
      t->next= p;
   }
}

int  Delete_after(PTR p)
{   PTR q;
  
   if((p == NULL) || (p->next == NULL))
      return 0;
     q = p->next;  // q chi nut can xoa
     p->next = q->next;
     delete q;
     return 1;
}

   

int main (){
  char filename[80]="D:\\DSSV_DTB.TXT";int x;
  char tensv[16];
  int chon;   PTR head;
  PTR First=NULL; int so;PTR First1=NULL, First2=NULL;
  
  int i ; Sinhvien sv; int maso;
  do
  {
    chon = Menu (thucdon);
    switch (chon ){
    case 1: Nhap_DSSV(First) ; break;
    case 2: LietKe(First) ; break;
    case 3: printf("So luong sinh vien =%d", Reccount(First));
            cin.get();
            break;
//    case 4:{
//        
//            system ("cls");
//            cout << "Vi tri can them :" ; cin >> i ;
//            if(Them_SV_theo_vitri(First,i)==1)
//                  BaoLoi("Da them xong");
//            break;
//            }
/*    case 5: {
        
            cout << "Ma so SV muon xoa :" ; cin >> maso;
            int err= Xoa_SV_theo_Masv (First, maso);
            if (err==1)
              BaoLoi("Da xoa sinh vien co ma so trong DSSV.");
            else BaoLoi ("Ma so SV khong co trong danh sach.");
            break;
        }
          
    case 7: {
             head= filter(First) ;
             for (PTR i=head;i!=NULL;i=i->next)
               printf ("%-10s ",  i->sv.ten );
            
            getch();
            break;
        }

    case 8: SapXepTangTheoTenVaHo(First );
            BaoLoi("Da sap xep xong DSSV theo ten+ho tang dan");
            break;
*/
    case 9: system ("cls");
            if (SaveFile(First, filename)==0) cout << "Loi mo file de ghi ";
            else cout << "Da ghi xong danh sasch sinh vien vao file.";
            sleep(2000);
            break;

    case 10:  system ("cls");
            if (OpenFile(First, filename)==0) cout << "Loi mo file de doc ";
            else cout << "Da doc xong danh sasch sinh vien tu file.";
            sleep(2000);
            break;
/*
    case 11: {xepHang(First);
              break;
            }
    
    case 12: {
            system ("cls");
            cout << "Ten SV muon xoa :" ; fflush(stdin); gets (tensv);
             cout << "So SV da xoa =" << XoatheotenSV(First,tensv);
             getch();
            break;
        }
    case 13: {
     
             reverseLinkedList(First);
             cout << "Da dao nguoc danh sach xong"; getch();
            break;
            }

    case 14: {
            First2= SaoChepDanhSach(First) ;
            LietKe(First2);
            break;
            }
       
        case 15: {
     
             InDSSVTangTheoTen(First);
             break;
            }
    */
    case so_item : {// clearlist(First); clearlist(First2);
                     return 0;
                   }
  } }while (1);
  
  return 0;
  }
