class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long max_sum = 0;
        unordered_map<int, int> freq_map;
        int left = 0;
        long long cur_sum = 0;

        for (int right = 0; right < nums.size(); ++right) {
            freq_map[nums[right]]++;
            cur_sum += nums[right];

            while (freq_map[nums[right]] > 1) {
                freq_map[nums[left]]--;
                cur_sum -= nums[left];
                left++;
            }

            if (right - left + 1 == k) {
                max_sum = max(max_sum, cur_sum);
                cur_sum -= nums[left];
                freq_map[nums[left]]--;
                left++;
            }
        }
        return max_sum;
    }
};