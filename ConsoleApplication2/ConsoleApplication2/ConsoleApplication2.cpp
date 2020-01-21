#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;
enum Race
{
	Human = 0, Elf, Ork, Dwarf
};
enum _Class
{
	Knight = 0, Wizard, Archer
};
enum Gender
{
	Man = 0, Woman
};
enum Move
{
	stop = 0, up, down, left, right
};
bool gameover{ false };
bool Flag(true);
vector<string>currentMap;
vector<string>CurrentDrawMap;
ifstream CurrentMapName;
string mapName{ "start_loc.txt" };
struct Charaster
{
	string name{};
	Race chRace{};
	_Class chClass{};
	Gender chGender{};
	Move chMove{};
	double atack{}, HP{};
	char chSuin{ '☺' };
	int x = 1, y = 1;
};

Charaster ch;

void Setup();
void Input();
void Logic();
void DrawMap(string CurrentMap);
int main()
{
	Setup();
}
void Setup()
{
	int a;
	string nameCLass, gender, nameRace;
	system("cls");
	cout << "Edit charaster:\n";
	cout << "Name: ";
	getline(cin, ch.name);
	cout << "Hello, " + ch.name << "\n";
	cout << "1-Human, 2-Elf, 3-Ork, 4-Dwarf. ";
	cout << "Choose your race: ";
	cin >> a;
	if (a == 1)
	{
		ch.chRace = Human;
		nameRace = "Human";
	}
	if (a == 2)
	{
		ch.chRace = Elf;
		nameRace = "Elf";
	}
	if (a == 3)
	{
		ch.chRace = Ork;
		nameRace = "Ork";
	}
	if (a == 4)
	{
		ch.chRace = Dwarf;
		nameRace = "Dwarf";
	}
	cout << "You are " << nameRace << "\n";
	cout << "1-Knight, 2-Wizard, 3-Archer. ";
	cout << "Choose your class: ";
	cin >> a;
	if (a == 1)
	{
		ch.chClass = Knight;
		nameCLass = "Knight";
	}
	if (a == 2)
	{
		ch.chClass = Wizard;
		nameCLass = "Wizard";
	}
	if (a == 3)
	{
		ch.chClass = Archer;
		nameCLass = "Archer";
	}
	cout << "You are " << nameCLass << "\n";
	cout << "1-Man, 2-Woman. ";
	cout << "Choose your gender: ";
	cin >> a;
	if (a == 1)
	{
		ch.chGender = Man;
		gender = "Man";
	}
	if (a == 2)
	{
		ch.chGender = Woman;
		gender = "Woman";
	}
	cout << "You are " << gender <<"\n";
	cout << "Hello, " + ch.name + ". You are " + gender + "-" + nameCLass + ". You are " + nameRace + ". You are going to search your adventure!" << "\n";
	DrawMap("Source.txt");
}
void Input()
{

}
void Logic()
{

}
void DrawMap(string mapName)
{
	int maphight, mapwidth;
	system("cls");
	if (Flag == true)
	{
		string str("");
		CurrentMapName.open(mapName);
		if (!CurrentMapName.is_open())
		{
			cout << "Error";
		}
		while (getline(CurrentMapName, str))
		{
			currentMap.push_back(str);
		}
		Flag = false;
		maphight = currentMap.size();
		mapwidth = currentMap.back().size();
	}
	for (int i = 0; i < maphight; ++i)
	{
		for (int j = 0; j < mapwidth; ++i)
		{ 
			if ((i == ch.x) && (j == ch.y))
			{
				currentMap[i][j] = ch.chSuin;
			}
			cout << currentMap[i] << '\n';
		}
	}
}