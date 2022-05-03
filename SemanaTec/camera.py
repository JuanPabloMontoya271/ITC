import numpy as np
import cv2
def empty (evt):
    pass
cap = cv2.VideoCapture(0)
cv2.namedWindow("trackbars",)
cv2.resizeWindow("trackbars", 640,420)
cv2.createTrackbar("hue min", "trackbars", 0, 179, empty)
cv2.createTrackbar("hue max", "trackbars", 19, 179, empty)
cv2.createTrackbar("sat min", "trackbars", 110, 255, empty)
cv2.createTrackbar("sat max", "trackbars", 240, 179, empty)
cv2.createTrackbar("value min", "trackbars", 153, 255, empty)
cv2.createTrackbar("value max", "trackbars", 255, 255, empty)
cap.set(3,640 )
cap.set(4, 480)
kernel = np.ones((5,5), np.uint8)

while True:
    # Capture frame-by-frame
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    h_min = cv2.getTrackbarPos("hue min", "trackbars")
    h_max = cv2.getTrackbarPos("hue max", "trackbars")
    s_min = cv2.getTrackbarPos("sat min", "trackbars")
    s_max = cv2.getTrackbarPos("sat max", "trackbars")
    v_min = cv2.getTrackbarPos("value min", "trackbars")
    v_max = cv2.getTrackbarPos("value max", "trackbars")
    print(h_min, h_max, s_min, s_max, v_min, v_max)
    lower= np.array([h_min, s_min, v_min])
    upper= np.array([h_max, s_max, v_max])
    mask = cv2.inRange(hsv, lower, upper )
    img_result = cv2.bitwise_and(frame,frame,mask = mask)
    # Our operations on the frame come here
 
    cv2.imshow('frame',frame)
    cv2.imshow("mask", mask)
    cv2.imshow('HSV',hsv)
    cv2.imshow('gray',gray)
    cv2.imshow('result',img_result)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()