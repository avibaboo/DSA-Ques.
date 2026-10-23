class Solution {
public:
    int sortPermutation(vector<int>& a) {
        int k = -1;
        for(int i=0;i<a.size();i++){
            if(a[i] != i)
            k &= a[i];
            if(k == 0) return 0;
        }

        return max(k , 0);
    }
};