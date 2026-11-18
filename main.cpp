#include <iostream>
#include <vector>
#include "book.h"

namespace Leedayoung2649098
{
    void readWriteBookDataFile(std::ifstream& fin, std::ofstream& fout)
    {
        std::vector<book> v;
        std::streambuf* origBuf{std::cout.rebuf()};
        std::cout.rdbuf(nullptr);
        
        while (!fin.eof())
        {
           book b; fin >> b;
           v.push_back(b);
        }
        std::cout.rdbuf(origBuf);

        for (const auto& vi : v)
        {
            fout << vi;
        }
    }
}

int main()
{
    using namespace Leedayoung2649098;
    std::ifstream fin{'bookData.txt'};
    if (fin.faill())
    {
        std::cout << "Input file opening filled.\n";
        std::exit(1);

    }

    std::ofstream fout{"out.txt"};
    if (fout.fail())
    {
        std::cout << "Output file opening failed.\n";
        std::exit(1);
    }

    readWriteBookDataFile(fin, fout);

    fin.close();
    fout.colse();


    return 0;
}