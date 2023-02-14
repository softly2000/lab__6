#include <iostream>
#include <fstream>
using namespace std;

struct Question {
    string text;
    string answers[3];
    int correct_answer;
    int chosen_answer;
};

int main() {
    string filename = "test.txt";
    ifstream infile(filename);

    string subject, date, direction;
    getline(infile, subject);
    getline(infile, date);
    getline(infile, direction);

    Question questions[3];
    for (int i = 0; i < 3; i++) {
        getline(infile, questions[i].text);
        for (int j = 0; j < 3; j++) {
            getline(infile, questions[i].answers[j]);
        }
        infile >> questions[i].correct_answer;
        infile.ignore(1);
    }
    infile.close();

    int num_correct = 0;
    cout << "Предмет: " << subject << endl;
    cout << "Дата: " << date << endl;
    cout << "Направление: " << direction << endl;
    for (int i = 0; i < 3; i++) {
        cout << endl << questions[i].text << endl;
        for (int j = 0; j < 3; j++) {
            cout << j + 1 << ". " << questions[i].answers[j] << endl;
        }
        cout << "Введите номер выбранного ответа: ";
        cin >> questions[i].chosen_answer;
        if (questions[i].chosen_answer == questions[i].correct_answer) {
            num_correct++;
        }
    }

    cout << endl << "Результат теста: " << num_correct << " из 3 правильных ответов." << endl;

    return 0;
}



Мат
22.22.22
BN-11
Вопрос1
Ответ1
Ответ2
Ответ3
3
Вопрос2
Ответ1
Ответ2
Ответ3
1 
Вопрос3
Ответ1
Ответ2
Ответ3
1 
