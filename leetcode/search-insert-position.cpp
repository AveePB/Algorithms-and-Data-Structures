class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        if(target <= nums[0])
            return 0;

        while(r-l > 1){
            int mid = (l+r)/2;
            if(nums[mid] >= target)
                r = mid;
            else 
                l = mid;
        }
        return r;
    }
};
