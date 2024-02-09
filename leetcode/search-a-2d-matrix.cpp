class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int mid, l, r;

        l = 0, r = matrix.size();
        while (r-l > 1){
            mid = (l+r) / 2;
            if(matrix[mid][0] == target && matrix[mid-1][0] == target)
                r = mid;
            else if(matrix[mid][0] > target)
                r = mid;
            else
                l = mid;
        }
        int row = l;

        l = 0, r = matrix[row].size();
        while (r-l > 1){
            mid = (l+r) / 2;
            if(matrix[row][mid] == target && matrix[row][mid-1] == target)
                r = mid;
            else if(matrix[row][mid] > target)
                r = mid;
            else
                l = mid;
        }

        return (matrix[row][l] == target);
    }
};
