class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> sum;
        vector<int>::iterator it = nums.begin();
        int number = 0;
        int i = 0;
        for (; it < nums.end(); it++) {
            number += *it;
            sum.push_back(number);
        }
        return (sum);
    }
};
