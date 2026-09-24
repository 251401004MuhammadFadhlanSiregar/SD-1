#include <iostream>
#include <string>

using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;

// TODO : Menambahkan karakter ke stack
void push(char value) {
    if (top < MAX - 1) {
        stack[++top] = value;
    }
}

// TODO : Mengambil karakter paling atas
char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

int main() {

    string kata;

    cout << "Masukkan sebuah kata: ";
    cin >> kata;

    // TODO : Memasukkan setiap karakter ke stack
    for (char karakter : kata) {
        push(karakter);
    }

    // TODO Mengeluarkan karakter dari stack
    while (top >= 0) {
        cout << pop();
    }
    
    cout << endl;

    return 0;
}