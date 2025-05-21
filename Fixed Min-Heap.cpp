#include <stdio.h>

int minHeap[100];
int dataCount = 0;

int getParentIndex(int index) {
    return (index - 1) / 2;
}

int getLeftIndex(int index) {
    return 2 * index + 1;
}

int getRightIndex(int index) {
    return 2 * index + 2;
}

void viewHeap() {
    if (dataCount <= 0) {
        printf("Your Heap is Empty. Insert more data!\n\n");
    } else {
        for (int i = 0; i < dataCount; i++) {
            printf("Heap[%2d] = %d\n", i, minHeap[i]);
        }
        puts("");
    }
}

void swapValue(int parentIndex, int currIndex) {
    int temp = minHeap[parentIndex];
    minHeap[parentIndex] = minHeap[currIndex];
    minHeap[currIndex] = temp;
}

void HeapUp(int index) {
    if (index <= 0) return;

    int parentIndex = getParentIndex(index);

    if (minHeap[parentIndex] <= minHeap[index]) return;

    swapValue(parentIndex, index);

    HeapUp(parentIndex);
}

void HeapDown(int index) {
    if (index >= dataCount) return;

    int smallest = index;
    int leftIndex = getLeftIndex(index);
    int rightIndex = getRightIndex(index);

    if (leftIndex < dataCount && minHeap[leftIndex] < minHeap[smallest]) {
        smallest = leftIndex;
    }

    if (rightIndex < dataCount && minHeap[rightIndex] < minHeap[smallest]) {
        smallest = rightIndex;
    }

    if (smallest != index) {
        swapValue(index, smallest);
        HeapDown(smallest);
    }
}

void push(int input) {
    minHeap[dataCount] = input;
    HeapUp(dataCount);
    dataCount++;
}

int pop() {
    if (dataCount <= 0) {
        printf("Heap is empty!\n");
        return -1;
    }
    
    int removed = minHeap[0];
    swapValue(0, dataCount - 1);
    dataCount--;
    HeapDown(0);
    return removed;
}

void createMenu() {
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Exit\n");
}

int main() {
    int input = -1, num;
    do {
        printf("Current Heap:\n");
        viewHeap();
        createMenu();

        do {
            printf("Input your choice: ");
            scanf("%d", &input);
        } while (input < 1 || input > 3);

        switch (input) {
            case 1:
                printf("What data should be inserted into the heap? ");
                scanf("%d", &num);
                push(num);
                printf("%d has been inserted into the heap\n\n", num);
                break;
            case 2:
                if (dataCount <= 0) {
                    printf("Your heap is empty. Insert more data!\n\n");
                } else {
                    printf("%d has been deleted\n\n", pop());
                }
                break;
        }
    } while (input != 3);

    return 0;
}