class Solution {
public:
    int minRange(int a, int b, int c) {
        vector<int>v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(),v.end());
        int ans = v[2]-v[0];
        int l = v[0] + v[1];
        if(l <= v[2]){
            ans = l - v[0];
        }
        return ans;
    }
};