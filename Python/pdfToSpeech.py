"""
PDF to AudioBook Converter
@author: TUSHAR
"""
import pyttsx3 
import PyPDF2 as pdf
from tkinter.filedialog import *

book = askopenfilename()
pdfreader = pdf.PdfFileReader(book)
pages = pdfreader.numPages
print(pages)
for num in range(0, pages):
    page = pdfreader.getPage(num)
    text = page.extractText()
    player = pyttsx3.init()
    player.say(text)
    player.runAndWait()
