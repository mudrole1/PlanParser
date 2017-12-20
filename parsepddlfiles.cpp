#include "parsepddlfiles.h"

/*
 * splitting a strign by spaces to separate words
 */
std::vector<std::string> splitLine(std::string s)
{
    std::vector<std::string> words;
    std::istringstream iss(s);
    for(std::string s; iss >> s;)
    {
        words.push_back(s);
    }

    return words;
}

int brackets(std::string line, int opened_bracket)
{
    //important: this doesnt really handle the case ".....)(...."
    size_t index = line.find("(");
    while (index != std::string::npos)
    {
        opened_bracket++;
        index = line.find("(", index+1);
    }
    index = line.find(")");
    while (index != std::string::npos)
    {
        opened_bracket--;
        index = line.find(")", index+1);
    }
    return opened_bracket;
}

void parseType(std::vector<std::shared_ptr<Type>> * types, std::vector<std::string> words)
{

    //take the last word - that is the type
    if((words.end()-1)->find("object")!=std::string::npos) //it is main general type
    {
        unsigned int index = types->size();
        types->push_back(std::shared_ptr<Type>(new Type("object",nullptr)));


        for(unsigned int i=0; i< words.size(); i++)
        {
            if(words.at(i).find("types")!=std::string::npos)
                continue;
            if(words.at(i).find("-")!=std::string::npos)
                break;
            types->push_back(std::shared_ptr<Type>(new Type(words.at(i),types->at(index))));
        }
    }
    else
    {
        //the type is already saved, find the index
        for(int i=types->size()-1;i>0;i--)
        {
            if((words.end()-1)->find(types->at(i)->getName())!=std::string::npos)
            {
                for(unsigned int j=0; j< words.size(); j++)
                {
                    if(words.at(j).find("types")!=std::string::npos)
                        continue;
                    if(words.at(j).find("-")!=std::string::npos)
                        break;
                    types->push_back(std::shared_ptr<Type>(new Type(words.at(j),types->at(i))));
                }
                break; //we found it
            }
        }
    }
}

void ParsePDDLfiles::parseDomain(std::string domain_file)
{
    std::string line;
    std::ifstream file_in;;

    file_in.open(domain_file.c_str());

    std::vector<std::shared_ptr<Type>> types;

    if (file_in.is_open())
    {
        while ( getline (file_in,line) )
        {
            //splitting line by spaces
            std::vector<std::string> words = splitLine(line);
            if(words.size()==0)
            {
                continue;
            }

            //get types
            if(words.at(0) == "(:types")
            {
                while(line.find(")")==std::string::npos)
                {
                    parseType(&types, words);
                    do
                    {
                        getline(file_in,line);
                        words = splitLine(line);

                    } while(words.size()==0);
                }
                parseType(&types,words);
            }

        }//end while ( getline (file_in,line) )
    }//(file_in.is_open())
    for(unsigned int i=0; i< types.size();i++)
    {
        std::cout << types.at(i)->getName() << "\n";
    }

}
