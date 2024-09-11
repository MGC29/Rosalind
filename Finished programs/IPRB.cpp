/*
This program takes the number of individuals that are homozigot dominant, heterozigot and homozigot recessive for a given gene and calculates the probability of having a dominant descendant if two individuals are paired randomly. 
*/

#include <iostream>
#include <iomanip>
using namespace std;

// 
double mendels_law(int x, int y, int z){
	double probability = 0.0;
	int size_1 = x + y + z; 
	int size_2 = size_1 - 1; 
	
	double probability_x = x * 1.0 / size_1; 
	double probability_y = y * 1.0 / size_1; 
	double probability_z = z * 1.0 / size_1; 
	
	//if the first individual is dominant homozigot, in all cases all the descents are also dominant 
	if(probability_x > 0){
		probability += probability_x * ((x - 1) * 1.0 / size_2); 
		probability += probability_x * (y * 1.0 / size_2);
		probability += probability_x * ((z) * 1.0 / size_2);
	}
	
	//if the first individual is heterozigot, if the second is dominant all descents are dominant, if it is heterozigot 3/4 are dominant and if it is recessive 1/2
	if(probability_y > 0){
		probability += probability_y * (x * 1.0 / size_2); 
		probability += probability_y * ((y - 1) * 1.0 / size_2) * 3.0/4.0;
		probability += probability_y * (z * 1.0 / size_2) * 1.0/2.0;
	}
	//if the first individual is recessive, if the second is dominant all are dominant, if it's heterozigot 1/2 are dominat, if it's recessive none are dominant
	if(probability_z > 0){
		probability += probability_z * (x * 1.0 / size_2); 
		probability += probability_z * (y * 1.0 / size_2) * 1.0/2.0;
	}
	
	return probability;
}

int main(){
	int k, m, n;
	cin >> k >> m >> n; 
	cout << fixed; 
	cout << setprecision(6);
	cout << mendels_law (k, m, n) << endl; 
}
