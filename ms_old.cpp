#include<iostream.h>
#include<stdlib.h>
#include<time.h>

char Back[10][10]=
	{
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
	};

char Front[10][10]=
	{
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
		' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
	};


class Minesweeper
{
private:
	int x;
	int y;
	int nonmines;
public:
	Sweeper();
	void Intro();
	void Placemines();
	void Countem();
	void Move();
	void Showboard_Front();
	void Outro();
}player1;


Minesweeper::Sweeper()
{
	player1.nonmines=0;
	player1.x;
	player1.y;
}


void Minesweeper::Intro()
{
	cout<<" ________________________________________________________ "<<endl;
	cout<<"| Welcome to Minesweeper                                 |"<<endl;
	cout<<"|--------------------------------------------------------|"<<endl;
	cout<<"|  * Type coordinates when promted                       |"<<endl;
	cout<<"|  * Coordinates go from top to bottem                   |"<<endl;
	cout<<"|  * If you hit a mine, you die                          |"<<endl;
	cout<<"|  * Do  not uncover coordinates you think are mines     |"<<endl;
	cout<<"|                                                        |"<<endl;
	cout<<"|                                                        |"<<endl;
	cout<<"|                                                        |"<<endl;
	cout<<"| Good luck                                              |"<<endl;
	cout<<"|________________________________________________________|"<<endl;
	cout<<endl;
	system("pause");
	system("cls");

}

void Minesweeper::Placemines()
{
	for(int mines=0;mines<10;mines++)
	{
		int x=rand()%9;
		int y=rand()%9;

		if (Back[x][y]=='*')
		{			
			mines--;
		}
		else
		{
			Back[x][y]='*';
		}
	}
}

void Minesweeper::Countem()
{
	for (int a=0;a<10;a++)
	{
		for (int b=0;b<10;b++)
		{
			if(Back[a][b]!='*')
			{
				int temp=0;
				
				
				if (a==0 && b==0)
				{
					
					if (Back[a+1][b]=='*')
						temp++;
					if (Back[a+1][b+1]=='*')
						temp++;
					if (Back[a][b+1]=='*')
						temp++;

				}
				else if (a==0 && b==9)
				{
					
					if (Back[a][b-1]=='*')
						temp++;
					if (Back[a+1][b-1]=='*')
						temp++;
					if (Back[a+1][b]=='*')
						temp++;

				}
				else if (a==9 && b==9)
				{
					
					if (Back[a-1][b]=='*')
						temp++;
					if (Back[a-1][b-1]=='*')
						temp++;
					if (Back[a][b-1]=='*')
						temp++;

				}
				else if (a==9 && b==0)
				{
					
					if (Back[a-1][b]=='*')
						temp++;
					if (Back[a-1][b+1]=='*')
						temp++;
					if (Back[a][b+1]=='*')
						temp++;

				}								
				else if(a==0)
				{
					if (Back[a][b-1]=='*')
						temp++;
					if (Back[a][b+1]=='*')
						temp++;
					if (Back[a+1][b-1]=='*')
						temp++;
					if (Back[a+1][b+1]=='*')
						temp++;
					if (Back[a+1][b]=='*')
						temp++;

				}
				else if(a==9)
				{
					if (Back[a][b-1]=='*')
						temp++;
					if (Back[a][b+1]=='*')
						temp++;
					if (Back[a-1][b-1]=='*')
						temp++;
					if (Back[a-1][b+1]=='*')
						temp++;
					if (Back[a-1][b]=='*')
						temp++;

				}
				else if(b==0)
				{
					if (Back[a-1][b]=='*')
						temp++;
					if (Back[a+1][b]=='*')
						temp++;
					if (Back[a-1][b+1]=='*')
						temp++;
					if (Back[a+1][b+1]=='*')
						temp++;
					if (Back[a][b+1]=='*')
						temp++;

				}
				else if(b==9)
				{

					if (Back[a-1][b]=='*')
						temp++;
					if (Back[a+1][b]=='*')
						temp++;
					if (Back[a-1][b-1]=='*')
						temp++;
					if (Back[a+1][b-1]=='*')
						temp++;
					if (Back[a][b-1]=='*')
						temp++;

				}
				else
				{
				
					if (Back[a-1][b]=='*')
						temp++;
					if (Back[a][b-1]=='*')
						temp++;
					if (Back[a-1][b-1]=='*')
						temp++;
					if (Back[a+1][b+1]=='*')
						temp++;
					if (Back[a-1][b+1]=='*')
						temp++;
					if (Back[a+1][b-1]=='*')
						temp++;
					if (Back[a+1][b]=='*')
						temp++;
					if (Back[a][b+1]=='*')
						temp++;
				}
					temp=temp+48;
					Back[a][b]=temp;

				
			}
		}
	}


}



void Minesweeper::Move()
{
	Showboard_Front();

	cout<<"Please enter a row number (0-9)";
	cin>>player1.x;
	if (player1.x>9 || player1.x<0)
	{
		cout<<"Please enter a number between 1 and 10"<<endl;
		system("pause");
		system("cls");
		Move();
	}
	cout<<"Please enter a columm number (0-9)";
	cin>>player1.y;
	if (player1.y>9 || player1.y<0)
	{
		cout<<"Please enter a number between 1 and 10"<<endl;
		system("pause");
		system("cls");
		Move();
	}

if (Front[player1.x][player1.y]=='0' || Front[player1.x][player1.y]=='1' || Front[player1.x][player1.y]=='2' || Front[player1.x][player1.y]=='3' || Front[player1.x][player1.y]=='4' || Front[player1.x][player1.y]=='5' || Front[player1.x][player1.y]=='6' || Front[player1.x][player1.y]=='7' || Front[player1.x][player1.y]=='8')
{
	Front[player1.x][player1.y]=Back[player1.x][player1.y];
}
else
{
	Front[player1.x][player1.y]=Back[player1.x][player1.y];
	player1.nonmines++;
}

system("cls");

if (Back[player1.x][player1.y]=='*' || player1.nonmines>=90)
{
	Outro();
}
else
Move();

}


void Minesweeper::Showboard_Front()
{
	for (int a=0;a<10;a++)
	{
		for (int b=0;b<10;b++)
		{
			cout<<Front[a][b]<<" ";
		}
		cout<<endl;
	}

}

void Minesweeper::Outro()
{
	for (int a=0;a<10;a++)
	{
		for (int b=0;b<10;b++)
		{
			cout<<Back[a][b]<<" ";
		}
		cout<<endl;
	}


	cout<<"Thank you for playing minesweeper"<<endl;
	if (player1.nonmines=90)
	{
		cout<<"You have beat the game"<<endl;
	}
	else
	{
		cout<<"You have hit a mine and died"<<endl;
	}

	cout<<endl<<"Thanks for playing"<<endl;

}

int main()
{
	srand(time(0));
	Minesweeper thisgame;
  	thisgame.Intro();
	thisgame.Placemines();
	thisgame.Countem();
	thisgame.Move();
	return 0;
}