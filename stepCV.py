import numpy as np
import cv2
import serial

ser = serial.Serial('COM6')

upper =(117,255,255)
lower = (97, 100, 117)
chamber_color = (0,255,0)
chamber_thickness = 2
morph_field = np.ones((5, 5), np.uint8)

camera = cv2.VideoCapture(1)


while True:
    (grabbed, frame) = camera.read()

    flip = cv2.flip(frame, 1)
    hsv = cv2.cvtColor(flip, cv2.COLOR_BGR2HSV)

    mask = cv2.inRange(hsv, lower, upper)
    mask = cv2.morphologyEx(mask, cv2.MORPH_OPEN, morph_field)


    cnts = cv2.findContours(mask.copy(), cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)[-2]
    center = None
    if len(cnts) > 0:
        c = max(cnts, key=cv2.contourArea)
        ((x, y), radius) = cv2.minEnclosingCircle(c)
        M = cv2.moments(c)
        center = (int(M["m10"] / M["m00"]), int(M["m01"] / M["m00"]))
        if radius > 0.5:
            cv2.circle(flip, (int(x), int(y)), int(radius), chamber_color, chamber_thickness)
        if x<270:
            ser.write(b'1')
        elif x>=270 and x<=330:
            ser.write(b'2')
        elif x>330 and x<600:
            ser.write(b'3')
    else:
        ser.write(b'0')
    cv2.imshow("Gercek", flip)
    cv2.imshow("Renk Filtresi", mask)

    key = cv2.waitKey(1) & 0xFF
    if key == ord("q"):
        ser.write(b'2')
        break

camera.release()
cv2.destroyAllWindows()