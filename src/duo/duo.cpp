
#include <unistd.h> // STDIN_FILENO
#include <termios.h> // tcgetattr
#include <ctype.h> // isprint()
#include <chrono> // std::chrono::system_clock
#include "duo/duo.h"

using namespace std;

Duo::Duo()
{
}

void Duo::print()
{
	string sentence = "Foo bar baz fizz";

	cout << sentence << endl;
	cout << "\e[2m" << sentence << "\e[m" << endl;
	cout << "\e[A";
}

void Duo::typing()
{
}

// private
void Duo::load(const string& filename)
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

