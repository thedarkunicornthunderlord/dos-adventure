#include <iostream>
#include <string>
using namespace std;
const int DEATH = -1;
const int COURT = 0;
const int NORTHW = 1;
const int EASTC = 2;
const int EASTGATE = 3;
const int GODROOM = 4;
const int BATH = 5;
const int BROTHEL = 6;
const int SOUP = 7;
int player;
int manwoman;
int north[8] = { 
	NORTHW,// from court
	DEATH,//from northwhing
	DEATH,//from East corridor
	DEATH,//from East gate
	DEATH,//from godroom
	COURT,// from bathroom
	DEATH,//from brothel
	DEATH// from soup kitchen
}; 
int south[8] = {
	BATH, // from court
	COURT,// from north wing
	DEATH,// from east corridor
	DEATH,// from eastgate
	DEATH,// from godroom
	DEATH,//bathroom
	DEATH, //brothel
	DEATH, // from soup kitchen
};
int west[8] = {
	BROTHEL, //from court
	DEATH,// from northwing
	COURT, //from east corridor
	EASTC, //from east gate
	EASTGATE, // from godroom
	DEATH, // from bathroom
	SOUP, // from  brothel
	DEATH // from  soup kitchen
};
int east[8] = {
	EASTC, // from court
	DEATH, // from northwing
	EASTGATE, // from east corridor
	GODROOM, // from east corridor
	DEATH, // from godroom
	DEATH, //from bathroom
	COURT, // from brothel
	BROTHEL // from soup kitched
};


string info [8] = { // descriptoins of each room
"You are in a large courtyard, with a door every direction from where you stand. \nYou may go north, south east or west\n",//court 
"You find yourself in a large room filled with greek statues of naked people.\n After making a joke you notice only a door to the south.\n", //northwing
"You are walking down a large ornate corridor , with a large gate to the east.\n It smells rather unpleaent there.\n", //eastcorridor
"A large imposing gate is infrom of you, and some dumb bastard has left it open,\n Continue east to enter or turn back?\n", //gate
"You are in a large chamber, surrounded by gold jewels and other fancy things.\n In the middle of the room is a awesome looking sandwitch,\n and I mean very awesome looking. But it is guarded by a beastly manwoman.\n What do you do?\n", //goddroom
"you are in a bathroom, and it looks like someone forgot to flush.\n",
"You find yourself in a brothel, where debouchery is everywhere.\n you see a woman [excerpt censored for explicit content] with a tube sock.\n what do you do?\n", // brothel
"You are now in a soup kitchen, with homeless men looking at you like \n you just walked out of a brothel. \n what do you do\n"//soup kitchen
};
char get_input();
void move_player (int);
bool battle();



char get_input()
{
	char c;
	cout << ">"; //so you can see where to type
	cin >> c;
	cin.ignore (200,'\n');
	while ( c != 'n' &&  // all the valid entries and to test if a correct input
			c != 'N' &&
			c != 's' &&
			c != 'S' &&
			c != 'w' &&
			c != 'W' &&
			c != 'e' &&
			c != 'E' &&
			c != 'f' &&
			c != 'F' &&
			c != 'Q' &&
			c != 'q' )

		{
			cout << "   Is not a valid expression" << endl << "Please enter in n for north \n s for south\n e for east\n w for west" << endl;
			cout << " Enter f to fight or q to quite like a little bitch.\n "; // let the user know what is up
			cout << "> " << endl;
			cin >> c;
		}
			
	return c;
}
void move_player ( int newlocation )
{
	if ( newlocation != DEATH) 
		player = newlocation;
	else 
		cout << " You look out a conveniently placed window to see nothing but fire and death\n you do nothing really.\n";
}
bool battle()
{
	int womanhealth = 50;
	int herohealth = 50;
	bool win ;
	char choice;

	cout << " you challenge manwoman to battle. He/she draws his/her sword\n You draw your sword\n what do you do.";
	cout << " enter f to flirt, s to stab, p to phone 911, and d to slash\n";
	cout << "> ";
	cin >> choice;
	do
	{
		cout << " she bashes your head in with an autistic toaster \n" << endl;
		herohealth = herohealth - 10;
		switch (choice)
		{
		case 'f':
		case 'F':cout << " you try to flirt with ...it. it is flattered but stabs you anyways.\n";
			break;
		case 's':
		case 'S':cout << " you stab ...it, blood explodes from the inpact area, its weakened" << endl;
			womanhealth = womanhealth - 15;
			cout << " She has " << womanhealth <<" health left \n";
			break;
		case 'p':
		case 'P':cout << " you phone 911, aaaaaand there is no signal you unlucky bastard \n";
			break;
		case 'd':
		case 'D': cout << " you slash...it along its breast...i think..it bleeds anyways\n";
			womanhealth = womanhealth - 15;
			cout << " She has " << womanhealth <<" health left \n";
			break;
		}
	if ( womanhealth >= 0 ) 
		{
		cout << "what do you do " << endl << "<";
		cin >> choice;
		cout << endl;
	    }
	} while (womanhealth >=0 || herohealth >=0  );
	if (herohealth <=0)
		win = false;
	else 
		win = true;
	return win;
}

int main()
{
	bool gameover = false;
	player = COURT;
	manwoman = GODROOM;
	while (!gameover)
	{
		cout << info[player];
		char input = get_input();
		switch (input)
		{
		case 'n':
		case 'N': 
			move_player(north[player]);break;
		case 'e':
		case 'E':
			move_player(east[player]);break;
		case 's':
		case 'S':
			move_player(south[player]);break;
		case 'w':
		case 'W':
			move_player(west[player]);break;
		case 'f':
		case 'F':
			if (player==manwoman)
			{
				 bool win = battle();
				if (win)
					cout << " you have defeated manwoman, enjoy your now bloodstained sandwitch\n";
				else 
					cout << " manwoman has tougher than you thought, and you are now dead.\n";
				gameover = true;break;

		
			}
			else
				cout << " stop trying to get in a fight you overviolent bastard\n";break;
		case 'q':
		case 'Q':
			cout << " You rage quit as the you draw a small knife and plunge into your jugular" << endl;
			cout << " You are now dead. " << endl;
			gameover = true;break;
			}
		}
		cout << "GAME OVER" << endl;
		return 0;
	}
			