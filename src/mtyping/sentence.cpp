
#include <unistd.h> // STDIN_FILENO
#include <termios.h> // tcgetattr
#include <ctype.h> // isprint()
#include <chrono> // std::chrono::system_clock
#include "mtyping/sentence.h"

using namespace std;

Sentence::Sentence()
{
}

void Sentence::print()
{
	string sentence = "Foo bar baz fizz";

	cout << sentence << endl;
	cout << "\e[2m" << sentence << "\e[m" << endl;
	cout << "\e[A";
}

void Sentence::typing()
{
	int chr;
	string sentence = "Foo bar baz fizz";

	struct termios CookedTermIos; // cooked モード用
	struct termios RawTermIos; // raw モード用

	tcgetattr(STDIN_FILENO, &CookedTermIos);

	RawTermIos = CookedTermIos;
	cfmakeraw(&RawTermIos);

	tcsetattr(STDIN_FILENO, 0, &RawTermIos);

	for(auto it = sentence.begin(); it != sentence.end(); ++it) {
		if((chr = getchar()) == 0x03) break;
		if(chr == *it){
			putchar(chr);
		}else{
			--it;
		}
	}
	
	tcsetattr(STDIN_FILENO, 0, &CookedTermIos);
	putchar('\n');

}

// private
void Sentence::load(const string& filename)
{
	// section
	// 1,2,3,
	// 1~3
	// random 3
	//
	// time (default 1 min)
	//
	//
	// other random 3
	// 
	// other sentences
}

