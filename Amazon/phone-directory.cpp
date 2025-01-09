class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // Use a set to store unique contacts and then convert to vector for sorting
        set<string> contactSet(contact, contact + n);
        vector<string> contactList(contactSet.begin(), contactSet.end());

        vector<vector<string>> result;

        string prefix = "";
        for (char ch : s) {
            prefix += ch;
            vector<string> matches;

            // Find all contacts that match the current prefix
            for (const string &c : contactList) {
                if (c.find(prefix) == 0) { // If prefix matches
                    matches.push_back(c);
                }
            }

            if (matches.empty()) {
                matches.push_back("0");
            }

            result.push_back(matches);
        }

        return result;
    }
};