// 4061. Minimum Queen Moves to Reach Target
class Solution {
 public:
  int minQueenMoves(vector<int>& source, vector<int>& target) {
    if (source == target) {
      return 0;
    }
    if (source[0] == target[0] or source[1] == target[1]) {
      // same row /col
      return 1;
    }
    if (source[0] + source[1] == target[0] + target[1]) {
      // main diagnaol
      return 1;
    }
    if ((source[0] - source[1]) == (target[0] - target[1])) {
      // main diagnaol
      return 1;
    }
    return 2;
  }
};