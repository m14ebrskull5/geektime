class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        head=0,tail=0,count=0,capacity=k;
        vec = new int[k];
    }
  
   bool insertFront(int value) {
        if(isFull())return false;
        head=index(-1);
        vec[head]=value;
        count++;
        return true;
    }
    bool insertLast(int value) {
        if(isFull())return false;
        vec[tail]=value;
        tail=index(tail-head+1);
        count++;
        return true;
    }
     bool deleteFront() {
        if(isEmpty())return false;
        head=index(1);
        count--;
        return true;
    }
    bool deleteLast() {
        if(isEmpty())return false;
        tail=index(tail-head -1);
        count--;
        return true;
    }
    int getFront() {
        if(isEmpty())return -1;
        return vec[head];
    }
    int getRear() {
        if(isEmpty())return -1;
        return vec[index(tail-head-1)];
    }
    bool isEmpty() {
        return count==0;
    }   
    bool isFull() {
        return count==capacity;
    }
private:
    int *vec;
    int head;
    int tail;
    int count;
    int capacity;
    int index(int target) {
        return (head+capacity+target)%capacity;
    }
};