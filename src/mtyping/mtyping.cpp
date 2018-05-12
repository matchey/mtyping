
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

	cout << "sections: ";
	getline(cin, str_input);

	sections = split(str_input, ',');

	for(auto it = sections.begin(); it != sections.end(); ++it){
		size_t pos;
		while((pos = it->find_first_of(" 　\t")) != string::npos){
			it->erase(pos, 1);
		}
		if((pos = it->find_first_of("~-")) != string::npos){
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
		}else{
			selected.push_back(stoi(*it));
		}
	}
	
	for(auto it = selected.begin(); it != selected.end(); ++it){
		cout << *it << endl;
	}
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

