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

void ClearScreen()
{
    system("clear");
}

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

int ReadQuestionAnswer()
{
    int Answer = 0;
    cin >> Answer;
    return Answer;
}

string GetOpTypeSymbol(enOperationType OpType)
{
    switch (OpType)
    {
    case enOperationType::Add:
        return "+";
    case enOperationType::Sub:
        return "-";
    case enOperationType::Multi:
        return "*";
    case enOperationType::Divid:
        return "/";
    default:
        return "?";
    }
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

void PrintQuestion(stQuizz &Quizz, short NumberOfQuestion)
{
    cout << "\n";
    cout << "Question [" << NumberOfQuestion + 1 << "/" << Quizz.NumberOfQuestion << "] \n\n";
    cout << Quizz.QuestionsList[NumberOfQuestion].Number1 << endl;
    cout << Quizz.QuestionsList[NumberOfQuestion].Number2 << " ";
    cout << GetOpTypeSymbol(Quizz.QuestionsList[NumberOfQuestion].OpType);
    cout << "\n---------------" << endl;

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
    Question.QuestionLevel = QuesetionLvl;

    switch (QuesetionLvl)
    {
    case  enQuestionLevel::Easy:
        Question.Number1 = RandomNumber(1, 10);
        Question.Number2 = RandomNumber(1, 10);
        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OpType);
        return Question;
        break;

    case  enQuestionLevel::Medium:
        Question.Number1 = RandomNumber(10, 50);
        Question.Number2 = RandomNumber(10, 50);
        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OpType);
        return Question;
        break;    
    
        case  enQuestionLevel::Hard:
        Question.Number1 = RandomNumber(50, 100);
        Question.Number2 = RandomNumber(50, 100);
        Question.CorrectAnswer = SimpleCalculator(Question.Number1, Question.Number2, Question.OpType);
        return Question;
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

void CorrectTheQuestionAnswer(stQuizz &Quizz, short QuistionNumber)
{
    if(Quizz.QuestionsList[QuistionNumber].PlayerAnswer != Quizz.QuestionsList[QuistionNumber].CorrectAnswer)
    {
        Quizz.QuestionsList[QuistionNumber].AnswerResult = false;
        Quizz.NumberOfWrongAnswers++;

        cout << "Wrong Answer -:(\n";
        cout << "The Correct Answer Is:\n";
        cout << Quizz.QuestionsList[QuistionNumber].CorrectAnswer;
        cout << "\n";
    }
    else
    {
        Quizz.QuestionsList[QuistionNumber].CorrectAnswer = true;
        Quizz.NumberOfCorrectAnswers++;

        cout << "Correct Answer -:)\n";
    }

    cout << endl;

    
}

void AskAndCorrectQuestionList(stQuizz &Quizz)
{
    for(short Question = 0; Question < Quizz.NumberOfQuestion; Question++)
    {
        PrintQuestion(Quizz, Question);
        Quizz.QuestionsList[Question].PlayerAnswer = ReadQuestionAnswer();
        CorrectTheQuestionAnswer(Quizz, Question);

    }

    Quizz.isPass = (Quizz.NumberOfCorrectAnswers >= Quizz.NumberOfWrongAnswers);
}

int main()
{
    srand(time(0));


    return 0;
}