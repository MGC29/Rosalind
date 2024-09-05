#include <iostream>
#include<string>
#include <iomanip>
#include <fstream>
using namespace std;

double GC_content(string s){
	int n = s.size();
	int counter = 0;
	for(int i = 0; i < n; i++){		
		if(s[i] == 'G' or s[i] == 'C') counter ++;
	}
	double result = (counter * 100.0 / n) ;
	return result; 
}

int main(int argc, char* argv[]){
	ifstream input(argv[1]);
	if (!input.good()) {
        cout << "Error opening: " << argv[1] << " . You have failed." << endl;
        return -1;
    }
	
	string line, id, DNA;
	double max_GC = 0.0;
	string max_id = "";

	while(getline(input, line)){
		if(line.empty())
			continue;
		if(line[0] == '>'){
			if(!id.empty()){
				double gc_count = GC_content(DNA); 
				if(gc_count > max_GC){
					max_GC = gc_count;
					max_id = id;
				}
			}
			id = line.substr(1);
			DNA.clear();
		}
		else {
			line = line.substr(0, line.length() - 1);
			DNA += line; 
		}
	}
	if(!id.empty()){
		double gc_count = GC_content(DNA);
		if(gc_count > max_GC){
			max_GC = gc_count;
			max_id = id;
		}
	}
	cout << fixed; 
	cout << setprecision(6);
	cout << max_id << endl << max_GC << endl;
}
