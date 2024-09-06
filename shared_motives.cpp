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

int three_max(int x, int y, int z){
	int aux = max(x, y);
	aux = max(aux, z);
	if(aux < 0) return 0; 
	return aux; 
}

void local_alignment(string s, string t, vector<vector<int>>& matrix){
	int s_size = s.size(), t_size = t.size();
	for(int i = 1; i <= s_size; i++){
		for(int j = 1; j <= t_size; j++){
			/* int top = matrix[i - 1][j] - 2; 
			int left = matrix[i][j - 1] - 2; 
			int diagonal = matrix[i - 1][j - 1]; 
			if(s[i - 1] == t[j - 1]) diagonal++; 
			else diagonal--;
			matrix[i][j] = three_max(top, left, diagonal) */;
			if(s[i - 1] == t[j - 1]) matrix[i][j] = matrix[i - 1][j - 1] + 1; 
		}
	}

}


int main(int argc, char* argv[]){
	vector<string> DNA;
	read_FASTA(DNA); 
	
	int size_1 = DNA[0].size(), size_2 = DNA[1].size();
	vector<vector<int>> matrix (size_1 + 1, vector<int>(size_2 + 1));
	
	local_alignment(DNA[0], DNA[1], matrix); 
	for(int i = 0; i <= size_1; i++){
		for(int j = 0; j <= size_2; j++) cout << matrix[i][j]; 
		cout << endl; 
	}
	
}


/*
	for(int i = 0; i <= s_size; i++){
		for(int j = 0; j <= t_size; j++){
			cout << matrix[i][j]; 
			if(matrix[i][j] == 0) cout << '0'; 
			else cout << '-'; 
		}
		cout << endl; 
	}
	
	for(int i = 0; i <= size_1; i++){
		for(int j = 0; j <= size_2; j++) cout << matrix[i][j]; 
		cout << endl; 
	}
*/