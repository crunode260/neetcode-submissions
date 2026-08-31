class Solution {
public:
bool isAnagram(string s, string t) {
    if (s.length() != t.length()){
        return false;
    }
    int shash[26];
    for (long unsigned int i = 0; i < 26; i++){
        shash[i] = 0;
    }
    for (long unsigned int i = 0; i < s.length(); i++){
        int k = (int) s[i];
        k -= 97;
        shash[k]++;
    }
    int thash[26];
    for (long unsigned int i = 0; i < 26; i++){
        thash[i] = 0;
    }
    for (long unsigned int i = 0; i < t.length(); i++){
        int k = (int) t[i];
        k -= 97;
        thash[k]++;
    }
    for (int i = 0; i < 26; i++){
      if (shash[i] != thash[i]){
          return false;
      }
    }
    return true;

}
};