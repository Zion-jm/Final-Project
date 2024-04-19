#pragma once

#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::setfill;
using std::left;

class Manage_Profile {
public:
    string UserName;
    string UserProgram;

    Manage_Profile(const string& name, const string& program);

    void profileHeader();

    void displayProfile();

    void editName();

    void editProgram();
};
