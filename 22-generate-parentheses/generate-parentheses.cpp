class Solution {
public:
    vector<string>result;
    // bool isValid(string &curr){
    //     int cnt = 0;
    //     for(int i=0;i<curr.size();i++){
    //         if(curr[i] == '(') cnt++;
    //         else{
    //             cnt--;
    //             if(cnt < 0) return false;
    //         }
    //     }
    //     if(cnt == 0) return true;
    //     return false;
    //}
    void solve(string curr , int n,int open , int close){
        if(curr.length() == 2*n){
            result.push_back(curr);
            return;
        }
        if(open < n){
        curr.push_back('(');
        solve(curr , n , open+1 , close);
        curr.pop_back();
        }

        if(close < open){
        curr.push_back(')');
        solve(curr, n , open , close+1);
        curr.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(curr , n,0,0);
        return result;
    }
};