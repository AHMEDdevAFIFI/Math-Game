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
    stQuestion QuestionsList[100];
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

enOperationType ReadOperationType()
{
    short OpType;
    do
    {
        cout << "Enter The Operation [1]Add+ [2]Sub- [3]Multi* [4]Divid/ [5]MixOp?";
        cin >> OpType;
    } while (OpType < 1 || OpType > 5);
    
    return (enOperationType) OpType;
}

enQuestionLevel ReadQuestionLvl()
{
    short QuestionLvl;
    do
    {
        cout << "Enter The Level [1]Easy [2]Medium [3]Hard [4]MixLvl ?";
        cin >> QuestionLvl;
    } while (QuestionLvl < 1 || QuestionLvl > 4);
    
    return (enQuestionLevel) QuestionLvl;
}

enOperationType GetRandomOperationType()
{
    return (enOperationType) RandomNumber(1, 4);
}

int SimpleCalculator(int Number1, int Number2, enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add:
        return Number1 + Number2;
        break;

    case enOperationType::Sub:
        return Number1 - Number2;
        break;

    case enOperationType::Multi:
        return Number1 * Number2;
        break;

    case enOperationType::Divid:
        return Number1 / Number2;
        break;    
    
    default:
        return Number1 + Number2;
        break;
    }
}

stQuestion GenerateQuestion(enOperationType OpType, enQuestionLevel QuesetionLvl)
{
    stQuestion Question;

    if(QuesetionLvl == enQuestionLevel::MixLvl)
    {
        QuesetionLvl = (enQuestionLevel) RandomNumber(1, 3);
    }

    if(OpType == enOperationType::MixOp)
    {
        OpType =  GetRandomOperationType();
    }

    Question.OpType = OpType;

    switch (QuesetionLvl)
    {
    case  enQuestionLevel::Easy:
        Question.Number1 = RandomNumber(1, 10);
        Question.Number2 = RandomNumber(1, 10);

        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, OpType);
        Question.QuestionLevel = QuesetionLvl;
        break;

    case  enQuestionLevel::Medium:
        Question.Number1 = RandomNumber(10, 50);
        Question.Number2 = RandomNumber(10, 50);

        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, OpType);
        Question.QuestionLevel = QuesetionLvl;
        break;    
    
        case  enQuestionLevel::Hard:
        Question.Number1 = RandomNumber(50, 100);
        Question.Number2 = RandomNumber(50, 100);

        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, OpType);
        Question.QuestionLevel = QuesetionLvl;
        break;
   
    }

    return Question;
}

void GenerateQuizzQuestioins(stQuizz &Quizz)
{
    for(int Question = 0; Question < Quizz.NumberOfQuestion; Question++)
    {
        Quizz.QuestionsList[Question] = GenerateQuestion(Quizz.OperationType, Quizz.QuestionsLevel);
    }
}

int main()
{
    srand(time(0));


    return 0;
}