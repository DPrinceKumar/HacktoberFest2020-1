import cv2
import vlc
from pynput.mouse import Button, Controller

ms = Controller()
m = vlc.MediaPlayer(r'C:\Users\aditya\Videos\arash.mp4')
cam = cv2.VideoCapture(0)
fd = cv2.CascadeClassifier(
    r'C:\Users\aditya\Anaconda3\Lib\site-packages\cv2\data\haarcascade_frontalface_alt.xml')
flag = 1
while True:
    r, i = cam.read()
    j = cv2.cvtColor(i, cv2.COLOR_BGR2GRAY)
    face = fd.detectMultiScale(j, 1.5, 7)
    print(face)
    print('number of faces are: ', len(face))
    if (len(face) > 0):
        for (x, y, w, h) in face:
            cv2.rectangle(i, (x, y), (x + w, y + h), (0, 0, 255), 5)
            #ms.position = (x, y)
            m.position = (x, y)
            m.play()
            #m.audio_set_volume((x * y) / 1000)
            flag = 0
    elif (flag == 0):
        m.pause()
        flag = 1

    cv2.imshow('image', i)
    k = cv2.waitKey(5)
    if k == ord('q'):
        cv2.destroyAllWindows()
        m.stop()       #to close running vlc media window
        break
