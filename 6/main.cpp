#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

std::string Combine(std::vector<std::string>& answerSet);
void ParseFile(std::vector<std::vector<std::string>>& Container);

int main(void){
    std::vector<std::vector<std::string>> allSets;
    ParseFile(allSets);
    
    for(int i = 0, l = allSets[0].size(); i < l; i++)
    {
        std::cout << allSets[0][i] << "\n";
    }
}

void ParseFile(std::vector<std::vector<std::string>>& Container){
    std::ifstream file;
    std::string line;
    std::vector<std::string> answerSet;

    file.open("input.txt");
    if(file.is_open())
    {
        while(getline(file, line))
        {
            if(line != ""){
                answerSet.push_back(line);
            }else{
                Container.push_back(answerSet);
            }
        }   
    }
}

std::string Combine(std::vector<std::string>& answerSet){
    std::string common = answerSet[0];
    for(int i = 1, l = answerSet.size(); i < l; i++)
    {
        std::cmatch matches;
        std::regex reg ("[^" + common + "]");
        std::regex_search(answerSet[i], matches, reg);
        if(!matches.empty()){
            std::cout << matches[0] << "\n";
        }
        else{
            std::cout << "no fucking matches" << "\n";
        }
    }
    return common;
}

//make new regex using ^string