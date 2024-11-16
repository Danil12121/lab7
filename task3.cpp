#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

enum Score
{
    Unsatisfactorily = 2,
    Satisfactorily,
    Good,
    Excellent
};

struct Student
{
    std::string Name;
    int Year;
    std::map<std::string, Score> RecordBook;
};

// в качестве ключа - название группы
// в качестве значения - список студентов
using Groups = std::map<std::string, std::vector<Student>>;

void saveToFile(const std::string& filename, const Groups& groups){
    std::ofstream out;
    out.open(filename, std::ios::out);
    for (std::pair<const std::string, std::vector<Student>> g: groups){
        out <<g.first << " " << g.second.size()<< std::endl;
        for (Student s: g.second){
            out << s.Name << " " << s.Year << " " << s.RecordBook.size() << " ";
            for (std::pair<std::string, Score> p: s.RecordBook)
                out << p.first << " " << p.second << " ";
            out << std::endl;
        }

    }
    out.close();
}

void loadFromFile(const std::string& filename, Groups& outGroups){
    std::ifstream in;
    in.open(filename, std::ios::in);
    std::string group_name, n;
    while (in >> group_name >> n){
        std::vector<Student> students;
        std::map<std::string, Score> p;
        for (int i = 0; i < stoi(n); i++){
            Student s; int n_mark;
            in >> s.Name >> s.Year >> n_mark;
            for (int j = 0; j < n_mark; j++){
                std::string name; int mark;
                in >> name >> mark;
                p[name] = static_cast<Score>(mark);
            }
            s.RecordBook = p;
            students.push_back(s);
        }
        outGroups[group_name] = students;
    }
    in.close();
}