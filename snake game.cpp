#include<iostream>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;
bool gameOver;
const int width=20;
const int height=20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;// lenght of the tail
enum eDir { STOP=0, LEFT, RIGHT,UP,DOWN};
eDir dir;
void Setup()
{
	gameOver=false;
	dir = STOP;
	x = width / 2;// intializing the position of snake
	y=height / 2;
	fruitX = rand() % width;// intializing the position of food
    fruitY = rand() % height;
    score = 0;
}
void Draw()
{
    system("cls");//for clear the screen
	for (int i = 0; i < width+2; i++)//displaying top  boundary
	    cout << "#";
    cout << endl;
    
    for(int i = 0; i < height; i++)//displaying left 
       {
       	    for(int j = 0; j < width; j++)
       	    {
              if(j == 0)
                 cout << "#";
                 
                 
              if(i == y && j == x)// position of the snake
                 cout << "O";
              else if( i == fruitY && j == fruitX) // position of the food
                 cout << "f";
			  else
			  {
			  	  bool print = false;
			  	for ( int k = 0; k < nTail; k++)// priting the tail of the snake
			  	{
			  		if (tailX[k] == j && tailY[k] == i)
			  		{
			  			cout << "o";
			  			print = true;
					  }
				  }
				  if (!print)
				     cout << " ";
			  }
			  
              
              
              if( j == width-1)// displaying right boundary
                cout << "#";
		    }
		    
		    cout << endl;
	   }
	   
    
    for (int i=0; i< width+2; i++)//displayind the bottom boundary
        cout << "#";
     cout << endl;
	 
	 cout << "SCORE:" << score << endl;   
}

void Input()
{
	if (kbhit())//
	{
	   switch(getch())
	   {
	   	case '4':
	   		dir = LEFT;
	   		break;
	    case '6':
	    	dir = RIGHT;
	    	break;
	    case '8':
	        dir = UP;
	        break;
	    case '2':
	    	dir = DOWN;
	    	break;	
	   case 'x':
	   	    gameOver = true;
	   	    break;
	   }
	}
}
void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for ( int i = 1; i < nTail; i++)// logic for storing the coordinate of the tail
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	 } 
  switch(dir)// chaning direction of the snake
  {
  	case LEFT:
  		x--;
  		break;
    case RIGHT:
    	x++;
    	break;
    case UP:
    	y--;
    	break;
    case DOWN:
    	y++;
    	break;
    
    default:
    	break;
	  }
	
	if (x > width || x < 0 || y > height || y < 0)// termination of the game
	   gameOver = true;
	
	for ( int i = 0; i < nTail; i++)//if head == tail then gameover
	{
		if(tailX[i] == x && tailY[i] == y)
		{
			gameOver = true;
		}
	}
		
	if (x== fruitX && y == fruitY)
	   {
	   	score +=10;
		fruitX = rand() % width;// intializing the position of food again
        fruitY = rand() % height; 
        nTail++;
	   }
}
int main()
{
	Setup();
	while(!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(200);
	}
	return 0;
}
