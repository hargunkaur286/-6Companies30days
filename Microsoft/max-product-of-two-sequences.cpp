class Solution {
public:
    int result = 0;
    
    // Checks if a given string is a palindrome
    bool isPalin(string& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
    
    // Depth-first search to explore all ways of splitting characters into s1 and s2
    void dfs(string& s, int i, string& s1, string& s2) {
        if (i == s.size()) {
            if (isPalin(s1) && isPalin(s2)) {
                result = max(result, (int)s1.size() * (int)s2.size());
            }
            return;
        }
        
        // Option 1: Add s[i] to s1
        s1.push_back(s[i]);
        dfs(s, i + 1, s1, s2);
        s1.pop_back();
        
        // Option 2: Add s[i] to s2
        s2.push_back(s[i]);
        dfs(s, i + 1, s1, s2);
        s2.pop_back();
        
        // Option 3: Skip s[i]
        dfs(s, i + 1, s1, s2);
    }
    
    int maxProduct(string s) {
        string s1, s2;
        dfs(s, 0, s1, s2);
        return result;
    }
};
