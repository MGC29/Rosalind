/*
This program calculates "the number of rabbits after n months if we begin with 1 pair and in each generation, every pair of reproduction-age rabbits produces a litter of k rabbit pairs". 
Both solutions use a bottom-up dynamic programming algorithm. The function number_rabbits_2 is better because it doesn't need a n-size vector so instead of having space complexity O(n) it is O(1).
*/

#include <iostream>
#include<vector>
using namespace std;

long long int number_rabbits_1(int n, int k){
	if(n == 1 or n == 2) return 1;
	if(n == 3) return k;
	vector<long long int> rabbits(n + 1);
	rabbits[1] = 1;
	rabbits[2] = 1;
	rabbits[3] = 1 + k;
	for(int i = 4; i <= n; i++){
		rabbits[i] = rabbits[i - 1] + rabbits[i - 2] * k;
	}
	return rabbits[n];
}

long long int number_rabbits_2(int n, int k){
	long long int i = 1; 
	long long int j = 1;
	for(int a = 2; a < n; a++){
		long long int aux = j;
		j = i * k + aux; 
		i = aux;
	}
	return j; 
}

 int main (){
	int n, k; 
	cin >> n >> k; 
	cout << number_rabbits_2(n, k) << endl;
}




/*

}
*/