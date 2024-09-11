/*
This program takes an mRNA string and outputs the corresponding protein string. It first searches for the location of the AUG codon, as it signals the start of translation. It then iterates through the RNA string from that position, and converts each codon to the corresponding amino acid, which are stored in a string. The stop codons are represented with a dot. Once the strind ends or it encounters a stop codon, the function stops and returns the protein string. 
*/

#include <iostream>
#include <string>
#include<vector>
using namespace std;

int find_AUG(string RNA){
	for(int i = 0; i <= RNA.size() - 2; i++){
		if(RNA[i] == 'A' and RNA[i + 1] == 'U' and RNA[i + 2] == 'G') return i;
	}
	return -1; 
}

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
	int n = RNA.size(), i = 0;
	while(not finish){
		if(i + 2 < n){
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
		else finish = true;
	} 
	return protein; 
}

int main(){
	string RNA, protein; 
	cin >> RNA; 
	int start = find_AUG(RNA);  
	if(start != -1) {
		RNA = RNA.substr(start);
		protein = RNA_to_protein(RNA, start);
		cout << protein << endl;
	}
}
