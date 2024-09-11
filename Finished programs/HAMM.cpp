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