#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <map>

int main(void){
    std::ifstream file;
    std::string line;
    int count = 0;

    file.open("input.txt");
    std::map<std::string, std::string> passport = {};
    if(file.is_open()){
        while(getline(file, line)){
            std::string str = line;

            if(line == ""){
                //process passport
                std::cout << passport.size() << "\n";
                if(passport.size() >= 8){
                    std::cout << "valid" << "\n";
                    count++;
                }else{
                    if((passport.count("cid") == 0)&&(passport.size() == 7)){
                        count++;
                    }else{
                        std::cout << "invalid" << "\n";
                    }
                    
                }
                passport = {};
                continue;
            }

            bool end = false;
            
            while(!end){
                std::size_t pos = str.find(":");
                std::size_t next = str.find(" ");

                std::string key = str.substr(0, pos);
                std::string value = str.substr(pos+1, next-pos);
                //std::cout << key << ", " << value << "\n";
                
                if(next == -1){
                    end = true;
                }else{
                    str = str.substr(next+1);
                }
                passport[key] = value;
            }   
        }
    }
    std::cout << count << "\n";
}