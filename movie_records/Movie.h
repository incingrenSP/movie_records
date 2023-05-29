#pragma once
#include <iostream>

class Movie
{
private:
	std::string movie_name;
	std::string rating;
	int watch_count;
public:
	Movie(std::string movie_name = "None", std::string rate = "None", int watch_count = 0);
	~Movie();
	void addMovies(std::string, std::string, int);
	void increaseCount();
	void displayMovies();
	std::string getName();
	std::string getRating();
	int getCount();
};

