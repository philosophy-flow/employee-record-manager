#include <iostream>
#include <string>

using namespace std;

int main() {
    /*
    Creates an Employee base class with a name member + id member.
    Also includes a method that welcomes the user to the program.

    Protected members are initialized via the constructor when an instance of
    the class is created.
    */
    class Employee {
       protected:
        string name;
        string password;

       public:
        int id;

        void logoutUser() {
            cout
                << "Thank you for using the program, and have a wonderful day!";
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

        Employee(string userName, int userId, string userPassword) {
            name = userName;
            id = userId;
            password = userPassword;
        }
    };

    // Creates a HumanResources subclass that extends the Employee class.
    class HumanResources : public Employee {
       public:
        void welcomeUser() {
            cout << "Hello, " << name << " - welcome to the Program." << endl;
            cout << "Your permission level is: HUMAN RESOURCES (ADMIN)."
                 << endl;
        }

        void displayMenu() {
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
        void welcomeUser() {
            cout << "Hello, " << name << " - welcome to the Program." << endl;
            cout << "Your permission level is: MANAGEMENT." << endl;
        }

        void displayMenu() {
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
        void welcomeUser() {
            cout << "Hello, " << name << " - welcome to the Program." << endl;
            cout << "Your permission level is: EMPLOYEE." << endl;
        }

        void displayMenu() {
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
    static HumanResources hrDirector("Hannah", 1552, "pass123");
    static Management midLevelManager("Michael", 2461, "pass456");
    static GeneralEmployee associate("Gillian", 7717, "pass789");
    Employee* employeeArray[3] = {&hrDirector, &midLevelManager, &associate};

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

    // Clears any errors from first input and prepare cin for second input
    cin.clear();
    cin.ignore(1000, '\n');

    // Gets password input from user
    string userPassword;
    cout << "Enter your password: ";
    getline(cin, userPassword);
    cout << endl;

    /*
    Searches existing employee IDs and attempts to match user input.
    If ID match, then validates the password. Else, alerts user.
    */

    bool userFound = false;
    for (Employee* employee : employeeArray) {
        if (employee->id == userId) {
            userFound = true;
            cout << "password validation here" << endl;
            // validate password here
            break;
        }
    }
    if (!userFound) {
        cout << "Employee not found. Please enter another ID." << endl;
    }

    // Program should start, welcome the user, and request login
    // credentials. Depending on user type, different options should be
    // displayed. Each option will correspond to a method on the subclass.

    return 0;
}
