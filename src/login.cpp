#include <iostream>
#include "../include/login.h"

using namespace std;

bool login()
{
    string username;
    string password;

    cout << "\n===== LOGIN ADMIN =====\n";

    cout << "Username : ";
    cin >> username;

    cout << "Password : ";
    cin >> password;

    if (username == "admin" && password == "123")
    {
        cout << "\nLogin berhasil!\n";
        return true;
    }

    cout << "\nUsername atau password salah!\n";
    return false;
}

void logout()
{
    cout << "\nLogout berhasil!\n";
}