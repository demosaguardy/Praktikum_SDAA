#include <iostream>
using namespace std;

struct Lukisan {
    string nama;
    string pelukis;
    int tahun;
};

struct NodeLukisan {
    Lukisan lukisan;
    NodeLukisan* next;
};

struct Pengunjung {
    string nama;
    int usia;
};

struct NodePengunjung {
    Pengunjung pengunjung;
    NodePengunjung* next;
};

struct Kurator {
    string nama;
    string spesialisasi;
};

struct NodeKurator {
    Kurator kurator;
    NodeKurator* next;
};

void clear() {
    system("cls");
}

void lihatPengunjung(NodePengunjung* head) {
    clear();
    if (head == nullptr) {
        cout << "Tidak ada pengunjung yang tersedia.\n";
    } else {
        cout << "Daftar Pengunjung (Stack):\n";
        NodePengunjung* current = head;
        int i = 1;
        while (current != nullptr) {
            cout << i++ << ". " << current->pengunjung.nama << " (Usia: " << current->pengunjung.usia << ")\n";
            current = current->next;
        }
    }
    cout << endl;
}

void lihatKurator(NodeKurator* head) {
    clear();
    if (head == nullptr) {
        cout << "Tidak ada kurator yang tersedia.\n";
    } else {
        cout << "Daftar Kurator (Queue):\n";
        NodeKurator* current = head;
        int i = 1;
        while (current != nullptr) {
            cout << i++ << ". " << current->kurator.nama << " (Spesialisasi: " << current->kurator.spesialisasi << ")\n";
            current = current->next;
        }
    }
    cout << endl;
}

void menuUtama() {
    cout << "MENU UTAMA" << endl;
    cout << "1. Kelola Lukisan" << endl;
    cout << "2. Kelola Pengunjung (Stack)" << endl;
    cout << "3. Kelola Kurator (Queue)" << endl;
    cout << "4. Keluar" << endl;
}

void menuLukisan() {
    cout << "MENU LUKISAN" << endl;
    cout << "1. Tambah Data Lukisan" << endl;
    cout << "2. Lihat Data Lukisan" << endl;
    cout << "3. Ubah Data Lukisan" << endl;
    cout << "4. Hapus Data Lukisan" << endl;
    cout << "5. Kembali ke Menu Utama" << endl;
}

void menuPengunjung() {
    cout << "MENU PENGUNJUNG (STACK)" << endl;
    cout << "1. Tambah Pengunjung" << endl;
    cout << "2. Hapus Pengunjung" << endl;
    cout << "3. Kembali ke Menu Utama" << endl;
}

void menuKurator() {
    cout << "MENU KURATOR (QUEUE)" << endl;
    cout << "1. Tambah Kurator" << endl;
    cout << "2. Hapus Kurator" << endl;
    cout << "3. Kembali ke Menu Utama" << endl;
}

void tambahLukisan(NodeLukisan*& head) {
    clear();
    NodeLukisan* newNode = new NodeLukisan;
    cout << "Masukkan nama lukisan: ";
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
        NodeLukisan* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Data lukisan berhasil ditambahkan.\n";
}

bool lihatLukisan(NodeLukisan* head) {
    clear();
    if (head == nullptr) {
        cout << "Data lukisan kosong.\n";
        return false;
    } else {
        NodeLukisan* current = head;
        int i = 1;
        while (current != nullptr) {
            cout << i++ << ". " << current->lukisan.nama << " oleh " << current->lukisan.pelukis << " (" << current->lukisan.tahun << ")" << endl;
            current = current->next;
        }
        return true;
    }
}

void ubahdata(NodeLukisan*& head) { 
    clear();
    if (lihatLukisan(head)) { 
        int nomor;
        cout << "Masukkan nomor lukisan yang ingin diubah: ";
        cin >> nomor;
        cin.ignore();

        NodeLukisan* current = head;
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

void hapusdata(NodeLukisan*& head) { 
    clear();
    if (lihatLukisan(head)) { 
        int nomor;
        cout << "Masukkan nomor lukisan yang ingin dihapus: ";
        cin >> nomor;
        cin.ignore();

        if (nomor == 1) {
            NodeLukisan* temp = head;
            head = head->next;
            delete temp;
        } else {
            NodeLukisan* current = head;
            for (int i = 1; current != nullptr && i < nomor - 1; i++) {
                current = current->next;
            }

            if (current != nullptr && current->next != nullptr) {
                NodeLukisan* temp = current->next;
                current->next = current->next->next;
                delete temp;
                cout << "Data berhasil dihapus." << endl;
            } else {
                cout << "Nomor lukisan tidak ditemukan." << endl;
            }
        }
    }
}

void tambahPengunjung(NodePengunjung*& head) {
    clear();
    NodePengunjung* newNode = new NodePengunjung;
    cout << "Masukkan nama pengunjung: ";
    getline(cin, newNode->pengunjung.nama);
    cout << "Masukkan usia pengunjung: ";
    cin >> newNode->pengunjung.usia;
    cin.ignore();

    newNode->next = head;
    head = newNode;
    cout << "Pengunjung berhasil ditambahkan ke Stack.\n";
}

void hapusPengunjung(NodePengunjung*& head) {
    clear();
    if (head == nullptr) {
        cout << "Stack kosong, tidak ada pengunjung untuk dihapus.\n";
    } else {
        NodePengunjung* temp = head;
        head = head->next;
        delete temp;
        cout << "Pengunjung berhasil dihapus dari Stack.\n";
    }
}

void tambahKurator(NodeKurator*& head) {
    clear();
    NodeKurator* newNode = new NodeKurator;
    cout << "Masukkan nama kurator: ";
    getline(cin, newNode->kurator.nama);
    cout << "Masukkan spesialisasi kurator: ";
    getline(cin, newNode->kurator.spesialisasi);

    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    } else {
        NodeKurator* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Kurator berhasil ditambahkan ke Queue.\n";
}

void hapusKurator(NodeKurator*& head) {
    clear();
    if (head == nullptr) {
        cout << "Queue kosong, tidak ada kurator untuk dihapus.\n";
    } else {
        NodeKurator* temp = head;
        head = head->next;
        delete temp;
        cout << "Kurator berhasil dihapus dari Queue.\n";
    }
}
void pilihMenuLukisan(NodeLukisan*& headLukisan) {
    char pilih;
    menuLukisan();
    cout << "Pilih menu: ";
    cin >> pilih;
    cin.ignore();

    switch (pilih) {
        case '1':
            tambahLukisan(headLukisan);
            break;
        case '2':
            lihatLukisan(headLukisan);
            break;
        case '3':
            ubahdata(headLukisan); 
            break;
        case '4':
            hapusdata(headLukisan); 
            break;
        case '5':
            return;
        default:
            cout << "Pilihan tidak valid.\n";
    }
    pilihMenuLukisan(headLukisan);
}

void pilihMenuPengunjung(NodePengunjung*& headPengunjung) {
    lihatPengunjung(headPengunjung);  
    char pilih;
    menuPengunjung();
    cout << "Pilih menu: ";
    cin >> pilih;
    cin.ignore();

    switch (pilih) {
        case '1':
            tambahPengunjung(headPengunjung);
            break;
        case '2':
            hapusPengunjung(headPengunjung);
            break;
        case '3':
            return;
        default:
            cout << "Pilihan tidak valid.\n";
    }
    pilihMenuPengunjung(headPengunjung);
}

void pilihMenuKurator(NodeKurator*& headKurator) {
    lihatKurator(headKurator); 
    char pilih;
    menuKurator();
    cout << "Pilih menu: ";
    cin >> pilih;
    cin.ignore();

    switch (pilih) {
        case '1':
            tambahKurator(headKurator);
            break;
        case '2':
            hapusKurator(headKurator);
            break;
        case '3':
            return;  
        default:
            cout << "Pilihan tidak valid.\n";
    }
    pilihMenuKurator(headKurator);  
}

int main() {
    NodeLukisan* headLukisan = nullptr;
    NodePengunjung* headPengunjung = nullptr;
    NodeKurator* headKurator = nullptr;

    char pilih;
    do {
        menuUtama();
        cout << "Pilih menu: ";
        cin >> pilih;
        cin.ignore();

        switch (pilih) {
            case '1':
                pilihMenuLukisan(headLukisan);
                break;
            case '2':
                pilihMenuPengunjung(headPengunjung);
                break;
            case '3':
                pilihMenuKurator(headKurator);
                break;
            case '4':
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi.\n";
                break;
        }
    } while (pilih != '4');

    return 0;
}
