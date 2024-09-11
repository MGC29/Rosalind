/*
This program uptakes a collection of DNA strings from a FASTA file and constructs its profile matrix, a "4×n matrix P in which P1,j represents the number of times that 'A' occurs in the jth position of one of the strings, P2,j represents the number of times that C occurs in the jth position, and so on". 
It also constructs the consensus string, which is "formed from our collection by taking the most common symbol at each position".
Finally it prints the consensus string and the profile matrix. 
*/

#include <iostream>
#include <fstream>
#include <string>
#include<vector>
using namespace std;

int nucleotide_to_number(char c){
    switch (c) {
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
    } 
	return 3;
}

char number_to_nucleotide(int n){
    switch (n) {
		case 0 : return 'A'; 
		case 1 : return 'C'; 
		case 2 : return 'G'; 
    } 
	return 'T';
}

//this function imputs a string of DNA and for each position adds one to the corresponding nucleotide in the vector
void count_nucleotides(string DNA, vector<vector<int>>& freq){
	int n = DNA.size();
	if(freq[0].size() == 0) {
		freq = vector<vector<int>>(4, vector<int>(n));
	}
	for(int i = 0; i < n; i++){
		int j = nucleotide_to_number(DNA[i]);
		freq[j][i]++;
	}
}

//this function checks for each position of the sequence (j) the most abundant nucleotide (i) and appends it to the sequence
void most_common_seq(vector<vector<int>> &freq, string& seq){
	int n = freq[0].size();
	for(int j = 0; j < n; j++){
		int max = -1; 
		for(int i = 0; i < 4; i++){
			if(freq[i][j] > max){
				max = freq[i][j]; 
				seq[j] = number_to_nucleotide(i); 
			}
		}
	}
}

//this function takes a DNA sequence from a FASTA file and calls the count_nucleotides function 
void read_FASTA(vector<vector<int>>& freq){
	string line, id, DNA;
	bool first_time = true; 
	
	while(cin >> line){
		if(line.empty())
			continue;
		if(line[0] == '>'){
			if(!id.empty()){
				count_nucleotides(DNA, freq); 
			}
			id = line.substr(1);
			DNA.clear();
		}
		else {
			DNA += line; 
		}
	}
	if(!id.empty()){
		count_nucleotides(DNA, freq); 
	}
}

int main(){
	vector<vector<int>> freq(4); 
	read_FASTA(freq); 
	
	string common_seq(freq[0].size(), ' ');
	most_common_seq(freq, common_seq);
	
	cout << common_seq << endl; 
	for(int i = 0; i < 4; i++){
		cout << number_to_nucleotide(i) << ": "; 
		for (int j = 0; j < freq[0].size(); j++) cout << freq[i][j] << ' '; 
		cout << endl; 
	}

}
