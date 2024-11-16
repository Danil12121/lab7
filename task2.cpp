#include <string>
#include <vector>
#include <fstream>

struct Book
{
    std::string Author;
    std::string Title;
    int Year;
};

void saveToFile(const std::string& filename, const std::vector<Book>& data){
    std::ofstream out;
    out.open(filename, std::ios::out);
    for (const Book& b: data)
        out << b.Author << " " << b.Title << " " << b.Year << std::endl;
    out.close();
}

void loadFromFile(const std::string& filename, std::vector<Book>& outData){
    std::ifstream in;
    in.open(filename, std::ios::in);
    std::string buf, buf2, buf3;
    while (in >> buf >> buf2 >> buf3){
        Book b = {buf, buf2, std::stoi(buf3)};
        outData.push_back(b);
    }
    in.close();
}