#include <iostream>
using namespace std;

struct Lukisan {
    string nama;
    string pelukis;
    int tahun;
};

struct Node {
    Lukisan lukisan;
    Node* next;
};
void clear(){
    system("cls");
}
void menu(){
    cout << "MENU" << endl;
    cout << "1. Tambah Data Lukisan Bersejarah" << endl;
    cout << "2. Lihat Data Lukisan Bersejarah" << endl;
    cout << "3. Ubah Data Lukisan Bersejarah" << endl;
    cout << "4. Hapus Data Lukisan Bersejarah" << endl;
    cout << "5. Keluar" << endl;
}

bool lihatdata(Node* head){
    clear();
    if (head == nullptr) {
        cout << "Data tidak tersedia. Mohon tambahkan data." << endl;
        return false;
    } else {
        Node* current = head;
        int i = 1;
        while (current != nullptr) {
            cout << i++ << ". " << current->lukisan.nama << " oleh " << current->lukisan.pelukis << " (" << current->lukisan.tahun << ")" << endl;
            current = current->next;
        }
        return true;
    }
}

void tambahdata(Node*& head){
    clear();
    Node* newNode = new Node;
    cout << "Masukkan nama lukisan bersejarah: ";
    getline(cin, newNode->lukisan.nama);
    
    cout << "Masukkan nama pelukis: ";
    getline(cin, newNode->lukisan.pelukis);

    cout << "Masukkan tahun pembuatan: ";
    cin >> newNode->lukisan.tahun;
    cin.ignore();

    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Data berhasil ditambahkan\n";
}

void ubahdata(Node* head){
    clear();
    if (lihatdata(head)) {
        int nomor;
        cout << "Masukkan nomor lukisan yang ingin diubah: ";
        cin >> nomor;
        cin.ignore();

        Node* current = head;
        for (int i = 1; current != nullptr && i < nomor; i++) {
            current = current->next;
        }

        if (current != nullptr) {
            cout << "Masukkan nama lukisan baru: ";
            getline(cin, current->lukisan.nama);
            cout << "Masukkan nama pelukis baru: ";
            getline(cin, current->lukisan.pelukis);
            cout << "Masukkan tahun pembuatan baru: ";
            cin >> current->lukisan.tahun;
            cin.ignore();
            cout << "Data berhasil diubah." << endl;
        } else {
            cout << "Nomor lukisan tidak ditemukan." << endl;
        }
    }
}

void hapusdata(Node*& head){
    clear();
    if (lihatdata(head)) {
        int nomor;
        cout << "Masukkan nomor lukisan yang ingin dihapus: ";
        cin >> nomor;
        cin.ignore();

        if (nomor == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
        } else {
            Node* current = head;
            for (int i = 1; current != nullptr && i < nomor - 1; i++) {
                current = current->next;
            }

            if (current != nullptr && current->next != nullptr) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                cout << "Data berhasil dihapus." << endl;
            } else {
                cout << "Nomor lukisan tidak ditemukan." << endl;
            }
        }
    }
}

void pilihmenu(Node*& head) {
    char pilih;
    menu();
    cout << "Masukkan nomor menu yang ingin Anda pilih: ";
    cin >> pilih;
    cin.ignore();

    switch (pilih) {
        case '1':
            tambahdata(head);
            break;
        case '2':
            lihatdata(head);
            break;
        case '3':
            ubahdata(head);
            break;
        case '4':
            hapusdata(head);
            break;
        case '5':
            cout << "Keluar dari program." << endl;
            return;
        default:
            cout << "Pilihan tidak valid. Silakan pilih kembali." << endl;
    }

    pilihmenu(head); 
}

int main(){
    Node* head = nullptr;

    pilihmenu(head);

    return 0;
}
