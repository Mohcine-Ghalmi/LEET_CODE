#include <iostream>
#include <string>
#include <vector>

using namespace std;

string multiply(string num1, string num2) {
    int m = num1.size(), n = num2.size();
    
    if (num1 == "0" || num2 == "0") return "0";
    
    vector<int> result(m + n, 0);
    
    for (int i = m - 1; i >= 0; --i)
        for (int j = n - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    
    string res = "";
    for (int num : result)
        if (!(res.empty() && num == 0))
            res.push_back(num + '0');
    
    return res;
}

int main(void) {
    cout << multiply("123", "456") << endl;

    return (0);
}
