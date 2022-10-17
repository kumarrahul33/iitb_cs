# Linear Queue
    Functions:
    1. size: returns the size of the queue
    2. isEmpty
    3. isFull
    4. grow: to implement this i copy the existing list to a new pointer which has approprite size assigned to it 
        then i point A pointer to that.
    5. Qinsert:

# Circular Queue
    Functions:
    1. size
    2. isEmpty: only N-1 elements are inserted in the queue so that we can differenciate when the queue is full and when it is empty. When the head and tail are at the same position then the queue is empty
    3. isFull: when tail and head are N-1 or 1 elements apart then the queue is full.
    4.Qinsert: we insert an element to in a circular fashion, meaning if the queue is full from the end we insert the element at the beginning.
    5.grow: to grow the size of the queue we copy the data to a temp pointer converting the circular queue to a linear queue and then pointing 
     