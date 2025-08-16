#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return unique(nums.begin(), nums.end()) != nums.end();
}

int main() {
    vector<int> nums = {1, 2, 3};
    cout << containsDuplicate(nums) << endl; 
    return 0;
}
