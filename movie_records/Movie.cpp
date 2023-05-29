#include "Movie.h"

Movie::Movie(std::string name, std::string p_rating, int count)
	:movie_name(name), rating(p_rating), watch_count(count)
{}

Movie::~Movie()
{}

void Movie::addMovies(std::string name, std::string rate, int count)
{
	this->movie_name = name;
	this->rating = rate;
	this->watch_count = count;
}

void Movie::increaseCount()
{
	if (this->movie_name == "None") {
		std::cout << "Movie is not in the list.";
	}
	else {
		this->watch_count += 1;
	}
}

void Movie::displayMovies()
{
	std::cout << "Movie name: " << this->movie_name << std::endl;
	std::cout << "Your rating: " << this->rating << std::endl;
	std::cout << "Times watched: " << this->watch_count << std::endl;
}

std::string Movie::getName()
{
	return movie_name;
}

std::string Movie::getRating()
{
	return rating;
}

int Movie::getCount()
{
	return watch_count;
}