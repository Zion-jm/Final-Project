#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Manage_Profile {
public:
    string UserName;
    string UserProgram;

    Manage_Profile(const string& name, const string& program);

    void displayProfile();

    void editName();

    void editProgram();
};
