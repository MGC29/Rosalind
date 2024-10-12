/*
This program takes two strings of the same length, iterates through them and counts the number of point mutations, meaning that for a given position they have different nucleotides. 
*/

#include <iostream>
#include<string>
using namespace std;

int count_point_mutations(string s, string t){
	int n = s.size();
	int counter = 0;
	for(int i = 0; i < n; i++){
		if(s[i] != t[i]) counter++;
	}
	return counter;
}

int main(){
	string s, t; 
	cin >> s >> t; 
	cout << count_point_mutations(s, t) << endl; 
}