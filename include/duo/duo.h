
#ifndef DUO_H
#define DUO_H

#include <iostream>
#include <vector>

struct Sentense
{
	std::string eng;
	std::string jpn;
};

class Duo
{
	std::vector<Sentense> sentenses;

	void load(const std::string&);

	public:
	Duo(const std::string&);
	void print();
	void typing();
};

#endif

