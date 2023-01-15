#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <windows.h>

void loading(){
        HANDLE hConsole;
        hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
system("cls");
system("color 0A");
printf("\n\n\n\n\n\n\n");
printf("\t\t  __          __          __  ________   __        _______   _______   __    __   ________       ");printf("\n");
printf("\t\t  \\ \\        /  \\        / / |  ______| | |       |  _____| |  ____ | |   \\/   | |  ______|  ");printf("\n");
printf("\t\t   \\ \\      / /\\ \\      / /  | |        | |       | |       | |   | | | |\\__/| | | |        ");printf("\n");
printf("\t\t    \\ \\    / /  \\ \\    / /   | |______  | |       | |       | |   | | | |    | | | |______   ");printf("\n");
printf("\t\t     \\ \\  / /    \\ \\  / /    | |        | |       | |       | |   | | | |    | | | |         ");printf("\n");
printf("\t\t      \\ \\/ /      \\ \\/ /     | |______  | |_____  | |_____  | |___| | | |    | | | |______   ");printf("\n");
printf("\t\t       \\__/        \\__/      |________| |_______| |_______| |_______| |_|    |_| |________|    ");printf("\n\n");
printf("\t\t\t\t\t\t            Loading   \n");
SetConsoleTextAttribute(hConsole,2);
printf("\t\t\t\t\t\t      ____________________\n");
printf("\t\t\t\t\t\t      ");
SetConsoleTextAttribute(hConsole,4);
for(int i=0;i<20;i++){
    printf("%c",178);
    usleep(100000);
    fflush(stdout);
}
SetConsoleTextAttribute(hConsole,241);
}


