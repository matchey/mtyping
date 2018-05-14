
#ifndef M_TYPING_H
#define M_TYPING_H

// #include <iostream>
#include <vector>
#include "mtyping/sentence.h"

class Mtyping
{
	std::vector<Sentence> sentences;
	std::vector<int> selected;

	void set_sentences(const std::string&);
	void show_count_down();

	public:
	Mtyping();
	void select_sections();
	void load();
	void play();
};

#endif

