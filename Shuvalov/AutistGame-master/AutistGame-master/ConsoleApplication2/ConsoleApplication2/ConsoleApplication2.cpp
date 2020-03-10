#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
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
	Stop = 0, Up, Down, Left, Right
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
	Move chMove{Stop};
	double atack{}, HP{};
	char chSuin{ '0' };
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
	while (gameover == false)
	{
		Input();
		Logic();
	}
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
	if (_kbhit() ==true)
	{
		switch (_getch())
		{
		case 'a': ch.chMove = Left;
			break;
		case 's': ch.chMove = Down;
			break;
		case 'd': ch.chMove = Right;
			break;
		case 'w': ch.chMove = Up;
			break;
		}
	}
}
void Logic()
{
	switch (ch.chMove)
	{
	case Left:
		if (currentMap[ch.x][ch.y-1] == ' ')
		{
			--ch.y;
			currentMap[ch.x][ch.y+1] = ' ';
			DrawMap(mapName);
			break;
		}
		else if (currentMap[ch.x][ch.y - 1] == '9')
		{
			mapName = "House.txt";
			Flag = true;
			ch.x = 1;
			ch.y = 1;
			currentMap.clear();
			DrawMap(mapName);
			break;
		}
		break;
	case Right:
		if(currentMap[ch.x][ch.y+1] == ' ')
		{
			++ch.y;
			currentMap[ch.x][ch.y-1] = ' ';
			DrawMap(mapName);
			break;
		}
		else if (currentMap[ch.x][ch.y + 1] == '9')
		{
			mapName = "House.txt";
			Flag = true;
			ch.x = 1;
			ch.y = 1;
			currentMap.clear();
			DrawMap(mapName);
			break;
		}
		break;
	case Down:
		if(currentMap[ch.x+1][ch.y] == ' ')
		{
			++ch.x;
			currentMap[ch.x-1][ch.y] = ' ';
			DrawMap(mapName);
			break;
		}
		else if (currentMap[ch.x + 1][ch.y] == '9')
		{
			mapName = "House.txt";
			Flag = true;
			ch.x = 1;
			ch.y = 1;
			currentMap.clear();
			DrawMap(mapName);
			break;
		}
		break;

	case Up:
		if (currentMap[ch.x - 1][ch.y] == ' ')
		{
			--ch.x;
			currentMap[ch.x + 1][ch.y] = ' ';
			DrawMap(mapName);
			break;
		}
		else if (currentMap[ch.x - 1][ch.y] == '9') 
		{
			mapName = "House.txt";
			Flag = true;
			ch.x = 1;
			ch.y = 1;
			currentMap.clear();
			DrawMap(mapName);
			break;
		}
		break;

	}
	ch.chMove = Stop;

}
void DrawMap(string mapName)
{
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
	}
	for (int i = 0; i < currentMap.size(); ++i)
	{
		for (int j = 0; j < currentMap.back().size(); ++j)
		{ 
			if ((i == ch.x) && (j == ch.y))
			{
				currentMap[i][j] = ch.chSuin;
			}
		}
		cout << currentMap[i] << '\n';
	}
}