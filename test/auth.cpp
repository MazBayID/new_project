//file auth.cpp

#include "auth.h"
#include <fstream>
#include <string>
#include <cstdint>

//logika perumusan yang menghasilkan hash
std::uint64_t calculatedHash(const std::string& key) {
    std::uint64_t hash = 0;
    const std::uint64_t modulus = 1000000007ULL;

    for (char karakter : key) {
        hash = (hash * 31 + static_cast<unsigned char>(karakter))
                % modulus;
    }
    return hash;
}


//pemeriksa usename != exist
bool usernameExists(const std::string& username) {
    std::ifstream file("data_user.txt");
    if (!file.is_open()) return false; // <== kalau belum ada file = belum ada data_user

    std::string usernameCek;

    while (file >> usernameCek) {
        if (usernameCek == username)
        return true;
    }
    return false;
}


//menulis data masukan dari new user
bool registerUser(const std::string& username, const std::string& key) {
    std::ofstream file("data_user.txt", std::ios::app);
    if (!file.is_open())
        return false;
    file << username << " " << calculatedHash(key) << "\n";
    return true;
}


//pemeriksaan login
bool verifyLogin(const std::string& username, const std::string& key) {
    std::ifstream file("data_user.txt");
    if (!file.is_open()) {
        return false;
    }

    std::string usernameCek;
    std::uint64_t hashCek;

    const std::uint64_t hashInput = calculatedHash(key);

    while (file >> usernameCek >> hashCek) {
        if (username == usernameCek && hashInput == hashCek) {
            return true;
            }
    }
    return false;
}
