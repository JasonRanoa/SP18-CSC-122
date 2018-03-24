//
// Created by TheLoneWoof on 3/22/18.
//

#ifndef CH19_PR8_EMPLOYEE_TREE_EMPLOYEEINFO_H
#define CH19_PR8_EMPLOYEE_TREE_EMPLOYEEINFO_H

#include <string>

class EmployeeInfo {

private:
    int EmpID;
    std::string EmpName;

public:
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

// Overloaded Operators for Binary Tree Template
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
