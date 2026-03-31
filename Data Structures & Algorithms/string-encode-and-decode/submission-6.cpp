class Solution {
public:
    string encode(vector<string>& strs) {
        if (strs.empty()) return "$";
        string ans = "";
        for (auto& x : strs) {
            string temp = "";
            for (char y : x) {
                temp += (26 - (y - 'a' + 1)) + 'a';
            }
            ans += temp + "#";
        }
        ans.pop_back();
        return ans;
    }

    vector<string> decode(string s) {
        if (s == "$") return {};
        if(s=="") return {""};
        vector<string> ans;
        string temp = "";
        for (char x : s) {
            if (x == '#') {
                ans.push_back(temp);
                temp = "";
            } else {
                temp += (26 - (x - 'a' + 1)) + 'a';
            }
        }
        if (temp != "") ans.push_back(temp);
        return ans;
    }
};
