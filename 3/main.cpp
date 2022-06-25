#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(void){
    std::ifstream file;
    std::string line;
    int scroll = 31;
    int pos = 0;
    int trees = 0;
    char tree = '#';

    file.open("input.txt");
    if(file.is_open()){
        //this line skips the first line of the input, as it is never used
        file.seekg(scroll);
        
        while(getline(file,line)){

            if(line[pos] == tree){
                trees++;
            }
            pos += 3;
            if (pos >= scroll){
                pos -= scroll;

            }
        }
    }
    std::cout << trees;
    return 0;
}