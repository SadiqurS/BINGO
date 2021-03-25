//Sadiqur Sakib
//cpp
//Bingo project
//Period 9
#include<iostream>//these are all my libraries
#include<cstdlib>
#include<ctime>
#include <stdio.h>
#include <stdlib.h>
#define underline "\033[4m"
using namespace std;

bool exist_in(int arr[5][5], int target);//exist in funtion this is the prototype
bool check(int bingoboard[5][5]);//check win function this is the prototype

int main()//main function
{
	system("COLOR FC");
	cout<<"------Welcome Player to the game of Bingo!-------"<<endl;//rules of the game
	system("Color 3C");
	std::cout<<"The rules are very simple press enter and keep track of your board until you finally win!"<<endl;
	
	std::cout<<"Good luck"<<endl;
	srand(time(0));//random time
	int bingoboard[5][5];//bingo board size
	int num;
	bool find = false;
	for(int r=0; r<5; r++)//creates the bingo board
	{
		for(int c=0; c<5; c++)
		{
			do
			{
				num = rand()%15+(c*15+1);
			}
			while(exist_in(bingoboard, num)==true);
			bingoboard[r][c]=num;
		}
	}
	bingoboard[2][2]=0;//makes the middle number of the board 0
	bool win = false;
	bool tablet [75];
	for (int i = 0; i<75; i++)
	    tablet[i] = true;
	int picked;
	
	while(win == false)
	{
		system("Color 4D");
		std::cout<<underline <<" B  I  N  G  O  "<<endl;//prints out bingo board 
	    for (int r=0; r<5; r++)
		{
		    for(int c=0; c<5; c++)
			{
			    if(bingoboard[r][c] / 10 == 0)
			        cout<<" "<<bingoboard[r][c] << " ";//creates spacing between the numbers
			    else
			        cout<<bingoboard[r][c] << " ";
		    }
		    cout << "\n";
	    }
	    getchar();
	    do 
		{
		    find = false;
		    picked = rand()%75+1;
		    if(tablet[picked-1] == true)
			{
		        tablet[picked-1]=false;
		        find = true;
		   	}
		}
		while(find == false);
			system("CLS");
			system("Color 4D");
			std::cout<<"The number generated is: "<<picked<<endl;//prints out number generated
			for(int r = 0; r<5; r++)
			{
				for(int c = 0; c<5; c++)
				{
					if(bingoboard[r][c]==picked)//checks to see if the board has random number
					{
						bingoboard[r][c]=0;//if it does then the number is replaced by 0
					}
				}	
			}
		if(check(bingoboard))
		{
			system("Color D4");
			std::cout<<"you win!"<<endl;//when the player wins
			win = true;//
		}
	}
}
bool exist_in(int arr[5][5], int target)//the function is continued here
{
	for (int r=0; r<5 ; r++)
	{
		for(int c=0; c<5; c++)
		{
			if(arr[r][c] == target)
				return true;
		}
	}
    return false;
}
bool check(int bingoboard[5][5])//checks the board to see if user won the game or not 
{
	for(int r=0; r<5; r++)
	{
		if(bingoboard [r][0]== bingoboard[r][1] && 
		bingoboard[r][1] == bingoboard[r][2] && 
		bingoboard[r][2] == bingoboard[r][3] && 
		bingoboard[r][3] == bingoboard[r][4] &&
		bingoboard[r][4] == 0)
		return true;
	}
	for(int c=0; c<5; c++)
	{
		if(bingoboard[0][c] == bingoboard[1][c] &&
		bingoboard[1][c] == bingoboard[2][c] &&
		bingoboard[2][c] == bingoboard[3][c] &&
		bingoboard[3][c] == bingoboard[4][c] &&
		bingoboard[4][c] == 0)
		return true;
	}
	if(bingoboard[0][0] == bingoboard[1][1] &&
		bingoboard[1][1] == bingoboard[2][2] &&
		bingoboard[2][2] == bingoboard[3][3] &&
		bingoboard[3][3] == bingoboard[4][4] &&
		bingoboard[4][4] == 0)
		return true;
	else
		return false;
}



