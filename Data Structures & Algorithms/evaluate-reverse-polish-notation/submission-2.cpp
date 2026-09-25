class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    vector<string> operators = {"+", "*", "-", "/"};
    stack<int> numbers;
    int num1;
    int num2;
    for (unsigned int i = 0; i < tokens.size(); i++){
      if (find(operators.begin(), operators.end(), tokens[i]) != operators.end()){
        num2 = numbers.top();
        numbers.pop();
        num1 = numbers.top();
        numbers.pop();
        if (tokens[i] == "+"){
          numbers.push(num1 + num2);
        }
        else if (tokens[i] == "*"){
          numbers.push(num1 * num2);
        }
        else if (tokens[i] == "-"){
          numbers.push(num1 - num2);
        }
        else{
          numbers.push(num1 / num2);
        }
      }
      else{
        numbers.push(stoi(tokens[i]));
      }
    }
    return numbers.top();
  }
};
