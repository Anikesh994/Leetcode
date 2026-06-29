#include <string>

class Solution {
public:
    int repeatedStringMatch(std::string a, std::string b) {
        std::string repeatA = a;
        int count = 1;
        if(a.find(b)!=-1) return 1;
        while (repeatA.length() < b.length()) {
            repeatA += a;
            count++;
            if (repeatA.find(b) != std::string::npos) return count;
        }

       
        repeatA += a;
        count++;
        if (repeatA.find(b) != std::string::npos) return count;

        return -1;
    }
};