from tkinter import *
from PIL import ImageTk, Image
import requests
import json
import random

wind= Tk()
wind.title('Weather App')

def fetch(fr):
    try:
        zipc=zip.get()
#        api_r= requests.get(f'http://www.airnowapi.org/aq/observation/zipCode/current/?format=application/json&zipCode={zipc}&distance=5&API_KEY=AD06A07B-CC39-4006-BAC4-B9DBB2B5F8BE')
        k ="353ddfe27aa4b3537c47c975c70b58d9"
        p= {"http": "http://111.233.225.166:1234"}
        api_r= requests.get(f"http://api.openweathermap.org/data/2.5/weather?appid={k}&q={zipc}, verify= False, proxies=p")
        """ api = json.loads(api_r.content)
        city= api[0]['ReportingArea']
        qual= api[0]['AQI']
        p = api[0]['Category']['Name']
        if p=='Good':
            col= "#0C0"
        elif p=='Moderate':
            col= "#FFFF00"
        elif p=='Unhealthy for Sensitive Groups':
            col= "#ff9900"
        elif p=="Unhealthy":
            col= "FF0000"
        elif p=="Very Unhealthy":
            col="#990066"
        else:
            col= "#660000"
        wind.configure(bg=col)
        l= Label(wind, text= f'{city} Air Quality: {qual} {p}', font=("Helvetica", 20), bg=col)
        l.grid(row=1, column= 0, columnspan= 2)
        """
        x= api_r.json()
        if x["cod"] != "404":
            y = x["main"]
            temp = y["temp"]
            p =y['pressure']
            hum= y['humidity']
            z = x['weather'][0]
            desc = z["description"]
            wid = str(z['id'])
            if '8' in wid[0]:
                if wid=='800':
                    col="#d8d1b4"
                else:
                    col="#bababa"
            elif '7' in wid[0]:
                col="#c2eaea"
            elif '6' in wid[0]:
                col="#dde5f4"
            elif '5' in wid[0]:
                col= "#68707c"
            elif '3' in wid[0]:
                col= "#b1c4d8"
            elif '2' in wid[0]:
                col= "#4d5665"
            else: col="white"

            l.config(text=" Temperature: " +str(temp-273.16) +"°C\n\
Atmospheric pressure: " +str(p) +"hpa\n\
Humidity: " +str(hum) +"%\n\
Description: " +str(desc), font=("Helvetica",18), bg=col)
    except:
        l.config(fr, text= 'Connection Refused', bg='red')
#p = [f'{i}:{api[0][i]}' for i in api[0]]
fr= Frame(wind)
fr.grid(row= 1, column= 0, columnspan=2)
l= Label(fr)
l.pack()
zip= Entry(wind)
zip.grid(row=0, column=0, sticky=N+S+W+E)
sub= Button(wind, text= 'Show Weather', command= lambda: fetch(fr))
sub.grid(row= 0, column=1, sticky= N+S+W+E)

wind.mainloop()
