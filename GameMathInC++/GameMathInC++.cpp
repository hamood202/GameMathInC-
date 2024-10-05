
#include <iostream>
using namespace std;

enum enQuestionsLevel { Easy = 1, Med = 2, Hard = 3, Mix = 4 };

enum enOprationType { Add = 1, Sub = 2, Mul = 3, Div = 4, Mix1 = 5 };

enum enWinner
{
    Right = 1,
    Wronge = 2
};

struct sMathQuestions
{
    int nFirstNumber;
    int nSecondNumber;
    enOprationType nOperator;
};

sMathQuestions mathQuestions;

struct sQizz
{
    int NumberQuestion;
    enQuestionsLevel NumberQuestionLevel;
    enOprationType NumberOprationType;
    int NumberRight = 0;
    int NumberWronge = 0;
    bool isPass = false;
};

sQizz sqizz;

int HowManyWantQuestion()
{
    //int NumberOfQuestion;
    do
    {
        cout << "How Many  Questions do you want to answar : ";
        cin >> sqizz.NumberQuestion;
    } while (sqizz.NumberQuestion < 1 || sqizz.NumberQuestion > 10);

    return sqizz.NumberQuestion;
}

enQuestionsLevel EnterQuestionsLevel()
{
    int number;
    do {
        cout << "Enter Questions Level [1] Easy ,[2] Med ,[3] Hard ,[4] Mix : ";
        cin >> number;
    } while (number < 1 || number > 4);

    return (enQuestionsLevel)number;
}

enOprationType EnterOprationType()
{
    int number;
    do
    {
        cout << "Enter Opration Type  [1] Add ,[2] Sub ,[3] Mul ,[4] Div ,[5] Mix : ";
        cin >> number;
    } while (number < 1 || number > 5);

    return (enOprationType)number;
}

int NumberRandom(int From, int To)
{
    int  resualt = rand() % (To - From + 1) + From;
    return resualt;
}

string ChoiceName(enQuestionsLevel Choice)
{
    string arrGameChoices[4] = { "Easy","Med","Hard","Mix" };
    return arrGameChoices[Choice - 1];
}

string ChoiceNameOpration(enOprationType Choice)
{
    string arrGameChoices[5] = { "Add","Sub","Mul","Div","Mix" };
    return arrGameChoices[Choice - 1];
}

void SetWinnerScreenColor(enWinner Winner)
{
    switch (Winner)
    {
    case enWinner::Right:
        system("color 2F"); //turn screen to Green
        break;
    case enWinner::Wronge:
        system("color 4F"); //turn screen to Red
        cout << "\a";
        break;
    default:
        system("color 6F"); //turn screen to Yellow
        break;
    }
}

int CheckLevelQuestion(enQuestionsLevel level)
{
    switch (level)
    {
    case enQuestionsLevel::Easy:
        return  NumberRandom(1, 10);
        break;
    case enQuestionsLevel::Med:
        return NumberRandom(10, 40);
        break;
    case enQuestionsLevel::Hard:
        return NumberRandom(50, 100);
        break;
    case enQuestionsLevel::Mix:
        return NumberRandom(1, 100);
        break;
    default:
        system("color 6F"); //turn screen to Yellow
        break;
    }
}

string WriteLevelQuestion(enOprationType level)
{
    switch (level)
    {
    case enOprationType::Add:
        return "+";
        break;
    case enOprationType::Sub:
        return "-";
        break;
    case enOprationType::Mul:
        return "*";
        break;
    case enOprationType::Div:
        return "/";
        break;
    case enOprationType::Mix1:
        cout << "Mix1" << endl;
        break;
    default:
        system("color 6F"); //turn screen to Yellow
        break;
    }
}

enOprationType CheckOprationType(enOprationType type)
{
    switch (type)
    {
    case enOprationType::Add:
        return (enOprationType)1;
        break;
    case enOprationType::Sub:
        return (enOprationType)2;
        break;
    case enOprationType::Mul:
        return (enOprationType)3;
        break;
    case enOprationType::Div:
        return (enOprationType)4;
        break;
    case enOprationType::Mix1:
        return  (enOprationType)NumberRandom(1, 3);
        break;
    default:
        system("color 6F"); //turn screen to Yellow
        break;
    }
}

int CheckResualt()
{
    int resualt;
    switch (mathQuestions.nOperator)
    {
    case 1:
        return mathQuestions.nFirstNumber + mathQuestions.nSecondNumber;
        break;
    case 2:
        return mathQuestions.nFirstNumber - mathQuestions.nSecondNumber;
        break;
    case 3:
        return mathQuestions.nFirstNumber * mathQuestions.nSecondNumber;
        break;
    case 4:
        return mathQuestions.nFirstNumber / mathQuestions.nSecondNumber;
        break;
    default:
        break;
    }
}

void readNumbers(enQuestionsLevel level, enOprationType type)
{
    // int num1 =(enQuestionsLevel)EnterQuestionsLevel();

    mathQuestions.nFirstNumber = CheckLevelQuestion(level);
    mathQuestions.nSecondNumber = CheckLevelQuestion(level);
    mathQuestions.nOperator = CheckOprationType(type);

}

bool CheckResult(sMathQuestions currentNumber, int Result)
{
    bool isRightAnser = false;
    switch (currentNumber.nOperator)
    {
    case 1:
        isRightAnser = (Result == currentNumber.nFirstNumber + currentNumber.nSecondNumber);
        break;
    case 2:
        isRightAnser = (Result == currentNumber.nFirstNumber - currentNumber.nSecondNumber);
        break;
    case 3:
        isRightAnser = (Result == currentNumber.nFirstNumber * currentNumber.nSecondNumber);
        break;
    case 4:
        isRightAnser = (Result == currentNumber.nFirstNumber / currentNumber.nSecondNumber);
        break;
    }
    return isRightAnser;
}

void PrintQuestion()
{
    cout << mathQuestions.nFirstNumber << endl;
    cout << mathQuestions.nSecondNumber << " ";
    cout << WriteLevelQuestion(mathQuestions.nOperator) << endl;
}

void PrintResualt()
{
    cout << mathQuestions.nFirstNumber << endl;
    cout << mathQuestions.nOperator << endl;
    cout << mathQuestions.nSecondNumber << endl;
}

void CorrectTheQuestionAnswer()
{
    bool isRightAnser = false;
    int Result, right = 0, wronge = 0;

    PrintQuestion();
    cout << "-----------------------\n";
    cin >> Result;
    isRightAnser = CheckResult(mathQuestions, Result);

    if (isRightAnser)
    {
        cout << "Right Answer\n";
        system("color 2F");
        // right++;
        sqizz.NumberRight++;
    }
    else
    {
        cout << "Wrong Answer\n";
        cout << "----------------------------------\n";
        system("color 4F"); //turn screen to Red
        cout << "The Right Answer : " <<
            CheckResualt() << endl;
        // wronge++;
        sqizz.NumberWronge++;
        //  nWrongAnswerCount++;
    }
    sqizz.isPass = (sqizz.NumberRight >= sqizz.NumberWronge);


}

string GetFinalResultsText(bool Pass)
{
    if (Pass)
        return "PASS :-)";
    else
        return "Fail :-(";
}

void NumberQuestion(int num)
{
    int n = EnterQuestionsLevel();
    int v = EnterOprationType();
    sqizz.NumberQuestionLevel = (enQuestionsLevel)n;
    sqizz.NumberOprationType = (enOprationType)v;
    for (int i = 1;i <= sqizz.NumberQuestion;i++)
    {
        readNumbers((enQuestionsLevel)n, (enOprationType)v);
        cout << "\n\nQuestion [" << i << "/" << num << "]\n";
        CorrectTheQuestionAnswer();
    }
    //  return num;
}

void PrintFinal(sQizz sqizz)
{
    cout << "\n";
    cout << "______________________________\n\n";
    cout << " Final Resutls is " << GetFinalResultsText(sqizz.isPass);
    cout << "\n______________________________\n\n";
    cout << "Number of Question : " << sqizz.NumberQuestion << endl;
    cout << "Number of Question Level : " << ChoiceName(sqizz.NumberQuestionLevel) << endl;
    cout << "Number of Opration Type : " << WriteLevelQuestion(sqizz.NumberOprationType) << endl;
    cout << "Number of Right Answer : " << sqizz.NumberRight << endl;
    cout << "Number of Wrong Answer : " << sqizz.NumberWronge << endl;
    cout << "\n______________________________\n";
}

void ResetScreen()
{
    system("cls");
    /* system("calc");*/
    system("color 0F");
}

string Tabs(short NumberOfTabs)
{
    string t = "";
    for (int i = 1; i < NumberOfTabs; i++)
    {
        t = t + "\t";
        cout << t;
    }
    return t;
}

void ShowGameOverScreen()
{
    cout << Tabs(2) << "__________________________________________________________\n\n";
    cout << Tabs(2) << "                 +++  G a m e O v e r	 +++ \n";
    cout << Tabs(2) << "__________________________________________________________\n\n";
}

void StartGame()
{
    char PlayAgain = 'Y';
    do
    {
        sqizz.NumberRight = 0;
        sqizz.NumberWronge = 0;
        ResetScreen();
        NumberQuestion(HowManyWantQuestion());
        ShowGameOverScreen();
        PrintFinal(sqizz);
        cout << endl << Tabs(3) << "Do you want to play again? Y/N? ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
    srand((unsigned)time(NULL));
    StartGame();

}

