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
val = 100000
val2 = 100000
val3 = 100000
val4 = 100000
val5 = 100000
val6 = 100000

if(rank == 0):
    for i in range(0, 7):
        for j in range(0, 7):
            val = arr1[x+i,y+i] - arr2[x+i+dx,y+j+dy]
            val2 = min(val,val2)
            comm.send(val2,dest = 1, tag = 1)

if(rank == 1):
    for i in range(8, 15):
        for j in range(8, 15):
            val2 = comm.recv(source = 0, tag = 1)
            val3 = arr1[x+i,y+i] - arr2[x+i+dx,y+j+dy]
            val4 = min(val2,val3)


val5 = min(val2,val4)
print(val5)
print("Saludos desde el rango :",rank)
