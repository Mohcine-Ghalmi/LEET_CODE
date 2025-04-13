
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagramMap;

    for (const string& word : strs) {
        string sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end());
        anagramMap[sortedWord].push_back(word);
    }

    vector<vector<string>> res;
    for (auto& entry : anagramMap)
        res.push_back(entry.second);

    return res;
}
