#ifndef App_h
#define App_h

#include "GlutApp.h"
#include "AnimatedRect.h"
#include <list>
#include <vector>

using namespace std;

#define MSIZE 14 //declaring the size of of our allocated space of the grid.

class App: public GlutApp {
    
public:
    
    App(int argc, char** argv, int width, int height, const char* title);
    
    void draw();
    
    void keyDown(unsigned char key, float x, float y);
	void specialKeyDown(int, float, float);
	void leftMouseDown(float, float);
	void leftMouseUp(float, float);
    ~App();
    
    friend void timer(int);

private:

	int mode;		// 0=menu, 1=play, 2=help
	int dir;		// 0=left, 1=right, 2=buttom, 3=top
	
	// cell size in window normalized coordinates
	float cell_size_x;
	float cell_size_y;

	// display area
	float x0 = -0.9; //x coordiante to display the game
	float y0 = -0.9; //y coordinate to display the game
	float w  = 1.8; //width to adjust the skew
	float h  = 1.8; //height to adjust the skew
	
	// true if the game ends
	bool gameOver;

	// 2 images
	TexRect *menu;
	TexRect *help;
	
	// default map
	char map_ini[MSIZE][MSIZE+1] =	{ //tilt head right to see the actual game board. we can add and subtract new blocks in this way.
		"**************",
		"*            *",
		"*            *",
		"*   **       *",
		"*   *        *",
		"*   *        *",
		"*            *",
		"*            *",
		"*        *   *",
		"*        *   *",
		"*       **   *",
		"*            *",
		"*            *",
		"**************",
	};

	// playing map (should be a copy of the default map)
	char map[MSIZE][MSIZE + 1];

	// 500 ms
	int timerSpeed = 500;

	// the snake position inside the table
	struct snakePos {

		int x, y;

		snakePos(int x, int y)	{ //when we call the snakePos struct, we send the initial value coordinates

			this->x = x; this->y = y;

		}

		snakePos(const snakePos & p) {

			this->x = p.x; //setting our acquired snake x
			this->y = p.y; //setting our acquired snake y

		}

	};

	// all the used positions by the snake on the table
	list<snakePos> snake;

	// number of free positions in the table
	int freePositions;
	
	// maximum score since the app starts
	int highScore;
	
	// current player score
	int score;
	
	// points for moving the snake in 1 position
	int appleValue;
	
	// points for eating an apple
	int posValue;
	
	// bool insicating we have to updte the snake position or not
	bool update;

	// get the next free position, and remove that position 
	void createApple();

	// display score and game status (game over...)
	void drawStatus();

	void drawCircle(int lineAmount, float x, float y, float r);

	// init the map and score
	void initGame();

};

#endif
