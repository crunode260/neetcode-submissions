class Solution {
public:
    bool isValid(string s){
    stack<char> openBrackets;
    char currentBracket;
    for (int i = 0; i < s.length(); i++){
        if (isOpenBracket(s[i])){
        openBrackets.push(s[i]);
        }
        else{
        if (openBrackets.empty()){
            return false;
        }
        currentBracket = openBrackets.top();
        openBrackets.pop();
        if (!isCorrectClose(currentBracket, s[i])){
            return false;
        }
        }
    }
    if (openBrackets.empty()){
        return true;
    }
    return false;
    }

    bool isCorrectClose(char o, char c){
    if ((o=='(' && c==')') || (o=='{' && c=='}') || (o=='[' && c==']')){
        return true;
    }
    return false;
    }

    bool isOpenBracket(char c){
    if (c=='(' || c=='{' || c=='['){
        return true;
    }
    return false;
}};
