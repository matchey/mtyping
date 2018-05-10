
#ifndef DUO_H
#define DUO_H

#include <iostream>
#include <vector>

struct Sentence
{
	std::string eng;
	std::string jpn;
};

class Duo
{
	std::vector<Sentence> sentences;
	// std::vector< std::vector<Sentence> > sections;

	void load(const std::string&);

	public:
	Duo();
	void print();
	void typing();
};

#endif

