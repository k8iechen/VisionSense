# VisionSense

#### Link to more detailed information
https://www.hackster.io/137953/visionsense-2b9f4a

#### Inspiration
Our team was discussing the advances in wearable technology, and how it helps us stay connected while making daily life easier in aspects like health, navigation, and safety. Eventually, we began to wonder how wearable technology could play these same roles in the lives of different user groups. We considered the design specifications and changes for groups that cannot use the sense of sight- primarily people with visual impairment or in occupations like mining/mountaineering that can at times be in pitch darkness.

#### What it does

###### Step (1) Environmental Assessment

The Telus DevKit Board takes sensory data from the users environment (e.g. temperature, pressure, humidity, latitude/longitude and location) and sends it over LTE to the Azure database via Azure IOT Hub. This step provides invaluable information in the case of accidents or emergencies to authorities on the environment at the time of the accident (e.g. mining disasters, missing person, etc.)

###### Step (2) Obstruction Detection

The Raspberry Pi board is connected to 3 Ultrasonic Sensors, through which it determines any obstructions within a 4 metre range from the user's head. This data is wirelessly communicated to an online server via WiFi, that can then provide input to the Arduino system. The system is also equipped with a help button that sends an emergency text message to an emergency contact with just a simple press of a button by the user.

###### Step (3) Haptic Direction

The Arduino uses input communicated wirelessly from the Ultrasonic sensors to set custom vibrations that can communicate any obstructions, along with their range and direction relative to the user. This component allows users to act upon all the information gathered from our system to seamlessly move around without any hand-held aids.

#### How we built it
System-on-a-chip: Telus Devkit (to Azure), Arduino, Raspberry Pi
Languages: Python, C++, C, JavaScript Hardware Implemented: Ultrasonic Sensors, Force Sensor, 4 Stepper Motors

#### Challenges we ran into
- Setting up the Python Wireless Connection for Data collection
- Drawing out (and accordingly building) sound circuitry to ensure all UltraSonic Sensors provide accurate data
- Streaming sensor data from TELUS boards to Azure DB
- Stably building the housing components in wearable form for the systems
- Interfacing Raspberry Pi with Arduino

#### Accomplishments we're proud of
We did not have actuators or vibrators available, so we really had to understand the inner workings of Stepper Motors and rewire them (as well as format the code accordingly) to have them work as vibrators using input from the Raspberry Pi

Setting up the environments for all the systems-on-a-chip was a time-consuming and tedious job with much debugging. Getting through that took many hours, but we managed to successfully interface and integrate all components of our tech

The data output by hardware was a bit challenging to work with, especially in the case of the UltraSonic Sensors. However, with much testing and documentation review, we did eventually achieve proper obstacle detection using these sensors.

GPS location data was reliant on LTE antennas, which were not strong enough to function indoors. As a result the program would attempt to search for GPS signal for long periods of time without success and end up timing out. This caused the data stream to be slow and unstable but we were able to promptly pin-point this issue and adjust the code for indoor testing.

#### What we learned
Setting up multi-component IoT Systems, and the importance of considering different user groups and their specific design specs when prototyping.

#### What's next for VisionSense
- Making the wearable technology smaller and easier to wear
- Using computer vision with an embedded camera that communicates (using audio) any pre-determined tags (machine learning - image recognition) to user if they appear within range
