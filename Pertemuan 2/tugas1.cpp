#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void printList() {
    if (head == NULL) {
        cout << "Linked list masih kosong.\n";
        return;
    }

    Node *temp = head;
    cout << "Isi Linked List: ";
    while (temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void insertFirst(int n) {
    Node *newNode = new Node();
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void insertLast(int n) {
    Node *newNode = new Node();
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAfter(int n, int check) {
    if (head == NULL) {
        cout << "Linked list kosong!\n";
        return;
    }

    Node *p = head;
    while (p != NULL && p->value != check) {
        p = p->next;
    }

    if (p == NULL) {
        cout << "Nilai " << check << " tidak ditemukan!\n";
    } else {
        Node *newNode = new Node();
        newNode->value = n;
        newNode->next = p->next;
        p->next = newNode;

        if (p == tail) {
            tail = newNode;
        }
    }
}

void deleteByValue(int val) {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    if (head->value == val) {
        Node *temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        delete temp;
        return;
    }

    Node *p = head;
    while (p->next != NULL && p->next->value != val) {
        p = p->next;
    }

    if (p->next == NULL) {
        cout << "Nilai " << val << " tidak ditemukan untuk dihapus.\n";
    } else {
        Node *temp = p->next;
        p->next = temp->next;

        if (temp == tail) {
            tail = p;
        }
        delete temp;
    }
}

int main() {
    int pilihan, nilai, acuan;

    do {
        cout << "1. Tambah Nilai di Awal (Insert First)\n";
        cout << "2. Tambah Nilai di Akhir (Insert Last)\n";
        cout << "3. Tambah Nilai Setelah Nilai Tertentu (Insert After)\n";
        cout << "4. Hapus Nilai Mahasiswa (Delete by Value)\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu [1-5]: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                insertFirst(nilai);
                printList();
                break;

            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                insertLast(nilai);
                printList();
                break;

            case 3:
                cout << "Masukkan nilai baru: ";
                cin >> nilai;
                cout << "Disisipkan setelah nilai berapa? : ";
                cin >> acuan;
                insertAfter(nilai, acuan);
                printList();
                break;

            case 4:
                cout << "Masukkan nilai mahasiswa yang ingin dihapus: ";
                cin >> nilai;
                deleteByValue(nilai);
                printList();
                break;

            case 5:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    } while (pilihan != 5);

    return 0;
}
