#pragma once

#include "utility.h"

#include <vector>
#include <ctime>
#include <algorithm>
using std::vector;
using std::to_string;
using std::transform;
using std::to_string;

namespace Manage_Task {
    struct TaskType {
        string TaskName;
        string DueMonth;
        string DueDay;
        int PriorityLevel;
    };

    void displayTask(vector<TaskType>& TaskElements);

    void displaySingleTask(vector<TaskType>& TaskElements, int index);

    void addTask(vector<TaskType>& TaskElements);

    void editTask(vector<TaskType>& TaskElements);

    void deleteTask(vector<TaskType>& TaskElements);

    void swapElement(vector<TaskType>& TaskElements, int j);

    void sortTask(vector<TaskType>& TaskElements, int SortType, int SortOrder);

    void searchTask(vector<TaskType>& TaskElements, vector<TaskType>& TaskFound, int SearchType);
}

class User_Task {
public:
    vector<Manage_Task::TaskType> TaskElements;

    void DisplayTask();

    void AddTask();

    void EditTask();

    void DeleteTask();

    void SortTask(int SortType, int SortOrder);

    void SearchTask(vector<Manage_Task::TaskType>& TaskFound, int SearchType);
};











