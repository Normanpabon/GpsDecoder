#!/bin/bash

if [ $(whoami) != "root" ]; then
    echo "This script must be ran as root"
    exit 1
else
    echo "root user detected"
fi


echo "Starting the script"
echo "Use Ctrl-c to stop"
sudo cat /dev/ttyACM0 &>> GpsLog.txt &
sudo ./decoder &
sudo python3 LCDController.py &
wait
echo "script closed successfully"
