class Solution {
public:
    int searchInsert(vector<int>& a, int target) {
        int n = a.size();
        int st = 0 , end = n-1;
        bool ok = true;
        while(st <= end){
            int mid = st + (end - st)/2;

            if(a[mid] == target){
                ok = true;
                return mid;
            }else if(a[mid] < target){
                ok = false;
                st = mid + 1;
            }else{
                ok = false;
                end = mid  - 1;
            }
        }
        // int idx = -1;
        // if(!ok){
        //     for(int i=0;i<n;i++){
        //         if(a[i] < target){
        //             continue;
        //         }else{
        //             idx = i;
        //             break;
        //         }
        //     }
        //     if(target > a[n-1]){
        //         idx = n;
        //     }
        // }
        return st;
    }
};