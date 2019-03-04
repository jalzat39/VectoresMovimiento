from mpi4py import MPI
import numpy as np

comm = MPI.COMM_WORLD
rank = comm.Get_rank()
arr1 = np.zeros((16,16))
arr2 = np.ones((16,16))
x = 0
y = 0
dx = 1
dy = 1
val = 100000
val2 = 100000
val3 = 100000
val4 = 100000
val5 = 100000
if(rank == 0):
    for i in range(0, 7):
        for j in range(0, 7):
            val = arr1[x+i,y+i] - arr2[x+i+dx,y+j+dy]
            val2 = min(val,val2)
if(rank == 1):
    for i in range(8, 15):
        for j in range(8, 15):
            val3 = arr1[x+i,y+i] - arr2[x+i+dx,y+j+dy]
            val4 = min(val,val2)


val5 = min(val2,val4)
print(val5)