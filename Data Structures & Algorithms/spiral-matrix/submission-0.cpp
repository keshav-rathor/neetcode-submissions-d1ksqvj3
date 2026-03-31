class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& nums) {
        int top=0;
        int bottom=nums.size()-1;
        int left=0;
        int right=nums[0].size()-1;
        int dir=0;
        vector<int> ans;
        while(top<=bottom && left<=right)
        {
            if(dir==0)
            {
                for(int i=left;i<=right;i++)
                {
                    ans.push_back(nums[top][i]);
                }
                top++;
            }
            else if(dir==1)
            {
                for(int i=top;i<=bottom;i++)
                {
                    ans.push_back(nums[i][right]);
                }
                right--;
            }
            else if(dir==2)
            {
                for(int i=right;i>=left;i--)
                {
                    ans.push_back(nums[bottom][i]);
                }
                bottom--;
            }
            else if(dir==3)
            {
                for(int i=bottom;i>=top;i--)
                {
                    ans.push_back(nums[i][left]);
                }
                left++;
            }
            dir=(dir+1)%4;
        }
        return ans;
    }
};



