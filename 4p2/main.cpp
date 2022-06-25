#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

#include <map>
#include <regex>

bool valid_num(int input, int lower, int upper);
bool str_contains(std::string input, std::string chars);
bool validYears(int byr, int iyr, int eyr);
bool validHeight(std::string height);
bool validHaircolour(std::string hcl);
bool validEyecolour(std::string ecl);
bool validPassportID(std::string pid);

int main(void){
    std::ifstream file;
    std::string line;

    std::map<std::string, std::string> passport = {};
    int count = 0;

    file.open("input.txt");

    if(file.is_open()){
        while(getline(file, line)){

            if(line == ""){
                //process passport

                bool valid = true;
                int byr, iyr, eyr, pid;

                try{ 
                    byr = stoi(passport["byr"]); 
                    iyr = stoi(passport["iyr"]);
                    eyr = stoi(passport["eyr"]);
                    pid = stoi(passport["pid"]);
                    }
                catch(std::exception& e)
                { 
                    passport = {};
                    continue;
                }

                //birth year
                if(!validYears(byr, iyr, eyr)){
                    passport = {};
                    continue;
                }

                //height
                // // hgt (Height) - a number followed by either cm or in:
                // // If cm, the number must be at least 150 and at most 193.
                // // If in, the number must be at least 59 and at most 76.

                if(!validHeight(passport["hgt"])){
                    passport = {};
                    continue;
                }
                
                //validate hair colour
                //hcl (Hair Color) - a # followed by exactly six characters 0-9 or a-f.

                if(!validHaircolour(passport["hcl"])){
                    passport = {};
                    continue;
                }
                      
                // //validate eyecolour
                // // ecl (Eye Color) - exactly one of: amb blu brn gry grn hzl oth.

                if(!validEyecolour(passport["ecl"])){
                    passport = {};
                    continue;
                }           

                // //validate passport id
                // // pid (Passport ID) - a nine-digit number, including leading zeroes.

                if(!validPassportID(passport["pid"])){
                    passport = {};
                    continue;
                }
                if(passport.size() == 8){
                    count += 1;
                }else if((passport.size() == 7)&&(passport.count("cid") == 0)){
                    count += 1;
                }

                passport = {};
                continue;
            }

            bool end = false;
            
            while(!end){
                std::size_t pos = line.find(":");
                std::size_t next = line.find(" ");

                std::string key = line.substr(0, pos);
                std::string value = line.substr(pos+1, next-pos-1);
                
                if(next == -1){
                    end = true;
                }else{
                    line = line.substr(next+1);
                }
                passport[key] = value;
            }   
        }
    }
    std::cout << count << "\n";
}

bool valid_num(int input, int lower, int upper){
    if((input < lower)||(input > upper)){
        return false;
    }else{
        return true;
    }
}

bool str_contains(std::string input, std::string chars){
    if(input.find(chars) != std::string::npos){
        return true;
    }else{
        return false;
    }
}

bool validHeight(std::string height){
    //height in cm
    if(str_contains(height, "cm")){
        std::string tmp = height.substr(0, 3);
        int hgt;
        try { hgt = stoi(tmp); } //check if height is a valid number
        catch(std::exception& e)
        {
            return false;
        }
        if(valid_num(hgt, 150, 193)){ //check height is in range
            return true;
        }else{
            return false;
        }
    }

    else if(str_contains(height, "in"))
    {
        std::string tmp = height.substr(0, 2);
        int hgt;
        try { hgt = stoi(tmp);}
        catch(std::exception& e)
        {
            return false;
        }
        if(valid_num(hgt, 59, 76)){
            return true;
        }else{
            return false;
        }
    }else{
            return false; //return false if no suffix
        }
}

bool validYears(int byr, int iyr, int eyr){
    if((valid_num(byr, 1920, 2002)&&(valid_num(iyr, 2010, 2020)&&(valid_num(eyr, 2020, 2030))))){
        return true;
    }else{
        return false;
    }
}

bool validHaircolour(std::string hcl){
    if(hcl[0] == '#'){
        if(hcl.length() != 7){
            return false;
        }
        std::smatch matches;
        std::regex reg ("[g-z]");
        std::regex_search(hcl, matches, reg);

        if(matches.empty()){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

bool validEyecolour(std::string ecl){
    std::smatch matches;
    std::regex reg ("(amb|hzl|gry|brn|oth|blu|grn)");

    std::regex_search(ecl, matches, reg);
        
    if(matches.empty())
    {
        return false;
    }else{
        return true;
    }
}

bool validPassportID(std::string pid){
    if(pid.length() != 9){
        return false;
    }else{
        return true;
    }       
}