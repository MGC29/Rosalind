/*
This program returns all the locations of a string t as a substring of s.
It requires 1-based numbering, that is why I add 1 to position, as the function find() returns in 0-based numbering. Similarly I set position to be != 0, because in case t is not in s, the function returns -1, + 1 = 0. 
*/

#include <iostream>
#include <string>
#include<vector>
using namespace std;

int main(){
	string s, r; 
	cin >> s >> r; 
	int position = s.find(r) + 1;
	if(position != 0){
		cout << position;
		position = s.find(r, position) + 1;
		while(position !=  0){
			cout << ' ' << position; 
			position = s.find(r, position) + 1;
		}
	}
	cout << endl;
}