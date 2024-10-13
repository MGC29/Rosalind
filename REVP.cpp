/*

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

void palindrome(string &seq, string &reverse_seq){
	for(int i = 0; i <= seq.size() - 4;  i++){
		for(int j = i + 3; j <= i + 11; j++){
			if(j > seq.size()) break; 
			string original_seq = seq.substr(i, j - i) ; 
			string palindrome_seq = reverse_seq.substr(i, j - i); 
			reverse(palindrome_seq.begin(), palindrome_seq.end());
			if(original_seq == palindrome_seq){
				cout << i + 1 << ' ' << j - i << endl; 
			}
		}
	}
}



int main(){
	string seq; 
	read_FASTA(seq);
	string rev_seq(seq.size(), ' '); 
	complement(seq, rev_seq); 
	palindrome(seq, rev_seq); 
}
