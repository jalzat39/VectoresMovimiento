import numpy as np
arr1 = np.zeros((16,16))
arr2 = np.ones((16,16))
x = 0
y = 0
dx = 1
dy = 1
val2 = 100000
for i in range(0, arr1.shape[0] - 1):
    for j in range(0, arr2.shape[0] -1):
        val = arr1[x+i,y+i] - arr2[x+i+dx,y+j+dy]
        val2 = min(val,val2)
print(val2)
 