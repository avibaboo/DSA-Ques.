class Solution {
public:
    int sumCounts(vector<int>& a) {
        int n = a.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            set<int> st;
            for (int j = i; j < n; j++) {
                st.insert(a[j]);
                sum += st.size()*st.size();
            }
        }
        return sum;
    }
};