
#ifndef SENTENCE_H
#define SENTENCE_H

#include <iostream> //e.g. std::string

class Sentence
{
	std::string jpn;
	std::string eng;
	// std::vector<Sentence> sentences;
	// std::vector< std::vector<Sentence> > sections;

	public:
	Sentence(const std::string&, const std::string&);
	void show();
	int typing();
};

#endif

