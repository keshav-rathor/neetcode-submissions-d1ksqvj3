class Solution {
    public boolean hasDuplicate(int[] nums) {
        // int n=nums.size();
        Map<Integer, Integer> hashMap = new HashMap<>();

        for(int x:nums)
        {
            if(hashMap.containsKey(x))
            {
                return true;
            }
            hashMap.put(x, 1); 

        }
        return false;
 
    }
}
