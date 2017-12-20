#ifndef LITERAL_H
#define LITERAL_H

#include <string>
#include <vector>
#include <term.h>

class Literal
{
private:
    std::string name_;
    std::vector<Term> terms_;
    bool negated;
public:
    Literal(std::string, std::vector<Term>, bool);
};

#endif // LITERAL_H
