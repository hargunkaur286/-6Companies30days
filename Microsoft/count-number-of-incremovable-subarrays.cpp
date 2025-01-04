class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = (int)nums.size();
        
        if (n == 0) return 0;  
        vector<bool> incStart(n, false), incEnd(n, false);
        incStart[0] = true;
        for (int i = 1; i < n; i++) {
            incStart[i] = incStart[i-1] && (nums[i] > nums[i-1]);
        }
        incEnd[n-1] = true;
        for (int i = n-2; i >= 0; i--) {
            incEnd[i] = incEnd[i+1] && (nums[i] < nums[i+1]);
        }

        //    validL[l], validR[r]
        //    validL[l] => [0..l-1] is strictly inc if l=0 or incStart[l-1] is true
        //    validR[r] => [r+1..n-1] is strictly inc if r=n-1 or incEnd[r+1] is true
        auto validL = [&](int l) {
            return (l == 0) || incStart[l-1];
        };
        auto validR = [&](int r) {
            return (r == n-1) || incEnd[r+1];
        };

        //   Count subarrays in the "easy" boundary cases
        //    (A) l=0, remove [0..r]
        //    (B) r=n-1, remove [l..n-1]
        int countA = 0, countB = 0; 
        for (int r = 0; r < n; r++) {
            if (validR(r)) countA++;
        }
        for (int l = 0; l < n; l++) {
            if (validL(l)) countB++;
        }
        // subtract 1 if (0, n-1) is double-counted (it always is)
        long long countBasic = (long long)countA + (long long)countB - 1;

        //    Count subarrays strictly inside: l>0, r<n-1, with l <= r
        //    plus the boundary condition nums[l-1] < nums[r+1]
        vector<int> Lprime, Rprime;
        for (int l = 1; l < n-1; l++) {
            if (validL(l)) Lprime.push_back(l);
        }
        for (int r = 1; r < n-1; r++) {
            if (validR(r)) Rprime.push_back(r);
        }

        long long countInside = 0;
        // O(|L'| * |R'|) naive approach
        for (int l: Lprime) {
            for (int r: Rprime) {
                if (l <= r && nums[l-1] < nums[r+1]) {
                    countInside++;
                }
            }
        }

        //  Final answer
        long long ans = countBasic + countInside;
        return (int)ans;  // problem states "Return the total number", presumably fits in int
    }
};
