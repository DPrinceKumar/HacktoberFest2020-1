# Code by Amey Band

import pytesseract
import shutil
import os
import random
try:
 from PIL import Image
except ImportError:
 import Image

image = 'sample.jpg'
extracted_text= pytesseract.image_to_string(Image.open(image))
print(extracted_text)
