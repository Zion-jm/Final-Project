#include "manage_profile.h"

Manage_Profile::Manage_Profile(const string& name, const string& program)
    : UserName(name), UserProgram(program) {}

void Manage_Profile::displayProfile() {
    cout << "Name: " << UserName << endl;
    cout << "Program: " << UserProgram << endl;
}

void Manage_Profile::editName() {
        cout << "Enter New Name: " << endl;
        getline(cin, UserName);
}

void Manage_Profile::editProgram() {
    cout << "Enter New Program: " << endl;
    getline(cin, UserProgram);
}
