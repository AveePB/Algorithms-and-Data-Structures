class Solution {
public:

    bool canJump(vector<int>& nums) {
        int max_jump = nums[0] - 1;
        if(max_jump < 0 && nums.size() > 1)
            return false;
        for(int i=1; i<nums.size()-1; i++){
            if(nums[i] == 0 && max_jump <= 0){
                return false;
            }
            max_jump = max(max_jump, nums[i]) - 1;
        }
        return true;
    }
};
