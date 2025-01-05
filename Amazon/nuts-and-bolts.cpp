class Solution {
  public:
    static int getPriority(char c)
    {
        if(c == '!')    return 1;
        if(c == '#')    return 2;
        if(c == '$')    return 3;
        if(c == '%')    return 4;
        if(c == '&')    return 5;
        if(c == '*')    return 6;
        if(c == '?')    return 7;
        if(c == '@')    return 8;
        if(c == '^')    return 9;
    }
    
    static bool mycmp(char a, char b)
    {
        return getPriority(a) < getPriority(b);
    }
    void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
        sort(nuts, nuts+n, mycmp);
        sort(bolts, bolts+n, mycmp);
    }
};