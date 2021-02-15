#include <bits/stdc++.h>
#include <map>
using namespace std;


void SaveToFile(string data){
    string fileName = "ParsedGpsData.txt";
    fstream file; file.open(fileName, std::ios_base::app);
    if(file){
        file << data << endl;
    }else{
        ofstream file(fileName);
        file << data << endl;
    }  
    file.close();
}

void exporToCsv(vector<string> data){
    string csvFile = "gpsData.csv";
    fstream file; file.open(csvFile, std::ios_base::app);
    if(file){
        file << (data[1]+","+data[2]+data[3]+","+data[4]+data[5]+","+data[9]+"M"+","+data[7]+","+"\n");
    }else{
        ofstream file(csvFile);
        file << "UTCTime, Latitude, Longitude, Altitude, SatelliteCount,\n"; //Not working
        file << (data[1]+","+data[2]+data[3]+","+data[4]+data[5]+","+data[9]+"M"+","+data[7]+","+"\n");
        //write wikitiki
    }
    file.close();


    
}

string GTMFix(string hour){ //error here, some ascii trouble
    string returnValue;
    returnValue += (hour[0]+hour[1]+':'+hour[2]+hour[3]+':'+hour[4]+hour[5]);
    
    return returnValue;


    
}

vector<string> parseInput(string in){
    vector<string> parsedVec;
    string tempData;
    for(int i = 0; i < in.size(); i++){
        if(in[i] == ','){
            parsedVec.push_back(tempData);
            tempData = "";

        }else tempData+=in[i];
    }
    parsedVec.push_back(tempData);
    
    return parsedVec;
}

string gpggaCordenades(vector<string> output){
    string data;
    string time = GTMFix(output[1]);
    data += "UtcTime: "+ output[1] +"\tlatitude: "+ output[2]+output[3] + "\tLongitude: " + output[4]+output[5] + "\tAltitude: " + output[9] +"M" + "\tSatelliteCount: " + output[7]+"\n";
    return data;
}

void parseDataToCsv(){

}


int main(){

    string testData;
    ifstream ReadFile("GpsLog.txt");
    string tmpData;
    while(getline(ReadFile, testData)){
        
        vector<string> output = parseInput(testData);
        if(output[0] == "$GPGGA"){
            exporToCsv(output);
            tmpData = gpggaCordenades(output);
            SaveToFile(tmpData);
            cout << tmpData;
        }
        
    }
    ReadFile.close();
    
    
    

    //todo check first string and call for designated function (or not)
    return 0;
}    