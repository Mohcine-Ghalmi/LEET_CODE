void findNumbers(vector<int>& candiates, int target, vector<vector<int> >& sum, vector<int>& res, int i) {
    if (target == 0) {
        sum.push_back(res);
        return;
    }
    while (i < candiates.size() && target - candiates[i] >= 0) {
        res.push_back(candiates[i]);
        findNumbers(candiates, target - candiates[i], sum, res, i);
        i++;
        res.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());

    vector<int> res;
    vector<vector<int> > sum;
    findNumbers(candidates, target, sum, res, 0);
    return sum;
}
