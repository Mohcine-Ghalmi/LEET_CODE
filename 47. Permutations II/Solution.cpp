#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(vector<int>& nums, vector<vector<int>>& result, int start) {
    if (start == nums.size()) {
        result.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        backtrack(nums, result, start + 1);
        swap(nums[start], nums[i]);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> result;
    backtrack(nums, result, 0);
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permuteUnique(nums);
    for (const auto& permutation : result) {
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}