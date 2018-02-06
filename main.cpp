#include <iostream>
#include "buffer.h"
#include <fstream>
#include <streambuf>
#include <stdio.h>
#include <string.h>
#include <sstream>
using namespace std;

int main(int argc, char *argv[])
{
    Buffer<std::string>* cyclicBuffer = new Buffer<std::string>(10);
    const std::vector<std::string>& rawBuf = cyclicBuffer->getBuf();

    std::ifstream fd("Environmental_Data_Deep_Moor_2012.txt");
    std::string rawString = std::string(std::istreambuf_iterator<char>(fd),std::istreambuf_iterator<char>());
    std::istringstream ss(rawString);
    std::string line;
    std::vector<std::string> logs;
    while(getline(ss,line))
    {
        std::string tmp;
        std::istringstream ssFromLine(line);
        while(getline(ssFromLine,tmp,'\t'))
        {
            ;
            logs.push_back(tmp);
        }
    }
    for(const auto& i : logs)
    {
        cyclicBuffer->push(i);
    }

    for(const auto& i : rawBuf)
    {
        cout << i;
    }
    return 0;
}
