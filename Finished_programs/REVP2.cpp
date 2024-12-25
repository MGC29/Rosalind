/*
This program takes a DNA string and returns the position and lenght of every reverse palindrome,
meaning a sequence that is equal to its reverse complement, that has a lenght between 4 and 12 
nucleotides. 
*/

#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

void read_FASTA(string &DNA){
	string line, seq_id, seq_DNA;
	while(cin >> line){ 
		if(line.empty())
			continue;
		if(line[0] == '>'){
			if(!seq_id.empty()){
				DNA = seq_DNA;
			}
			seq_id = line.substr(1);
			seq_DNA.clear();
		}
		else {
			seq_DNA += line; 
		}
	}
	if(!seq_id.empty()){
		DNA = seq_DNA;
	}
}

void complement(string &DNA, string &reverse){
	int n = DNA.length();
	for (int i = 0; i < n; i++){
		if(DNA[i] == 'A') reverse[i] = 'T';
		else if(DNA[i] == 'T') reverse[i] = 'A';
		else if(DNA[i] == 'C') reverse[i] = 'G';
		else reverse[i] = 'C';
	}
}

void palindrome(string &seq){
	for(int i = 0; i < seq.size(); i++){
		for(int j = 4; j <= 12; j = j + 2){
			if(i + j > seq.size()) break;
			string subseq = seq.substr(i, j / 2);
			string rev_subseq = seq.substr(i + (j / 2), j / 2);
			complement(rev_subseq, rev_subseq);
			reverse(rev_subseq.begin(), rev_subseq.end());
			if(subseq == rev_subseq) cout << i + 1 << ' ' << j << endl;
		}
	}
}

int main(){
	string seq;
	read_FASTA(seq);
	palindrome(seq); 
}
