import numpy as np
import cv2
import serial

ser = serial.Serial('COM3')

upper =(117,255,255)
lower = (97, 100, 117)
chamber_color = (255,0,0)
chamber_thickness = 1
morph_field = np.ones((3, 3), np.uint8)

camera = cv2.VideoCapture(0)

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
            if y < 138:
                if x < 210:
                    ser.write(b'a')
                elif x >= 210 and x < 420:
                    ser.write(b'd')
                elif x >= 420:
                    ser.write(b'g')
            elif y >= 138 and y < 276:
                if x < 210:
                    ser.write(b'b')
                elif x >= 210 and x < 420:
                    ser.write(b'e')
                elif x >= 420:
                    ser.write(b'h')
            elif y >= 276:
                if x < 210:
                    ser.write(b'c')
                elif x >= 210 and x < 420:
                    ser.write(b'f')
                elif x >= 420:
                    ser.write(b'i')
        else:
            ser.write(b'0')
    cv2.imshow("Gercek", flip)
    cv2.imshow("Renk Filtreli", mask)

    key = cv2.waitKey(1) & 0xFF
    if key == ord("q"):
        ser.write(b'0')
        break

camera.release()
cv2.destroyAllWindows()