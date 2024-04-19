#include "task_management_section.h"

int TaskManagementSection(User_Task& UserTask, User_Task& TaskFound) {
    int choice, sortType, sortOrder;
    while(true) {
        system("cls");

        headerDesign("Task Management");
        UserTask.DisplayTask();
        lineDesign();

        printOption("[1] View Task");
        printOption("[2] Sort Task");
        printOption("[3] Search Task");
        printOption("[0] Back");
        lineDesign();
        choice = getValidInput(0, 3, "Enter: ");
        cin.ignore();

        switch(choice) {
        case 0://!!Exit Task Management Section Go Back To Main Section
            return 0;

        case 1://!!View Task Section
            while(true) {
                system("cls");

                headerDesign("Task ManageMent");
                subHeaderDesign("View Task");
                UserTask.DisplayTask();
                lineDesign();

                printOption("[1] Add Task");
                printOption("[2] Edit Task");
                printOption("[3] Delete Task");
                printOption("[0] Back");
                lineDesign();
                choice = getValidInput(0, 1, "Enter: ");
                cin.ignore();
                if(choice == 0) { break;}//!!Exit View Task Section Go Back To Task Management

                switch(choice) {
                case 1://!!Add Task Section
                    UserTask.AddTask();
                    break;

                case 2://!!Edit Task Section
                    UserTask.EditTask();
                    break;

                case 3://!!Delete Task Section
                    UserTask.DeleteTask();
                    break;
                }
            }
            break;

        case 2://!!Sort Task Section
            while(true) {
                system("cls");

                headerDesign("Task Management");
                subHeaderDesign("Sort Task");
                UserTask.DisplayTask();
                lineDesign();

                cout << "Please Select A Sort Type." << endl;
                printOption("[1] Sort By Task Name");
                printOption("[2] Sort By Task Due Date");
                printOption("[3] Sort By Task Priority Level");
                printOption("[0] Back");
                sortType = getValidInput(0, 3, "Enter: ");
                cin.ignore();
                if(sortType == 0) { break;}

                lineDesign();
                cout << "Please Select A Sort Order" << endl;
                printOption("[1] Ascending");
                printOption("[2] Descending");
                printOption("[0] Back");
                sortOrder = getValidInput(0, 2, "Enter: ");
                cin.ignore();
                if(sortOrder == 0) { break;}

                UserTask.SortTask(sortType, sortOrder);
            }
            break;

        case 3://!!Search Task Section
            while(true) {
                system("cls");

                headerDesign("My Task");
                subHeaderDesign("Search Task");
                UserTask.DisplayTask();
                lineDesign();
                Manage_Task::displayTask(TaskFound.TaskElements);
                TaskFound.TaskElements.clear();
                lineDesign();

                printOption("[1] Search By Task Name");
                printOption("[2] Search By Task Due Date");
                printOption("[3] Search By Task Priority Level");
                printOption("[0] Back");
                choice = getValidInput(0, 3, "Enter: ");
                cin.ignore();
                if(choice == 0) { break;}

                UserTask.SearchTask(TaskFound.TaskElements, choice);
            }
            break;
        }
    }
}
