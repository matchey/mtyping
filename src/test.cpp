
#include <iostream>
#include "mtyping/mtyping.h"

using namespace std;

int main()
{
	cout << "test for Duo" << endl;

	// Sentence sentence("こんにちわ世界!", "Hello, world!");
	Mtyping mt;

	// sentence.print();
	// sentence.typing();
	mt.select_sections();

	return 0;
}

