#include <iostream>
#include <fstream>
using namespace std;
struct Question {
    string text;
    string answers[3];
    int correct_answer;
    int chosen_answer;
};

struct Test {
    string subject;
    string date;
    string direction;
    Question questions[3];
};

int main() {
    string filename = "results.txt";
    ifstream infile(filename);
    Test tests[3];
    for (int i = 0; i < 3; i++) {
        getline(infile, tests[i].subject);
        getline(infile, tests[i].date);
        getline(infile, tests[i].direction);

        for (int j = 0; j < 3; j++) {
            string question;
            getline(infile, question);
            tests[i].questions[j].text = question;

            for (int k = 0; k < 3; k++) {
                string answer;
                getline(infile, answer);
                tests[i].questions[j].answers[k] = answer;
            }

            int correct_answer;
            infile >> correct_answer;
            tests[i].questions[j].correct_answer = correct_answer;

            int chosen_answer;
            infile >> chosen_answer;
            tests[i].questions[j].chosen_answer = chosen_answer;

            infile.ignore(1);
        }
    }

    Test* correct_test = nullptr;
    for (int i = 0; i < 3; i++) {
        bool all_correct = true;
        for (int j = 0; j < 3; j++) {
            if (tests[i].questions[j].correct_answer != tests[i].questions[j].chosen_answer) {
                all_correct = false;
                break;
            }
        }
        if (all_correct) {
            correct_test = &tests[i];
            break;
        }
    }

    if (correct_test) {
        cout << "Subject: " << correct_test->subject << endl;
        cout << "Date: " << correct_test->date << endl;
        cout << "Direction: " << correct_test->direction << endl;
        cout << "Result: All answers are correct!" << endl;
    } else {
        cout << "No test with all correct answers found." << endl;
    }
    infile.close();

    return 0;
}



Мат
22.22.22
BN-11
Вопрос1
Ответ1
Ответ2
Ответ3
1 
1
Вопрос2
Ответ1
Ответ2
Ответ3
1 
1
Вопрос3
Ответ1
Ответ2
Ответ3
1 
2
Мат11
22.22.22
BN-11
Вопрос1
Ответ1
Ответ2
Ответ3
1 
1
Вопрос2
Ответ1
Ответ2
Ответ3
1 
1
Вопрос3
Ответ1
Ответ2
Ответ3
1 
1`