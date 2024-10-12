/*
This program computes the reverse complement of a DNA strand. It iterates through the DNA string from the end to the start and stores the complimentary nucleotide (A-T and G-C) in an auxiliary string from the start to the end (making it reverse). 
*/

#include <iostream>
#include<string>
using namespace std;

string reverse_complement(string DNA){
	int n = DNA.length();
	int j = n - 1;
	string reverse(n, ' '); 
	for (int i = 0; i < n; i++){
		if(DNA[j] == 'A') reverse[i] = 'T';
		else if(DNA[j] == 'T') reverse[i] = 'A';
		else if(DNA[j] == 'C') reverse[i] = 'G';
		else reverse[i] = 'C';
		j--;
	}
	return reverse; 
}

 int main (){
	string DNA; 
	cin >> DNA; 
	string reverse = reverse_complement(DNA);
	int n = reverse.length();
	for(int i = 0; i < n; i++) cout << reverse[i];
	cout << endl; 
}
