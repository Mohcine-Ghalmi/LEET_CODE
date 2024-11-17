string countAndSay(int n) {
    if (n == 1)
        return "1";

    string prevSequence = countAndSay(n - 1);
    string nextSequence = "";
    int count = 1;

    for (int i = 1; i < prevSequence.length(); i++)
        if (i < prevSequence.length() && prevSequence[i] == prevSequence[i - 1])
            count = count + 1;
        else {
            nextSequence += to_string(count) + prevSequence[i - 1];
            count = 1;
        }
    nextSequence += to_string(count) + prevSequence[prevSequence.length() - 1];
    return nextSequence;
}
