#include <ncurses.h>
#include <windows.h>
#include <stdlib.h>
#include <cstdlib>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

#define KEY_SPACE 32

using namespace std;

int poin1=0, poin2=0;

void menu00(){
	mvprintw(7,51,"................");
   	mvprintw(8,51,"|1| PLAY A GAME|");
   	mvprintw(9,51,"................");
   	
   	mvprintw(10,51,"................");
	mvprintw(11,51,"|2| LEADERBOARD|");
    mvprintw(12,51,"................");
    
    mvprintw(13,51,"................");
    mvprintw(14,51,"|3|    EXIT    |");
    mvprintw(15,51,"................");
}

void menu11(){
	mvprintw(7,48,"   ................");
   	mvprintw(8,48,"=> |1| PLAY A GAME|");
   	mvprintw(9,48,"   ................");
   	
   	mvprintw(10,48,"   ................");
	mvprintw(11,48,"   |2| LEADERBOARD|");
    mvprintw(12,48,"   ................");
    
    mvprintw(13,48,"   ................");
    mvprintw(14,48,"   |3|    EXIT    |");
    mvprintw(15,48,"   ................");
}

void menu22(){
	mvprintw(7,48,"   ................");
   	mvprintw(8,48,"   |1| PLAY A GAME|");
   	mvprintw(9,48,"   ................");
	
	mvprintw(10,48,"   ................");
	mvprintw(11,48,"=> |2| LEADERBOARD|");
    mvprintw(12,48,"   ................");
    
    mvprintw(13,48,"   ................");
    mvprintw(14,48,"   |3|    EXIT    |");
    mvprintw(15,48,"   ................");
}

void menu33(){
	mvprintw(7,48,"   ................");
   	mvprintw(8,48,"   |1| PLAY A GAME|");
   	mvprintw(9,48,"   ................");
   	
   	mvprintw(10,48,"   ................");
	mvprintw(11,48,"   |2| LEADERBOARD|");
    mvprintw(12,48,"   ................");
    
	mvprintw(13,48,"   ................");
    mvprintw(14,48,"=> |3|    EXIT    |");
    mvprintw(15,48,"   ................");
}

void menu();
void leaderboard();
void game();

int main(){
    
   	initscr();
   	
   	curs_set(0);
   	
   	WINDOW * win = newwin(20, 75, 3, 23);
	refresh();
	box(win, 0, 0);
    wrefresh(win);
    
   	start_color();
	init_pair(1,COLOR_BLACK,COLOR_YELLOW);

    
   	mvprintw(7,46,"=+=+=+=+=+ WELCOME +=+=+=+=+=");
   	mvprintw(8,48,"  [Press Any Key to Start]"    );
   	refresh();
	Sleep(3000);	
   	getch();
   	
    
    WINDOW * win1 = newwin(20, 75, 3, 23);
   	refresh();
	box(win1, 0, 0);
    wrefresh(win1);
    
    mvprintw(10,56,"Loading...");
    
   	attron(COLOR_PAIR(1));
   	
   	for (int i = 1; i <= 12; i++){
   		mvprintw(9,54+i, "_");
   		refresh();
		Sleep(200);
	}
	   
   	attroff(COLOR_PAIR(1));
   	
    menu();
    
   	getch();
   	
   	endwin();
   	
    	
}

void game(){
	char finish[8] = {'|','F','I','N','I','S','H','|'};
	
	WINDOW * win2 = newwin(20, 75, 3, 23);
   	refresh();
	box(win2, 0, 0);
    wrefresh(win2);
	char pil;
	int a = 10, b = 52, x, c = 11 , d = 52, y;
	
	keypad(stdscr,TRUE);
	srand(time(NULL));
	x = (rand()%6)+1;
	y = (rand()%6)+1;
	mvprintw(9,48,"Press space for spin dice!");
	mvprintw(10, 48, "P1");
	mvprintw(11, 48, "P2");
	mvprintw(a, b, ".");
	mvprintw(c, d, ",");
	for (int i = 0; i <= 7; i++ ){
		mvprintw(10, 66+i, "%c", finish[i]);
		mvprintw(11, 66+i, "%c", finish[i]);
	}

	while( b < 65 && d < 65){
		char dice = getch();
		if(dice == KEY_SPACE){
			b += x;
			for(int i = 53 ; i <= b ; i++){
				refresh();
				Sleep(100);
				mvprintw(a, i, ".");
			}
		}
		dice = getch();
		if(dice == KEY_SPACE){
			d += y;
			for(int i = 53 ; i <= d ; i++){
				refresh();
				Sleep(100);
				mvprintw(c, i, ",");
			}
		}		
	}
	
	if (b >= 65){
		clear();
        refresh();
        box(win2, 0, 0);
        wrefresh(win2); 
		mvprintw(11,57,"[P1 WIN!]");
		poin1++;
	} else if (d >= 65){
		clear();
        refresh();
      	box(win2, 0, 0);
        wrefresh(win2); 
		mvprintw(11,57,"[P2 WIN!]");
		poin2++;
	}
	refresh();
	box(win2, 0, 0);
	mvprintw(19, 55, "Back to menu? (y/n)");
	char back = getch();
	if(back == 'y'){
		menu();
	} else if(back == 'n'){
		exit(0);
	}
}

void menu(){
   	
   	WINDOW * win2 = newwin(20, 75, 3, 23);
   	refresh();
	box(win2, 0, 0);
    wrefresh(win2);
    
   	mvprintw(5,52,"Go-Ahead Dice");
   	mvprintw(6,54,"MAIN MENU");

   	menu00();

//#define KEY_UP 72
//#define KEY_DOWN 80

	char pilihan;
   	int selection = 2;

	for(int i=0; ; ){
		
		noecho();
		
		pilihan = getch();
		
		if(pilihan == 72 && (selection >= 2 && selection <=3)){
			selection--;
		}
	
		if(pilihan == 80 && (selection >= 1 && selection <=2)){
			selection++;
		}
		if(pilihan == '\n'){
			if (selection == 1 ){
				clear();
        		game();
        	}
        	
        	else if (selection == 2 ){
				clear();
	        	leaderboard();
	    	}
	    	
	    	else if(selection == 3){
        		printw("\n== Program dihentikan==\n");
				exit(0);
			}
		}
		
		if(selection==1){
			menu11();		
		}
		
		if(selection==2){
			menu22();
		}
		
		if(selection==3){
			menu33();		
		}
	}
}

void leaderboard(){
	clear();
	mvprintw(9,46,"_______________________________");
	mvprintw(10,46,"||       PLAYER       || WIN ||");
	mvprintw(11,46,"||====================||=====||");
	mvprintw(12,46,"||         P1         ||     ||");
	mvprintw(13,46,"||         P2         ||     ||");
	mvprintw(14,46,"||____________________||_____||");
	
	move(53, 77);
	mvprintw(12,72,"%d", poin1);
	move(54, 77);
	mvprintw(13,72,"%d", poin2);
	
	mvprintw(18, 52, "Back to menu?(y/n)");
	char back = getch();
	if(back == 'y'){
		menu();
	} else if(back == 'n'){
		exit(0);
	}
}