class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        for (int i = 0; i < ransomNote.length(); i++)
            if (ransomNote[i] != magazine[i])
                return (false);
        return (true);
    }
};