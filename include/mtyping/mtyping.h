
#ifndef M_TYPING_H
#define M_TYPING_H

// #include <iostream>
#include <vector>
#include "mtyping/sentence.h"

class Mtyping
{
	std::vector<Sentence> sentences;
	std::vector<int> selected;

	public:
	Mtyping();
	void select_sections();
};

#endif

