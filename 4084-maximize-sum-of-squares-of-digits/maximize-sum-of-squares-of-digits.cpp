
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int cnt = 0;
        int s = sum;

        while(s >= 9){
            cnt++;
            s -= 9;
        }

        int leftsum = cnt * 9;
        int rem = s;

        string ans1 = "";
        for(int i = 0; i < cnt; i++){
            ans1 += '9';
        }

        if(rem > 0) ans1 += to_string(rem);

        while(ans1.size() < num){
            ans1 += '0';
        }

        if(ans1.size() != num || sum > 9 * num) return "";

        return ans1;
    }
};
