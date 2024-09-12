#include <iostream>
#include <string>
#include<vector>
using namespace std;

//this function transcribes the DNA string to RNA
string transcribe_DNA(string& seq){
	int n = seq.length();
	for(int i = 0; i < n; i++){
		if(seq[i] == 'T') seq[i] = 'U';
	}
	return seq;
}

//this function returns the reverse complement of a RNA string 
string reverse_complement(string seq){
	int n = seq.length();
	int j = n - 1;
	string reverse(n, ' '); 
	for (int i = 0; i < n; i++){
		if(seq[j] == 'A') reverse[i] = 'U';
		else if(seq[j] == 'U') reverse[i] = 'A';
		else if(seq[j] == 'C') reverse[i] = 'G';
		else reverse[i] = 'C';
		j--;
	}
	return reverse; 
}

//this function searches for the first starting condon of the string 
int find_AUG(string RNA){
	for(int i = 0; i <= RNA.size() - 2; i++){
		if(RNA[i] == 'A' and RNA[i + 1] == 'U' and RNA[i + 2] == 'G') return i;
	}
	return -1; 
}

//this function translates an RNA strand to the protein sequence and prints it if it ends with an end codon 
string RNA_to_protein(string RNA, int start){
	//for each letter in the codon, U is position 0, C is position 1, A is position 2 and G is position 3
	vector<vector<string>>codon_table = {
		{"FFLL", "SSSS", "YY..", "CC.W"},
		{"LLLL", "PPPP", "HHQQ", "RRRR"},
		{"IIIM", "TTTT", "NNKK", "SSRR"},
		{"VVVV", "AAAA", "DDEE", "GGGG"}
	};
	string protein;  
	bool finish = false; 
	int n = RNA.size(), i = start;
	while(i + 2 < n and not finish){
		vector<int>nums (3);
		for(int j = 0; j < 3; j++){
			if(RNA[i + j] == 'U') nums[j] = 0; 
			else if (RNA[i + j] == 'C') nums[j] = 1; 
			else if (RNA[i + j] == 'A') nums[j] = 2; 
			else nums[j] = 3; 
		}
		char aa = codon_table[nums[0]][nums[1]][nums[2]]; 
		if(aa == '.') finish = true; 
		else protein += aa; 
		i += 3; 
	} 
	if(finish == true) return protein;  
	else return ""; 
}

//this function returns all the protein strings that can be translated form ORFs of a string
void protein_sequence(string RNA, vector<string>& prot){
	int start = find_AUG(RNA); 
	while(start != -1){
		string protein = RNA_to_protein(RNA, start); 
		if(protein != "") {
			bool in = false; 
			for(int i = 0; i < prot.size(); i++) if(protein == prot[i]) in = true; 
			if(not in) prot.push_back(protein);
		}
		RNA = RNA.substr(start + 1); 
		start = find_AUG(RNA); 
	}
}


int main(){
	string line, sequence; 
	vector<string> protein_seq; 
	while(cin >> line){
		if(line.empty()) continue;
		if(line[0] == '>') continue; 	
		else sequence += line; 
	}
	transcribe_DNA(sequence); 
	protein_sequence(sequence, protein_seq);
	sequence = reverse_complement(sequence);
	protein_sequence(sequence, protein_seq);
	for(int i = 0; i < protein_seq.size(); i++) cout << protein_seq[i] << endl; 
}