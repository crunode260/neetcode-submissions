int binpow(int a, int n){
  int result = 1;

  while (n>0){
    if (n % 2 == 1){
      result *= a;
    }
    a*=2;
    n/=2;
  }
  return result;
}


class KthLargest {
  public:
    int index;
    vector<int> heap;


    KthLargest(int k, vector<int>& nums){
      index = k;
      int length = nums.size();
      if (length == 0){
        heap.push_back(-1001);
      }
      else if (length < k){
        heap = nums;
        heap.push_back(-1001);
      }
      else{
        sort(nums.begin(), nums.end());
        vector<int> lastK(&nums[length] - k, &nums[length]);
        heap = lastK;
      }
      makeMinHeap();
    }

    void minHeapify(int index){
      int l = getLeftChild(index);
      int r = getRightChild(index);
      int length = heap.size();
      if (l >= length){
        return;
      }
      if (r >= length){
        if (heap[l] < heap[index]){
          int temp = heap[index];
          heap[index] = heap[l];
          heap[l] = temp;
        }
        return;
      }
      if (heap[l] < heap[r] && heap[l] < heap[index]){
        int temp = heap[index];
        heap[index] = heap[l];
        heap[l] = temp;
        minHeapify(l);
      }
      if (heap[r] <= heap[l] && heap[r] < heap[index]){
        int temp = heap[index];
        heap[index] = heap[r];
        heap[r] = temp;
        minHeapify(r);
      }
    }


    void makeMinHeap(){
      int layers = log(heap.size()) / log(2);
      int lastParentIndex = binpow(2, layers) - 2;
      for (int i = lastParentIndex; i >= 0; i--){
        minHeapify(i);
      }
    }


    int getParent(int index){
      return (index - 1) / 2;
    }

    int getLeftChild(int index){
      return index * 2 + 1;
    }


    int getRightChild(int index){
      return index * 2 + 2;
    }

    int add(int val){
      for (int j = 0; j < index; j++){
        cout << heap[j] << ", ";
      }
      cout << endl;

      if (val <= heap[0]){
        return heap[0];
      }

      heap[0] = heap[index - 1];
      heap[index - 1] = val;
      int i = index - 1;
      while (i > 0){
        for (int j = 0; j < index; j++){
          cout << heap[j] << ", ";
        }
        cout << endl;
        i = getParent(i);
        minHeapify(i);
      }
      for (int j = 0; j < index; j++){
        cout << heap[j] << ", ";
      }
      cout << endl;
      return heap[0];

    }
};
