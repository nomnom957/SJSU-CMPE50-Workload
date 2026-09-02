//============================================================================
// Name        : CMPE50-Lab-10.1.cpp
// Author      : Ivan Rybenko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "employee.h"
#include "salariedemployee.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

class Administrator : public SalariedEmployee {
public:
    Administrator()
        : SalariedEmployee(), admin_title(""), admin_area(""), supervisor_name(""), annual_salary(0.0) {
        set_salary(0.0);
    }

    Administrator(const string& the_name,
                  const string& the_ssn,
                  double annual,
                  const string& the_title,
                  const string& the_area,
                  const string& the_supervisor)
        : SalariedEmployee(the_name, the_ssn, annual / 52.0),
          admin_title(the_title), admin_area(the_area), supervisor_name(the_supervisor), annual_salary(annual) {}

    void set_supervisor(const string& new_supervisor) {
        supervisor_name = new_supervisor;
    }

    void set_title(const string& t) { admin_title = t; }
    void set_area(const string& a) { admin_area = a; }
    void set_annual_salary(double a) { annual_salary = a; set_salary(a / 52.0); }

    const string& get_title() const { return admin_title; }
    const string& get_area() const { return admin_area; }
    const string& get_supervisor() const { return supervisor_name; }
    double get_annual_salary() const { return annual_salary; }

    void read_administrator(istream& in = cin) {
        string tmp;
        double a = 0.0;

        if (&in == &cin) cout << "Enter name: ";
        getline(in, tmp);
        if (tmp.size() == 0) getline(in, tmp);
        set_name(tmp);

        if (&in == &cin) cout << "Enter SSN: ";
        getline(in, tmp);
        set_ssn(tmp);

        if (&in == &cin) cout << "Enter annual salary: ";
        in >> a;
        in.ignore(numeric_limits<streamsize>::max(), '\n');
        set_annual_salary(a);

        if (&in == &cin) cout << "Enter title: ";
        getline(in, admin_title);

        if (&in == &cin) cout << "Enter area: ";
        getline(in, admin_area);

        if (&in == &cin) cout << "Enter supervisor: ";
        getline(in, supervisor_name);
    }

    void print(ostream& out = cout) const {
        out << "Administrator Information\n";
        out << "Name: " << get_name() << "\n";
        out << "SSN: " << get_ssn() << "\n";
        out << "Title: " << admin_title << "\n";
        out << "Area: " << admin_area << "\n";
        out << "Supervisor: " << supervisor_name << "\n";
        out << fixed << setprecision(2);
        out << "Annual Salary: $" << annual_salary << "\n";
        out << "Weekly Equivalent: $" << get_salary() << "\n\n";
    }

    void print_check() {
        double pay = annual_salary / 52.0;
        set_net_pay(pay);
        cout << "\n__________________________________________________\n";
        cout << "Pay to the order of " << get_name() << "\n";
        cout << "The sum of " << fixed << setprecision(2) << get_net_pay() << " Dollars\n";
        cout << "_________________________________________________\n";
        cout << "Check Stub NOT NEGOTIABLE \n";
        cout << "Employee Number: " << get_ssn() << "\n";
        cout << "Administrator: " << admin_title << " (" << admin_area << ")\n";
        cout << "Supervisor: " << supervisor_name << "\n";
        cout << "Regular Pay (weekly): " << fixed << setprecision(2) << pay << "\n";
        cout << "_________________________________________________\n";
    }

protected:
    string admin_title;
    string admin_area;
    string supervisor_name;
    double annual_salary;
};

int main() {
    Administrator admin("Alice Admin", "123-45-6789", 130000.00, "Director", "Accounting", "Bob Boss");
    cout << "Initial data:\n";
    admin.print(cout);

    admin.set_supervisor("Carol Chief");
    admin.set_title("Vice President");
    admin.set_area("Finance");
    admin.set_annual_salary(156000.00);

    cout << "After updates:\n";
    cout << "Title: " << admin.get_title() << "\n";
    cout << "Area: " << admin.get_area() << "\n";
    cout << "Supervisor: " << admin.get_supervisor() << "\n";
    cout << fixed << setprecision(2) << "Annual Salary: $" << admin.get_annual_salary() << "\n\n";

    admin.print(cout);
    cout << "Administrator paycheck:\n";
    admin.print_check();
    return 0;
}

/*
Initial data:
Administrator Information
Name: Alice Admin
SSN: 123-45-6789
Title: Director
Area: Accounting
Supervisor: Bob Boss
Annual Salary: $130000.00
Weekly Equivalent: $2500.00

After updates:
Title: Vice President
Area: Finance
Supervisor: Carol Chief
Annual Salary: $156000.00

Administrator Information
Name: Alice Admin
SSN: 123-45-6789
Title: Vice President
Area: Finance
Supervisor: Carol Chief
Annual Salary: $156000.00
Weekly Equivalent: $3000.00

Administrator paycheck:

__________________________________________________
Pay to the order of Alice Admin
The sum of 3000.00 Dollars
_________________________________________________
Check Stub NOT NEGOTIABLE
Employee Number: 123-45-6789
Administrator: Vice President (Finance)
Supervisor: Carol Chief
Regular Pay (weekly): 3000.00
_________________________________________________
 */
