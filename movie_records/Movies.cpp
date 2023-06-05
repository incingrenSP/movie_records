#include "Movies.h"

Movies::Movies()
{}

Movies::~Movies()
{}

void Movies::addMovie(std::string name, std::string rating, int count)
{
	bool counter{ false };
	for (int i = 0; i < movie.size(); i++) {
		if (name == movie.at(i).getName()) {
			std::cout << "Error: The record for the movie " << name << "already exists" << std::endl;
			counter = true;
		}
	}
	if (!counter) {
		movie.push_back(Movie(name, rating, count));
	}
}

void Movies::incCount(std::string name)
{
	bool counter{ false };
	for (int i = 0; i < movie.size(); i++) {
		if (name == movie.at(i).getName()) {
			movie.at(i).increaseCount();
			counter = true;
		}
	}
	if (!counter) {
		std::cout << "Error: Could not find record for '" << name << "'" << std::endl;
	}
}

int Movies::checkVecCount()
{
	if (movie.size()) {
		return 1;
	}
	else {
		return 0;
	}
}

void Movies::displayRecords()
{
	for (int i = 0; i < movie.size(); i++) {
		display(movie.at(i));
	}
}

void Movies::display(Movie record)
{
	std::cout << "\nMovie Name: " << record.getName();
	std::cout << "\nMovie Rating: " << record.getRating();
	std::cout << "\nTimes Watched: " << record.getCount() << std::endl;
	std::cout << "===============================" << std::endl;
}

void increase(Movies& admin)
{
	std::string name;
	std::cout << "Movie Name: ";
	std::getline(std::cin, name);
	admin.incCount(name);
}

void viewRecords(Movies admin)
{
	if (admin.checkVecCount()) {
		admin.displayRecords();
	}
	else {
		std::cout << "There are currently no records saved." << std::endl;;
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
