class Solution {
public:
    int jump(vector<int>& nums) {
        int max_global_jump = nums[0];
        int max_local_jump = nums[0];
        int j = 1;

        if(nums.size() == 1){
            return 0;
        }

        if(max_local_jump >= nums.size()-1){
                return 1;
        }

        for(int i=1; i<nums.size()-1; i++){
            max_local_jump = max(max_local_jump, i+nums[i]);

            if(max_local_jump >= nums.size()-1){
                return j+1;
            }


            if(i == max_global_jump){
                max_global_jump = max_local_jump;
                j++;
            }

        }
        return j;
    }
};
