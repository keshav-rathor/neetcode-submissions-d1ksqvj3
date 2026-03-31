class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> a(26,0);
        vector<int> b(26,0);
        for(auto x:s) a[x-'a']++;
        for(auto x:t) b[x-'a']++;
        if(a==b) return true;
        return false;

    }
};
