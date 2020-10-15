#Thank you for this repo DPrinceKumar
#THIS WILL REMOVE EXTRA SPACES FROM YOUR TEXT

Final = ''
text = input('TEXT HERE :\n')
for index, char in enumerate(text):
        if not(text[index] == " " and text[index+1]==" "):
            Final = Final + char
print(Final)
