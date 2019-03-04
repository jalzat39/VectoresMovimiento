import numpy as np
from PIL import Image
img = Image.open("anchor.png")
img2 = Image.open("controller.png")
img = img.convert('1')
img2 = img.convert('1')
arr = np.array(img)
arr = arr*1
print(np.matrix(arr))