#include "Xandaria.h"

//Score system variables
int score;

char* intro_text = "Xandaria: The tale of a tragic hero embarking on the journey he never wanted...\n\r\
to save a girl he would never love. He will realize that everything he thought he knew was wrong,\n\r\
and that there is a power within him he will never know...";

int main(){
  system("stty raw");
  intro();
  start_story();
  int ending = check_score();
  end_game(ending);
}

void intro(){//Run intro sequence
  TYPE(intro_text);
}

void type_text(char* string){//Print text on screen to simulate typing
  int size = strlen(string);
  for(int i = 0; i < size; i++) {
    write(1, string++, 1);
    //fprintf(stderr, "%c", string[i]);
    delay(SPEED);
    if(string[i] == '\n'){
      delay(LINE);
    }
  }
}

void start_story(){
  //Call story functions, modularization will allow for easy addition, as well as editing
  score = 0;
  char answer;
  char *decisions[] = {"You arrive at the large gates of Xandaria. Do you wish to proceed? (y/n)", "Do you want an adventure?", 
    "You see a helpless old lady, do you want to mug her?"};
  char *text[] = {"And so it begins... ", "Fine, we didn't want you anyway...", "Welcome, Brave Hero. Your Journey Awaits...", 
    "If you aren't going to be a hero, get out!", "You gain 10 gold.", "You did the right thing."};
  int i = 0, j = 0, maxd = sizeof(decisions)/sizeof(char *), maxt = sizeof(text)/sizeof(char *), flag = 0;
  while(i < maxd && j < maxt){
    TYPE(decisions[i]);
    read(0, &answer, 1);
    printf("%c\r\n", answer);
    //write(1, &answer, 1);
    //answer = getchar();
    do{
      if(answer == 'y'){
        TYPE(text[i<<1]);
      }
      else if(answer == 'n'){
        TYPE(text[(i<<1)+1]);
        if(!flag) return;
      }
      else{
        TYPE("Please type y or n...\n\r");
        read(0, &answer, 1);
        printf("%c\r\n", answer);
        continue;
      }
    } while(answer != 'y' && answer != 'n');
    i++;
    if(i>=2) --flag;
  }
}

int check_score(){//Check score variables to choose ending
  return score;
}

void end_game(int num){//Choose ending based on score
  system("stty cooked");
  switch(num){
    case 0:
      TYPE("You did nothing...\nWhy?");
      break;
    case 1:
      break;
    default:
      break;
  }
}

void delay(int milliseconds)
{
  long pause;
  clock_t now,then;

  pause = milliseconds*(CLOCKS_PER_SEC/1000);
  now = then = clock();
  while( (now-then) < pause )
    now = clock();
}

void type_pause(char *str){
  type_text(str);
  delay(PAUSE);
  type_text("\n\r");
}