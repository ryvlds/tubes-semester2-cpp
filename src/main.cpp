#include <iostream>
using namespace std;

int main() {
    int pilihan;

    do {
        system("cls");

        cout << "===================================" << endl;
        cout << " SISTEM MANAJEMEN PERPUSTAKAAN " << endl;
        cout << "===================================" << endl;

        cout << "1. Login" << endl;
        cout << "2. Keluar" << endl;
        cout << endl;

        cout << "Pilih menu : ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                cout << "\n[ MENU LOGIN ]" << endl;

                // di isi login disini sama Ridzki

                system("pause");
                break;

            case 2:
                cout << "\nTerima kasih..." << endl;
                break;

            default:
                cout << "\nMenu tidak tersedia!" << endl;
                system("pause");
                break;
        }

    } while(pilihan != 2);

    return 0;
}
