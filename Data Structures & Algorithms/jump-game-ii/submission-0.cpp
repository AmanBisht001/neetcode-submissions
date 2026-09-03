class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        if (n <= 1) return 0;

        int count = 0;
        int i = 0;
        int maxi = 0;

        while (maxi < n - 1) {
            int end = maxi;
            int farthest = maxi;

            for (int j = i; j <= end; j++) {
                farthest = max(farthest, j + nums[j]);
            }

            i = end + 1;
            maxi = farthest;
            count++;
        }

        return count;
    }
};