
#ifndef SENTENCE_H
#define SENTENCE_H

#include <iostream>
#include <vector>

class Sentence
{
	std::string eng;
	std::string jpn;
	// std::vector<Sentence> sentences;
	// std::vector< std::vector<Sentence> > sections;

	void load(const std::string&);

	public:
	Sentence();
	void print();
	void typing();
};

#endif

