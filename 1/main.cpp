#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


/*funtion that prints vector contents, for debug
void printVector(std::vector<int> vector){
    std::cout << "vector contains:" << "\n";
    for (std::vector<int>::iterator it = vector.begin() ; it != vector.end(); it++)
        std::cout << ' ' << *it << "\n";
    std::cout << '\n';
}
*/

int main(void){
    std::string line;
    std::ifstream file;

    //vector used to store input
    std::vector<int> input;

    //vectors used to filter values into those < (target/2)
    std::vector<int> large;
    std::vector<int> small;

    int target = 2020;
    int halfcount = 0;
    
    //filestream from input file
    file.open("input.txt");
    if (file.is_open())
    { 
        while( getline (file,line))
        {
            //cast line to int then push it into input vector
            std::stringstream data(line);
            int value;
            data >> value;
            input.push_back(value);
        }
        file.close();
    }   
    else {
        std::cout << "file.open failed";
        return 0;
    }
    
    //filter elements in input by size
    for (int i = 0, l = input.size(); i<l; i++)
    {
        int var = input[i];
        if(var < (target/2)){
            small.push_back(var);
            continue
        }
        else{
            large.push_back(var);
            continue
        }   
    }
    //printVector(small);
    //printVector(large);


    //function to compare sum of small and large values against target
    for (int i=0, s = small.size(); i<s; i++){
        int var = small[i];
        for (int j = 0, l = large.size(); j<l; j++){
            if((var + large[j]) == target){
                std::cout << large[j] << " and " << var << "\n";
                std::cout << large[j] * var;
                return 0;
            }
        }
    }
    return 0;
    
}

