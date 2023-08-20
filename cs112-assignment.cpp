/* H **********************************************************************
 * FILENAME: cs112-assignment.cpp
 *
 * DESCRIPTION:
 *      This is a simple employee management system.The user can enter an ID /
 *      password, and if successfully validated access a number of options based
 *      on their permission level.
 *
 * CLASSES:
 *      Employee (base class)
 *          -- ID, name, and password members
 *          -- informational methods (welcome, standby, logout)
 *          -- shared methods (view, search, validate)
 *      HumanResources (derived class)
 *          -- specific methods (add, modify, delete) & menu method
 *      Management (derived class)
 *          -- menu method
 *      GeneralEmployee (derived class)
 *          -- overriden methods (view, search) & menu method
 *
 * FUNCTIONS:
 *  validateEmployee:
 *      This function takes an array of Employee pointers and the length of the
 *      array (employee count). The function prompts the user for an ID /
 *      password and then checks the input against each employee's data.
 *
 * AUTHOR: Jacob Stewart
 * START DATE: 08/19/23
 * H *********************************************************************/

#include <iostream>
#include <string>
using namespace std;

/*
Creates an Employee base class with a name member + id member.
Also includes a number of methods shared across some subclasses.

Protected members are initialized via the constructor when an instance of
the class is created.
*/
class Employee {
   protected:
    string name;
    string password;

   public:
    int id;

    bool validatePassword(string userInput) { return userInput == password; }

    void welcomeUser(string permissionLevel) {
        cout << "Hello, " << name << " - welcome to the Program." << endl;
        cout << "Your permission level is: " << permissionLevel << endl;
    }

    void logoutUser() {
        cout << "Thank you for using the program, and have a wonderful day!"
             << endl;
    }

    void standbyMessage() {
        cout << "Please standby for more options, or press (6) to exit the "
                "program."
             << endl;
    }

    void viewRecord() {
        cout << "Gathering information for selected employee." << endl;
        standbyMessage();
    }

    void searchRecords() {
        cout << "Gathering all employee records." << endl;
        standbyMessage();
    }

    virtual void displayMenu() {}

    Employee(string userName, int userId, string userPassword) {
        name = userName;
        id = userId;
        password = userPassword;
    }
};

// Creates a HumanResources subclass that extends the Employee class.
class HumanResources : public Employee {
   public:
    void displayMenu() {
        Employee::welcomeUser("HUMAN RESOURCES (ADMIN).");
        cout << "--------" << endl;
        cout << "Select an option by pressing the corresponding key on "
                "your keyboard:"
             << endl;
        cout << "(1) | View Selected Employee Record" << endl;
        cout << "(2) | Search Employee Records " << endl;
        cout << "(3) | Add Employee Record" << endl;
        cout << "(4) | Modify Selected Employee Record" << endl;
        cout << "(5) | Delete Selected Employee Record" << endl;
        cout << "(6) | Logout & Exit Program" << endl;
        cout << "--------" << endl;
    }

    void addRecord() {
        cout << "Booting EmployeeGen Software." << endl;
        standbyMessage();
    }

    void modifyRecord() {
        cout << "Gathering information for modification." << endl;
        standbyMessage();
    }

    void deleteRecord() {
        cout << "Gathering information for deletion." << endl;
        standbyMessage();
    }

    HumanResources(string userName, int userId, string userPassword)
        : Employee(userName, userId, userPassword) {}
};

// Creates a Management subclass that extends the Employee class.
class Management : public Employee {
   public:
    void displayMenu() {
        Employee::welcomeUser("MANAGEMENT");
        cout << "--------" << endl;
        cout << "Select an option by pressing the corresponding key on "
                "your keyboard:"
             << endl;
        cout << "(1) | View Selected Employee Record" << endl;
        cout << "(2) | Search Employee Records " << endl;
        cout << "(6) | Logout & Exit Program" << endl;
        cout << "--------" << endl;
    }

    Management(string userName, int userId, string userPassword)
        : Employee(userName, userId, userPassword) {}
};

// Creates a GeneralEmployee subclass that extends the Employee class.
class GeneralEmployee : public Employee {
   public:
    void displayMenu() {
        Employee::welcomeUser("EMPLOYEE");
        cout << "--------" << endl;
        cout << "Select an option by pressing the corresponding key on "
                "your keyboard:"
             << endl;
        cout << "(1) | View Your Employee Record" << endl;
        cout << "(6) | Logout & Exit Program" << endl;
        cout << "--------" << endl;
    }

    void viewRecord() {
        cout << "Gathering your employee record." << endl;
        standbyMessage();
    }

    void searchRecords() {
        cout << "You are not authorized to search records." << endl;
        standbyMessage();
    }

    GeneralEmployee(string userName, int userId, string userPassword)
        : Employee(userName, userId, userPassword) {}
};

/*
Creates 3 test IDs / passwords for validation demo purposes.
User input will be validated against this static content.
*/
HumanResources hrDirector("Hannah", 1552, "pass123");
Management midLevelManager("Michael", 2461, "pass456");
GeneralEmployee associate("Gillian", 7717, "pass789");
Employee* employeeArray[3] = {&hrDirector, &midLevelManager, &associate};

/*
 Takes an array of employees and validates credentials against user input
 If validation is successful, then an active employee is returned.
*/
Employee* validateUser(Employee* inputArray[], int employeeCount) {
    // Prints introductory program text
    cout << " " << endl;
    cout << "**************************************" << endl;
    cout << "EMPLOYEE MANAGEMENT INFORMATION SYSTEM" << endl;
    cout << "**************************************" << endl;
    cout << " " << endl;

    // Gets ID input from user
    int userId;
    cout << "Enter your Employee ID: ";
    cin >> userId;

    // Clears any errors from first input and prepares cin for second input
    cin.clear();
    cin.ignore(1000, '\n');

    // Gets password input from user
    string userPassword;
    cout << "Enter your password: ";
    getline(cin, userPassword);
    cout << endl;

    /*
    Searches existing employee IDs and attempts to validates input.
    If validation successful proceed. Else alert user and exit program.
    */

    for (int i = 0; i < employeeCount; i++) {
        if (inputArray[i]->id == userId &&
            inputArray[i]->validatePassword(userPassword)) {
            return inputArray[i];
        }
    }
    cout << "Employee ID or password is incorrect." << endl;
    return 0;
}

int main() {
    // Validates and sets active employee
    Employee* activeEmployee = validateUser(
        employeeArray, sizeof(employeeArray) / sizeof(employeeArray[0]));

    // Enters main program loop - user can select an option or close the app
    if (activeEmployee) {
        int selectedOption = 0;
        while (selectedOption != 6) {
            activeEmployee->displayMenu();
            cin >> selectedOption;

            cin.clear();
            cin.ignore(1000, '\n');

            // switch (selectedOption) {
            //     case 1:
            //     case 2:
            //     case 3:
            //     case 4:
            //     case 5:
            //     default:
            // }
        }
        activeEmployee->logoutUser();
    }

    // Program should start, welcome the user, and request login
    // credentials. Depending on user type, different options should be
    // displayed. Each option will correspond to a method on the subclass.

    return 0;
}
