#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string> > res;
    vector<string> tmp = strs;

    for (int i = 0; i < tmp.size(); i++)
        sort(tmp[i].begin(), tmp[i].end());

    for (int i = 0; i < strs.size(); i++) {
        vector<string> replace;
        int k = i;
        while (k < strs.size()) {
            if (i == k)
                replace.push_back(strs[k]);
            k++;
            if (tmp[i] == tmp[k]) {
                cout << k << "-" << tmp[i] << "-" << tmp[k] << "->" << strs[k]<< endl;
                replace.push_back(strs[k]);
                tmp.erase(tmp.begin() + k);
            }
        } 
        // for (auto elem: replace)
            // cout << i << "-" << elem << endl;
        res.push_back(replace);
    }
    return (res);
}

int main(int argc, char const *argv[]) {
    vector<string> test1 = {"eat","tea","tan","ate","nat","bat"};
    vector<string> test2 = {""};
    vector<string> test3 = {"a"};

    vector<vector<string> > output = groupAnagrams(test1);

    for (auto vec : output) {
        cout << "[";
        for (auto elem : vec)
            cout << elem << ",";
        cout << "]" << endl;
    }

    return 0;
}

