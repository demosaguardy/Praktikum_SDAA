#include <iostream>
using namespace std;

struct Lukisan {
    string nama;
    string pelukis;
    int tahun;
};

void menu(){
    cout << "MENU" << endl;
    cout << "1. Tambah Data Lukisan Bersejarah" << endl;
    cout << "2. Lihat Data Lukisan Bersejarah" << endl;
    cout << "3. Ubah Data Lukisan Bersejarah" << endl;
    cout << "4. Hapus Data Lukisan Bersejarah" << endl;
    cout << "5. Keluar" << endl;
}

bool lihatdata(Lukisan* lks, int n){
    if(n == 0){
        cout << "Data tidak tersedia. Mohon tambahkan data." << endl;
        return false;
    }
    else{
        Lukisan *ptr = lks;  
        for(int i = 0; i < n; i++){
            cout << i+1 << ". " << (ptr + i)->nama << " oleh " << (ptr + i)->pelukis << " (" << (ptr + i)->tahun << ")" << endl;
        }
        return true;
    }
}

void hapusdata(Lukisan* lks, int& n){
    int nomor;
    
    if(lihatdata(lks, n)){
        cout << "Masukkan nomor lukisan yang ingin dihapus: ";
        cin >> nomor;
        cin.ignore();
        
        Lukisan *ptr = lks;  
        for(int i = nomor-1; i < n-1; ++i){
            *(ptr + i) = *(ptr + i + 1);  
        }
        cout << "Data berhasil dihapus." << endl;
        n--; 
    }
    else{
        cout << "Input tidak valid." << endl;
    }
}

void tambahdata(Lukisan* lks, int& n){
    Lukisan tambah;
    cout << "Masukkan nama lukisan bersejarah: ";
    getline(cin, tambah.nama);
    
    cout << "Masukkan nama pelukis: ";
    getline(cin, tambah.pelukis);

    cout << "Masukkan tahun pembuatan: ";
    cin >> tambah.tahun;
    cin.ignore();

    Lukisan *ptr = lks; 
    *(ptr + n) = tambah;  
    n++;
    cout << "Data berhasil ditambahkan\n";
}

void ubahdata(Lukisan* lks, int& n){
    int nomor;
    Lukisan ubah;
    
    if(lihatdata(lks, n)){
        cout << "Masukkan nomor lukisan yang ingin diubah: ";
        cin >> nomor;
        cin.ignore();
        
        cout << "Masukkan nama lukisan baru: ";
        getline(cin, ubah.nama);
        
        cout << "Masukkan nama pelukis baru: ";
        getline(cin, ubah.pelukis);

        cout << "Masukkan tahun pembuatan baru: ";
        cin >> ubah.tahun;
        cin.ignore();
        
        Lukisan *ptr = lks;  
        *(ptr + (nomor-1)) = ubah;  
        cout << "Data berhasil diubah." << endl;
    }
}

void pilihmenu(Lukisan* lks, int& n) {
    char pilih;
    menu();
    cout << "Masukkan nomor menu yang ingin Anda pilih: ";
    cin >> pilih;
    cin.ignore();

    switch (pilih) {
        case '1':
            tambahdata(lks, n);
            break;
        case '2':
            lihatdata(lks, n);
            break;
        case '3':
            ubahdata(lks, n);
            break;
        case '4':
            hapusdata(lks, n);
            break;
        case '5':
            cout << "Keluar dari program." << endl;
            return;
        default:
            cout << "Pilihan tidak valid. Silakan pilih kembali." << endl;
    }

    pilihmenu(lks, n); 
}

int main(){
    int n = 4;
    
    Lukisan lks[100] = {
        {"MONA LISA", "Leonardo da Vinci", 1503},
        {"THE STAR NIGHT", "Vincent van Gogh", 1889},
        {"GIRL WITH A PEARL EARRING", "Johannes Vermeer", 1665},
        {"THE LAST SUPPER", "Leonardo da Vinci", 1498}
    };

    pilihmenu(lks, n);

    return 0;
}
