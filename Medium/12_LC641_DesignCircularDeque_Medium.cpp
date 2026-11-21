class MyCircularDeque {
private:
    int* arr;
    int front;
    int rear;
    int size;
    int count;
public:

    MyCircularDeque(int k) {
        arr = new int[k];
        size = k;
        front = 0;
        rear = -1;
        count = 0;
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        front = (front - 1 + size) % size;
        arr[front] = value;

        if(count == 0){
            rear = front;
        }

        count++;
        return true;
        }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        rear = (rear + 1) % size;
        arr[rear] = value;

        if(count == 0){
            front = rear;
        }
        count++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()){
            return false;
        }
        front = (front + 1) % size;
        count--;

        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        rear = (rear - 1 + size) % size;
        count--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()){
            return -1;
        }

        return arr[front];
    }
    
    int getRear() {
        if (isEmpty()){
            return -1;
        }

        return arr[rear];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
    }
};