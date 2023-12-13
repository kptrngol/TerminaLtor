#include <stdio.h>
#include <stdlib.h>


void drawScene();
void drawAvatar();
void playerInput();
void clear();
void check();
void savingPreviousAvatarPos();
int collisionDetection();


int main() {

    int mapH, mapW, avatarR, avatarC, avatarLastC, avatarLastR, win;
    win = 0;
    mapH = 5;
    mapW = 21;
    avatarR = 3;
    avatarC = 1;
    avatarLastR = 3;
    avatarLastC = 1;

    char gameMap[5][21] = 
    {
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','\n'},
        {'#','$','#','#','$','#',' ',' ',' ',' ','#','$','#','#',' ','#',' ','#','@','#','\n'},
        {'#',' ',' ','#',' ',' ',' ',' ','#','#','#',' ','#','#',' ','#',' ',' ',' ','#','\n'},
        {'#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#','\n'},
        {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','\n'}
    };

    char (*ptoMap)[21] = gameMap;
    printf("\n!Type a/w/s/d and click enter to move!\n\n");
    
    while(win != 1)
    {
    drawAvatar(avatarR,avatarC,ptoMap);
    drawScene(mapH, mapW, ptoMap);
    check(&win, ptoMap, mapH, mapW,3);
    savingPreviousAvatarPos(&avatarLastR,&avatarLastC,&avatarR,&avatarC);
    clear(avatarR, avatarC, ptoMap);
    // playerInput(&avatarR,&avatarC);
    do 
    {
        playerInput(&avatarR,&avatarC);
    } while (collisionDetection(ptoMap,&avatarLastR,&avatarLastC,&avatarR,&avatarC));
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

    p[r][c] = 'H';
}
void playerInput(int *row,int *column) 
{
    char mv;
    do 
    {
    scanf("%c",&mv);
    } while ((mv != 'a') && (mv != 'd') && (mv != 'w') && (mv != 's'));

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
void check(int * winCheck,char (*p)[21],int h,int w, int max)
{
    // points left counter
    int point = 0;

    for (int i = 0; i < h; i++) 
    {
        for (int j = 0; j < w; j++)
        {   
            if (p[i][j] == '$') 
            {
                point ++;
            }
        }
    }

    if (p[1][18] == 'H') 
    {
        if ((max-point) == max) 
        {
            printf("You terminalted this level!\n");
            exit(EXIT_SUCCESS);
        } else 
        {
            printf("You still have %d point$ to collect\n", point);
        }
    }
}
void savingPreviousAvatarPos(int * lastR,int * lastC,int * r, int * c)
{
    *lastR = *r;
    *lastC = *c;

}
int collisionDetection(char (*p)[21],int * lastR,int * lastC,int * r,int * c)
{
    int r1, c1;
    char el;
    r1 = *r;
    c1 = *c;
    el = p[r1][c1];
    if (el == '#') 
    {   
        *r = *lastR;
        *c = *lastC;
        return 1;
    } else 
    {
        return 0;
    }
    return 0;
}