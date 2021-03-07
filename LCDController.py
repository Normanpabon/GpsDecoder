import I2C_LCD_driver as ild
from time import *
import csv


def main():
    refreshDelay = 5 #delay to show new cordenades
    gpsDataCsvFileName = "gpsData.csv"
    lcd = ild.lcd()

    file = open(gpsDataCsvFileName, "r")
    for x in file:
        lcd.lcd_clear()
        parsedFile = parseToTuple(x)
        # 2 argument == row and 3 argument == column
        lcd.lcd_display_string(("Lat:"+str(parsedFile[1])),1,0)
        lcd.lcd_display_string(("Lon:"+str(parsedFile[2])),2,0)
        sleep(refreshDelay)

def parseToTuple(dataString):
    tmp = tuple(map(str, dataString.split(',')))
    
    return tmp

main()