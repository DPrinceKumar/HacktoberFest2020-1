# Code provided by Amey Band 

from gtts import gTTS

def text2Speech(data):
    my_text = data
    tts = gTTS(text=my_text, lang='en', slow=False)
    # save file as ... (here saving as mp3)
    tts.save('converted-file2.mp3')  
    
data = "For fetching the real-time data from twitter, the sentiment analysis model must require all requests to use OAuth for Authentication. Tweepy is the most easy-to-use Python library for accessing the functionalities provided by the Twitter API. Tweepy provides functionalities in a more straightforward way for Authentication. To design the sentiment model, we need to register our client application with Twitter. We follow the below authentication process"

text2Speech(data)
