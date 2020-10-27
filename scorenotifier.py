import requests
from bs4 import BeautifulSoup
from win10toast import ToastNotifier
import re
from time import sleep
import tkinter as tk
from tkinter import ttk
from tkinter import *
import tkinter.font as font
from PIL import ImageTk,Image


def art():
    print("""
|||      ||| \\\        ///  |||||||||          |||||||||  ||||||||| |||||||||  ||||||||  |||||||||
|||      |||  \\\      ///   |||                |||        |||       |||   |||  |||  |||  |||
|||      |||   \\\    ///    |||||              |||||||||  |||       |||   |||  |||||///  |||||
|||      |||    \\\  ///     |||                      |||  |||       |||   |||  ||| \\\   ||| 
|||||||| |||     \\\///      |||||||||          |||||||||  ||||||||| |||||||||  |||  \\\  |||||||||
""")

def get_current_matches():
    page = requests.get('http://static.cricinfo.com/rss/livescores.xml')
    soup = BeautifulSoup(page.text,'lxml')
    matches = soup.find_all('description')
    live_matches = [s.get_text() for s in matches if '*' in s.get_text()]
    return live_matches

def fetch_score(matchNum):
    page = requests.get('http://static.cricinfo.com/rss/livescores.xml')
    soup = BeautifulSoup(page.text,'lxml')
    matches = soup.find_all('description')
    live_matches = [s.get_text() for s in matches if '*' in s.get_text()]
    return live_matches[matchNum]


def popupmsg(score,name):
    popup = tk.Tk()
    popup.geometry("1200x800")
    myFont=font.Font(family='Helvetica', size=20, weight="bold")
    popup.wm_title("LIVE CRICKET SCORE")
    canvas = Canvas(popup,width=750,height=500)
    canvas.pack()
    img = ImageTk.PhotoImage(Image.open("ipl.jpg"))
    canvas.create_image(50,50,anchor=NW, image=img)
    label = ttk.Label(popup, text=score)
    label.pack(side="top", fill="x", pady=20 , padx=80)
    label.config(font=("Courier", 36, "bold"))
    popup.configure(bg='gold')
    B1 = Button(popup, text="Okay", command = popup.destroy, bg='red', fg='black')
    B1['font']=myFont
    B1.pack()
    copyri8 = Label(popup,text='Ⓒ:G3',
                bg='plum1',fg='red3',font=('arial',10,'bold'))
    copyri8.pack(side=BOTTOM)
    popup.mainloop()


if __name__ == "__main__":
    name = input("Please Enter your Name:")
    print("Hello",name,",Welcome to Live Cricket Score Notifier")
    art()
    matches = get_current_matches()
    print('Current matches in play')
    print('='*25)
    for i,match in enumerate(matches):
                print('[{}] '.format(i) + 
                        re.search('\D+',match.split('v')[0]).group() + 'vs.' +
                        re.search('\D+',match.split('v')[1]).group()
                      )

    print()
    matchNum = int(input('Please select Match Number for Live Scores [0,1,2...] => '))
    print("Getting Scores.....")
    print("Please check the popup window/icon in your Taskbar")
    print("Popup will appear again and again after every 10 seconds")  

    while True:
        current_score = fetch_score(matchNum)
        popupmsg(current_score, name)
        sleep(10)
      