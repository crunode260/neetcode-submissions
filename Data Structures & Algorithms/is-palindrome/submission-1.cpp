class Solution {
public:
    bool isPalindrome(string s) {
        string newS;
        newS = stripString(s);
        int start = 0;
        int end = newS.length() - 1;
        while (start < end){
            if (newS[start] != newS[end]){
                return false;
            }
            start +=1;
            end -=1;
        }
        return true;

    }
    string stripString(string s){
    string newS = "";
    for (int i = 0; i < s.length(); i++){
        if (isalnum(s[i])){
            newS += char(tolower(s[i]));
        }
    }
    return newS;
}
};
