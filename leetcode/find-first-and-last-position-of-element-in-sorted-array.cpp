class Solution {
public:
    int lowerBound(vector<int>& v, int t){
        int l=0, r=v.size();
        while (r-l > 1){
            int mid = (l+r)/2;
            
            if(v[mid] == t && v[mid-1] == t)
                r = mid;
            else if(v[mid] > t)
                r = mid;
            else
                l = mid;
        }
        return l;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 1)
            if(nums[0] == target)
                return {0, 0};
            else
                return {-1, -1};
        
        if(nums.size() == 0)
            return {-1, -1};
        
        int s = lowerBound(nums, target);
        int e = lowerBound(nums, target+1);

        if(nums[e] != target)
            e = max(e-1, 0);

        if(nums[s] != nums[e] || nums[s] != target)
            return {-1, -1};
        
        return {s, e};
    }
};
