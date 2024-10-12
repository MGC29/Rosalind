	/*
	This program takes a protein sequence of maximum lenght 1000 am and returns its total weight according to the monoisotopic mass of the amino acids. 
	*/

#include <iostream>
#include <unordered_map>
#include<iomanip>
using namespace std;

void populate_mass(unordered_map<char, double> &map){
	map['A'] =  71.03711; 
	map['C'] =   103.00919; 
	map['D'] =  115.02694; 
	map['E'] =  129.04259; 
	map['F'] =   147.06841; 
	map['G'] =  57.02146; 
	map['H'] = 137.05891;
	map['I'] =  113.08406; 
	map['K'] =  128.09496;
	map['L'] = 113.08406;
	map['M'] =   131.04049; 
	map['N'] =  114.04293;
	map['P'] = 97.05276;
	map['Q'] =   128.05858; 
	map['R'] =  156.10111;
	map['S'] = 87.03203;
	map['T'] =   101.04768; 
	map['V'] =  99.06841;
	map['W'] =   186.07931; 
	map['Y'] =  163.06333;
	
}

int main(){
	unordered_map<char, double> mass; 
	populate_mass(mass); 
	string protein; 
	long double prot_mass = 0; 
	cin >> protein; 
	for(int i = 0; i < protein.size(); i++){
		prot_mass += mass[protein[i]]; 
	}
	cout << setprecision(15) << prot_mass << endl; 
}
