class Solution {
public:
    vector<vector<int>> ans;
    vector<int> nums;
    set<int> st;

    void dfs(vector<int>& v, int idx, int pos){
        if(pos == nums.size()){
            ans.push_back(v);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(st.find(nums[i]) != st.end())
                continue;

            v[pos] = nums[i];
            st.insert(nums[i]);
            
            dfs(v, i+1, pos+1);
            st.erase(nums[i]);
        }
    }


    vector<vector<int>> permute(vector<int>& v) {
        vector<int> g = v;
        this->nums = v;
        dfs(g, 0, 0);
        return ans;
    }
};
