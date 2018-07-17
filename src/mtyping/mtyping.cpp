
#include <fstream>
#include <chrono>
#include <unistd.h>
#include <cmath> // std::round()
#include <thread> //this_thread::sleep_for()
#include <algorithm> //shuffle
#include <random>
#include <mach-o/dyld.h> // _NSGetExecutablePath
#include "mstring/mstring.h"
#include "mtyping/mtyping.h"

using namespace std;

Mtyping::Mtyping()
{
}

void Mtyping::select_sections()
{
	string str_input;
	vector<string> sections;
	int ranges[2];

	cout << "select sections: "; //e.g. 2, 4, 6, 12~19, 30
	getline(cin, str_input);

	if(str_input == "all" || str_input == ""){
		str_input = "1~45";
	}

	size_t pos;
	// while((pos = str_input.find_first_of(" 　\t")) != string::npos){
	// 	str_input.erase(pos, 1);
	// }
	while((pos = str_input.find_first_not_of("1234567890-~,")) != string::npos){
		str_input.erase(pos, 1);
	}

	sections = split(str_input, ',');

	for(auto it = sections.begin(); it != sections.end(); ++it){
		if(!it->empty()){
			if((pos = it->find_first_of("~-")) != string::npos){
				if(pos == it->find_last_of("~-") && 0 < pos && pos + 1 < it->length()){
					ranges[0] = stoi(it->substr(0, pos));
					ranges[1] = stoi(it->substr(pos+1));

					if(ranges[1] < ranges[0]){
						int tmp = ranges[0];
						ranges[0] = ranges[1];
						ranges[1] = tmp;
					}
					for(int i=ranges[0]; i<=ranges[1]; ++i){
						selected.push_back(i);
					}
				}
			}else{
				selected.push_back(stoi(*it));
			}
		}
	}
	
	// for(auto it = selected.begin(); it != selected.end(); ++it){
	// 	cout << *it << endl;
	// }
	// section
	// 1,2,3,
	// 1~3
	// random 3 (less order)
	//
	// time (default 1 min)
	//
	//
	// other random 3
	// 
	// other sentences
}

//private

void Mtyping::load()
{
	size_t pos;

	string str_fname;
	char pathname[256];
	char path2org[256];

	uint32_t bufsize = sizeof(pathname);
	_NSGetExecutablePath(pathname, &bufsize); // sybolic link たどれない
	str_fname = string(pathname);
	if(str_fname.find("test_duo", str_fname.size() - 8) == string::npos){
		ssize_t length = readlink(pathname, path2org, bufsize - 1);
		if(length != -1){
			path2org[length] = '\0';
			str_fname = string(pathname);
			pos = str_fname.find_last_of('/');
			str_fname.erase(pos+1, str_fname.back());
			str_fname = str_fname + string(path2org);
		}else{
			cerr << "couldnt find org link" << endl;
			return;
		}
	}

	if((pos = str_fname.find("mtyping")) != string::npos){
		str_fname.erase(pos+7, str_fname.back());
		str_fname += "/params.yaml";
	}

	ifstream f(str_fname.c_str());
	if(f.fail()){
		cerr << "couldnt find " << str_fname << endl;
		return;
	}
	string dir_name;
	while(getline(f, dir_name)){
		// if()
		// cout << "dirname: " << dir_name << endl;
		break;
	}

	string filename;
	for(auto it = selected.begin(); it != selected.end(); ++it){
		filename = dir_name + "/section" + to_string(*it) + ".txt";
		set_sentences(filename);
	}
}

// void Mtyping::load(const std::string& filename)
// {
// 	cout << filename << endl;
// }

void Mtyping::play()
{
	int cnt_miss = 0;
	int cnt_char = 0;
	chrono::system_clock::time_point start, end;

	show_count_down();

	start = chrono::system_clock::now();
	for(auto it = sentences.begin(); it != sentences.end(); ++it){
		cout << endl;
		cnt_char += it->show();
		cnt_miss += it->typing();
		end = chrono::system_clock::now();
		auto elaped = chrono::duration_cast<chrono::milliseconds>(end - start).count();
		if(elaped > 70 * 1e3){
			break;
		}
	}

	auto elaped = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	int score = round((cnt_char-cnt_miss) / (1e-3 * elaped / 60.0));
	// F:245~249, E:250~254, D:255~259, C:260~264, B:265~269, A:270~274, S:275~ 
	// char rank = 'F' - (score - 245)/5;
	char rank = 280 < score ? 'S' : score < 220 ? 'F'
		      : 'C' - int(-0.00002099146103*pow(score, 3) + 0.01487099732056*pow(score, 2)
		         - 3.38310710546607*score + 245);

	cout << "==========" << endl;
	cout << "CPM  : " << round(cnt_char / (1e-3 * elaped / 60.0)) << endl; // characters per minute
	cout << "miss : " << cnt_miss << endl; // "word" means "5 characters" for WPM

	// cout << "Score: " << score << endl;
	cout << "rank : " << rank << endl;
	cout << "==========" << endl;
}

// private

void Mtyping::set_sentences(const string& fname)
{
	string fline;
	string fline_eng;
	Sentence sentence;
	ifstream f(fname.c_str());
	int cnt = 0;
	
	if(f.fail()){
		cerr << "couldnt find " << fname << endl;
		return;
	}

	while(getline(f, fline)){
		if(!(cnt%3)){
			fline_eng = fline;
		}else if(!(cnt%3 - 2)){
			sentence.set(fline, fline_eng);
			sentences.push_back(sentence);
		}
		cnt++;
	}
	std::random_device seed_gen;
	std::mt19937 engine(seed_gen());
	shuffle(sentences.begin(), sentences.end(), engine);
}

void Mtyping::show_count_down()
{
	cout<<"準備はいいですか(Etnerキーを押してください)"<<endl;;
	getchar();
	//	cin.ignore();
	cout<<"\033[A";
	cout<<"\033[A";
	cout<<"\033[2K";
	// cout<<"(プレイ中 \":suspend\" と入力することで中断できます)"<<endl;

	for(int i=0;i<3;i++){
		cout<<"=============================="<<endl<<endl;
		cout<<"              "<<3-i<<endl<<endl;
		cout<<"=============================="<<endl<<endl;
		// sleep(1);
		chrono::milliseconds dura(1000);
		this_thread::sleep_for(dura);
		cout<<"\033[A";
		cout<<"\033[A";
		cout<<"\033[A";
		cout<<"\033[A";
		cout<<"\033[A";
		cout<<"\033[A";
	}
	for(int i=0;i<6;i++){
		cout<<"                                      "<<endl;
	}
	cout<<"\033[A";
	cout<<"\033[A";
	cout<<"\033[A";
	cout<<"\033[A";
	cout<<"\033[A";
	cout<<"\033[A";

	// sleep(0.5);
	chrono::milliseconds dura(500);
	this_thread::sleep_for(dura);

}

