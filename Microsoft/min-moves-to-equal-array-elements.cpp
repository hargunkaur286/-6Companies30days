//link -> https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/

//sort the array and then find the median
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // finding the size of the array
        int n = nums.size();
        int steps = 0;

        // sorting and finding median
        sort(nums.begin(), nums.end());
        int median = nums[n/2];

        for(int i = 0; i<n; i++){
            steps += abs(nums[i] - median);
        }
        return steps;
    }
};