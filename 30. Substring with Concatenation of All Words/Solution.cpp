
std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
    std::vector<int> result;
    if (words.empty() || s.empty()) return result;

    int word_length = words[0].size();
    int word_count = words.size();
    int target_length = word_length * word_count;

    if (s.size() < target_length) return result;

    std::unordered_map<std::string, int> word_map;
    for (const auto& word : words) 
        word_map[word]++;
    
    for (int i = 0; i < word_length; ++i) {
        int left = i, count = 0;
        std::unordered_map<std::string, int> seen_words;

        for (int j = i; j + word_length <= s.size(); j += word_length) {
            std::string word = s.substr(j, word_length);

            if (word_map.find(word) != word_map.end()) {
                seen_words[word]++;
                count++;

                while (seen_words[word] > word_map[word]) {
                    std::string left_word = s.substr(left, word_length);
                    seen_words[left_word]--;
                    left += word_length;
                    count--;
                }

                if (count == word_count)
                    result.push_back(left);
            } else {
                seen_words.clear();
                count = 0;
                left = j + word_length;
            }
        }
    }
    return result;
}
