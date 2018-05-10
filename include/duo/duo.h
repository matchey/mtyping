
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

	void load(const std::string&);

	public:
	Duo();
	void print();
	void typing();
};

#endif

