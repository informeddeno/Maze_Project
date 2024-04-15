#include "../headers/header.h"
#include "SDL2/SDL.h"

bool GameRunning = true;
int TicksLastFrame;
player_t player;

/**
 * setup_game - initialize player variables and load wall textures
 *
*/

void setup_game(void)
{

	player.x = SCREEN_WIDTH / 2;
	player.y = SCREEN_HEIGHT / 2;
	player.width = 1;
	player.height = 30;
	player.walkDirection = 0;
	player.walkSpeed = 100;
	player.turnDirection = 0;
	player.turnSpeed = 45 * (PI / 180);
	player.rotationAngle = PI / 2;
	WallTexturesready();
}


/**
 * update_game - update_game delta time, the ticks last frame
 *          the player movement and the ray casting
 *
*/
void update_game(void)
{
	float DeltaTime;
	int timeToWait = FRAME_TIME_LENGTH - (SDL_GetTicks() - TicksLastFrame);

	if (timeToWait > 0 && timeToWait <= FRAME_TIME_LENGTH)
	{
		SDL_Delay(timeToWait);
	}
	DeltaTime = (SDL_GetTicks() - TicksLastFrame) / 1000.0f;

	TicksLastFrame = SDL_GetTicks();

	movePlayer(DeltaTime);
	castAllRays();
}

/**
 * render - calls all functions needed for on-screen rendering
 *
*/

void render_game(void)
{
	clearColorBuffer(4278190080);

	renderWall();

	renderMap();
	renderRays();
	renderPlayer();

	renderColorBuffer();
}

/**
 * Destroy - free wall textures and destroy window
 *
*/
void destroy_game(void)
{
	freeWallTextures();
	destroyWindow();
}

/**
 * main - main function
 * Return: 0
*/

int main(void)
{
        SDL_Init(SDL_INIT_EVERYTHING);

	if(SDL_Init(SDL_INIT_EVERYTHING) > 0){
        printf("SDL could not be initialized\n");
        SDL_GetError();
	}else
	{
        printf("SDL video system is ready to go\n");
	}

	
	SDL_Window *window = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	bool initializeWindow(void);
	 if (!initializeWindow()) {
        fprintf(stderr, "Error initializing window.\n");
        return 1; // Exit with error
    }
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_Delay(3000);

	setup_game();

	while (GameRunning)
	{
		handleInput();
		update_game();
		render_game();
	}
	destroy_game();
	return (0);
}
