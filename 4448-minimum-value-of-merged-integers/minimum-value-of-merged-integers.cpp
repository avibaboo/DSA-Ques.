class Solution {
public:
    int minMergedInteger(vector<int>& a) {
        int n = a.size();
        int i = 0 , j = 1;
        string ch = "1000000001";
        while(j < n){
            string ans = "";
            ans += to_string(a[i]);
            ans += to_string(a[j]);
            if(stoi(ans) < stoi(ch)){
                ch = ans;
            }
            i+=2;
            j+=2;
        }
        return stoi(ch);
    }
};