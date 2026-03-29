class DynamicArray {

int * test;
int size;
int capacity;

public:

DynamicArray(int capacity) : capacity(capacity), size(0) {
        test = new int[capacity];
    }

    int get(int i) {
        return test[i];
    }

    void set(int i, int n) {
        test[i] = n;
    }

    void pushback(int n) {
        if(size == capacity)
        {
            resize();
        }
        test[size] = n;
        size++;
    }

    int popback() {
        if(size > 0)
        {
            size--;
        }
        return test[size];
    }

    void resize() {
        capacity *= 2;
        int * newArray = new int[capacity];
        for(int i = 0; i < size; i++)
        {
            newArray[i] = test[i];
        }
        delete[] test;
        test = newArray;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
