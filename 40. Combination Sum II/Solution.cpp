void findNumbers(const vector<int>& candidates, int target, vector<vector<int>>& sum, vector<int>& res, int start) {
    if (target == 0) {
        sum.push_back(res);
        return;
    }
    for (int i = start; i < candidates.size(); ++i) {
        if (i > start && candidates[i] == candidates[i - 1]) 
            continue;

        if (candidates[i] > target) 
            break;

        res.push_back(candidates[i]);
        findNumbers(candidates, target - candidates[i], sum, res, i + 1);
        res.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> res;
    vector<vector<int>> sum;
    findNumbers(candidates, target, sum, res, 0);
    return sum;
}
