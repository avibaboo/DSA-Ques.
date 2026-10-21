class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        
        char mn_char = *min_element(s.begin(),s.end());
        char mx_char = *max_element(s.begin(),s.end());
        if(is_sorted(s.begin(),s.end())){
            return 0;
        }
        if(n == 2){
            return -1;
        }

        if(s[0] == mn_char || s[n-1] == mx_char){
            return 1;
        }

        char mn_mid = s[1] , mx_mid = s[n-2];
        for(int i=1;i<n-1;i++){
            mn_mid = min(mn_mid , s[i]);
            mx_mid = max(mx_mid , s[i]);
        } 
        
        

        if(s[0] > mx_mid && mn_mid > s[n-1]){
            return 3;
        }else
        return 2;

        return -1;
    }
};