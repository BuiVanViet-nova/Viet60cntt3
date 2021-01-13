
#include <iostream>
#include <math.h>
#include<stdlib.h>
#include<time.h>
#define N 8
using namespace std;
 
//khoi tao ham cung cap diem bat dau cho thuat toan
void configureRandomly(int board[][N],
                       int* state)
{
    // Seed for the random function
    srand(time(0));
    //lap lai chi so cot
    for (int i = 0; i < N; i++) {
 
        // nhan hang ngau nhien
        state[i] = rand() % N;
 
        //Dat quan hau vao vi tri thu duoc trong ban co
        board[state[i]][i] = 1;
    }
}
 
//ham in ban co
void printBoard(int board[][N])
{
 
    for (int i = 0; i < N; i++) {
        cout << " ";
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}
 
//ham in trang thai cua mang
void printState(int* state)
{
 
    for (int i = 0; i < N; i++) {
        cout << " " << state[i] << " ";
    }
    cout << endl;
}
 
// ham so sanh 2 mang, tra ve true neu = va tra ve false neu !=
bool compareStates(int* state1,
                   int* state2)
{
 
    for (int i = 0; i < N; i++) {
        if (state1[i] != state2[i]) {
            return false;
        }
    }
    return true;
}
 
// ham lap day bang voi cac gia tri la value
void fill(int board[][N], int value)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = value;
        }
    }
}
 
// ham tinh toan gia tri muc tieu cua trang thai(quan hau tan cong nhau)
int calculateObjective(int board[][N],
                       int* state)
{
 
    //voi moi quan hau trong cot, ta kiem tra cac quan hau khac nam trong hang cua quan hau nay
    //neu tim thay thi tang so luong tan cong thay doi
 
    // so luong cac quan hau tan cong nhau
    //ban dau = 0
    int attacking = 0;
 
    // tao bien de dinh nghia hang va cot
    int row, col;
 
    for (int i = 0; i < N; i++) {
 
        // tai moi cot 'i', quan hau dc dat o hang state[i]
 
        // o ben trai cung 1 hang(hang ko doi nhung cot giam)
        row = state[i], col = i - 1;
        while (col >= 0 && board[row][col] != 1) {
            col--;
        }
        if (col >= 0 && board[row][col] == 1) {
            attacking++;
        }
 
        // o ben phai cua cung 1 hang(hang ko doi va cot tang len)
        row = state[i], col = i + 1;
        while (col < N && board[row][col] != 1) {
            col++;
        }
        if (col < N && board[row][col] == 1) {
            attacking++;
        }
 
        // Theo duong cheo sang trai len(hang va cot giam dan)
        row = state[i] - 1, col = i - 1;
        while (col >= 0 && row >= 0 && board[row][col] != 1) {
            col--;
            row--;
        }
        if (col >= 0 && row >= 0 && board[row][col] == 1) {
            attacking++;
        }
 
        // Theo duong cheo sang phai xuong(hang va cot tang dong thoi)
        row = state[i] + 1, col = i + 1;
        while (col < N && row < N && board[row][col] != 1) {
            col++;
            row++;
        }
        if (col < N && row < N && board[row][col] == 1) {
            attacking++;
        }
 
        // Theo duong cheo tu trai xuong(cot giam va hang tang)
        row = state[i] + 1, col = i - 1;
        while (col >= 0 && row < N && board[row][col] != 1) {
            col--;
            row++;
        }
        if (col >= 0 && row < N && board[row][col] == 1) {
            attacking++;
        }
 
        // Theo duong cheo sang phai len(cot tang va hang giam)
        row = state[i] - 1, col = i + 1;
        while (col < N && row >= 0 && board[row][col] != 1) {
            col++;
            row--;
        }
        if (col < N && row >= 0 && board[row][col] == 1) {
            attacking++;
        }
    }
 
    // tra lai cac cap
    return (int)(attacking / 2);
}

//tao cau hinh bang cua cac state da cho
void generateBoard(int board[][N], int* state)
{
    fill(board, 0);
    for (int i = 0; i < N; i++) {
        board[state[i]][i] = 1;
    }
}

//copy trang thai 2 den trang thai 1
void copyState(int* state1, int* state2)
{
    for (int i = 0; i < N; i++) {
        state1[i] = state2[i];
    }
}
// ham main
int main()
{
 
    int state[N] = {};
    int board[N][N] = {};
 
    // bat dau bang cau hinh bang ngau nhien
    configureRandomly(board, state);
    return 0;
}
