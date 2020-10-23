# ------ CODE TO CAPTURE A PIC USING WEBCAM --------

import cv2                             
cap = cv2.VideoCapture(0)           

status , photo = cap.read()         
status                              

cv2.imwrite('mypic.png' , photo)   
cap.release()                     

cv2.imshow('pic' , photo)       
cn2.waitKey()                  
