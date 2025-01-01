//link->https://leetcode.com/problems/russian-doll-envelopes/submissions/1494194723/
class Solution {
    // If the widths are equal, sort by height in descending order
    // Otherwise, sort by width in ascending order
    static bool comp(vector<int>& a , vector<int>& b) {
        if(a[0] == b[0]) {
            return a[1] > b[1]; // Sort by height in descending order if widths are the same
        }
        return a[0] < b[0]; // Sort by width in ascending order
    }
public:
    // Function to find the maximum number of envelopes that can be Russian-dolled
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Sort the envelopes using the custom comparator
        sort(envelopes.begin(), envelopes.end(), comp);

        // Vector to store the heights of the envelopes in the LIS sequence
        vector<int> ans;

        // Iterate through each envelope
        for(auto& e : envelopes) {
            // If `ans` is empty or the current height is greater than the last height in `ans`
            if(ans.size() == 0 || e[1] > ans.back()) {
                ans.push_back(e[1]); // Add the height to `ans`
            } else {
                // Find the first element in `ans` that is greater than or equal to `e[1]`
                int index = lower_bound(ans.begin(), ans.end(), e[1]) - ans.begin();
                ans[index] = e[1]; // Replace it with the current height
            }
        }
        // The size of `ans` gives the length of the Longest Increasing Subsequence (LIS)
        // This is the maximum number of envelopes that can be Russian-dolled
        return ans.size();
    }
};
