def min_heap(heap,value):
    heap.append(value)
    index = len(heap)-1
    while index > 0 and heap[(index-1) // 2] > heap[index]:
        heap[index],heap[(index-1) // 2]=heap[(index-1) // 2],heap[index]
        index =(index-1) // 2

heap=[]
array=[10,7,11,5,4,13]
for value in array:
    min_heap(heap,value)
    print(f"inserted {value} into min heap {heap}")


