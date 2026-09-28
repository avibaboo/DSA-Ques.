class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int Max_depth = 0;
        int curr = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                curr++;
                if(Max_depth < curr){
                    Max_depth = curr;
                }
            }
            else if(s[i] == ')'){
                curr--;
            }
        }
        return Max_depth;
    }
};