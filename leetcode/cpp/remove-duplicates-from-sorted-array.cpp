class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        for(auto a: nums) st.insert(a);
        nums.clear();

        for(auto a: st) nums.push_back(a);
        return st.size();
    }
};
