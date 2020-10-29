# Code by Amey Band

import PyPDF2
import pyttsx3
from gtts import gTTS

def extract_text(filename):
	"""
	function to extract text from pdf at given filename
	"""
	pdfFileObj = open(filename, "rb")
	pdfReader = PyPDF2.PdfFileReader(pdfFileObj)

	mytext = ""

	for pageNum in range(pdfReader.numPages):
		pageObj = pdfReader.getPage(pageNum)
		mytext += pageObj.extractText()

	pdfFileObj.close()

	return mytext

text = extract_text("index.pdf")

speech=gTTS(text=text,lang="en",tld="com")
speech.save("pdf_reasearch_audio.mp3")
