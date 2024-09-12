#include <iostream>
#include <vector>
using namespace std;

void permute (vector<int>& nums, int start, int end){
	if(start == end) {
		for(int i = 0; i < end; i++) cout << nums[i] << ' '; 
		cout << nums[end] << endl; 
	}
	for(int i = start; i <= end; i++){
		swap(nums[start], nums[i]);
		permute(nums, start + 1, end);
		swap(nums[start], nums[i]); 
	}
}

int main(){
	int x, perm = 1; 
	cin >> x; 
	vector<int> nums(x);
	for(int i = 1; i <= x; i++) {
		perm *= i; 
		nums[i - 1] = i; 
	}
	cout << perm << endl; 
	permute(nums, 0, nums.size() - 1);
}
