class Solution {
public:
    int minimumChairs(string s) {
        int current_chairs = 0;
        int max_chairs = 0;
        
        // Loop through each character in the event string
        for (char event : s) {
            if (event == 'E') {
                current_chairs++; // Person enters, takes a chair
            } else {
                current_chairs--; // Person leaves, frees a chair
            }
            
            // Keep track of the maximum chairs needed at any peak moment
            max_chairs = max(max_chairs, current_chairs);
        }
        
        return max_chairs;
    }
};
