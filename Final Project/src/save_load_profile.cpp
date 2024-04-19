#include "save_load_profile.h"

void SaveProfile(string& name, string& program, const string& fileName) {
    ofstream file(fileName);
    if(file.is_open()) {
        file << name << endl;
        file << program << endl;
        file.close();
    }
}

void LoadProfile(string& name, string& program, const string& fileName) {
    ifstream file(fileName);
    if(file.is_open()) {
        getline(file, name);
        getline(file, program);
        file.close();
    }
}
