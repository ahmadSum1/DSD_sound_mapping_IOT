# DSD_sound_mapping_IOT

# IoT Based Real Time Noise Mapping System for Urban Sound Pollution Study


# Abstract.
  This paper describes the development of a system that
enables real time data visualization via a webapp regarding sound
intensity using multiple node devices connected through internet. The
prototype was realized using ATmega328 (Arduino Nano) and
ESP8266 hardware modules, NodeMCU arduino wrapper library,
Google maps and firebase API along with JavaScript webapp.
System architecture is such that multiple node devices will be
installed in different locations of the target area. On each node
device, an Arduino Nano interfaced with a Sound Sensor measures
ambient sound intensity and ESP8266 Wi-Fi module transmits the
data to a database via web API. On the webapp, it plots all the real-
time data from the devices over Google maps according to the
locations of the node devices. The logged data that is collected can
then be used to carry out researches regarding sound pollution in
targeted areas.
Keywords: Sound Sensor, NodeMCU, ESP8266, Noise Pollution,
Mapping, IoT, Google firebase.
