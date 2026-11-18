class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int cnt = 0;

        int i = 0 , j = 1;
        while(j < n && i < n){
            if(s[i] != s[j]){
                cnt++;
            }
            i += 2;
            j += 2;
        }
        return cnt;
    }
};