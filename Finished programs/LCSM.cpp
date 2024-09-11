/*
This program finds the longest consecutive common sequence amongst a number of DNA strings. 
it first reads a Fasta file and stores the different sequences in a vector. Then it iterates through all the possible substrings of the first sequence and checks if said substring is common amongst all the othr DNA sequences. If it is, it is then stored in a variable. If the substring is shorter than the variable, the it is not checked, as we want the longest substring. This is a sub-optimal solution.  
*/

#include <iostream>
#include <fstream>
#include <string>
#include<vector>
using namespace std;

void read_FASTA(vector<string>& DNA){
	string line, seq_id, seq_DNA;
	while(cin >> line){
		if(line.empty())
			continue;
		if(line[0] == '>'){
			if(!seq_id.empty()){
				DNA.push_back(seq_DNA);
			}
			seq_id = line.substr(1);
			seq_DNA.clear();
		}
		else {
			line = line.substr(0, line.length());
			seq_DNA += line; 
		}
	}
	if(!seq_id.empty()){
		DNA.push_back(seq_DNA);
	}
}

bool check_motive(vector<string> DNA, string motive){
	for(int i = 1; i < DNA.size(); i++){
		if(DNA[i].size() < motive.size() or DNA[i].find(motive) == -1) return false; 
	}
	return true; 
}

string find_motive(vector<string> DNA){
	string longest = ""; 
	int size_1 = DNA[0].size();
	for(int i = 0; i < size_1; i++){
		for(int j = size_1; j > i; j--){
			if(j - i <= longest.size()) break; 
			else {
				string motive = DNA[0].substr(i, j - i);
				if (check_motive(DNA, motive) == true) longest = motive; 
			}
		}
	}
	return longest; 
}
	
int main(){
	vector<string> DNA;
	string motive; 
	read_FASTA(DNA); 
	motive = find_motive(DNA); 
	cout << motive << endl; 
}
