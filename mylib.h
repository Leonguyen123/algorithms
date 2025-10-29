//
//  mylib.h
//  AlgorithmsAndDataStructure (macOS compatible)
//
//  Updated by ChatGPT on 16/10/2025
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

using namespace std;

#define Enter 10              // trên macOS, Enter có mã ASCII = 10
#define PASSWORD "abcdef"

/// ==========================
/// HÀM NHẬP MẬT KHẨU (Pwd)
/// ==========================
char* Pwd() {
    static char S[40];  // dùng static để không trả về con trỏ local
    int i = 0;
    char ch;

    // Tắt chế độ echo để không in ký tự nhập
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ECHO);  // tắt hiển thị ký tự
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    while (true) {
        ch = getchar();
        if (ch == Enter) break;
        S[i++] = ch;
        printf("*");
        fflush(stdout);
    }
    S[i] = '\0';

    // Bật lại echo
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    printf("\n");
    return S;
}

/// ==========================
/// KIỂM TRA MẬT KHẨU (CheckPwd)
/// ==========================
int CheckPwd() {
    for (int dem = 1; dem <= 3; dem++) {
        printf("Password: ");
        if (strcmp(Pwd(), PASSWORD) == 0)
            return 1;
        else
            printf("\nPassword sai. Hay nhap lai\n");
    }
    return 0;
}

/// ==========================
/// gotoxy, wherex, wherey
/// ==========================

void gotoxy(int x, int y) {
    // Di chuyển con trỏ bằng mã escape ANSI
    printf("\033[%d;%dH", y, x);
    fflush(stdout);
}

// ⚠️ macOS không có API để lấy vị trí con trỏ hiện tại
// Nếu thực sự cần, phải dùng ioctl() phức tạp — tạm thời ta giả lập 0
int wherex(void) { return 0; }
int wherey(void) { return 0; }

/// ==========================
/// Xóa phần còn lại của dòng hiện tại (clreol)
/// ==========================
void clreol() {
    printf("\033[K"); // ANSI: xóa đến cuối dòng
    fflush(stdout);
}

/// ==========================
/// Đặt màu chữ và màu nền
/// ==========================
// Mã màu ANSI: 30–37 (chữ), 40–47 (nền)

void SetColor(int color) {
    // color: 0–7 (đen, đỏ, xanh lá, vàng, xanh dương, tím, cyan, trắng)
    printf("\033[%dm", 30 + (color % 8));
    fflush(stdout);
}

void SetBGColor(int color) {
    printf("\033[%dm", 40 + (color % 8));
    fflush(stdout);
}

/// ==========================
/// Xóa màn hình (clrscr)
/// ==========================
void clrscr() {
    printf("\033[2J");      // Xóa toàn bộ màn hình
    printf("\033[H");       // Đưa con trỏ về góc trên bên trái
    fflush(stdout);
}
