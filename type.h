#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <memory>

class Type
{
    std::string name_;
    std::shared_ptr<Type> type_;
public:
    Type(std::string);
    Type(std::string, std::shared_ptr<Type>);
    std::string getName();

    void setName(std::string);
};

#endif // TYPE_H
