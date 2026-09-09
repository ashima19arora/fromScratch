class Solution {
 public:
  bool chkifdivisable(string s, string t) {
    if ((s + t) == (t + s) && s.length() % t.length() == 0) {
      return true;
    }
    return false;
  }
  string gcdOfStrings(string str1, string str2) {
    if (str1 == str2) {
      return str1;
    }
    string a, b;
    if (str1.length() < str2.length()) {
      a = str1;
      b = str2;
    } else {
      a = str2;
      b = str1;
    }
    string gcd = "";
    for (int i = 1; i <= a.length(); i++) {
      if (chkifdivisable(a, a.substr(0, i)) &&
          chkifdivisable(b, a.substr(0, i))) {
        gcd = a.substr(0, i);
      }
    }
    return gcd;
  }
};