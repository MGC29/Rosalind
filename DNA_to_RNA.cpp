/*
This program takes a DNA string and returns its transcribed RNA string thorugh the function transcribe_DNA, that exchanges the Ts for Us. The time complexity is O(n).
/*
	
#include <iostream>
#include<string>
using namespace std;

string transcribe_DNA(string DNA){
	string RNA = DNA; 
	int n = RNA.length();
	for(int i = 0; i < n; i++){
		if(RNA[i] == 'T') RNA[i] = 'U';
	}
	return RNA;
}

 int main (){
	string DNA; 
	cin >> DNA; 
	string RNA = transcribe_DNA(DNA);
	int n = RNA.length();
	for(int i = 0; i < n; i++) cout << RNA[i];
	cout << endl; 
}
