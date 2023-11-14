class Solution {
public:
    map<int, int> m;
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++)
            m[nums[i]] = i;

        for(int i=0; i<nums.size(); i++){
            int diff = target - nums[i];
            
            if(m.find(diff) != m.end() && m[diff] != i)
                    return {m[diff], i};
        }
        return {0, 0};
    }
};