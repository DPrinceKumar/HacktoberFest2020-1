import zipfile

from PIL import Image
import pytesseract
import cv2 as cv
import numpy as np
from IPython.display import display
import pytesseract

# loading the face detection classifier
face_cascade = cv.CascadeClassifier('readonly/haarcascade_frontalface_default.xml')

# the rest is up to you!
zp = zipfile.ZipFile(file = 'readonly/images.zip')
lst = zp.infolist()

imnamelst = [] 
imdic = {}  

for item in lst :
    imdic[item.filename] = []
    imdic[item.filename].append(Image.open(zp.open(item.filename)))
    imnamelst.append(item.filename)

for name in imnamelst :
    pic = imdic[name][0]
    text = pytesseract.image_to_string(pic).replace('\n','')
    imdic[name].append(text)
    if "Mark" in imdic[name][1] :
        print("Results found in file",name)
        try :
            faces = (face_cascade.detectMultiScale(np.array(pic),1.35,4)).tolist()
            imdic[name].append(faces)
            
            facesinit = []
            
            for x,y,w,h in imdic[name][2] :
                facesinit.append(pic.crop((x,y,x+w,y+h)))
                
            contact_sheet = Image.new(pic.mode, (550,110*int(np.ceil(len(facesinit)/5))))
            x = 0
            y = 0
            
            for face in facesinit :
                face.thumbnail((110,110))
                contact_sheet.paste(face, (x, y))

                if x+110 == contact_sheet.width :
                    x=0
                    y=y+110
                else :
                    x=x+110

            display(contact_sheet)
        except :
            print('But there were no faces in that file!')
