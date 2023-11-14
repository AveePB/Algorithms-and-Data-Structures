class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    int[] sum = new int[2];

    void kSum(int[] arr, int start, long tar, int k) {
        if(k < 2) {
            for(int i=start; i<arr.length-k; i++) {
                if(i > start && arr[i-1] == arr[i]) continue;
                this.sum[k] = arr[i];
                kSum(arr, i+1, tar-(long)arr[i], k+1);
            }
            return;
        }

        int l = start, r = arr.length-1;

        while (l < r) {
            if((long)arr[l] + (long)arr[r] < tar) {
                l++;
            }
            else if((long)arr[l] + (long)arr[r] > tar) {
                r--;
            }
            else {
                this.ans.add(Arrays.asList(this.sum[0], this.sum[1], arr[l], arr[r]));
                l++;
                while (l < r && arr[l-1] == arr[l]) l++;
            }
        }
    }

    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums);
        kSum(nums, 0, target, 0);
        return this.ans;
    }
}
