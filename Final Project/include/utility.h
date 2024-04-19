#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <thread>
#include <limits>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::setfill;
using std::right;
using std::left;
using std::numeric_limits;
using std::streamsize;

//!!-----Design Functions
void headerDesign(const string& header);
void subHeaderDesign(const string& subHeader);
void lineDesign();
void printOption(const string& option);

//!!-----Display Functions
void displayCurrentTime();

//!!-----Validation Functions
void clearIgnore();
int getValidInput(int Min, int Max, const string& prompt);
