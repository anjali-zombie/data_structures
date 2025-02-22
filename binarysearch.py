arr = [-3,-2,-1,0,1,2,3]
n = len(arr)
target = 3
low =0
high = n-1
found = False
while low <= high:
    mid = (low+high) // 2
    if(arr[mid] == target):
        found = True
        print(f"{mid}")
        break
    elif(arr[mid] >= target):
        high = mid-1
    else:
        low = mid+1
if not found:
    print(f"target {target} is not found in given array")



