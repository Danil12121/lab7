#include <iostream>
#include "header.hpp"

const std::string filename1 = "test.txt";
const std::string filename2 = "test2.txt";
const std::string filename3 = "test3.txt";
int main() {
    std::vector<std::string> v = {"house", "black", "lift", "index", "enjoy", "animal"};
    saveToFile(filename1, v);
    std::vector<std::string> v2;
    loadFromFile(filename1, v2);
    for (const std::string& word: v2)
        std::cout << word << " "; //task1
    std::cout << std::endl;
    std::cout << std::endl;


    Book
    b1 = {"Golding", "Lord", 1954},
    b2 = {"King", "It", 1986},
    b3 = {"Orwell", "1984", 1949},
    b4 = {"Bradbury", "Fahrenheit", 1953},
    b5 = {"Heller", "Catch", 1961};

    std::vector<Book> v3 = {b1, b2, b3, b4, b5};
    saveToFile(filename2, v3);
    std::vector<Book> v4;
    loadFromFile(filename2, v4);
    for (const Book& b: v4)
        std::cout << b.Author << " " << b.Title << " " << b.Year << std::endl; //task2
    std::cout << std::endl;


    Student
    s1 = {"Dan", 1, {std::pair{"m", Excellent}, std::pair{"r", Good}}},
    s2 = {"Ben", 3, {std::pair{"m", Good}}},
    s3 = {"Alise", 1, {std::pair{"m", Excellent}, std::pair{"r", Excellent}, std::pair{"ch", Excellent}}},
    s4 = {"Mary", 2, {std::pair{"r", Satisfactorily}, std::pair{"m", Unsatisfactorily}}};

    std::vector<Student> v5 = {s1, s4};
    std::vector<Student> v6 = {s2, s3};
    Groups g1 = {std::pair{"group1", v5}, std::pair{"group2", v6}};

    saveToFile(filename3, g1);
    Groups g2;
    loadFromFile(filename3, g2);
    for(std::pair<std::string, std::vector<Student>> p : g2) {
        std::cout << p.first << std::endl;
        for (const Student& s: p.second) {
            std::cout << s.Name << " " << s.Year << " ";
            for (std::pair<std::string, Score> mark: s.RecordBook) {
                std::cout << mark.first << " " << mark.second << " ";
            }
            std::cout << std::endl;
        }
    }
        return 0;
}
