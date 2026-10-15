//AUTH file

#ifndef AUTH_H
#define AUTH_H
#include <cstdint>
#include <string>

std::uint64_t calculatedHash(const std::string& key);
bool verifyLogin(const std::string& username, const std::string& key);
bool registerUser(const std::string& username, const std::string& key);
bool usernameExists(const std::string& username);

#endif
