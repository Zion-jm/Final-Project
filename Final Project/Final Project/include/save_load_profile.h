#pragma once

#include <iostream>
#include <fstream>

#include "manage_profile.h"
using std::ofstream;
using std::ifstream;
using std::string;
using std::endl;

void SaveProfile(string& name, string& program, const string& fileName);

void LoadProfile(string& name, string& program, const string& fileName);
