################THIS IS FOR THE BACKGROUND IMAGE###################################3
#import cv2
# cap = cv2.VideoCapture(0) #to record from the web cam .my web cam is present on 0 therefore i used 0

# while cap.isOpened():
#     ret,back=cap.read() ##HERE WE ARE READING FROM THE CAM 
#     ##Basically, ret is a boolean regarding whether or not there was a return at all, 
#     # at the back is each frame that is returned. 
#     # If there is no back, no error is generated simply None is returned
#     if ret:
#         cv2.imshow("image",back)
#         if cv2.waitKey(1)==ord("r"):
#             cv2.imwrite('back.jpg',back)##so in back.jpg your background image is saved(the last image when r was pressed)
#             break
# cap.release()##it releases all the resources of your machine(here camera only)
# cv2.destroyAllWindows()
# ##after running you can see a back.jpg being created

#################################MAIN CLOAK PROGRAM#####################################
import cv2
import numpy as np

cap=cv2.VideoCapture(0)
back = cv2.imread("./back.jpg")##returns BGR
fourcc = cv2.VideoWriter_fourcc(*'XVID')
out = cv2.VideoWriter('output.avi',fourcc, 20.0, (640,480))
while cap.isOpened():
    ret,frame=cap.read()
    if ret:
        hsv=cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
        blue=np.uint8([[[255,0,0]]])##bgr value of blue
        hsv_blue=cv2.cvtColor(blue,cv2.COLOR_BGR2HSV)
        #print(hsv_blue)##[[[120 255 255]]]
        lower_blue=np.array([0,100,100])
        upper_blue=np.array([130,255,255])
        mask=cv2.inRange(hsv,lower_blue,upper_blue)
        part1=cv2.bitwise_and(back,back,mask=mask)
        ##(src1, src2[, dst[, mask]])
        mask=cv2.bitwise_not(mask)
        part2=cv2.bitwise_and(frame,frame,mask=mask)
        out.write(part1+part2)
        cv2.imshow("cloak",part1+part2)
    if cv2.waitKey(1)==ord("r"):
        break
cap.release()
cv2.destroyAllWindows()

            
