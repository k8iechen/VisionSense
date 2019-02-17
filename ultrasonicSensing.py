#Libraries
import RPi.GPIO as GPIO
import time
 
#GPIO Mode (BOARD / BCM)
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False) 

#set GPIO 1 Pins
GPIO_TRIGGER1 = 20
GPIO_ECHO1 = 21

#set GPIO 2 Pins
GPIO_TRIGGER2 = 18
GPIO_ECHO2 = 24


#set GPIO 3 Pins
GPIO_TRIGGER3 = 19
GPIO_ECHO3 = 26
 
#set GPIO 4 Pins
#GPIO_TRIGGER3 = 18
#GPIO_ECHO3 = 24

#set GPIO direction (IN / OUT)
GPIO.setup(GPIO_TRIGGER1, GPIO.OUT)
GPIO.setup(GPIO_ECHO1, GPIO.IN)


#set GPIO direction 2 (IN / OUT)

GPIO.setup(GPIO_TRIGGER2, GPIO.OUT)
GPIO.setup(GPIO_ECHO2, GPIO.IN)

#set GPIO direction 3 (IN / OUT)
GPIO.setup(GPIO_TRIGGER3, GPIO.OUT)
GPIO.setup(GPIO_ECHO3, GPIO.IN)




def distance(GPIO_TRIGGER, GPIO_ECHO):
    # set Trigger to HIGH
    GPIO.output(GPIO_TRIGGER, True)
 
    # set Trigger after 0.01ms to LOW
    time.sleep(0.00001)
    GPIO.output(GPIO_TRIGGER, False)
 
    StartTime = time.time()
    StopTime = time.time()
 
    # save StartTime
    while GPIO.input(GPIO_ECHO) == 0:
        StartTime = time.time()
 
    # save time of arrival
    while GPIO.input(GPIO_ECHO) == 1:
        StopTime = time.time()
 
    # time difference between start and arrival
    TimeElapsed = StopTime - StartTime
    # multiply with the sonic speed (34300 cm/s)
    # and divide by 2, because there and back
    distance = int((TimeElapsed * 34300) / 2)
 
    return distance

##sets speed for two front haptic motors based on distance to obstacles 
def speedSet(distanceUS):
	if distanceUS <=10:
		return veryFast
	elif distanceUS<=100:
		return mediumFast
	elif distanceUS<=300:
		return slow
	else:
		return nothing

##activates back haptic motor based on distance to obstacle fromt the backside
def speedSetBack(distanceUS):
	if distanceUS<=15:
		return veryFast

if __name__ == '__main__':
    try:
        while True:
            dist = distance(GPIO_TRIGGER1, GPIO_ECHO1)
            time.sleep(0.001)
            dist2 = distance(GPIO_TRIGGER2, GPIO_ECHO2)
            time.sleep(0.002)
            dist3 = distance(GPIO_TRIGGER3, GPIO_ECHO3)
            print ("Measured Distance = %.0f, %.0f, %.0f" %(dist, dist2, dist3))

            returnToArduino(distanceUS(dist), distanceUS(dist2), speedSetBack(dist3))


            time.sleep(3)
 
        # Reset by pressing CTRL + C
    except KeyboardInterrupt:
        print("Measurement stopped by User")
        GPIO.cleanup()