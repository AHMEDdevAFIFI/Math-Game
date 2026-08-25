#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

enum enQuestionLevel {Easy = 1, Medium, Hard, MixLvl};
enum enOperationType {Add  = 1, Sub, Multi, Divid, MixOp};

struct  stQuestion
{
    int Number1 = 0;
    int Number2 = 0;
    enQuestionLevel QuestionLevel;
    enOperationType OpType;
    int PlayerAnswer = 0;
    int CorrectAnswer = 0;
    bool AnswerResult = false;

};

struct  stQuizz
{
    stQuestion Questions[100];
    short NumberOfQuestion;
    enQuestionLevel QuestionsLevel;
    enOperationType OperationType;
    short NumberOfCorrectAnswers = 0;
    short NumberOfWrongAnswers = 0;
    bool isPass = false;

};

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

int ReadHowManyQuestons()
{
    short HowManyQuestons = 0;
    do
    {
        cout << "How Many Questions Do You Want [1:100]?";
        cin >> HowManyQuestons;
    } while (HowManyQuestons < 1 || HowManyQuestons > 100);

    return HowManyQuestons;
    
}

int main()
{
    srand(time(0));


    return 0;
}