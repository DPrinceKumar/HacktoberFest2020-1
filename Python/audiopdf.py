import pyttsx3
import PyPDF2

book = open('book.pdf','rb') #enter any pdf file name
pdfreader = PyPDF2.PdfFileReader(book)
pages = pdfreader.numPages
print(pages)
reading_speed=10
voice_id=1         # 1 - female voice 0- male voice
speaker = pyttsx3.init()
for num in range(2,pages) :
    voices = speaker.getProperty('voices')
    page = pdfreader.getPage(num)
    text = page.extractText()

    speaker.setProperty('voice', voices[voice_id].id)

    speaker.say(f"Page {num + 1}" +". "+", -" + text)    #convert the text into speech (,- used to create a delay)
    speaker.setProperty('rate', reading_speed)
    speaker.runAndWait()
book.close()
