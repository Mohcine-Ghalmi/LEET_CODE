vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> > res;
    set<vector<int> > seter; // is stl which each element has to be unique and sorted 

    sort(nums.begin(), nums.end());
    
    for (int  i = 0; i < nums.size(); i++) {
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k) {
            if (nums[i] + nums[j] + nums[k] == 0) {
                seter.insert({nums[i], nums[j], nums[k]});
                j++;
                k--;
            } else if (nums[i] + nums[j] + nums[k] < 0)
                j++;
            else
            k--;
        }
    }
    for (auto numbers : seter)
        res.push_back(numbers);
    return res;
}
