#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int find_path(int right, int down);

int main(void){
    long long product = 1;

    int trees = find_path(7, 1);
    product *= trees;

    trees = find_path(3, 1);
    product *= trees;

    trees = find_path(5, 1);
    product *= trees;
    
    trees = find_path(1, 1);
    product *= trees;

    trees = find_path(1, 2);
    product *= trees;

    std::cout << product << "\n";
    return 0;

}

int find_path(int right, int down){
    std::ifstream file;
    std::string line;
    
    int scroll = 31;
    char tree = '#';
    int pos = 0;
    int linecount = 1;
    int trees = 0;
    

    file.open("input.txt");
    if(file.is_open()){
        //this line skips the first line of the input, as it is never used
        file.seekg(scroll);
        
        while(getline(file,line)){
            linecount++;
            if(linecount%down != 0){
                continue;
            }

            if(line[pos] == tree){
                trees++;
            }
            pos += right;
            if (pos >= scroll){
                pos -= scroll;
            }
        }
    }
    return trees;
}