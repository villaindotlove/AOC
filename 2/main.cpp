#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

//funtion that prints vector contents, for debug
void printVector(std::vector<std::string> vector){
    std::cout << "vector contains:" << "\n";
    for (std::vector<std::string>::iterator it = vector.begin() ; it != vector.end(); it++)
        std::cout << ' ' << *it << "\n";
    std::cout << '\n';
}


int main(void){
    std::ifstream file;
    std::string line;
    int valid = 0;
    int total = 0;

    //vector used to store input
    std::vector<std::string> input;

    file.open("input.txt");
    if (file.is_open())
    { 
        while( getline (file,line))
        {
            std::string str = line;
            std::size_t pos = str.find(" ");
            std::size_t pos_2 = str.find(" ", pos+1);

            std::string range = str.substr(0, pos);
            std::string identifier = str.substr(pos+1, (pos_2-pos));
            std::string pword = str.substr(pos_2+1, (str.size()-pos_2));  

            pos = range.find("-");
            std::string temp = range.substr(0, pos);
            int lowerbound = std::stoi(temp);
            temp = range.substr(pos+1);
            int upperbound = std::stoi(temp);
            char keychar = identifier[0];

            int count = 0;
            for(int i = 0, l = pword.size(); i<l; i++){
                if(pword[i] == keychar){
                    count++;
                }
            }

            if((count >= lowerbound)&&(count <= upperbound)){
                valid++;
            }
            total++;
        }
        file.close();
    }   
    else {
        std::cout << "file.open failed";
        return 1;
    }
    //printVector(input);
    std::cout << valid << " out of " << total << "\n";
    return 0;
}