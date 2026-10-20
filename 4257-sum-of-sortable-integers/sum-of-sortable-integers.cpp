class Solution {
public:
    vector<int> lps(vector<int>& a) {
        int n = a.size();
        vector<int> p(n, 0);

        for (int i = 1, j = 0; i < n; i++) {
            while (j > 0 && a[i] != a[j])
                j = p[j - 1];

            if (a[i] == a[j])
                j++;

            p[i] = j;
        }

        return p;
    }
    bool required(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        if (n != m) {
            return false;
        }

        vector<int> c = b;
        c.insert(c.end(), b.begin(), b.end());

        vector<int> p = lps(a);

        for (int i = 0, j = 0; i < 2 * m - 1; i++) {
            while (j > 0 && c[i] != a[j]) {
                j = p[j - 1];
            }

            if (c[i] == a[j]) {
                j++;
            }

            if (j == n) {
                return true;
            }
        }

        return false;
    }

    int sortableIntegers(vector<int>& a) {
        int n = a.size();

        vector<int> sorted = a;
        sort(begin(sorted), end(sorted));

        int result = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;
            bool ok = true;

            for (int st = 0; st < n; st += k) {
                vector<int> vec1(a.begin() + st, a.begin() + st + k);
                vector<int> vec2(sorted.begin() + st, sorted.begin() + st + k);
                if (!required(vec1, vec2)) {
                    ok = false;
                    break;
                }
            }
            if (ok)
                result += k;
        }
        return result;
    }
};