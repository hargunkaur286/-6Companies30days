class Solution {
public:
    map<vector<int>, int> mp;
    int solve(vector<int>& price, vector<vector<int>>& special, vector<int> needs){
        int n = price.size();
        int cost = INT_MAX;
        
        // We'll store a copy of the current needs to modify later
        vector<int> v = needs;

        // If we've already computed the cost for this exact 'needs' configuration, return it
        if(mp.find(needs) != mp.end()) {
            return mp[needs];
        }

        // Try each special bundle
        for(int i = 0; i < (int)special.size(); i++){
            bool canUseOffer = true;
            int regularPriceSum = 0;
            
            // Calculate the regular price (without special) for the current "needs"
            // and check if the special offer can be applied
            for(int j = 0; j < n; j++){
                // If the offer requires more items than we currently need, we can't use this bundle
                if(special[i][j] > needs[j]) {
                    canUseOffer = false;
                }
                // Summation of what it would cost to buy all needed items at regular price
                regularPriceSum += (price[j] * needs[j]);
            }

            // If we can use this offer AND the special offer price is cheaper
            // than buying those items at the regular price, consider using it
            if(canUseOffer && regularPriceSum > special[i][n]){
                // Subtract the bundle items from our needs
                for(int j = 0; j < n; j++){
                    v[j] = needs[j] - special[i][j];
                }
                // Recur with the updated needs, adding the cost of this bundle
                cost = min(cost, special[i][n] + solve(price, special, v));
            }
        }

        // If cost is still INT_MAX, it means no bundle could be applied beneficially.
        // So, just calculate cost by buying everything at the regular price.
        if(cost == INT_MAX){
            cost = 0;
            for(int i = 0; i < n; i++){
                cost += price[i] * needs[i];
            }
            // This print statement likely serves debugging purposes (would typically be removed or disabled)
            cout << cost << endl;
        }

        // Store the computed cost in our memoization map before returning
        return mp[needs] = cost;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        // Calculate the cost if we buy everything at regular price (no bundles)
        int cost = 0;
        int n = price.size();
        for(int i = 0; i < n; i++){
            cost += (price[i] * needs[i]);
        }

        // Compare that cost with the cost that tries to use special offers
        cost = min(cost, solve(price, special, needs));
        return cost;
    }
};
