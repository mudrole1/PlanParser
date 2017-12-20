#ifndef TERM_H
#define TERM_H

#include <type.h>
#include <string>


class Term
{
private:
    std::string name_;
    Type type_;
public:
    Term(std::string, Type);
};

#endif // TERM_H
