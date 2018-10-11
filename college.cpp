/************************************
This file defines the class college. 
College
************************************/
/** @file */



#include "college.h"
#include <iostream>
#include <fstream>
#include <string>
#include "course.h"
#include "node.h"

college::college(std::string username)
{
    name = username;
    head = NULL;//ctor
}
college::college(const college& original)
{
    name=original.get_name();
    head=new node;
    node* tempcopy=NULL;
    node* temporiginal=original.get_head();
    while(temporiginal!=NULL)
    {
        if(tempcopy==NULL)
        {
            head->set_data(temporiginal->data());
            temporiginal=temporiginal->link();
            tempcopy=head;
            head->set_link(NULL);
        }
        else
        {
            tempcopy->set_link(new node);
            tempcopy=tempcopy->link();
            tempcopy->set_data(temporiginal->data());
            temporiginal=temporiginal->link();
            tempcopy->set_link(NULL);
        }
    }
}


std::string college::get_name()const
{
    return name;
}

node* college::get_head()const
{
    return head;
}

void college::load(std::istream& ins)
{
    node* temp = head;
    course c;
    getline(ins, name);
    while(!ins.eof())
    {
        if(ins.peek()== '\n' || ins.peek() == '\r'){ins.ignore();}
        c.input(ins);
        add(c);
    }
    return;
}
void college::save(std::ostream& outs)
{
    outs<<name;
    node* cursor=head;
    while(cursor!=NULL)
    {
        cursor->data().output(outs);
        cursor=cursor->link();
    }
    return;
}
void college::add(course c)
{
    node* cursor=head;
    node* temp;
    node* addptr;
    if(head==NULL)
    {
        head=new node;
        head->set_data(c);
        head->set_link(NULL);
        return;
    }
    else
    {
        while(cursor!=NULL)
        {
            if(cursor->data()==c)
            {
                std::cout<<"This course is already in the list."<<std::endl;
                return;
            }
            else if(cursor->data()>c)
            {
                if(cursor==head)
                {
                    temp=head;
                    head=new node;
                    head->set_data(c);
                    head->set_link(temp);
                    return;
                }
                else
                {
                    temp->set_link(new node);
                    temp=temp->link();
                    temp->set_data(c);
                    temp->set_link(cursor);
                    return;
                }
            }
            else if(cursor->link()==NULL)
            {
                cursor->set_link(new node);
                cursor=cursor->link();
                cursor->set_link(NULL);
                return;
            }
            else
            {
                temp=cursor;
                cursor=cursor->link();
            }
        }
    }
}
void college::remove(std::string target)
{
    node* cursor=head;
    node* rmptr;
    while(cursor!=NULL)
    {
         if(cursor->data().get_course_number()==target)
        {
            if(cursor==head)
            {
                head=head->link();
                delete cursor;
                return;
            }
            else
            {
                rmptr->set_link(cursor->link());
                delete cursor;
                return;
            }
        }
        else
        {
            rmptr=cursor;
            cursor=cursor->link();
        }
    }
    return;
}
void college::display(std::ostream& outs)
{
    node* temp=head;
    while(temp!=NULL)
    {
        temp->data().output(outs);
        temp=temp->link();
    }
    return;
}
double college::hours()
{
    double total=0;
    node* temp=head;
    while(temp!=NULL)
    {
        total+=temp->data().get_hours();
        temp=temp->link();
    }
    return total;
}
double college::gpa()
{
    double totalhours=0;
    double points=0;
    double average=0;
    node* temp=head;
    while(temp!=NULL)
    {
        points += temp->data().get_hours() * temp->data().get_number_grade();
        totalhours+=temp->data().get_hours();
        temp=temp->link();
    }
    if(totalhours!=0)
    {
        average=points/totalhours;
    }
    return average;
}

college::~college()
{
    node* temp=head;
    while(temp!=NULL)
    {
        temp=temp->link();
        delete head;
        head=temp;
    }
}
