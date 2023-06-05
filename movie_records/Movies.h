#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include "Movie.h"

class Movies
{
	friend void increase(Movies& admin);
	friend void viewRecords(Movies admin);
	friend void input_data(Movies& admin);

public:
	Movies();
	~Movies();
	void addMovie(std::string, std::string, int);
	void incCount(std::string);
	int checkVecCount();
	void displayRecords();
private:
	std::string name;
	std::vector<Movie> movie;
	void display(Movie);
};

