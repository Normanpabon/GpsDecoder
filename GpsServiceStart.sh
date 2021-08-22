#!/bin/bash


echo "Starting the script"
echo "Use Ctrl-c to stop"
cat /dev/ttyACM0 &>> GpsLog.txt &
./decoder &
wait
echo "script closed successfully"
