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

    int target = 2020;
    int target_copy = target;
    
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
    
    //choose initial value
    for (int ind = 0, lsz = input.size(); ind<lsz; ind++){

        int x = input[ind];
        
        target_copy = target - x;
        std::cout << "choosing value " << x << "\n" << "new target value is " << target_copy << "\n";
        std::vector<int> large;
        std::vector<int> small;

        //filter elements in input by size
        for (int i = 0, l = input.size(); i<l; i++)
        {
            int var = input[i];
            if(var < (target_copy/2)){
                small.push_back(var);
            }
            else{
                large.push_back(var);
            }   
        }
        //function to compare sum of small and large values against target
        for (int i=0, s = small.size(); i<s; i++){
            int var = small[i];
            for (int j = 0, l = large.size(); j<l; j++){
                if((var + large[j] + x) == target){
                    std::cout << x << ", " << large[j] << " and " << var << "\n";
                    std::cout << large[j] * var * x;
                    return 0;
                }
            }
        }
    }
    return 0;
}

