#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int days[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
      
        auto getDay = [&](string s) {
            int m = (s[0] - '0') * 10 + (s[1] - '0'); 
            int d = (s[3] - '0') * 10 + (s[4] - '0');
            return days[m - 1] + d;
        };
        
       
        int start = max(getDay(arriveAlice), getDay(arriveBob));
        int end = min(getDay(leaveAlice), getDay(leaveBob));
        
        return max(0, end - start + 1);
    }
};