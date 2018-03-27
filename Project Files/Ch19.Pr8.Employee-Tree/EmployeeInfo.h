//
// Created by TheLoneWoof on 3/22/18.
//

#ifndef CH19_PR8_EMPLOYEE_TREE_EMPLOYEEINFO_H
#define CH19_PR8_EMPLOYEE_TREE_EMPLOYEEINFO_H

#include <string>
#include <iostream>

class EmployeeInfo {

private:
    int EmpID;
    std::string EmpName;

public:
    EmployeeInfo() {
        EmpID = 0;
        EmpName = "";
    }
    EmployeeInfo(int id, std::string name = "") {
        EmpID = id;
        EmpName = name;
    }
    int getID() const {
        return EmpID;
    }
    std::string getName() const {
        return EmpName;
    }


};

/*
 * The following functions are made assuming that each employee
 * will have a unique ID and that two EmployeeInfo objects
 * with the same ID refer to the same employee.
 *
 * THESE ARE HERE JUST TO MAKE THE CLASS WORK WITH THE BINARY TREE.
 * I couldn't make the BinaryTree template to accept a
 * function pointer as argument with the == operator as the default.
 * This is the next best thing.
 */
inline bool operator< (const EmployeeInfo &lhs, const EmployeeInfo &rhs) {
    return ( lhs.getID() < rhs.getID() );
}

inline bool operator> (const EmployeeInfo &lhs, const EmployeeInfo &rhs) {
    return ( lhs.getID() > rhs.getID() );
}

inline bool operator== (const EmployeeInfo &lhs, const EmployeeInfo &rhs) {
    return ( lhs.getID() == rhs.getID() );
}

#endif //CH19_PR8_EMPLOYEE_TREE_EMPLOYEEINFO_H
