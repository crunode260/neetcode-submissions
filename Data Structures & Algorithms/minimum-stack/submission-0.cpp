class MinStack {
public:
  vector<int> stack;
  vector<int> minS;
  MinStack() {
    stack = {};
    minS = {};
  }
  
  void push(int val) {
    stack.push_back(val);
    if (minS.size() > 0){
      minS.push_back(min(minS[minS.size() - 1], val));
    }
    else{
      minS.push_back(val);
    }
  }
  
  void pop() {
    stack.pop_back();
    minS.pop_back();
  }
  
  int top() {
      return stack[stack.size() - 1];
  }
  
  int getMin() {
      return minS[stack.size() - 1];
  }
};
