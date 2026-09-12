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


class MaxHeap {
  public:
    vector<int> heap;

    MaxHeap(vector<int> inputHeap){
      heap = inputHeap;
      makeMaxHeap();
    }

    // Outputs each element of the heap (for debugging)
    void printHeap(){
      for (unsigned int i = 0; i < heap.size(); i++){
        cout << heap[i] << " ";
      }
      cout << endl;
    }

    // Returns the index of the parent
    int getParent(int index){
      return (index - 1) / 2;
    }

    // Returns the index of the left child
    int getLeftChild(int index){
      return index * 2 + 1;
    }

    // Returns the index of the right child
    int getRightChild(int index){
      return index * 2 + 2;
    }


    void maxHeapify(int index){
      unsigned int l = getLeftChild(index);
      unsigned int r = getRightChild(index);
      if (l >= heap.size()){
        return;
      }
      if (r >= heap.size()){
        if (heap[l] > heap[index]){
          int temp = heap[index];
          heap[index] = heap[l];
          heap[l] = temp;
        }
        return;
      }
      if (heap[l] > heap[r] && heap[l] > heap[index]){
        int temp = heap[index];
        heap[index] = heap[l];
        heap[l] = temp;
        maxHeapify(l);
      }
      if (heap[r] >= heap[l] && heap[r] > heap[index]){
        int temp = heap[index];
        heap[index] = heap[r];
        heap[r] = temp;
        maxHeapify(r);
      }
    }


    void makeMaxHeap(){
      unsigned int layers = log(heap.size()) / log(2);
      unsigned int lastParentIndex = binpow(2, layers) - 2;
      for (int i = lastParentIndex; i >= 0; i--){
        maxHeapify(i);
      }
    }

    // Don't use min heapify here as it worsens the complexity - it checks all the way down the tree but we know that structure is correct on insertion
    void insertElement(int element){
      heap.push_back(element);
      int i = heap.size() - 1;
      int parent;
      while (i>0){
        parent = getParent(i);
        if (element > heap[parent]){
          heap[i] = heap[parent];
          heap[parent] = element;
          i = parent;
        }
        else{
          return;
        }
      }
    }


    // Don't min heapify as worsens complexity (substructure is already solid)
    void deleteLargest(){
      int largest = heap[0];
      heap[0] = heap[heap.size() - 1];
      heap[heap.size() - 1] = largest;
      heap.pop_back();
      unsigned int i = 0;
      unsigned int leftChild = getLeftChild(i);
      unsigned int rightChild = getRightChild(i);
      while (leftChild < heap.size()){
        if (rightChild == heap.size()){
          if (heap[leftChild] > heap[i]){
            int temp = heap[i];
            heap[i] = heap[leftChild];
            heap[leftChild] = temp;
            i = leftChild;
          }
          i = leftChild;
        }
        else{
          if (heap[leftChild] > heap[i] && heap[leftChild] > heap[rightChild]){
            int temp = heap[i];
            heap[i] = heap[leftChild];
            heap[leftChild] = temp;
            i = leftChild;
          }
          else if (heap[rightChild] > heap[i] && heap[rightChild] >= heap[leftChild]){
            int temp = heap[i];
            heap[i] = heap[rightChild];
            heap[rightChild] = temp;
            i = rightChild;
          }
          else{
            return;
          }
        }
        leftChild = getLeftChild(i);
        rightChild = getRightChild(i);
      }
    }


};

class Solution {
  public:
    int lastStoneWeight(vector<int>& stones){
      MaxHeap maxHeap(stones);
      int largest;
      int secondLargest;
      int difference;
      while (maxHeap.heap.size() > 1){
        largest = maxHeap.heap[0];
        maxHeap.deleteLargest();
        secondLargest = maxHeap.heap[0];
        maxHeap.deleteLargest();
        if (largest == secondLargest){
          continue;
        }
        else{
          difference = largest - secondLargest;
          maxHeap.insertElement(difference);
        }
      }
      if (maxHeap.heap.size() == 0){
        return 0;
      }
      else{
        return maxHeap.heap[0];
      }
    }
};
