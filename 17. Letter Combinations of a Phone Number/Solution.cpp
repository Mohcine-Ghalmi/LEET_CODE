#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <unordered_map>

using namespace std;

void backtrack(const string &digits, const unordered_map<char, string> &key, int index, string &current, vector<string> &result) {
    if (index == digits.length()) {
        result.push_back(current);
        return;
    }

    char digit = digits[index];
    for (char letter : key.at(digit)) {
        current.push_back(letter);
        backtrack(digits, key, index + 1, current, result);
        current.pop_back(); 
    }
}

vector<string> letterCombinations(string digits) {
    if (digits.empty() || digits == "1") return {};

    unordered_map<char, string> key = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    
    vector<string> result;
    string currentCombination;
    backtrack(digits, key, 0, currentCombination, result);

    return result;
}

int main(void) {
    vector<string> vect = letterCombinations("1");
    for (auto elem : vect)
        cout << elem << " ";
    return (0);
}