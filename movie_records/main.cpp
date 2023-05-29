/*
* For this challenge you are to develop the foundation for a program
* for movie fanatics to keep track of what movies they hav watched
* and how many times they watched each movie.
*
* The program must support the following:
* class Movie - models a movie which includes
* -movie name
* -movie rating (G, PG, PG-14, R)
* -watched - the number of time the movie has been watched
*
* class Movies - models a collection of movie objects
*
* Obviously, Movies needs to know about Movie since it is a collection
* of movie objects
* However, our main driver should only interact with the Movies class
*
* For example, a simple main should be able to
* -create a Movies obj
* -ask the Movies object to add a movie by providing the
* movie name, rating and watched count
* -ask the Movies object to increment the watched count by 1 for a movie given its nam
* ask the Movies object to display all of its movies
*
* Additionally,
* -if we try to add a movie whose name is already in the movies collection
* we should display this error to the user
* -if we try to increment the watched count for a movie whose name is not in the movies
* collection we should display this error to the user.
*/

#include "Movie.h"
#include "Movies.h"
#include <cstdlib>
#include <sstream>

void print_stuffs()
{
	std::cout << "1. Add new record" << std::endl;
	std::cout << "2. View existing records [WIP]" << std::endl;
	std::cout << "3. Add watch count" << std::endl;
	std::cout << "4. Exit" << std::endl;
}

void increase(Movies& admin)
{
	std::string name;
	std::cout << "Movie Name: ";
	std::cin >> name;
	admin.incCount(name);
}

void viewRecords(Movies admin)
{
	if (admin.checkVecCount()) {
		admin.displayRecords();
	}
	else {
		std::cout << "There are currently no records saved.";
	}
}

void input_data(Movies& admin)
{
	std::string name, rate;
	int count{ 0 };
	std::cout << "\nMovie Name: ";
	std::getline(std::cin, name);
	std::cout << "\nMovie Rating: ";
	std::getline(std::cin, rate);
	std::cout << "\nWatch Count: ";
	std::cin >> count;
	system("cls");
	admin.addMovie(name, rate, count);
}

void checkChoice(int choice, Movies& admin)
{
	switch(choice) {
		case 1:
			input_data(admin);
			break;
		case 2:
			viewRecords(admin);
			break;
		case 3:
			increase(admin);
			break;
		case 4:
			system("exit");
			break;
		default:
			std::cout << "Enter valid input" << std::endl;
			system("exit");
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
		std::cin.ignore(10000, '\n');
		checkChoice(choice, admin);
	} while (choice != 0);
	return 0;
}

/*
* admin stores all the data for the account admin
* it has access to the attribute movie which is a vector of the objects of class Movie
* in order to add a new movie infomation:
* i need to use the object admin
* and pass data into the constructor of class Movies
* which creates a new object for class Movie
* and stores it into the vector of objects
*/

//cosine similarity