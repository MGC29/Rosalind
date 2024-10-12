/*
This program takes a series of DNA strings in FASTA format and returns the adjacency list corresponding to O3. 
*/

#include <iostream>
#include <string>
#include<vector>
using namespace std;

const int K = 3; 

void read_FASTA(vector<string>& id, vector<string>& DNA){
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

void find_nodes(vector<string>& id, vector<string>& DNA){
	int n = DNA.size(); 
	int counter = 0;
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(DNA[i] != DNA[j]){ 
				string suffix = DNA[i].substr(DNA[i].size() - K); 
				string prefix = DNA[j].substr(0, K);
				if(suffix == prefix) {
					cout << id[i] << ' ' << id[j] << endl; 
				}
				suffix = DNA[j].substr(DNA[j].size() - K); 
				prefix = DNA[i].substr(0, K);
				if(suffix == prefix) {
					cout << id[j] << ' ' << id[i] << endl; 
				}
			}
		}
	}
}

int main(){
	vector<string> id;
	vector<string> DNA;
	read_FASTA(id, DNA);
	find_nodes(id, DNA); 	
}
