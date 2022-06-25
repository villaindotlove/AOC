#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

void parseFile(std::vector<std::string> &rows, std::vector<std::string> &columns);
int parseBSP(std::string bspID, int min, int max, char upperIndicator);

int main(void){

    std::vector<std::string> rows;
    std::vector<std::string> columns;
    std::vector<int> seatIDs;

    parseFile(rows, columns);

    int largest = 0;

    for(int i = 0, l = rows.size(); i < l; i++)
    {
        int r = parseBSP(rows[i], 0, 127, 'B');
        int c = parseBSP(columns[i], 0, 7, 'R');

        int n = ((r*8) + c);
        seatIDs.push_back(n);
    }
    

    std::sort(seatIDs.begin(), seatIDs.end());
    
    int offset = seatIDs[0];

    for(int i = 1, l = seatIDs.size(); i < l; i++)
    {
        if(seatIDs[i] != i + offset)
        {
            std::cout << seatIDs[i] << "\n";
        }
    }
}

void parseFile(std::vector<std::string> &rows, std::vector<std::string> &columns){
    std::ifstream file;
    std::string line;

    file.open("input.txt");
    if(file.is_open())
    {
        
        while(getline(file, line))
        {
            std::string rowID = line.substr(0,7);
            std::string columnID = line.substr(7,9);
            
            rows.push_back(rowID);
            columns.push_back(columnID);
        }
    }
}

int parseBSP(std::string bspID, int min, int max, char upperIndicator){
    if(bspID[0] == 0){
        return max;
    }   
    else{
        int newMax = 0;
        int newMin = 0;
        int half = (min + max)/2;
        std::string newID = bspID.substr(1);
        char c = bspID[0];
        if(c == upperIndicator){
            newMin = half+1;
            newMax = max;
        }else{
            newMin = min;
            newMax = half;
        }
        return parseBSP(newID, newMin, newMax, upperIndicator);
    }
}