#include <iostream>
#include <vector>
using namespace std;

int subsetXORSum(vector<int>& nums) {
    if (nums.size() == 0)
        return 0;
    
    int sum = 0;
    vector<int> Subsets;
    for (size_t i = 0; i < nums.size(); i++) {
        sum += nums[i];
    }
    
    return sum;
}

int main() {
    vector<int> nums = {1, 3};
    cout << "result : " << subsetXORSum(nums) << endl;
    return (0);
}

