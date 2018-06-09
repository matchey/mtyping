
#include <unistd.h> // STDIN_FILENO
#include <termios.h> // tcgetattr
// #include <ctype.h> // isprint()
// #include <chrono> // std::chrono::system_clock
#include "mtyping/sentence.h"

using namespace std;

Sentence::Sentence()
{
}

Sentence::Sentence(const std::string& ja, const std::string& en)
{
	jpn = ja;
	eng = en;
}

void Sentence::set(const std::string& ja, const std::string& en)
{
	jpn = ja;
	eng = en;
}

int Sentence::show()
{
	cout << jpn << endl;
	// cout << eng << endl;
	cout << "\e[2m" << eng << "\e[m" << endl;
	cout << "\e[A";

	return eng.length();
}

int Sentence::typing()
{
	char chr;
	int cnt_miss = 0;

	struct termios CookedTermIos; // cooked モード用
	struct termios RawTermIos; // raw モード用

	tcgetattr(STDIN_FILENO, &CookedTermIos); //初期状態を保存

	RawTermIos = CookedTermIos;
	cfmakeraw(&RawTermIos);

	tcsetattr(STDIN_FILENO, 0, &RawTermIos); //端末をRowモードに設定

	for(auto it = eng.begin(); it != eng.end(); ++it) {
		if((chr = getchar()) == 0x03){
			cnt_miss = eng.length() - distance(eng.begin(), it);;
			break; // <C-c> for break
		}
		if(chr == *it){
			putchar(chr);
		}else{
			cnt_miss++;
			--it;
		}
	}
	
	tcsetattr(STDIN_FILENO, 0, &CookedTermIos);
	putchar('\n');

	return cnt_miss;
}

// private

