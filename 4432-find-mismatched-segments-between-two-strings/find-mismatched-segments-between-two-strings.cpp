class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int n = s1.size();

        vector<vector<string>>ans;
        int i = 0 , j = 0;
        while(i < n && j < n){
            string sub1 = "";
            string sub2 = "";

            if(s1[i] == s2[j]){
                i++ , j++;
            }else{
                while(i < n && j < n && s1[i] != s2[j]){
                    sub1 += s1[i];
                    sub2 += s2[j];
                    i++ , j++;
                }
                ans.push_back({sub1 , sub2});
            }
        }
        return ans;
    }
};