//file main_login.cpp

#include <iostream>
#include <string>
#include "login.h"
#include "auth.h"

void runLogin() {
    std::string username;
    std::string key;

    std::cout << "===Neo Autentification System===\n\n";
    std::cout << "Username: " << std::endl;
    std::getline(std::cin, username);

    std::cout << "Password: " << std::endl;
    std::getline(std::cin, key);

    if (verifyLogin(username, key)) {
        std::cout << "Selamat datang, " << username << "!\n";
        std::cout << "Neo siap dijalankan.\n";
    } else {
        std::cout << "\nUsername atau Password salah!\n";
    }
}
