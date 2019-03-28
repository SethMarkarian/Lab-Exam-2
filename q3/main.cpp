// Close the Terminal window properly when testing this code (CTRL+C, ENTER, EXIT).
// It is not well destructed and so could lead to continued, unwanted processes
// that need killing via Task Manager, Activity Monitor, etc.

#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <functional>
#include <string>
#include <vector>
#include <cstring>

void timer_start(std::function<void(void)> func, unsigned int interval){
    std::thread([func, interval](){
        while(true){
            auto x = std::chrono::steady_clock::now() + std::chrono::milliseconds(interval);
            func();
            std::this_thread::sleep_until(x);
        }
    }).detach();
}

std::vector<unsigned int> string_container(std::string _filename, int scale_factor)
{
    std::vector<std::string> sc;
    std::vector<unsigned int> times;

    //reading to file
    std::string content;
    std::ifstream file;
    file.open(_filename);
    if(!file) {
        std::cout <<"Can't open file";
        exit(1);
    }
    while(!file.eof()) {
        file >> content;
        sc.push_back(content);
    }
    file.close();


    //calculating the times into milliseconds
    for(int i = 0; i < sc.size(); i++) {
        int mill = 0;
        std::string temp = sc.at(i);

        //hours
        std::string hours_string = temp.substr(0, 2);
        mill += (std::stoi(hours_string) * 60 * 60 * 1000) * scale_factor;

        //mins
        std::string mins_string = temp.substr(3, 5);
        mill += (std::stoi(mins_string) * 60 * 1000) * scale_factor;

        //seconds
        std::string sec_string = temp.substr(6, 8);
        mill += (std::stoi(sec_string) * 1000) * scale_factor;

        //milliseconds
        std::string mill_string = temp.substr(8);
        mill += (std::stoi(mill_string)) * scale_factor;
        times.push_back(mill);

    }
    return times; //vector of milliseconds
}

void do_something(){
    std::cout << "Good evening! How do you do?" << std::endl;
}

int main(){
    int sf = 1;
    std::vector<unsigned int> t = string_container("times.csv", sf);
    for(int i = 1; i < t.size(); i++) {
        int interval = (t[i] - t[0]) / 1000; //get interval (difference between first and ith time)
        timer_start(do_something, interval);
    }
    //timer_start(do_something, 1000);
    while(true){}
}
