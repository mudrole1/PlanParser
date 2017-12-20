#include <iostream>
#include <parsepddlfiles.h>

int main(int argc, char *argv[])
{
    ParsePDDLfiles::parseDomain("/home/lenka/PostDoc/POPMER/testing_files/durative/domains/driverlog/exp.pddl");
    std::cout << "f";
}
