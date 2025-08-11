#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int subsetXORSum(vector<int> &nums) {
    int n = nums.size();
    int bits = 0;

    for (int i=0; i < n; ++i)
        bits |= nums[i];

    cout << "bits = " << bits << endl;

    int ans = bits * pow(2, n-1);

    return ans;
}

int main() {
    vector<int> nums = {7, 9};
    cout << "result : " << subsetXORSum(nums) << endl;
    return (0);
}

