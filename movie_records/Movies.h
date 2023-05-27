#pragma once
#include <iostream>
#include <vector>
#include "Movie.h"

class Movies
{
public:
	Movies();
	~Movies();
	void addMovie(std::string, std::string, int);
	void checkName(std::string);
	void incCount(std::string);
	int checkVecCount();
	void displayRecords();
	void display(Movie);
private:
	std::string name;
	std::vector<Movie> movie;
};

