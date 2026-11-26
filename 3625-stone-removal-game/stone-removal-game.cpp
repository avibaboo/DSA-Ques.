class Solution {
public:
    bool canAliceWin(int n) {
        if(n < 10){
            return false;
        }
        int x = 10;
        int cnt = 1;
        n -= x;
        while(true){
            x--;
            if(n < x){
                if(cnt % 2 != 0)
                return true;
                else
                return false;
            }
            n -= x;
            cnt++;
        }
        return true;
    }
};