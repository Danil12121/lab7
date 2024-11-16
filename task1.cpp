#include <string>
#include <vector>
#include <fstream>

void saveToFile(const std::string& filename, const std::vector<std::string>& data){
    std::ofstream out;
    out.open(filename, std::ios::out);
    for (const std::string& word: data)
        out << word << std::endl;
    out.close();
}

void loadFromFile(const std::string& filename, std::vector<std::string>& outData){
    std::ifstream in;
    in.open(filename, std::ios::in);
    std::string buf;
    while (in >> buf)
        outData.push_back(buf);
    in.close();
}