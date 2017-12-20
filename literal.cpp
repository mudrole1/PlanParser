#include "literal.h"

Literal::Literal(std::string name, std::vector<Term> terms, bool negated)
{
    this->name_ = name;
    this->terms_ = terms;
    this->negated = negated;
}
