/*
The program takes 6 nonnegative integers which represent "the number of couples in a population possessing each genotype pairing for a given factor. In order, the six given integers represent the number of couples having the following genotypes: 1 - AA-AA, 2 - AA-Aa, 3 - AA-aa, 4 - Aa-Aa, 5 - Aa-aa, 6 - aa-aa". 
It returns the "expected number of offspring displaying the dominant phenotype in the next generation, under the assumption that every couple has exactly two offspring".
*/

#include <iostream>

using namespace std;

double calculate_offspring(int x, int i){
	double probability; 
	switch(i){
		case 1 : 
			probability = 1;
			break; 			
		case 2: 
			probability = 1; 
			break; 
		case 3: 
			probability = 1; 
			break; 
		case 4: 
			probability = 3.0 / 4.0; 
			break; 
		case 5: 
			probability = 1.0 / 2.0; 
			break; 
		case 6: 
			probability = 0; 
			break; 
	} 
	double offspring = 2 * x * probability; 
	return offspring; 
}

int main(){
	double offspring = 0.0; 
	for(int i = 1; i <= 6; i++){
		int x; 
		cin >> x; 
		if(x > 0) {
			offspring += calculate_offspring(x, i);
		}
	}
	cout << offspring << endl; 
}

