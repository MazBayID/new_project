//file main_signup.cpp
#include <iostream>
#include <string>
#include "signup.h"
#include "auth.h"

void runSignup() {
    std::string username, key;

    std::cout << "Masukan username baru: ";
    std::getline(std::cin, username);

    if (usernameExists(username)) {
        std::cout << "Username tidak tersedia!\n";
    }

    std::cout << "Masukan password baru; ";
    std::getline(std::cin, key);

    if (registerUser(username, key))
        std::cout << "**Akun berhasil dibuat**\n";
    else
        std::cout << "Gagal menyimpan akun(?)\n";
}
