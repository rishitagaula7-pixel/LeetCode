#include <stack>
#include <utility>

class StockSpanner {
private:
    // Stack में {price, index} के जोड़े (pairs) स्टोर होंगे
    std::stack<std::pair<int, int>> st;
    int ind;

public:
    StockSpanner() {
        ind = -1; // शुरुआत में index को -1 पर सेट करें
        
        // Stack को पूरी तरह खाली (clear) करने के लिए
        while (!st.empty()) {
            st.pop();
        }
    }
    
    int next(int price) {
        ind = ind + 1; // हर नए दिन के लिए index को 1 बढ़ाएं
        
        // जब तक stack खाली न हो और top का price छोटा या बराबर हो, pop करें
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }
        
        // दूरी (span) की गणना करें: current_index - index_of_previous_greater
        int ans = ind - (st.empty() ? -1 : st.top().second);
        
        // आज का price और index stack में push करें
        st.push({price, ind});
        
        return ans; // calculated span वापस भेजें
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
