class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        // unordered_map<int,int> map;
        vector<vector<int>> ans;
        set<vector<int>> s;


        for(int i=0;i<n-2;i++)
        {
            // unordered_map<int,int> map;
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                int sum=nums[j]+nums[k];
                if(sum==-nums[i])
                {
                    s.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
                else if(sum<-nums[i])
                {
                    j++;
                }
                else if(sum>-nums[i])
                {
                    k--;
                }


            }
        }
        for(auto x:s) ans.push_back(x);
        return ans;
    }
};
