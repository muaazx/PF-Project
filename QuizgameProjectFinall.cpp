#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <conio.h>

using namespace std;
using namespace chrono;

int Q_NO = 1;
int CORRECT = 0;
int WRONG = 0;
bool ask[15] = {true, true, true, true, true, true, true, true, true, true, true, true, true, true, true};
auto start_time = system_clock::now();
 int TIME_LIMIT = 200;

void welcome_message();
void display();
void question(const string& question, const string& a, const string& b, const string& c, const string& d, char correct_answer);
void result();
bool is_time_remaining();

int main() {
    welcome_message();
    start_time = system_clock::now();
    display();
    return 0;
}

void welcome_message() {
    cout << "======================================" << endl;
    cout << "   Welcome to the C++ Quiz Program!   " << endl;
    cout << "======================================" << endl << endl;
    cout << "Test your knowledge of programming basics!" << endl;
    cout << "You will be asked 15 questions, one by one." << endl;
    cout << "For each question, type the letter corresponding to the correct answer (A, B, C, or D)." << endl;
    cout << "You have 5 minutes to complete the quiz. Good luck!" << endl << endl;
    cout << "Press any key to start the test..." << endl;
    _getch(); // Wait for user to start
    system("cls");
}

void display() {
    system("cls");
    cout << "Question NO: " << Q_NO << "\t\tCorrect Answers: " << CORRECT << "\t\tWrong Answers: " << WRONG << endl;

    int time_remaining = TIME_LIMIT - duration_cast<seconds>(system_clock::now() - start_time).count();
    if (time_remaining > 0) {
        cout << "Time Remaining: " << time_remaining << " seconds" << endl << endl;
    } else {
        cout << "\nTime's up!" << endl;
        result();
        return;
    }


    for (int i = 0; i < 15; i++) {
        if (ask[i]) {
            ask[i] = false;
            switch (i) {
                case 0:
                    question("1. Which language supports the Object Oriented Programming Technique?", "C language", "C++ language", "Cobal language", "Fortran Language", 'b');
                    break;
                case 1:
                    question("2. What is a variable?", "An empty container in which we store data", "box", "Data type", "language", 'a');
                    break;
                case 2:
                    question("3. Which of the following is a high-level programming language?", "C", "C++", "Java", "Machine code", 'c');
                    break;
                case 3:
                    question("4. What does OOP stand for?", "Object Oriented Programming", "Object Option Programming", "Open Operated Programming", "Other Operation Programming", 'a');
                    break;
                case 4:
                    question("5. Which of these is not a loop structure in programming?", "for", "while", "until", "do-while", 'c');
                    break;
                case 5:
                    question("6. What is the main function in C++?", "main()", "start()", "begin()", "init()", 'a');
                    break;
                case 6:
                    question("7. Which is the correct syntax for declaring a variable in C++?", "int x;", "int x = 5;", "x int;", "int x 5;", 'b');
                    break;
                case 7:
                    question("8. What is polymorphism in OOP?", "Ability to create multiple objects", "Ability to hide data", "Ability to take many forms", "None of the above", 'c');
                    break;
                case 8:
                    question("9. What does HTML stand for?", "HyperText Markup Language", "HyperText Machine Language", "HighText Markup Language", "None of the above", 'a');
                    break;
                case 9:
                    question("10. Which language is primarily used for web development?", "C", "Python", "HTML", "Java", 'c');
                    break;
                case 10:
                    question("11. What is inheritance in OOP?", "Ability of a class to use methods of another class", "Ability to inherit rights", "Sharing data between two programs", "None of the above", 'a');
                    break;
                case 11:
                    question("12. Which of the following is an example of an IDE?", "Notepad", "Eclipse", "Notepad++", "Terminal", 'b');
                    break;
                case 12:
                    question("13. What is an array?", "A data structure to store multiple values", "A type of loop", "A method", "A function", 'a');
                    break;
                case 13:
                    question("14. Which of the following is used to define a constant in C++?", "const", "let", "define", "constant", 'a');
                    break;
                case 14:
                    question("15. What does the 'cin' keyword do in C++?", "Output data", "Input data", "Control flow", "Define a variable", 'b');
                    break;
            }
            break;
        }
    }
    result();
}

void question(const string& question, const string& a, const string& b, const string& c, const string& d, char correct_answer) {
    cout << question << endl;
    cout << "a.\t" << a << endl;
    cout << "b.\t" << b << endl;
    cout << "c.\t" << c << endl;
    cout << "d.\t" << d << endl;

    char answer;
    cin >> answer;
    if (tolower(answer) == correct_answer)
        CORRECT++;
    else
        WRONG++;

    Q_NO++;
    display();
}

void result() {
    system("cls");
    cout << "======================================" << endl;
    cout << "              Quiz Results            " << endl;
    cout << "======================================" << endl;
    cout << "Total Questions = " << Q_NO - 1 << endl;
    cout << "Correct Answers = " << CORRECT << endl;
    cout << "Wrong Answers = " << WRONG << endl;
    if (CORRECT > WRONG)
        cout << "Result = PASS" << endl;
    else if (WRONG > CORRECT)
        cout << "Result = FAIL" << endl;
    else
        cout << "Result = Tie" << endl;
    cout << "======================================" << endl;
    cout << "Thank you for taking the quiz! Press any key to exit..." << endl;
    getch();
}

bool is_time_remaining() {
    int elapsed_time = duration_cast<seconds>(system_clock::now() - start_time).count();
    return elapsed_time < TIME_LIMIT;
}
