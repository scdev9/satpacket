/*
 *  This file is part of Satpacket.
 *  Copyright (c) 2025-2027 Shamika Chathuranga (SCDEV9), Xerbo (xerbo@protonmail.com) 2019-2022
 *
 *  Satpacket is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>   // For chrono::seconds
#include <thread>
#include <iomanip>
extern "C" {
    #include <rtl-sdr.h>
}
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"


#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)    // only show filename and not it's path (less clutter)
#define INFO std::cout << std::put_time(std::localtime(&time_now), "[%y-%m-%d - %OH:%OM:%OS]") << " [I] "
#define ERROR std::cout << std::put_time(std::localtime(&time_now), "[%y-%m-%d - %OH:%OM:%OS]") << " [ERROR] "
 static std::time_t time_now = std::time(nullptr);
 using namespace std;



void display_help() {
    std::cout << "Usage: satpacket [options]" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  -h, --help           Show this help message and exit" << std::endl;
    std::cout << "  --version            Display version information" << std::endl;
    std::cout << "  -f                   Frequency for tune RTL-SDR Device" << std::endl;
    std::cout << "  -h, --help           Show this help message and exit" << std::endl;
    std::cout << "  -h, --help           Show this help message and exit" << std::endl;
    std::cout << "  -h, --help           Show this help message and exit" << std::endl;
    std::cout << "  -h, --help           Show this help message and exit" << std::endl;
    // Add more options here as needed
}



int main(int argc, char* argv[]){
    // Check for help or version arguments
    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "-h" || std::string(argv[i]) == "--help") {
            display_help();
            return 0;
        }
        if (std::string(argv[i]) == "--version") {
            std::cout << "satpacket version 1.0.0" << std::endl;
            return 0;
        }
    }

    INFO << "\033[32m    _____       __                  __         __ \033[0m" << endl;
    INFO << "\033[32m   / ___/____ _/ /_____  ____ _ ___/ /__ ___  / /_\033[0m" << endl;
    INFO << "\033[32m   \\__\\/' __ `/ __/ __ \\/ __ `/ __/ //_// _ \\/ __/\033[0m" << endl;
    INFO << "\033[32m  ___/ / /_/ / /_/ /_/ / /_/ / /__  ,< /  __/ /_  \033[0m" << endl;
    INFO << "\033[32m /____/\\__,_/\\__/ .___/\\__,_/\\ __/_/|_|\\___/\\__/  \033[0m" << endl;
    INFO << "\033[32m               /_/                                \033[0m" << endl;
    INFO << "\033[32m Starting Satpacket v1.0.0 \033[0m"<< endl;
    INFO << "                                        "<< endl;
    INFO << "\033[32m Loading config satpacket_cfg.json \033[0m"<< endl;
    std::this_thread::sleep_for(std::chrono::seconds(2)); 
    INFO << "\033[32m Loading user settings settings.json \033[0m"<< endl;
    std::this_thread::sleep_for(std::chrono::seconds(1)); 
    INFO << "\033[32m Loading plugins from ./plugins \033[0m"<< endl;
    std::this_thread::sleep_for(std::chrono::seconds(3)); 
    
    INFO << GREEN << " Checking for RTL-SDR device..." << RESET << endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));  // Delay execution


    int device_count = rtlsdr_get_device_count();
    if (device_count > 0) {
        INFO << "[ " << GREEN << "SUCCESS"  << RESET << " ] " << GREEN << "RTL-SDR device found" << RESET << endl;
    } else {
        INFO << "["  << RED << " FAILURE " << RESET << "]" << RED << " No RTL-SDR devices found"  << RESET << endl;
        std::cout << "Press Enter to Exit..." << std::endl;
        std::cin.get();
    }
    std::this_thread::sleep_for(std::chrono::seconds(2)); 



    char command;
    if (device_count > 0) {

        INFO<< GREEN << "Command: "<<RESET ;
        std::cin >> command;
    
    }
    

    return 0;

}
