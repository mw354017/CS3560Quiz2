#ifndef COLLEGE_H
#define COLLEGE_H
#include <iostream>
#include <fstream>
#include <string>
#include "course.h"
#include "node.h"
class college
{
    public:
        college(std::string userName);
        college(const college& original);
        ~college();
        void load(std::istream& ins);
        void save(std::ostream& outs);
        void add(course c);
        void remove(std::string target);
        void display(std::ostream& outs);
        double hours();
        double gpa();
        std::string get_name()const;
        node* get_head()const;

    private:
        std::string name;
        node* head;
};

#endif
