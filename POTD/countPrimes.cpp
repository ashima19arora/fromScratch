class Solution {
 public:
  int countPrimes(int n) {
    if (n <= 2) {
      return 0;
    }
    bool listofnum[n + 1];
    // sieve of Eratosthenes
    for (int i = 0; i <= n; i++) {
      listofnum[i] = 1;
    }  // o(n)
    // 1 means prime
    listofnum[0] = 0;
    listofnum[1] = 0;
    for (int i = 2; i <= sqrt(n); i++) {
      // mark multple of each prime as non prime
      // O(log log n)
      if (listofnum[i] == 1) {  // mark multiples only i itself is prime
        for (int j = i * i; j <= n; j += i) {
          listofnum[j] = 0;
          // 0 means it is non prime
        }
      }
    }
    // if u r here n>=3
    // then we must count 2 already
    //  ques says stictly less than n
    int count = 1;
    // even no except 2 are non prime
    for (int i = 3; i < n; i += 2) {
      if (listofnum[i] == 1) {
        count++;
      }
    }
    return count;
  }
};