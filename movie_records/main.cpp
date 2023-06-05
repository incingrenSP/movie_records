
#include "Movie.h"
#include "Movies.h"

void print_stuffs()
{
	std::cout << "\n[1] Add new record" << std::endl;
	std::cout << "[2] View existing records" << std::endl;
	std::cout << "[3] Add watch count" << std::endl;
	std::cout << "[4] Exit" << std::endl;
}

void checkChoice(int choice, Movies& admin)
{
	switch(choice) {
		case 1:
			system("cls");
			input_data(admin);
			break;
		case 2:
			system("cls");
			viewRecords(admin);
			break;
		case 3:
			system("cls");
			increase(admin);
			break;
		case 4:
			exit(0);
			break;
		default:
			std::cout << "\nEnter valid input" << std::endl;
			exit(0);
	}
}

int main()
{
	Movies admin;
	int choice{ 0 };
	do {
		print_stuffs();
		std::cout << "What do you want to do? ";
		std::cin >> choice;
		std::cin.ignore(100, '\n');
		checkChoice(choice, admin);
	} while (choice != 4);
	return 0;
}