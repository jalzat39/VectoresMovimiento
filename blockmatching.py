from mpi4py import MPI
import numpy as np
from PIL import Image

img = Image.open("images/anchor.png")
img2 = Image.open("images/controller.png")
img = img.convert('1')
img2 = img.convert('1')
comm = MPI.COMM_WORLD
rank = comm.Get_rank()
arr1 = np.array(img)
arr2 = np.array(img2)
arr1 = arr1*1.0
arr2 = arr2*1.0
x = 0
y = 0
dx = 1
dy = 1
val2 = 100000
for i in range(0, 15):
    for j in range(0, 15):
        val = arr1[x+i,y+i] - arr2[x+i+dx,y+j+dy]
        val2 = min(val,val2)
print(val2)

 