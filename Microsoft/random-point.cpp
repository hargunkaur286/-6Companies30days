class Solution {
public:
    vector<int> v;
    vector<vector<int>> rects;
    int area(vector<int>& r) {
        return (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
    }
    
    Solution(vector<vector<int>> rect) {
        rects = rect;
        int totalArea=0;
        for (auto r: rects) {
            totalArea+=area(r);
            v.push_back(totalArea);
        }
    }
    
    vector<int> pick() {
        // pick a random reactangle in rects
        int rnd = rand() % v.back();
        int idx = upper_bound(v.begin(), v.end(), rnd) - v.begin();
        
        // pick a random point in rects[idx]
        auto r = rects[idx];
        int x = rand() % (r[2] - r[0] + 1) + r[0];
        int y = rand() % (r[3] - r[1] + 1) + r[1];
        return { x, y };
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */