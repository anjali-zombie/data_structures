def min_heap(heap,value):
    heap.append(value)
    index = len(heap)-1
    while index > 0 and heap[(index-1) // 2] > heap[index]:
        heap[index],heap[(index-1) // 2]=heap[(index-1) // 2],heap[index]
        index =(index-1) // 2

def deletion_min_heap(heap,value):
    index =-1
    for i in range(len(heap)):
        if heap[i] == value:
            index = i
            break
    if index == -1:
        return
    heap[index]=heap[-1]
    heap.pop()
    while True:
        left = 2*index+1
        right = 2*index+2
        smallest = index
        if left < len(heap) and heap[left] < heap[smallest]:
            smallest = left
        if right < len(heap) and heap[right] < heap[smallest]:
            smallest = right
        if smallest!=index:
            heap[index],heap[smallest]=heap[smallest],heap[index]
            index = smallest
        else:
            break

heap=[]
array=[13,16,31,41,51,100]
for value in array:
    min_heap(heap,value)
print(f"min heap after creating a heap: {heap}")

deletion_min_heap(heap,13)
print(f"min heap after deletion: {heap}")


    


