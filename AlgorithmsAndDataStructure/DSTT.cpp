#include <iostream>
// #include "./DSLKD"

using namespace std;

const int MAXLIST = 1000;

// Cấp phát tĩnh
struct LIST {
    int n;
    int nodes[MAXLIST];
} LIST;

// Cấp phát động
struct LIST2 {
    int n;
    int *nodes;
} LIST2;

struct SV
{
  int maso;
  char ho[50];
  char ten[10];
}; // Cấp phát một vùng nhớ cố định MAXLIST với kiểu dữ liệu là Sinhvien, mỗi node sẽ trỏ tới một vùng nhớ SV.
// Với số lượng n vùng nhớ
struct danhsach
{
  int n = 0;
  int nodes[MAXLIST]; // Khi khai báo thì các node được cấp chỉ chứa các con trỏ và chưa trỏ đến vùng nhớ nào cả.
};

int kiemTraRong(danhsach &ds) { // tham chiếu đến vùng nhớ của ds được truyền vào
    return ds.n == 0; // 1: true, 0: false
};

int kiemTraDay(danhsach &ds){
    return ds.n == MAXLIST;
}

int insertItem(danhsach &ds, int i, int info){
    if(i < 0 || i > ds.n) return 0;
    
    for(int j = ds.n - 1; j >= i; j--){
        ds.nodes[j + 1] = ds.nodes[j];
    }
    // Tăng số lượng phần tử lên 1
    ds.n++;
    // Gán giá trị mới vào vị trí thứ i
    ds.nodes[i] = info;
    return 1;
}

int deleteIndex(danhsach &ds, int i){
    // vị trí thứ i này phải lớn hơn 0.
    // Danh sách này không được rỗng.
    // Vị trí thứ i này không lớn hơn ds.n
    if(i < 0 || kiemTraRong(ds) || i >= ds.n) return 0;

    // Di chuyển tịnh tiến về bên trái, i = i + 1;
    for(int j = i + 1; j < ds.n; j++){
        ds.nodes[j - 1] = ds.nodes[j];
    }
    
    // Giảm n về 1 số
    ds.n--;
    return 1;
}

int traverse(danhsach &ds){
    // vị trí thứ i này phải lớn hơn 0.
    // Danh sách này không được rỗng.
    // Vị trí thứ i này không lớn hơn ds.n
    if(kiemTraRong(ds)){
        cout << "Danh sách rỗng" << endl;
        return 0;
    }

    for(int i = 0; i < ds.n; i ++){
        cout << ds.nodes[i] << " ";
    }
    
    return 1;
}

int search_info(danhsach &ds, int info){
    if(kiemTraRong(ds)) return -1;

    for(int i = 0; i < ds.n; i++){
        if(ds.nodes[i] == info){
            return i;
        }
    }
    
    return -1;
}

void createList(danhsach &ds){
    cout << "Nhập số phần tử của danh sách : ";
    cin >> ds.n;
    cout << "Số phần tử trong danh sách: " << ds.n << endl;
    for(int i = 0; i < ds.n; i++){
        cout << "Nhập phần tử thứ " << i <<": ";
        cin >> ds.nodes[i];
    }
}

int insert(danhsach &ds, int info){
    if(kiemTraRong(ds)) return -1;

    for(int i = 0; i < ds.n; i++){
        if(ds.nodes[i] == info){
            return i;
        }
    }
    
    return -1;
}

int insert_item_sorted(danhsach &ds, int info){
    if(kiemTraRong(ds) || kiemTraDay(ds)) return 0;
    
    int i = 0;
    for(i = 0; i < ds.n - 1 && ds.nodes[i] < info; i++)
    cout << "Vị trí thứ " << i <<endl;
    insertItem(ds, 2, info);
    
    return 1;
}

// Rút ngắn vòng lặp thứ 2 bằng cách trừ cho i
void bubble_sort(danhsach &ds){
    bool sorted = 1;
    for(int i = 0; i < ds.n - 1; i++){
        for(int j = 0; j <= ds.n - j - 1; j++){
            if(ds.nodes[j] > ds.nodes[j + 1]){
                cout << "Danh sách chưa được sort trước đó " << endl;
                sorted = 0;
                int temp = ds.nodes[j];
                ds.nodes[j] = ds.nodes[j + 1];
                ds.nodes[j + 1] = temp;
            }
        }
        if(sorted){
            cout << "Danh sách đã được sort trước đó " << endl;
            return;
        }
    }
}
// Chọn vị trí đầu tiền là giá trị nhỏ nhất, hoán đổi với vị trí hiện tại nhỏ nhất nếu có
// Rút ngắn vòng lặp thứ 2 bằng cách tăng i cho j
void selection_sort(danhsach &ds){
    for(int i = 0; i < ds.n - 1; i++){
        int min = i;
        for(int j = i + 1; j <= ds.n - 1; j++){ // đi qua hết các phần tử
            if(ds.nodes[j] < ds.nodes[min]){
                min = j;
            }
        }
        int temp = ds.nodes[min];
        ds.nodes[min] = ds.nodes[i];
        ds.nodes[i] = temp;
    }
}


int menus(){
    int menu;
    cout << endl;
    cout << "0. Thoát chương trình" << endl;
    cout << "1. Nhập danh sách" << endl;
    cout << "2. Kiểm tra rỗng" << endl;
    cout << "3. Kiểm tra đầy" << endl;
    cout << "4. Duyệt danh sách" << endl;
    cout << "5. Tìm kiếm phần tử" << endl;
    cout << "6. Thêm giá trị vào một vị trí" << endl;
    cout << "7. Sắp xếp danh sách tăng dần (Bubble sort)" << endl;
    cout << "8. Sắp xếp danh sách tăng dần (Selection sort)" << endl;
    cout << "9. Thêm một giá trị vào một mảng đã sắp xếp" << endl;

    cout << "Nhập chức năng: ";
    cin >> menu;
    
    return menu;
}
 
int main() {
    danhsach ds;    // Khai báo biến ds
    int loop = true;
    
    while(loop)  {
        int menu = menus();
        
        switch (menu) {
            case 0:
                loop = false;
                break;
            case 1:
                createList(ds);
                break;
            case 2:
                if(kiemTraRong(ds)){
                    cout << "Danh sách rỗng";
                }else{
                    cout << "Danh sách có phần tử !";
                }
                break;
            case 3:
                if(kiemTraDay(ds)){
                    cout << "Danh sách đầy";
                }else{
                    cout << "Danh sách chưa đầy";
                }
                break;
            case 4:
                traverse(ds);
                break;
            case 5:
                int info;
                cout << "Nhập thông tin bạn muốn tìm kiếm: ";
                cin >> info;
                search_info(ds, info);
                if(search_info(ds, info) >= 0){
                    cout << "Tìm thấy tại vị trí: " << search_info(ds, info) << endl;
                }else{
                    cout << "Không tìm thấy" << endl;
                }
                break;
            case 6:
                int infochen, vitri;
                cout << "Nhập vị trí muốn chèn: ";
                cin >> vitri;
                cout << "Nhập giá trị muốn chèn: ";
                cin >> infochen;
                insertItem(ds, vitri, infochen);
                break;
            case 7:
                bubble_sort(ds);
                break;
            case 8:
                selection_sort(ds);
            case 9:
                int infosorted;
                cout << "Nhập giá trị muốn chèn: ";
                cin >> infosorted;
                insert_item_sorted(ds, infosorted);
                break;
            default:
                break;
        }
    }
    
    return 0;
}
