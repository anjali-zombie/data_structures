def heapify(arr,n,index):
    smallest = index
    left = 2*index+1
    right = 2* index+2
    
    if left < n and arr[left] < arr[smallest]:
        smallest = left
    if right < n and arr[right] < arr[smallest]:
        smallest = right
    if smallest!= index:
        arr[index],arr[smallest] = arr[smallest],arr[index]
        heapify(arr,n,smallest)

arr = [10,5,15,2,20,30]
n = len(arr)
for i in range(len(arr) // 2 - 1,-1,-1):
    heapify(arr,n,i)
print(f"array after heapify is {arr}")
