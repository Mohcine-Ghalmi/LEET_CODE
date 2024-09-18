bool isValid(string s) {
    stack<char> bracketStack;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[')
            bracketStack.push(c);
        else if (c == ')' && !bracketStack.empty() && bracketStack.top() == '(')
            bracketStack.pop();
        else if (c == '}' && !bracketStack.empty() && bracketStack.top() == '{')
            bracketStack.pop();
        else if (c == ']' && !bracketStack.empty() && bracketStack.top() == '[')
            bracketStack.pop();
        else
            return false;
        }
    return bracketStack.empty();
}
