#include <iostream>
#include <fstream>
#include <string>

const int MAX_RECORDS = 10; // максимальное количество записей

struct TestResult {
    std::string student_name;
    std::string subject;
    int num_questions;
    int num_correct_answers;
};

int main() {
    // Step 1: Read subject from console
    std::string subject;
    std::cout << "Enter subject: ";
    std::cin >> subject;

    // Step 2: Open file
    std::ifstream file("test.txt");
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    // Step 3: Read data from file and store in array of TestResult structures
    TestResult test_results[MAX_RECORDS];
    int i = 0;
    std::string student_name;
    std::string test_subject;
    int num_questions, num_correct_answers;
    while (file >> student_name >> test_subject >> num_questions >> num_correct_answers) {
        if (i == MAX_RECORDS) {
            break; // ограничиваем количество записей до максимального значения
        }
        test_results[i++] = TestResult{student_name, test_subject, num_questions, num_correct_answers};
    }

    // Step 4: Filter records by subject
    bool found_records = false;
    for (int j = 0; j < i; j++) {
        if (test_results[j].subject == subject) {
            found_records = true;
            // Step 5: Find students who answered all questions correctly
            if (test_results[j].num_correct_answers == test_results[j].num_questions) {
                std::cout << test_results[j].student_name << " answered all questions correctly." << std::endl;
            }
        }
    }
    if (!found_records) {
        std::cerr << "Error: no records found for subject " << subject << std::endl;
        return 1;
    }


    return 0;
}


Иванов Математика 10 10
Петров История 8 8
Сидоров Математика 10 8
Смирнов История 8 6
Кузнецов Математика 10 10
Козлов История 8 8
Васильев Математика 10 10
Попов История 8 8
Соколов Математика 10 10
Морозов История 8 7