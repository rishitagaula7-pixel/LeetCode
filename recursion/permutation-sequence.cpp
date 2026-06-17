class Solution {
public:
    string getPermutation(int n, int k) {\
    int fact=1;
    vector<int>numbers;
    for(int i=1;i<n;i++){
        fact=fact*i;
        numbers.push_back(i);
    }
    numbers.push_back(n);
    string ans="";
    k=k-1;
    while(true){
         int index = k / fact;
            ans += to_string(numbers[index]);
            
            // Remove the selected number so it cannot be used again
            numbers.erase(numbers.begin() + index);
            
            // If no numbers are left, we are done
            if (numbers.empty()) {
                break;
            }
            
            // Calculate k and the factorial size for the next position
            k = k % fact;
            fact = fact / numbers.size();
        }
        
        return ans;
    
        
    }
};