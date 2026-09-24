class Solution {
public:
    int sdig(int num){
        int ans = 0;
        while(num){
            ans += (num % 10);
            num /= 10;
        }
        return ans;
    }
    int smallestIndex(vector<int>& a) {
        for(int i=0;i<a.size();i++){
            int x = a[i];
            if(sdig(x) == i){
                return i;
            }
        }
        return -1;
    }
};