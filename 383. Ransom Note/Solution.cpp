class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int j = 0;
        for (int i = 0; i < ransomNote.length(); i++)
            for (int k = 0; k < magazine.length(); k++)
                if (ransomNote[i] == magazine[k]) {
                    magazine.erase(k, 1);
                    j++;
                    break;
                }
        if (j == ransomNote.length())
            return (true);
        return (false);
    }
};
