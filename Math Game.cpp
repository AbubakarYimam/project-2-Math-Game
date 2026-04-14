#include <iostream>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>

using namespace std;

enum enLevel { Easy = 1, Med = 2, Hard = 3, Mixl = 4 };
enum enOpertionType { Add = 1, Sub = 2, Mul = 3, Div = 4, Mix = 5 };

int RandomNumber(int From, int To) {
	return rand() % (To - From + 1) + From;
}
int EasyNum() {
	return RandomNumber(1, 10);
}
int MedNum() {
	return RandomNumber(10, 50);
}
int HardNum() {
	return RandomNumber(50, 100);
}
int RandNum() {
	return RandomNumber(1, 100);
}
string OpertionList() {
	string OpList[4] = { "+","-","X","/" };
	return OpList[RandomNumber(0, 3)];
}
int Number(enLevel Level) {
	switch ((enLevel)Level) {
	case enLevel::Easy:
		return EasyNum();
	case enLevel::Med:
		return MedNum();
	case enLevel::Hard:
		return HardNum();
	case enLevel::Mixl:
		return RandNum();
	default:
		return EasyNum();

	}
}

string LevelList(enLevel Level) {
	string LevelList[4] = { "Easy","Med","Hard","Mix" };
	return LevelList[Level - 1];
}
string OpList(enOpertionType Op) {
	string LevelList[5] = { "Add","Sub","Mul","Div","Mix" };
	return LevelList[Op - 1];
}
int HowManyRound() {
	int Round = 0;
	cout << "How Many Questions Do You Wnat To Answer ?  ";
	cin >> Round;
	return Round;
}
int AskLevel() {
	int Level = 0;
	cout << "\nEnter Question Level  [1] Easy [2] Med [3] Hard [4] Mix  ?  ";
	cin >> Level;
	return Level;
}
int AskOpertion() {
	int Opertion = 0;
	cout << "\nEnter Question Type [1] Add [2] Sub [3] Mul [4] Div [5] Mix ? ";
	cin >> Opertion;
	return Opertion;
}
string OpertionTypeList(enOpertionType Opertion) {
	switch ((enOpertionType)Opertion) {
	case enOpertionType::Add:
		return "+";
	case enOpertionType::Sub:
		return "-";
	case enOpertionType::Mul:
		return "X";
	case enOpertionType::Div:
		return "/";
	case enOpertionType::Mix:
		return OpertionList();
	default:
		return "+";


	}
}
int SolveOpertion(int Num1, int Num2, string Op) {
	if (Op == "+") return Num1 + Num2;
	else if (Op == "-")return Num1 - Num2;
	else if (Op == "X")return Num1 * Num2;
	else
	{
		if (Num2 == 0) Num2 = 1;
		return Num1 / Num2;
	}
}

void CheckAnswer(int Num1, int Num2, string OpertionType, int UserAnswer, int& RightAnswer, int& WrongAnswer) {
	if (SolveOpertion(Num1, Num2, OpertionType) == UserAnswer) {
		system("color 2F");
		cout << "\nRight Answer :-) \n";
		RightAnswer++;
	}
	else
	{
		system("color 4F");
		cout << "\nWrong Answer  :-( \n";
		cout << "The Right Answer is : " << SolveOpertion(Num1, Num2, OpertionType) << endl;
		WrongAnswer++;
	}

}

void QuetionBord(int Num1, int Num2, string OpertionType, int& RightAnswer, int& WrongAnswer) {
	int UserAnswer = 0;
	cout << Num1 << endl;
	cout << Num2 << "  " << OpertionType << endl;
	cout << "_____________________________\n";
	cin >> UserAnswer;
	CheckAnswer(Num1, Num2, OpertionType, UserAnswer, RightAnswer, WrongAnswer);


}
void FinalResultRaection(int RightAnswer, int WrongAnswer) {
	if (RightAnswer > WrongAnswer) {
		cout << "\t\nFinal Result Is : Pass :-) \n";
		system("color 2F");
	}
	else
	{
		cout << "\t\nFinal Result Is : Failed :-( \n";
		system("color 4F");
	}
}
void ResultBoard(int Round, int RightAnswer, int wrongAnswer, enOpertionType Operttion, enLevel Level) {
	cout << "\n____________________________________________";
	FinalResultRaection(RightAnswer, wrongAnswer);
	cout << "____________________________________________\n";
	cout << "\t Number Of Question     : " << Round << endl;
	cout << "\t Question Level         : " << LevelList(Level) << endl;
	cout << "\t Opertion Type          : " << OpList(Operttion)	 << endl;
	cout << "\t Number Of Right Answer : " << RightAnswer << endl;
	cout << "\t Number Of Wrong Answer : " << wrongAnswer << endl;
	cout << "____________________________________________\n";
		

}
void QuestionMenue() {
	int TotalRound = 0, RightAnswer = 0, WrongAnswer = 0, Level, Op, Num1 = 0, Num2 = 0;
	TotalRound = HowManyRound();
	Level = AskLevel();
	Op = AskOpertion();

	for (int Round = 1;Round <= TotalRound;Round++) {
		cout << "\n";
		Num1 = Number((enLevel)Level);
		Num2 = Number((enLevel)Level);
		cout << "Question [" << Round << "/" << TotalRound << "] \n";
		QuetionBord(Num1, Num2, OpertionTypeList((enOpertionType)Op), RightAnswer, WrongAnswer);


	}
	ResultBoard(TotalRound, RightAnswer, WrongAnswer, (enOpertionType)Op, (enLevel)Level);

}

void Start() {	
	char is = 'Y';
	do {
		system("cls");
		system("color 0F");
		QuestionMenue();
		cout << "\n\tDo You Want TO Play Again ?? ";
		cin >> is;
	} while (is == 'y' || is == 'Y');
}

int main() {
	srand(time(0));
	Start();
}
