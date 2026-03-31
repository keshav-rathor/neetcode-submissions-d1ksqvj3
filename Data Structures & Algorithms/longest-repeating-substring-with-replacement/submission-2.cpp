class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> map; 
        int maxFreq = 0; 
        int ans = 0; 
        int i = 0;

        for (int j = 0; j < s.size(); ++j) 
        {
            map[s[j]]++; 
            maxFreq = max(maxFreq, map[s[j]]); 

            while ((j - i + 1) - maxFreq > k) 
            {
                map[s[i]]--; 
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};
