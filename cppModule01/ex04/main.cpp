//
// Created by Екатерина Акулова on 10.10.2022.
//

#include <string>
#include <iostream>
#include <fstream>

int	main(int ac, char **argv)
{
    if (ac != 4)
    {
        std::cout << "Wrong number of arguments";
        return 0;
    }

    std::string	filename(argv[1]);
    std::string newfilename(filename + ".replace");
    std::string	str;
    std::string	line;
    std::string str2;
    std::string s1(argv[2]);
    int	s1len(s1.size());

    if (!*argv[1] || !*argv[2])
    {
        std::cout << "Wrong argument format";
        return 0;
    }

    std::ifstream	my_file(filename.c_str());
    if (my_file)
    {
        getline(my_file, str);
        while(!my_file.eof())
        {
            getline(my_file, line);
            str = str + '\n' + line;
        }
    }
    else
    {
        std::cout << "Error opening file";
        return 0;
    }
    std::size_t found(str.find(s1));

    while (found != std::string::npos)
    {
        str2.append(str.substr(0, found));
        str2.append(argv[3]);
        str = str.substr(found + s1len);
        found = str.find(s1);
    }

    std::ofstream	new_file(newfilename.c_str());
    if (new_file)
        new_file << str2;
    else
    {
        std::cout << "Error: file not opened!";
    }
    return 0;
}