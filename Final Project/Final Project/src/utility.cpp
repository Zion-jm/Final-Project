#include "utility.h"


//!!-----Design Functions
void headerDesign(const string& header) {
    cout << setw(211) << setfill('=') << "" << endl;
    cout << right << setw((211 + header.length()) / 2) << setfill(' ') << header << endl;
    cout << setw(211) << setfill('=') << "" << endl;
}

void subHeaderDesign(const string& subHeader) {
    cout << right << setw((211 + subHeader.length()) / 2) << setfill(' ') << subHeader << endl;
    cout << setw(211) << setfill('-') << "" << endl;
}

void lineDesign() {
    cout << setw(211) << setfill('-') << "" << endl;
}

void printOption(const string& option) {
    cout << left << setw(36) << setfill('-') << "" << endl;
    cout << "|" << left << setw(34) << setfill(' ') << option << right << "|" << endl;
    cout << left << setw(36) << setfill('-') << "" << endl;
}


//!!-----Display Functions
void displayCurrentTime() {
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    // Convert to local time
    std::tm* localTime = std::localtime(&now);

    // Print the current local time up to minute precision
    cout << localTime->tm_year + 1900 << '-' // Year
            << setw(2) << std::setfill('0') << localTime->tm_mon + 1 << '-' // Month
            << setw(2) << std::setfill('0') << localTime->tm_mday << ' ' // Day
            << setw(2) << std::setfill('0') << localTime->tm_hour << ':' // Hour
            << setw(2) << std::setfill('0') << localTime->tm_min // Minute
            << endl;
}

void displayUnderDevelopment() {
    cout << "This Section Is Still Under Development. Enter 0 To Go Back." << endl;
}


//!!-----Validation Functions
void clearIgnore() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
int getValidInput(int Min, int Max, const string& prompt) {
    int choice;
    cout << prompt;
    do {
        while(!(cin >> choice)) {
            cout << "Invalid Input! Please Enter An Integer." << endl;
            clearIgnore();
            cout << prompt;
        }
        if(!(choice >= Min && choice <= Max)) {
            cout << "Invalid Input! Please Enter An Integer From " << Min << " - " << Max << endl;
            clearIgnore();
            cout << prompt;
        }
    } while(!(choice >= Min && choice <= Max));
    return choice;
}
















