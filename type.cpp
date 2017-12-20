#include "type.h"

Type::Type(std::string name)
{
    this->name_ = name;
}

Type::Type(std::string name, std::shared_ptr<Type> type)
{
    this->name_ = name;
    this->type_ = type;
}

std::string Type::getName()
{
    return name_;
}

void Type::setName(std::string name)
{
    this->name_ = name;
}
