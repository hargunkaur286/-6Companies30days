class Solution {
public:
    string getHint(string secret, string guess) {
        int aCnt = 0; // Count of bulls (correct digit in the correct position)
        int bCnt = 0; // Count of cows (correct digit in the wrong position)
        
        // Vectors to count occurrences of digits in secret and guess
        vector<int> sVec(10, 0); // Counts for digits in the secret
        vector<int> gVec(10, 0); // Counts for digits in the guess
        
        // Edge case: If sizes are unequal or secret is empty, return "0A0B"
        if (secret.size() != guess.size() || secret.empty()) { 
            return "0A0B"; 
        }
        
        // First pass: Identify bulls and count unmatched digits
        for (int i = 0; i < secret.size(); ++i) {
            char c1 = secret[i]; // Current character from secret
            char c2 = guess[i];  // Current character from guess
            
            if (c1 == c2) {
                // If the characters match, it's a bull
                ++aCnt; 
            } else {
                // Otherwise, count unmatched digits in secret and guess
                ++sVec[c1 - '0'];
                ++gVec[c2 - '0'];
            }
        }
        
        // Second pass: Calculate cows by comparing unmatched digits
        for (int i = 0; i < sVec.size(); ++i) {
            // The number of cows for each digit is the minimum of its occurrences
            // in secret and guess
            bCnt += min(sVec[i], gVec[i]);
        }
        
        // Construct the result string in the format "xAyB"
        return to_string(aCnt) + 'A' + to_string(bCnt) + 'B';
    }
};

//link -> https://leetcode.com/problems/bulls-and-cows/submissions/1494326221/
