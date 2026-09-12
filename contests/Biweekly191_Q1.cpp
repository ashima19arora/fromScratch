class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int count=0;
        int freq[101]{};        // freq[x]=freq of number x
        
        vector<int> occur[101]; // occur[x]-a vector containing list of indices
                                // where that number occured
        for (int i = 0; i < nums.size(); i++) {
            // i is the index
            // nums[i] is a number in nums array
            int x = nums[i];
            freq[x]++;
            occur[x].push_back(i);
        }
        for(int number=0;number<101;number++){
            if (freq[number]==3){
                //number appears exactly thrice
                vector<int> indices=occur[number];
                if(indices[1]-indices[0]==indices[2]-indices[1]){
                    count++;
                }
            }
        }
        return count;
    }
};