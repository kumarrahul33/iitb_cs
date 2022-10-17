
def permute(arr, n, l=0):
    if (l == n):
        print(arr)
    else:
        for i in range (l, n+1):
            arr[l], arr[i] = arr[i], arr[l]
            permute(arr, n, l+1)
            arr[l], arr[i] = arr[i], arr[l]
        
str1 = ["a","b","c","d"]
# pass the list , ending index
permute(str1,3)
    
