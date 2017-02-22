#include <iostream>
#include <cstdio>

#include "../list.h"

using namespace std;


class Info
{
public:
    Info(uint32_t id, const string &name)
        : id_(id), name_(name)
    {
    }

private:
    uint32_t id_;
    string name_;
    struct list_head node_;
}



int main()
{
    Info info(1, "hello1");

    struct list_head *head = &(info->node);


    return 0;
}
