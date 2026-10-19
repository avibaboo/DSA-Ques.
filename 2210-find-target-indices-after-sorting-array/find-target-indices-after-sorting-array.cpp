class Solution {
public:
    vector<int> targetIndices(vector<int>& a, int target) {
        int n = a.size();
        int cntsmall = 0;
        int cntequal = 0;

        for(int i=0;i<n;i++){
            if(a[i] < target){
                cntsmall++;
            }else if(a[i] == target){
                cntequal++;
            }
        }
        vector<int>ans;
        int i = cntsmall;
        while(cntequal--){
            ans.push_back(i);
            i++;
        }

        return ans;

    }
};