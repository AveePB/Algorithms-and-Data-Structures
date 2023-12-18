class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int global_sum = nums[0];
        int local_sum = nums[0];

        for(int i=1; i<nums.size(); i++){
            local_sum = max(local_sum+nums[i], nums[i]);
            if(global_sum < local_sum)
                global_sum = local_sum;
        }
        return global_sum;
    }
};
