
#include <iostream>
#include "mtyping/mtyping.h"

using namespace std;

int main(int argc, char** argv)
{
	cout << "test for Duo" << endl;

	// Sentence sentence("こんにちわ世界!", "Hello, world!");
	Mtyping mt;

	// sentence.print();
	// sentence.typing();
	mt.select_sections();
	mt.load();
	mt.play();

	// cout << argv[0] << endl;

	return 0;
}

