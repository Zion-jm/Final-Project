#include "manage_profile.h"
#include "save_load_profile.h"
#include "utility.h"

#include <chrono>
#include <thread>
#include <ctime>

int main() {
    string Name, Program;

    ifstream profileFile("profile_data.txt");
    if(profileFile.is_open()) {
        LoadProfile(Name, Program, "profile_data.txt");
        profileFile.close();
    } else {
        cout << "Please Enter Your Profile Information." << endl;
        cout << "Name: ";
        getline(cin, Name);
        cout << "Program: ";
        getline(cin, Program);

        SaveProfile(Name, Program, "profile_data.txt");
    }

    Manage_Profile User(Name, Program);

    int choice;
    while(true) {
        system("cls");

        displayCurrentTime();
        headerDesign("StudentPal");
        User.displayProfile();
        lineDesign();

        printOption("[1] My Profile");
        printOption("[2] Dashboard");
        printOption("[3] Schedule Management");
        printOption("[4] Task Management");
        printOption("[5] Notifications");
        printOption("[6] View reports");
        printOption("[7] Settings");
        printOption("[8] Help");
        printOption("[0] Exit");
        lineDesign();

        choice = getValidInput(0, 8, "Enter: ");
        cin.ignore();

        switch(choice) {
        case 0://!!Exit The Program
            return 0;

        case 1://!!My Profile Section

            break;

        case 2://!!Dashboard Section

            break;

        case 3://!!Schedule Management Section

            break;

        case 4://!!Task Management Section

            break;

        case 5://!!Notifications Section

            break;

        case 6://!!View Reports Section

            break;

        case 7://!!Settings Section

            break;

        case 8://!!Help Section

            break;
        }
    }
}



























