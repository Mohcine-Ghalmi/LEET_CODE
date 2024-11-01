#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    if(n==1)
        return;

    for(int i = n - 1; i >= 0; i--) {
        int flag = 0;

        for(int j = i + 1; j < n; j++){
            if(nums[j] > nums[i]) {
                flag = 1;
                swap(nums[i], nums[j]);
                break;
            }
        }
        if(flag == 0)
            sort(nums.begin() + i, nums.end());
        else
            break;
    }
}

int main(void) {
     std::vector<int> nums = {1, 3, 2};
    nextPermutation(nums);
    
    for (int num : nums) {
        std::cout << num << " ";
    }
    return (0);
}