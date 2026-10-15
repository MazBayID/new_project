//main programs

#include <iostream>
#include <limits>
#include "login.h"
#include "signup.h"

int main() {
	int pilihan = 0;

	while (pilihan !=3) {
		std::cout << "===Neo Auntentification System===\n\n";
		std::cout << "1. Login\n";
		std::cout << "2. Sign Up\n";
		std::cout << "3. Exit\n";
		std::cout << "\nPillih Menu: ";

		if (!(std::cin >> pilihan)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			pilihan = 0;
			std::cout << "Masukan hanya Angka (123)\n";
			continue;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (pilihan == 1) {
			runLogin();
		} else if (pilihan == 2) {
			runSignup();
		} else if (pilihan == 3) {
			std::cout << "===Keluar Program===\n\n";
		} else {
			std::cout << "Pilihan Tidak Valid!! \n";
		}
	}
	return 0;
}
