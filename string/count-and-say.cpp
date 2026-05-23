class Solution {
public:
    string countAndSay(int n) {
        string result = "1";   // Base case

        for (int i = 1; i < n; i++) {
            string temp = "";
            int count = 1;

            for (int j = 1; j < result.length(); j++) {
                if (result[j] == result[j - 1]) {
                    count++;
                } else {
                    temp += to_string(count);
                    temp += result[j - 1];
                    count = 1;
                }
            }

            // Add the last group
            temp += to_string(count);
            temp += result.back();

            result = temp;
        }

        return result;
    }
};
