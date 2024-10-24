#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

struct Lukisan
{
    string nama;
    string pelukis;
    int tahun;
};

struct NodeLukisan
{
    Lukisan lukisan;
    NodeLukisan *next;
};

struct Pengunjung
{
    string nama;
    int usia;
};

struct NodePengunjung
{
    Pengunjung pengunjung;
    NodePengunjung *next;
};

struct Kurator
{
    string nama;
    string spesialisasi;
};

struct NodeKurator
{
    Kurator kurator;
    NodeKurator *next;
};

void clear()
{
    system("cls");
}

void lihatPengunjung(NodePengunjung *head)
{
    clear();
    if (head == nullptr)
    {
        cout << "Tidak ada pengunjung yang tersedia.\n";
    }
    else
    {
        cout << "Daftar Pengunjung (Stack):\n";
        NodePengunjung *current = head;
        int i = 1;
        while (current != nullptr)
        {
            cout << i++ << ". " << current->pengunjung.nama << " (Usia: " << current->pengunjung.usia << ")\n";
            current = current->next;
        }
    }
    cout << endl;
}

void lihatKurator(NodeKurator *head)
{
    clear();
    if (head == nullptr)
    {
        cout << "Tidak ada kurator yang tersedia.\n";
    }
    else
    {
        cout << "Daftar Kurator (Queue):\n";
        NodeKurator *current = head;
        int i = 1;
        while (current != nullptr)
        {
            cout << i++ << ". " << current->kurator.nama << " (Spesialisasi: " << current->kurator.spesialisasi << ")\n";
            current = current->next;
        }
    }
    cout << endl;
}

void menuUtama()
{
    cout << "MENU UTAMA" << endl;
    cout << "1. Kelola Lukisan" << endl;
    cout << "2. Kelola Pengunjung (Stack)" << endl;
    cout << "3. Kelola Kurator (Queue)" << endl;
    cout << "4. Keluar" << endl;
}

void menuLukisan()
{
    cout << "MENU LUKISAN" << endl;
    cout << "1. Tambah Data Lukisan" << endl;
    cout << "2. Lihat Data Lukisan" << endl;
    cout << "3. Ubah Data Lukisan" << endl;
    cout << "4. Hapus Data Lukisan" << endl;
    cout << "5. Urutkan Lukisan Ascending (Tahun)" << endl;
    cout << "6. Urutkan Lukisan Descending (Tahun)" << endl;
    cout << "7. Cari Lukisan berdasarkan Tahun (Fibonacci Search - Ascending)" << endl;
    cout << "8. Cari Lukisan berdasarkan Tahun (Jump Search - Descending)" << endl;
    cout << "9. Cari Lukisan berdasarkan Nama Lukisan (Boyer-Moore Search)" << endl;
    cout << "10. Kembali ke Menu Utama" << endl;
}

void menuPengunjung()
{
    cout << "MENU PENGUNJUNG (STACK)" << endl;
    cout << "1. Tambah Pengunjung" << endl;
    cout << "2. Hapus Pengunjung" << endl;
    cout << "3. Kembali ke Menu Utama" << endl;
}

void menuKurator()
{
    cout << "MENU KURATOR (QUEUE)" << endl;
    cout << "1. Tambah Kurator" << endl;
    cout << "2. Hapus Kurator" << endl;
    cout << "3. Kembali ke Menu Utama" << endl;
}

void tambahLukisan(NodeLukisan *&head)
{
    clear();
    NodeLukisan *newNode = new NodeLukisan;
    cout << "Masukkan nama lukisan: ";
    getline(cin, newNode->lukisan.nama);
    cout << "Masukkan nama pelukis: ";
    getline(cin, newNode->lukisan.pelukis);
    cout << "Masukkan tahun pembuatan: ";
    cin >> newNode->lukisan.tahun;
    cin.ignore();

    newNode->next = nullptr;
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        NodeLukisan *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Data lukisan berhasil ditambahkan.\n";
}

bool lihatLukisan(NodeLukisan *head)
{
    clear();
    if (head == nullptr)
    {
        cout << "Data lukisan kosong.\n";
        return false;
    }
    else
    {
        NodeLukisan *current = head;
        int i = 1;
        while (current != nullptr)
        {
            cout << i++ << ". " << current->lukisan.nama << " oleh " << current->lukisan.pelukis << " (" << current->lukisan.tahun << ")" << endl;
            current = current->next;
        }
        return true;
    }
}

NodeLukisan *getMiddle(NodeLukisan *head)
{
    if (!head)
        return head;

    NodeLukisan *slow = head;
    NodeLukisan *fast = head->next;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

NodeLukisan *partition(NodeLukisan *low, NodeLukisan *high)
{
    int pivot = high->lukisan.tahun;
    NodeLukisan *i = low;

    for (NodeLukisan *j = low; j != high; j = j->next)
    {
        if (j->lukisan.tahun > pivot)
        {
            swap(i->lukisan, j->lukisan);
            i = i->next;
        }
    }
    swap(i->lukisan, high->lukisan);
    return i;
}

void quickSort(NodeLukisan *low, NodeLukisan *high)
{
    if (high != nullptr && low != high && low != high->next)
    {
        NodeLukisan *pivotNode = partition(low, high);
        quickSort(low, pivotNode->next);
        quickSort(pivotNode->next, high);
    }
}

NodeLukisan *getLast(NodeLukisan *head)
{
    while (head != nullptr && head->next != nullptr)
    {
        head = head->next;
    }
    return head;
}

void quickSortWrapper(NodeLukisan *&head)
{
    NodeLukisan *last = getLast(head);
    quickSort(head, last);
}

NodeLukisan *merge(NodeLukisan *left, NodeLukisan *right)
{
    if (!left)
        return right;
    if (!right)
        return left;

    if (left->lukisan.tahun <= right->lukisan.tahun)
    {
        left->next = merge(left->next, right);
        return left;
    }
    else
    {
        right->next = merge(left, right->next);
        return right;
    }
}

NodeLukisan *mergeSort(NodeLukisan *head)
{
    if (!head || !head->next)
        return head;

    NodeLukisan *middle = getMiddle(head);
    NodeLukisan *half = middle->next;
    middle->next = nullptr;

    NodeLukisan *left = mergeSort(head);
    NodeLukisan *right = mergeSort(half);

    return merge(left, right);
}

void pilihSortingLukisan(NodeLukisan *&headLukisan, bool ascending)
{
    if (ascending)
    {
        headLukisan = mergeSort(headLukisan);
        cout << "Lukisan berhasil diurutkan secara ascending berdasarkan tahun.\n";
    }
    else
    {
        quickSortWrapper(headLukisan);
        cout << "Lukisan berhasil diurutkan secara descending berdasarkan tahun.\n";
    }
    lihatLukisan(headLukisan);
}

int length(NodeLukisan *head)
{
    int count = 0;
    NodeLukisan *temp = head;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int min(int x, int y)
{
    return (x <= y) ? x : y;
}

int fibMonaccianSearch(NodeLukisan *head, int tahunDicari, int n)
{
    NodeLukisan *temp = head;
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < n)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    while (fibM > 1)
    {
        int i = min(offset + fibMMm2, n - 1);

        temp = head;
        for (int j = 0; j < i; j++)
        {
            temp = temp->next;
        }
        if (temp->lukisan.tahun < tahunDicari)
        {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (temp->lukisan.tahun > tahunDicari)
        {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else
        {
            return i;
        }
    }

    temp = head;
    for (int j = 0; j < offset + 1; j++)
    {
        temp = temp->next;
    }
    if (fibMMm1 && temp->lukisan.tahun == tahunDicari)
    {
        return offset + 1;
    }

    return -1;
}

NodeLukisan *jumpSearchDescending(NodeLukisan *head, int targetTahun)
{
    if (!head)
        return nullptr;

    int n = 0;
    NodeLukisan *temp = head;
    while (temp)
    {
        n++;
        temp = temp->next;
    }

    int jump = sqrt(n);
    NodeLukisan *prev = nullptr;
    NodeLukisan *current = head;

    while (current && current->lukisan.tahun >= targetTahun)
    {
        prev = current;
        for (int i = 0; i < jump && current->next; i++)
        {
            current = current->next;
        }
        if (!current || current->lukisan.tahun < targetTahun)
            break;
    }

    while (prev && prev->lukisan.tahun >= targetTahun)
    {
        if (prev->lukisan.tahun == targetTahun)
        {
            return prev;
        }
        prev = prev->next;
    }
    return nullptr;
}

void badCharHeuristic(string str, int size, int badChar[256])
{
    for (int i = 0; i < 256; i++)
    {
        badChar[i] = -1;
    }
    for (int i = 0; i < size; i++)
    {
        badChar[(int)str[i]] = i;
    }
}

int boyerMooreSearch(string txt, string pattern)
{
    int m = pattern.size();
    int n = txt.size();
    int badChar[256];

    badCharHeuristic(pattern, m, badChar);

    int shift = 0;
    while (shift <= (n - m))
    {
        int j = m - 1;

        while (j >= 0 && pattern[j] == txt[shift + j])
        {
            j--;
        }

        if (j < 0)
        {
            return shift;
            shift += (shift + m < n) ? m - badChar[txt[shift + m]] : 1;
        }
        else
        {
            shift += max(1, j - badChar[txt[shift + j]]);
        }
    }
    return -1;
}

int cariLukisanNama(NodeLukisan *head, string namaDicari)
{
    NodeLukisan *temp = head;
    int index = 0;

    while (temp != nullptr)
    {
        if (boyerMooreSearch(temp->lukisan.nama, namaDicari) != -1)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}
void ubahdata(NodeLukisan *&head)
{
    clear();
    if (lihatLukisan(head))
    {
        int nomor;
        cout << "Masukkan nomor lukisan yang ingin diubah: ";
        cin >> nomor;
        cin.ignore();

        NodeLukisan *current = head;
        for (int i = 1; current != nullptr && i < nomor; i++)
        {
            current = current->next;
        }

        if (current != nullptr)
        {
            cout << "Masukkan nama lukisan baru: ";
            getline(cin, current->lukisan.nama);
            cout << "Masukkan nama pelukis baru: ";
            getline(cin, current->lukisan.pelukis);
            cout << "Masukkan tahun pembuatan baru: ";
            cin >> current->lukisan.tahun;
            cin.ignore();
            cout << "Data berhasil diubah." << endl;
        }
        else
        {
            cout << "Nomor lukisan tidak ditemukan." << endl;
        }
    }
}

void hapusdata(NodeLukisan *&head)
{
    clear();
    if (lihatLukisan(head))
    {
        int nomor;
        cout << "Masukkan nomor lukisan yang ingin dihapus: ";
        cin >> nomor;
        cin.ignore();

        NodeLukisan *temp = head;
        if (nomor == 1)
        {
            head = head->next;
            delete temp;
        }
        else
        {
            NodeLukisan *prev = nullptr;
            for (int i = 1; temp != nullptr && i < nomor; i++)
            {
                prev = temp;
                temp = temp->next;
            }

            if (temp != nullptr)
            {
                prev->next = temp->next;
                delete temp;
                cout << "Lukisan berhasil dihapus." << endl;
            }
            else
            {
                cout << "Nomor lukisan tidak ditemukan." << endl;
            }
        }
    }
}

int main()
{
    NodeLukisan *headLukisan = nullptr;
    NodePengunjung *headPengunjung = nullptr;
    NodeKurator *headKurator = nullptr;

    NodeLukisan *monalisa = new NodeLukisan;
    monalisa->lukisan = {"Monalisa", "Leonardo da Vinci", 1503};
    monalisa->next = nullptr;
    headLukisan = monalisa;

    NodeLukisan *starryNight = new NodeLukisan;
    starryNight->lukisan = {"Starry Night", "Vincent van Gogh", 1889};
    starryNight->next = nullptr;
    monalisa->next = starryNight;

    NodeLukisan *diponegoro = new NodeLukisan;
    diponegoro->lukisan = {"Penangkapan Pangeran Diponegoro", "Raden Saleh", 1857};
    diponegoro->next = nullptr;
    starryNight->next = diponegoro;

    int pilihan;
    do
    {
        menuUtama();
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan)
        {
        case 1:
        {
            int pilihLukisan;
            do
            {
                menuLukisan();
                cout << "Pilih menu: ";
                cin >> pilihLukisan;
                cin.ignore();
                switch (pilihLukisan)
                {
                case 1:
                    tambahLukisan(headLukisan);
                    break;
                case 2:
                    lihatLukisan(headLukisan);
                    break;
                case 3:
                    ubahdata(headLukisan);
                    break;
                case 4:
                    hapusdata(headLukisan);
                    break;
                case 5:
                    pilihSortingLukisan(headLukisan, true);
                    break;
                case 6:
                    pilihSortingLukisan(headLukisan, false);
                    break;
                case 7:
                {
                    int tahunDicari;
                    int n = length(headLukisan);
                    int hasil = 0;
                    cout << "Masukkan tahun lukisan yang dicari: ";
                    cin >> tahunDicari;

                    hasil = fibMonaccianSearch(headLukisan, tahunDicari, n);

                    if (hasil != -1)
                    {
                        NodeLukisan *temp = headLukisan;
                        for (int i = 0; i < hasil; i++)
                        {
                            temp = temp->next;
                        }
                        cout << "Lukisan ditemukan: " << temp->lukisan.nama << " oleh "
                             << temp->lukisan.pelukis << " (" << temp->lukisan.tahun << ")\n";
                    }
                    else
                    {
                        cout << "Lukisan dengan tahun " << tahunDicari << " tidak ditemukan.\n";
                    }
                    break;
                }
                case 8:
                {
                    int tahun;
                    cout << "Masukkan tahun lukisan yang dicari: ";
                    cin >> tahun;
                    NodeLukisan *result = jumpSearchDescending(headLukisan, tahun);
                    if (result)
                    {
                        cout << "Lukisan ditemukan: " << result->lukisan.nama << " oleh "
                             << result->lukisan.pelukis << " (" << result->lukisan.tahun << ")\n";
                    }
                    else
                    {
                        cout << "Lukisan dengan tahun " << tahun << " tidak ditemukan.\n";
                    }
                    break;
                }
                case 9:
                {
                    string namaDicari;
                    cout << "Masukkan nama lukisan yang dicari: ";
                    getline(cin, namaDicari);

                    int hasilnama = cariLukisanNama(headLukisan, namaDicari);

                    if (hasilnama != -1)
                    {
                        NodeLukisan *temp = headLukisan;
                        for (int i = 0; i < hasilnama; i++)
                        {
                            temp = temp->next;
                        }
                        cout << "Lukisan ditemukan: " << temp->lukisan.nama << " oleh "
                             << temp->lukisan.pelukis << " (" << temp->lukisan.tahun << ")\n";
                    }
                    else
                    {
                        cout << "Lukisan dengan nama " << namaDicari << " tidak ditemukan.\n";
                    }
                    break;
                }
                }
            } while (pilihLukisan != 10);
            break;
        }
        case 2:
            lihatPengunjung(headPengunjung);
            break;
        case 3:
            lihatKurator(headKurator);
            break;
        } 
    } while (pilihan != 4);

    return 0;
}

