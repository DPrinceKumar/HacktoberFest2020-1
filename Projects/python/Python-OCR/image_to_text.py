# Code by Amey Band

import pytesseract
import shutil
import os
import random
try:
 from PIL import Image
except ImportError:
 import Image

image = 'sample1.jpg'
extracted_text= pytesseract.image_to_string(Image.open(image))
print(extracted_text)

"""
Output:

"IF YOUR
DREAMS
DON'T
SCARE YOU,
THEY ARE
TOO SMALL"

- Richard Branson
"""
