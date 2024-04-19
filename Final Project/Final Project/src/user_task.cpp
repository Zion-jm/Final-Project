#include "user_task.h"

namespace Manage_Task {
    void displayTask(vector<TaskType>& TaskElements) {
        string PL;
        int counter = 1;
        cout << "You Currently Have " << TaskElements.size() << " Task" << endl;
        for(const auto& task : TaskElements) {
            switch(task.PriorityLevel) {
                case 1: PL = "LOW"; break;
                case 2: PL = "MEDIUM"; break;
                case 3: PL = "HIGH"; break;
            }

            cout << counter << ".) " << left << setw(50) << setfill(' ') << task.TaskName
                 << "Due Date(mm, dd): " << task.DueMonth << ", " << task.DueDay << "     PL: " << task.PriorityLevel << " = " << PL << endl;
            counter++;
        }
    }

    void displaySingleTask(vector<TaskType>& TaskElements, int index) {
        index--;
        string PL;
        switch(TaskElements[index].PriorityLevel) {
        case 1:
            PL = "LOW";
            break;
        case 2:
            PL = "MEDIUM";
            break;
        case 3:
            PL = "HIGH";
            break;
        }

        cout << "Task Name: " << TaskElements[index].TaskName << endl;
        cout << "Due Date(mm, dd): " << TaskElements[index].DueMonth << ", " << TaskElements[index].DueDay << endl;
        cout << "Priority Level: " << TaskElements[index].PriorityLevel << " = " << PL << endl;
    }

    void addTask(vector<TaskType>& TaskElements) {
        string taskName;
        string dueMonth;
        string dueDay;
        int priorityLevel;

        system("cls");
        headerDesign("Task Management");
        subHeaderDesign("Add Task");

        cout << "Enter The Following Task Information:" << endl;
        cout << "Task Name: ";
        getline(cin, taskName);

        cout << "Task Due Date: " << endl;
        dueMonth = to_string(getValidInput(1, 12, "              Month(mm): "));
        dueDay = to_string(getValidInput(1, 31, "              Day(dd): "));

        cout << "Priority Level(1 = LOW, 2 = MEDIUM, 3 = HIGH): " << endl;
        priorityLevel = getValidInput(1, 3, "Enter: ");

        if(dueMonth.length() == 1) {
            dueMonth = "0" + dueMonth;
        }
        if(dueDay.length() == 1) {
            dueDay = "0" + dueDay;
        }

        TaskElements.push_back({taskName, dueMonth, dueDay, priorityLevel});
    }

    void editTask(vector<TaskType>& TaskElements) {
        int choice, index;
        while(true) {
            system("cls");

            headerDesign("Task Management");
            subHeaderDesign("Edit Task");
            displayTask(TaskElements);
            lineDesign();

            cout << "Enter The Number Of The Task You Want To Edit. Enter 0 To Back." << endl;
            index = getValidInput(0, TaskElements.size(), "Enter: ");
            cin.ignore();
            if(index == 0) { break;}//!!Exit Edit Task

            printOption("[1] Edit All");
            printOption("[2] Edit Task Name");
            printOption("[3] Edit Due Date");
            printOption("[4] Edit Priority Level");
            printOption("[0] Back");
            choice = getValidInput(0, 4, "Enter: ");
            cin.ignore();
            if(choice == 0) { break;}

            switch(choice) {
            case 1://!!Edit All
                system("cls");
                headerDesign("Task Management");
                subHeaderDesign("Edit Task");
                cout << "You Are Editing The Information Of Task '" << TaskElements[index - 1].TaskName << "'" << endl;
                displaySingleTask(TaskElements, index);
                lineDesign();

                cout << "Enter The New Information For Task " << TaskElements[index - 1].TaskName << endl;
                cout << "New Task Name: ";
                getline(cin, TaskElements[index - 1].TaskName);

                cout << "New Due Date: " << endl;
                TaskElements[index - 1].DueMonth = to_string(getValidInput(1, 12, "             New Month: "));
                TaskElements[index - 1].DueDay = to_string(getValidInput(1, 31, "             New Day: "));

                cout << "New Priority Level(1 = LOW, 2 = MEDIUM, 3 = HIGH): " << endl;
                TaskElements[index - 1].PriorityLevel = getValidInput(1, 3, "New Priority Level: ");
                break;

            case 2://!!Edit Task Name
                system("cls");
                headerDesign("Task Management");
                subHeaderDesign("Edit Task");
                cout << "You Are Editing The Name Of Task '" << TaskElements[index - 1].TaskName << "'" << endl;
                displaySingleTask(TaskElements, index);
                lineDesign();

                cout << "New Task Name: ";
                getline(cin, TaskElements[index - 1].TaskName);
                break;

            case 3://!!Edit Due Date
                system("cls");
                headerDesign("Task Management");
                subHeaderDesign("Edit Task");
                cout << "You Are Editing The Due Date Of Task '" << TaskElements[index - 1].TaskName << "'" << endl;
                displaySingleTask(TaskElements, index);
                lineDesign();

                cout << "New Due Date: " << endl;
                TaskElements[index - 1].DueMonth = to_string(getValidInput(1, 12, "             New Month: "));
                TaskElements[index - 1].DueDay = to_string(getValidInput(1, 31, "             New Day: "));
                break;

            case 4://!!Edit Priority Level
                system("cls");
                headerDesign("Task Management");
                subHeaderDesign("Edit Task");
                cout << "You Are Editing The Prioriry Level Of Task '" << TaskElements[index - 1].TaskName << "'" << endl;
                displaySingleTask(TaskElements, index);
                lineDesign();

                cout << "New Priority Level(1 = LOW, 2 = MEDIUM, 3 = HIGH): " << endl;
                TaskElements[index - 1].PriorityLevel = getValidInput(1, 3, "New Priority Level: ");
                break;
            }
        }
    }

    void deleteTask(vector<TaskType>& TaskElements) {
        int index;
        while(true) {
            system("cls");

            headerDesign("Task Management");
            subHeaderDesign("Delete Task");
            displayTask(TaskElements);
            lineDesign();

            cout << "Enter The Number Of The Task You Want To Delete. Enter 0 To Back" << endl;
            index = getValidInput(0, TaskElements.size(), "Enter: ");
            if(index == 0) { break;}

            TaskElements.erase(TaskElements.begin() + index - 1);
        }
    }

    void swapElement(vector<TaskType>& TaskElements, int j) {
        TaskType holder = TaskElements[j];
        TaskElements[j] = TaskElements[j + 1];
        TaskElements[j + 1] = holder;
    }

    void sortTask(vector<TaskType>& TaskElements, int SortType, int SortOrder) {
        string Name1;
        string Name2;
        for(int i = 0; i < TaskElements.size() - 1; i++) {
            for(int j = 0; j < TaskElements.size() - i - 1; j++) {
                switch(SortType) {
                case 1://!!Sort By Task Name
                    Name1 = TaskElements[j].TaskName;
                    Name2 = TaskElements[j + 1].TaskName;
                    transform(Name1.begin(), Name1.end(), Name1.begin(), ::tolower);
                    transform(Name2.begin(), Name2.end(), Name2.begin(), ::tolower);
                    switch(SortOrder) {
                    case 1://!!Asc
                        if(Name1 > Name2) {
                            swapElement(TaskElements, j);
                        }
                        break;

                    case 2://!!Des
                        if(Name1 < Name2) {
                            swapElement(TaskElements, j);
                        }
                        break;
                    }
                    break;

                case 2://!!Sort By Task Due Date
                    switch(SortOrder) {
                    case 1://!!Asc
                        if(TaskElements[j].DueMonth > TaskElements[j + 1].DueMonth ||
                        (TaskElements[j].DueMonth == TaskElements[j + 1].DueMonth && TaskElements[j].DueDay > TaskElements[j + 1].DueDay)) {
                                swapElement(TaskElements, j);
                        }
                        break;

                    case 2://!!Des
                        if(TaskElements[j].DueMonth < TaskElements[j + 1].DueMonth ||
                        (TaskElements[j].DueMonth == TaskElements[j + 1].DueMonth && TaskElements[j].DueDay < TaskElements[j + 1].DueDay)) {
                                swapElement(TaskElements, j);
                        }
                        break;
                    }
                    break;

                case 3://!!Sort By Priority Level
                    switch(SortOrder) {
                    case 1://!!Asc
                        if(TaskElements[j].PriorityLevel > TaskElements[j + 1].PriorityLevel) {
                            swapElement(TaskElements, j);
                        }
                        break;

                    case 2://!!Des
                        if(TaskElements[j].PriorityLevel < TaskElements[j + 1].PriorityLevel) {
                            swapElement(TaskElements, j);
                        }
                        break;
                    }
                    break;
                }
            }
        }
    }

    void searchTask(vector<TaskType>& TaskElements, vector<TaskType>& TaskFound, int SearchType) {
        string keyword;
        int keynumber;
        string holder;
        if(SearchType == 1 || SearchType == 2) {
            cout << "Please Enter A Keyword: ";
            getline(cin, keyword);
            for(int i = 0; i < TaskElements.size(); i++) {
                switch(SearchType) {
                case 1:
                    holder = TaskElements[i].TaskName;
                    break;
                case 2:
                    holder = TaskElements[i].DueMonth + TaskElements[i].DueDay;
                    break;
                }
                for(int j = 0; j < holder.length(); j++) {
                    int k = 0;
                    while(k < keyword.length() && tolower(keyword[k]) == tolower(holder[j + k])) {
                        k++;
                    }
                    if(k == keyword.length()) {
                        TaskFound.push_back(TaskElements[i]);
                        break;
                    }
                }
            }
        } else if(SearchType == 3) {
            keynumber = getValidInput(1, 3, "Please Enter A Number Keyword: ");
            for(int i = 0; i < TaskElements.size(); i++) {
                if(keynumber == TaskElements[i].PriorityLevel) {
                    TaskFound.push_back(TaskElements[i]);
                }
            }
        }
    }
}

void User_Task::DisplayTask() {
    Manage_Task::displayTask(TaskElements);
}

void User_Task::AddTask() {
    Manage_Task::addTask(TaskElements);
}

void User_Task::EditTask() {
    Manage_Task::editTask(TaskElements);
}

void User_Task::DeleteTask() {
    Manage_Task::deleteTask(TaskElements);
}

void User_Task::SortTask(int SortType, int SortOrder) {
    Manage_Task::sortTask(TaskElements, SortType, SortOrder);
}

void User_Task::SearchTask(vector<Manage_Task::TaskType>& TaskFound, int SearchType) {
    Manage_Task::searchTask(TaskElements, TaskFound, SearchType);
}











