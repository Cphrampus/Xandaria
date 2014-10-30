#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#define TYPE(a) type_pause(a)
#ifdef DEBUG
#define SPEED 0
#define LINE 0
#define PAUSE 0
#else
#define SPEED 125
#define LINE 250
#define PAUSE 1000
#endif

int score;
char* intro_text;
void intro();
void type_text(char* string);
void start_story();
int check_score();
void end_game();
void delay(int milliseconds);
void type_pause(char* str);