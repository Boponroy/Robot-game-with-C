#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
//*****functions*****
//universal
void game_start();
void difficulty(int *x);
//easy mode
void generate_easy(int *ptr, int *player, int *life);
void render_easy(int x[][5]);
void change_easy(int *ptr, char move, int *player, int *life);
//medium mode
void generate_mid(int *ptr, int *player, int *life);
void render_mid(int x[][10]);
void change_mid(int *ptr, char move, int *player, int *life);
//hard mode
void generate_hard(int *ptr, int *player, int *life);
void render_hard(int x[][15]);
void change_hard(int *ptr, char move, int *player, int *life);

//*****main start here*****
void main()
{
    //variables
    int board_easy[5][5];
    int board_mid[10][10];
    int board_hard[15][15];
    char move;
    int player_flag, player_life, player_difficulty;

    //main body
    game_start();
    difficulty(&player_difficulty);
    if(player_difficulty==1)
    {
        system("cls");
        generate_easy(&board_easy[0][0], &player_flag, &player_life);
        render_easy(board_easy);
        for(;;)
        {
            if(player_flag==50)
            {
                printf("\n");
                printf("Enter your move: ");
                scanf(" %c", &move);
                change_easy(&board_easy[0][0], move, &player_flag, &player_life);
                render_easy(board_easy);
            }
            else if(player_flag==60)
            {
                printf("\n==========================================\n");
                printf("You landed on a bomb. Game Over!\n\a");
                printf("==========================================\n");
                break;
            }
            else if(player_flag==70)
            {
                printf("\n==========================================\n");
                printf("Congratulations. YOU WIN!!!\n\a");
                printf("==========================================\n");
                break;
            }
        }
    }
    else if(player_difficulty==2)
    {
        system("cls");
        generate_mid(&board_mid[0][0], &player_flag, &player_life);
        render_mid(board_mid);
        for(;;)
        {
            if(player_flag==50)
            {
                printf("\n");
                printf("Enter your move: ");
                scanf(" %c", &move);
                change_mid(&board_mid[0][0], move, &player_flag, &player_life);
                render_mid(board_mid);
            }
            else if(player_flag==60)
            {
                printf("\n==========================================\n");
                printf("You landed on a bomb. Game Over!\n\a");
                printf("==========================================\n");
                break;
            }
            else if(player_flag==70)
            {
                printf("\n==========================================\n");
                printf("Congratulations. YOU WIN!!!\n\a");
                printf("==========================================\n");
                break;
            }
        }
    }
    else if(player_difficulty==3)
    {
        system("cls");
        generate_hard(&board_hard[0][0], &player_flag, &player_life);
        render_hard(board_hard);
        for(;;)
        {
            if(player_flag==50)
            {
                printf("\n");
                printf("Enter your move: ");
                scanf(" %c", &move);
                change_hard(&board_hard[0][0], move, &player_flag, &player_life);
                render_hard(board_hard);
            }
            else if(player_flag==60)
            {
                printf("\n==========================================\n");
                printf("You landed on a bomb. Game Over!\n\a");
                printf("==========================================\n");
                break;
            }
            else if(player_flag==70)
            {
                printf("\n==========================================\n");
                printf("Congratulations. YOU WIN!!!\n\a");
                printf("==========================================\n");
                break;
            }
        }
    }


    //get char function
    getch();
}

//start function
void game_start()
{
    printf("==========================================\n");
    printf("Let the game begin!!!\n");
    printf("==========================================\n");
    printf("Use as many moves as you want.\n");
    printf("Beware of bombs hidden in the grid.\n");
    printf("------------------------------------------\n");
    printf("'w'= up, 'a'= left, 's'= down, 'd'= right\n");
    printf("------------------------------------------\n\n\n");
}

//difficulty selection
void difficulty(int *x)
{
    int diff;
    printf("==========================================\n");
    printf("Please select your difficulty level.\n");
    printf("==========================================\n");
    printf("1) Easy Mode\n\n");
    printf("2) Medium Mode\n\n");
    printf("3) Hard Mode\n\n");
    scanf("%d", &diff);
    *x=diff;
}

//generate easy starting grid
void generate_easy(int *ptr, int *player, int *life)
{
    *life=3;
    *player=50;
    //initialize all to zero
    srand(time(NULL));
    for(int i=0; i<=25; i++)
    {
        *(ptr+i)=0;
    }

    //10-12 bombs initialize
    for(int i=0; i<5; i++)
    {
        *(ptr+(rand()%25))=5;
    }

    //destination set to 100
    *(ptr+24)=100;

    //starting robot position
    *(ptr)=1;
}

//generate medium starting grid
void generate_mid(int *ptr, int *player, int *life)
{
    *life=2;
    *player=50;
    //initialize all to zero
    srand(time(NULL));
    for(int i=0; i<=100; i++)
    {
        *(ptr+i)=0;
    }

    //10-12 bombs initialize
    for(int i=0; i<20; i++)
    {
        *(ptr+(rand()%100))=5;
    }

    //destination set to 100
    *(ptr+99)=100;

    //starting robot position
    *(ptr)=1;
}

//generate hard starting grid
void generate_hard(int *ptr, int *player, int *life)
{
    *life=1;
    *player=50;
    //initialize all to zero
    srand(time(NULL));
    for(int i=0; i<=225; i++)
    {
        *(ptr+i)=0;
    }

    //10-12 bombs initialize
    for(int i=0; i<45; i++)
    {
        *(ptr+(rand()%225))=5;
    }

    //destination set to 100
    *(ptr+224)=100;

    //starting robot position
    *(ptr)=1;
}

//rendering the updated easy grid
void render_easy(int x[][5])
{
    system("cls");
    printf("==========================================\n");
    printf("Easy Mode.\n");
    printf("==========================================\n");
    printf("------------------------------------------\n");
    printf("'w'= up, 'a'= left, 's'= down, 'd'= right\n");
    printf("------------------------------------------\n\n");
    //printing the whole grid
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(x[i][j]==1)
            {
                printf(":D ");
            }
            else if(x[i][j]==100)
            {
                printf("[]");
            }
            else if(x[i][j]==10)
            {
                printf("XO ");
            }
            else if(x[i][j]==20)
            {
                printf("[_]");
            }
            else
            {
                printf("*  ", x[i][j]); //replace '*' with %d to show all the bombs.
            }
        }
        printf("\n");
    }
}

//rendering the updated medium grid
void render_mid(int x[][10])
{
    system("cls");
    printf("==========================================\n");
    printf("Medium Mode.\n");
    printf("==========================================\n");
    printf("------------------------------------------\n");
    printf("'w'= up, 'a'= left, 's'= down, 'd'= right\n");
    printf("------------------------------------------\n\n");
    //printing the whole grid
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(x[i][j]==1)
            {
                printf(":D ");
            }
            else if(x[i][j]==100)
            {
                printf("[]");
            }
            else if(x[i][j]==10)
            {
                printf("XO ");
            }
            else if(x[i][j]==20)
            {
                printf("[_]");
            }
            else
            {
                printf("*  ", x[i][j]); //replace '*' with %d to show all the bombs.
            }
        }
        printf("\n");
    }
}

//rendering the updated hard grid
void render_hard(int x[][15])
{
    system("cls");
    printf("==========================================\n");
    printf("Hard Mode.\n");
    printf("==========================================\n");
    printf("------------------------------------------\n");
    printf("'w'= up, 'a'= left, 's'= down, 'd'= right\n");
    printf("------------------------------------------\n\n");
    //printing the whole grid
    for(int i=0; i<15; i++)
    {
        for(int j=0; j<15; j++)
        {
            if(x[i][j]==1)
            {
                printf(":D ");
            }
            else if(x[i][j]==100)
            {
                printf("[]");
            }
            else if(x[i][j]==10)
            {
                printf("XO ");
            }
            else if(x[i][j]==20)
            {
                printf("[_]");
            }
            else
            {
                printf("*  ", x[i][j]); //replace '*' with %d to show all the bombs.
            }
        }
        printf("\n");
    }
}

//user inputted movement in easy grid
void change_easy(int *ptr, char move, int *player, int *life)
{
    if((move=='w')||(move=='a')||(move=='s')||(move=='d'))
    {
        for(int i=0; i<=25; i++)
        {
            if(move=='w')
            {
                if(*(ptr+i)==1)
                {
                    if((ptr+i-5)>=ptr)
                    {
                        if(*(ptr+i-5)==0)
                        {
                            *(ptr+i-5)=1;
                            *(ptr+i)=0;
                            break;
                        }
                        else if(*(ptr+i-5)==5)
                        {
                            *(ptr+i-5)=10;
                            *(ptr+i)=0;
                            *player=60;
                            *life--;
                            break;
                        }
                    }
                }
            }
            else if(move=='a')
            {
                if(*(ptr+i)==1)
                {
                    if(*(ptr+i-1)==0)
                    {
                        *(ptr+i-1)=1;
                        *(ptr+i)=0;
                        break;
                    }
                    else if(*(ptr+i-1)==5)
                    {
                        *(ptr+i-1)=10;
                        *(ptr+i)=0;
                        *player=60;
                        *life--;
                        break;
                    }
                }
            }
            else if(move=='s')
            {
                if(*(ptr+i)==1)
                {
                    if((ptr+i+5)<=(ptr+24))
                    {
                        if(*(ptr+i+5)==0)
                        {
                            *(ptr+i+5)=1;
                            *(ptr+i)=0;
                            break;
                        }
                        else if(*(ptr+i+5)==5)
                        {
                            *(ptr+i+5)=10;
                            *(ptr+i)=0;
                            *player=60;
                            *life--;
                            break;

                        }
                        else if(*(ptr+i+5)==100)
                        {
                            *(ptr+i+5)=20;
                            *(ptr+i)=0;
                            *player=70;
                            break;
                        }
                    }
                }
            }
            else if(move=='d')
            {
                if(*(ptr+i)==1)
                {
                    if(*(ptr+i+1)==0)
                    {
                        *(ptr+i+1)=1;
                        *(ptr+i)=0;
                        break;
                    }
                    else if(*(ptr+i+1)==5)
                    {
                        *(ptr+i+1)=10;
                        *(ptr+i)=0;
                        *player=60;
                        *life--;
                        break;
                    }
                    else if(*(ptr+i+1)==100)
                    {
                        *(ptr+i+1)=20;
                        *(ptr+i)=0;
                        *player=70;
                        break;
                    }
                }
            }
        }
    }
    else
    {
        printf("\a");
    }
}

//user inputted movement in medium grid
void change_mid(int *ptr, char move, int *player, int *life)
{
    if((move=='w')||(move=='a')||(move=='s')||(move=='d'))
    {
        for(int i=0; i<=100; i++)
        {
            if(move=='w')
            {
                if(*(ptr+i)==1)
                {
                    if((ptr+i-10)>=ptr)
                    {
                        if(*(ptr+i-10)==0)
                        {
                            *(ptr+i-10)=1;
                            *(ptr+i)=0;
                            break;
                        }
                        else if(*(ptr+i-10)==5)
                        {
                            *(ptr+i-10)=10;
                            *(ptr+i)=0;
                            *player=60;
                            *life--;
                            break;
                        }
                    }
                }
            }
            else if(move=='a')
            {
                if(*(ptr+i)==1)
                {
                    if(*(ptr+i-1)==0)
                    {
                        *(ptr+i-1)=1;
                        *(ptr+i)=0;
                        break;
                    }
                    else if(*(ptr+i-1)==5)
                    {
                        *(ptr+i-1)=10;
                        *(ptr+i)=0;
                        *player=60;
                        *life--;
                        break;
                    }
                }
            }
            else if(move=='s')
            {
                if(*(ptr+i)==1)
                {
                    if((ptr+i+10)<=(ptr+99))
                    {
                        if(*(ptr+i+10)==0)
                        {
                            *(ptr+i+10)=1;
                            *(ptr+i)=0;
                            break;
                        }
                        else if(*(ptr+i+10)==5)
                        {
                            *(ptr+i+10)=10;
                            *(ptr+i)=0;
                            *player=60;
                            *life--;
                            break;
                        }
                        else if(*(ptr+i+10)==100)
                        {
                            *(ptr+i+10)=20;
                            *(ptr+i)=0;
                            *player=70;
                            break;
                        }
                    }
                }
            }
            else if(move=='d')
            {
                if(*(ptr+i)==1)
                {
                    if(*(ptr+i+1)==0)
                    {
                        *(ptr+i+1)=1;
                        *(ptr+i)=0;
                        break;
                    }
                    else if(*(ptr+i+1)==5)
                    {
                        *(ptr+i+1)=10;
                        *(ptr+i)=0;
                        *player=60;
                        *life--;
                        break;
                    }
                    else if(*(ptr+i+1)==100)
                    {
                        *(ptr+i+1)=20;
                        *(ptr+i)=0;
                        *player=70;
                        break;
                    }
                }
            }
        }
    }
    else
    {
        printf("\a");
    }
}

//user inputted movement in hard grid
void change_hard(int *ptr, char move, int *player, int *life)
{
    if((move=='w')||(move=='a')||(move=='s')||(move=='d'))
    {
        for(int i=0; i<=225; i++)
        {
            if(move=='w')
            {
                if(*(ptr+i)==1)
                {
                    if((ptr+i-15)>=ptr)
                    {
                        if(*(ptr+i-15)==0)
                        {
                            *(ptr+i-15)=1;
                            *(ptr+i)=0;
                            break;
                        }
                        else if(*(ptr+i-15)==5)
                        {
                            *(ptr+i-15)=10;
                            *(ptr+i)=0;
                            *player=60;
                            *life--;
                            break;
                        }
                    }
                }
            }
            else if(move=='a')
            {
                if(*(ptr+i)==1)
                {
                    if(*(ptr+i-1)==0)
                    {
                        *(ptr+i-1)=1;
                        *(ptr+i)=0;
                        break;
                    }
                    else if(*(ptr+i-1)==5)
                    {
                        *(ptr+i-1)=10;
                        *(ptr+i)=0;
                        *player=60;
                        *life--;
                        break;
                    }
                }
            }
            else if(move=='s')
            {
                if(*(ptr+i)==1)
                {
                    if((ptr+i+15)<=(ptr+224))
                    {
                        if(*(ptr+i+15)==0)
                        {
                            *(ptr+i+15)=1;
                            *(ptr+i)=0;
                            break;
                        }
                        else if(*(ptr+i+15)==5)
                        {
                            *(ptr+i+15)=10;
                            *(ptr+i)=0;
                            *player=60;
                            *life--;
                            break;
                        }
                        else if(*(ptr+i+15)==100)
                        {
                            *(ptr+i+15)=20;
                            *(ptr+i)=0;
                            *player=70;
                            break;
                        }
                    }
                }
            }
            else if(move=='d')
            {
                if(*(ptr+i)==1)
                {
                    if(*(ptr+i+1)==0)
                    {
                        *(ptr+i+1)=1;
                        *(ptr+i)=0;
                        break;
                    }
                    else if(*(ptr+i+1)==5)
                    {
                        *(ptr+i+1)=10;
                        *(ptr+i)=0;
                        *player=60;
                        *life--;
                        break;
                    }
                    else if(*(ptr+i+1)==100)
                    {
                        *(ptr+i+1)=20;
                        *(ptr+i)=0;
                        *player=70;
                        break;
                    }
                }
            }
        }
    }
    else
    {
        printf("\a");
    }
}

