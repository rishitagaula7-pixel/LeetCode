class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;
        
        int word_len = words[0].size();
        int num_words = words.size();
        int total_len = word_len * num_words;
        if (s.size() < total_len) return result;
        
        unordered_map<string, int> word_count;
        for (auto &word : words) word_count[word]++;
        
        // Loop for each possible starting offset within word_len
        for (int i = 0; i < word_len; i++) {
            int left = i, count = 0;
            unordered_map<string, int> seen;
            
            for (int j = i; j + word_len <= s.size(); j += word_len) {
                string word = s.substr(j, word_len);
                if (word_count.count(word)) {
                    seen[word]++;
                    count++;
                    
                    // If word occurs more than expected, move left pointer
                    while (seen[word] > word_count[word]) {
                        string left_word = s.substr(left, word_len);
                        seen[left_word]--;
                        left += word_len;
                        count--;
                    }
                    
                    if (count == num_words) {
                        result.push_back(left);
                        // Move left to continue searching
                        string left_word = s.substr(left, word_len);
                        seen[left_word]--;
                        left += word_len;
                        count--;
                    }
                } else {
                    // Reset if word not in words
                    seen.clear();
                    count = 0;
                    left = j + word_len;
                }
            }
        }
        
        return result;
    }
};
