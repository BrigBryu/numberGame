#include <ncurses.h>
#include <string.h>

void printAGuy(char mesg[]) {
    int row,col;
    getmaxyx(stdscr, row, col); /* get the number of rows and columns */
    mvprintw(row / 2, (col - (int) strlen(mesg)) / 2, "%s", mesg);
    /* print the message at the center of the screen */
    mvprintw(row - 2, 0, "This screen has %d rows and %d columns\n", row, col);
    printw("Try resizing your window(if possible) and then run this program again");
    refresh();
    getch();
}

void getInput() {
        char mesg[] = "Enter a string: ";   /* message to be appeared on the screen */
    char str[80];
    int row, col;               /* to store the number of rows and */

    getmaxyx(stdscr, row, col); /* get the number of rows and columns */
    mvprintw(row / 2, (col - (int) strlen(mesg)) / 2, "%s", mesg);
    /* print the message at the center of the screen */
    getstr(str);
    mvprintw(LINES - 2, 0, "You Entered: %s", str);
    getch();

}
int main(){
    initscr(); //needed to start any ncurses stuff alocates ncurses memory
    raw();//this lets characters available as soon as the user types them
    //echo(); characters typed are shown on screen
    //noecho(); characters not typed on screen are not shown
    keypad(stdscr, TRUE); //lets use arowkeys
    //printAGuy("HIIIII I am computer");
    getInput();

/*
    printw("Hello world!\n Enter a character:"); //batch drawing
    refresh(); // draw the batch
    char c = getch(); //  can disable the line buffering to avoid <enter> after input where getchar cant
    mvprintw(10,5,"\nyou gave the char: %c", c);
    getch(); // waits for input bfoer continuing and ending
*/
    endwin(); //closes and frees ncurses memory

    return 0;
}
