/*
This program takes a DNA sequence, iterates through it and counts the number of each nucleotide, assuming that the sequence will only have As, Ts, Gs and Cs. 
It has time complexity O(n) and space complexity O(1).
*/

#include <iostream>
#include<string>
using namespace std;

 int main (){
	string DNA; 
	int a = 0, c = 0, g = 0, t = 0; 
	cin >> DNA; 
	int s = DNA.length();
	for(int i = 0; i < s; i++){
		if(DNA[i] == 'A') a++;
		else if (DNA[i] == 'C') c++;
		else if (DNA[i] == 'G') g++;
		else  if (DNA[i] == 'T') t++;
	}
	cout << a << ' ' << c << ' ' << g << ' ' << t << endl;
}
