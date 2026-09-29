// Rearrange Array by Removing Distinct Values
class Solution {
 public:
  vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> ans;  // empty initially
    // build freq array for nums
    int n = nums.size();
    int freq[101]{0};  // 1 <= nums[i] <= 100
    for (int i = 0; i < n; i++) {
      int number = nums[i];
      freq[number]++;
    }
    int maxRounds = 0;
    for (int x : freq) {
      maxRounds = max(maxRounds, x);
    }
    vector<int> smallans;
    for (int i = 0; i < maxRounds; i++) {
      // check which numbers freq>0
      for (int i = 0; i < 101; i++) {
        if (freq[i] > 0) {
          smallans.push_back(i);
          freq[i]--;
        }
      }
      sort(smallans.begin(), smallans.end());
      for (int x : smallans) {
        ans.push_back(x);
      }
      smallans.clear();
    }
    return ans;
  }
};