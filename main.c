#include <stdio.h>
#include <stdlib.h>

void drawScene(int mapH, int mapW, char (*p)[21]);
void drawAvatar();
void playerInput();
void clear();
void check();

int main() {
    int mapH, mapW, avatarR, avatarC, avatarLastC, avatarLastR, win;
    win = 0;
    mapH = 5;
    mapW = 21;
    avatarR = 3;
    avatarC = 1;
    avatarLastR = 3;
    avatarLastC = 1;
    int * pWin = &win;
    int * pAvatarR = &avatarR;
    int * pAvatarC = &avatarC;
    int * pAvatarLastR = &avatarLastR;
    int * pAvatarLastC = &avatarLastC;
    

    char gameMap[5][21] = 
    {
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','\n'},
        {'#','&','#','#',' ','#',' ',' ',' ',' ','#',' ','#','#',' ','#',' ','#',' ','$','\n'},
        {'#',' ',' ','#',' ',' ',' ',' ','#','#','#',' ','#','#',' ','#',' ',' ',' ','#','\n'},
        {'#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#','\n'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','\n'}
    };

    char (*ptoMap)[21] = gameMap;

    while(win != 1)
    {
    drawAvatar(avatarR,avatarC,ptoMap);
    drawScene(mapH, mapW, ptoMap);
    check(&pWin, ptoMap);
    clear(avatarR, avatarC, ptoMap);
    playerInput(&avatarR,&avatarC); 
    }


}

void drawScene(int mapH, int mapW, char (*p)[21])
{
    for (int h = 0; h < mapH; h++)
    {
        for (int w = 0; w < mapW; w++)
        {
            printf("%c",p[h][w]);
        }
    }
    printf("\n");
}

void drawAvatar(int r,int c, char (*p)[21]) 
{

    p[r][c] = 'A';
}

void playerInput(int *row,int *column) 
{
    char mv;
    scanf("%c",&mv);
    switch(mv)
    {
        case 'a':
            (*column)--;
            break;
        case 'd':
            (*column)++;
            break;
        case 'w':
            (*row)--;
            break;
        case 's':
            (*row)++;
            break;
    }
    
}

void clear(int r, int c, char (*p)[21]) 
{
    p[r][c] = ' ';
}
void check(int*w,char (*p)[21])
{
    printf("Absorb the %c!\n",p[1][19]);
    if ((p[1][19]) == 'A') 
    {
        exit(EXIT_SUCCESS);
    }
}