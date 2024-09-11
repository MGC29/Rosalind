/*
This program imputs a FASTA file (function read_FASTA), calculates it's GC content (function GC_content), meaning the percentage of nucleotides that are G or C and returns the id of the sequence with the highest GC_content as well as this percentage (function max_GC). 

*/

#include <iostream>
#include<string>
#include <iomanip>
#include <vector>
using namespace std;


void read_FASTA(vector<string>& DNA, vector<string>& id){
	string line, seq_id, seq_DNA;
	while(cin >> line){ 
		if(line.empty())
			continue;
		if(line[0] == '>'){
			if(!seq_id.empty()){
				DNA.push_back(seq_DNA);
			}
			seq_id = line.substr(1);
			id.push_back(seq_id);
			seq_DNA.clear();
		}
		else {
			seq_DNA += line; 
		}
	}
	if(!seq_id.empty()){
		DNA.push_back(seq_DNA);
	}
}

double GC_content(string s){
	int n = s.size();
	int counter = 0;
	for(int i = 0; i < n; i++){		
		if(s[i] == 'G' or s[i] == 'C') counter ++;
	}
	double result = (counter * 100.0 / n) ;
	return result; 
}

void max_GC(vector<string>& DNA, vector<string>& id){
	double max_content = 0.0;
	string max_id = ""; 
	for(int i = 0; i < DNA.size(); i++){
		double gc_count = GC_content(DNA[i]);
		if(gc_count > max_content){
			max_content = gc_count;
			max_id = id[i]; 
		}
	}
	cout << fixed; 
	cout << setprecision(6);
	cout << max_id << endl << max_content << endl;
}

int main(){
	vector<string> DNA; 
	vector<string> id; 
	read_FASTA(DNA, id);  
	max_GC(DNA, id); 
}
