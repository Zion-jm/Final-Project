#include "my_profile_section.h"

int MyProFileSection(Manage_Profile& User){
    while(true) {
        system("cls");

        displayCurrentTime();
        headerDesign("My Profile");
        User.profileHeader();
        lineDesign();

        printOption("[1] View Profile");
        printOption("[2] Set Preferences");
        printOption("[0] Back");
        lineDesign();

        int choice = getValidInput(0, 2, "Enter: ");
        cin.ignore();

        switch(choice) {
        case 0://!!Exit My Profile Section Go Back To Main Section
            return 0;

        case 1://!!View Profile Section
            while(true) {
                system("cls");

                displayCurrentTime();
                headerDesign("My Profile");
                subHeaderDesign("View Profile");
                User.displayProfile();
                lineDesign();

                printOption("[1] Edit Name");
                printOption("[2] Edit Program");
                printOption("[0] Back");
                lineDesign();
                choice = getValidInput(0, 2, "Enter: ");
                cin.ignore();

                switch(choice) {
                case 0://!!Exit View Profile Section Go Back To My Profile Section
                    return 0;

                case 1://!!Edit Name
                    User.editName();
                    break;

                case 2://!!Edit Program
                    User.editProgram();
                    break;
                }
            }
            break;

        case 2://!!Set Preference Section
            while(true) {
                system("cls");

                displayCurrentTime();
                headerDesign("My Profile");
                subHeaderDesign("Set Preferences");
                displayUnderDevelopment();
                lineDesign();

                choice = getValidInput(0, 0, "Enter: ");
                cin.ignore();

                switch(choice) {
                case 0://!!Exit Set Preference Section Go Back To My Profile Section
                    return 0;
                }
            }
            break;
        }
    }
}
