class Solution {
public:
    int modifiedBinSearch(vector<int>& v, int t){
        int l=0, r=v.size()-1;
        while (l < r){
            int mid = (l+r)/2;
            if(v[mid] == t) return mid;
            if(v[l] == t) return l;
            if(v[r] == t) return r;
            
            if(v[mid] < v[r]){
                if(v[mid] < t && t < v[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else{
                if(t < v[mid] && v[l] < t)
                    r = mid -1;
                else
                    l = mid + 1;
            }
        }

        return -1;
    }
        

    int search(vector<int>& nums, int target) {
        if(nums.size() == 1)
            if(nums[0] == target)
                return 0;
        return modifiedBinSearch(nums, target);
    }
}; 
