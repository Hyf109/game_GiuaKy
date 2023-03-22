#include<bits/stdc++.h>
#include<conio.h>
#include<stdlib.h>

using namespace std;

int board[4][4]; //in ra bang choi game
int temp[4][4];
int canPlay = 1;


void copyBoard()
{
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            temp[i][j]=board[i][j];
}

pair<int,int> generateUnoccupiedPosition() //tao ra cap so ngau nhien
{
    int occupied = 1, line, column;
    while (occupied)
    {
        line = rand() % 4;
        column = rand() % 4;
        if(board[line][column]==0)
            occupied = 0;
    }
    return make_pair(line,column);
}


void newGame() //van moi
{
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            board[i][j]=0;

    pair<int,int> pos = generateUnoccupiedPosition();
    board[pos.first][pos.second] = 2;
}

int checkEmpty(int tmp[4][4],int a[4][4]) //ktra con cho trong khong
{
    int fl=1,i,j;
    for(i=0; i<4; i++)
        for(j=0; j<4; j++)
            if(tmp[i][j]!=a[i][j])
            {
                fl=0;
                break;
            }
    return fl;
}

int checkOver(int a[4][4]) // ktra con choi duoc tiep hay khong
{
    int fl=0,gl=0,i,j;
    for(i=0; i<4; i++)
        for(j=0; j<4; j++)
            if(a[i][j]==0)
            {
                fl=1;
                break;
            }

    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            if(a[i+1][j]==a[i][j] || a[i][j+1]==a[i][j])
            {
                gl=1;
                break;
            }

    if(fl || gl) return 1;
    else return 0;
}


void printUI() //in ra man hinh choi game
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(board[i][j]==0)
                cout << "." ;
            else cout << board[i][j];
            cout << " ";
        }
        cout << endl;
    }
    cout << "n: newGame/ w: up/ s: down/ a: left/ d: right/ q: quit" << endl;

}


void upMove(int a[4][4]) //di chuyen len
{
    int i,j,li,ri;
    for(j=0; j<4; j++)
    {
        li=0,ri=j;
        for(i=1; i<4; i++)
        {
            if(a[i][j]!=0)
            {
                if(a[i-1][j]==0 || a[i-1][j]==a[i][j])
                {
                    if(a[li][ri]==a[i][j])
                    {
                        a[li][ri]*=2;
                        a[i][j]=0;
                    }
                    else
                    {
                        if(a[li][ri]==0)
                        {
                            a[li][ri]=a[i][j];
                            a[i][j]=0;
                        }
                        else
                        {
                            a[++li][ri]=a[i][j];
                            a[i][j]=0;
                        }
                    }
                }
                else li++;
            }
        }
    }
}

void downMove(int a[4][4]) //di chuyen xuong
{
    int i,j,li,ri;
    for(j=0; j<4; j++)
    {
        li=3,ri=j;
        for(i=2; i>=0; i--)
        {
            if(a[i][j]!=0)
            {
                if(a[i+1][j]==0 || a[i+1][j]==a[i][j])
                {
                    if(a[li][ri]==a[i][j])
                    {
                        a[li][ri]*=2;
                        a[i][j]=0;
                    }
                    else
                    {
                        if(a[li][ri]==0)
                        {
                            a[li][ri]=a[i][j];
                            a[i][j]=0;
                        }
                        else
                        {
                            a[--li][ri]=a[i][j];
                            a[i][j]=0;
                        }
                    }
                }
                else li--;
            }
        }
    }
}

void leftMove(int a[4][4]) //di chuyen trai
{
    int i,j,li,ri;
    for(i=0; i<4; i++)
    {
        li=i,ri=0;
        for(j=1; j<4; j++)
        {
            if(a[i][j]!=0)
            {
                if(a[i][j-1]==0 || a[i][j-1]==a[i][j])
                {
                    if(a[li][ri]==a[i][j])
                    {
                        a[li][ri]*=2;
                        a[i][j]=0;
                    }
                    else
                    {
                        if(a[li][ri]==0)
                        {
                            a[li][ri]=a[i][j];
                            a[i][j]=0;
                        }
                        else
                        {
                            a[li][++ri]=a[i][j];
                            a[i][j]=0;
                        }
                    }
                }
                else ri++;
            }
        }
    }
}

void rightMove(int a[4][4]) //di chuyen phai
{
    int i,j,li,ri;
    for(i=0; i<4; i++)
    {
        li=i,ri=3;
        for(j=2; j>=0; j--)
        {
            if(a[i][j]!=0)
            {
                if(a[i][j+1]==0 || a[i][j+1]==a[i][j])
                {
                    if(a[li][ri]==a[i][j])
                    {
                        a[li][ri]*=2;
                        a[i][j]=0;
                    }
                    else
                    {
                        if(a[li][ri]==0)
                        {
                            a[li][ri]=a[i][j];
                            a[i][j]=0;
                        }
                        else
                        {
                            a[li][--ri]=a[i][j];
                            a[i][j]=0;
                        }
                    }
                }
                else ri--;
            }
        }
    }
}





int main()
{
    srand(time(0));


    newGame();
    while(true)
    {
        while(!canPlay)
        {
            system("cls");
            printUI();
            cout<< "Choi tiep khong?" << endl;
            cout << "Co: y/ Khum: n" << endl;
            char answer = getch();
            if(answer=='y')
            {
                canPlay=1;
                newGame();

            }
            else if(answer=='n') return 0;
        }

        copyBoard();
        system("cls");
        printUI();
        char command = getch();

        switch(command)
        {
        case 'n':
            newGame();
            break;
        case 'q':
            return 0;
        case 'w':
        {
            upMove(board);
            if(!checkEmpty(temp,board))
            {
                pair<int,int> pos = generateUnoccupiedPosition();
                board[pos.first][pos.second] = 2;
            }
            if(!checkOver(board))
            {
                cout << "Thua roi nha cu" ;
                canPlay=0;
                break;
            }
            break;
        }
        case 's':
        {
            downMove(board);
            if(!checkEmpty(temp,board))
            {
                pair<int,int> pos = generateUnoccupiedPosition();
                board[pos.first][pos.second] = 2;
            }
            if(!checkOver(board))
            {
                cout << "Thua roi nha cu" ;
                canPlay=0;
                break;
            }
            break;
        }
        case 'd':
        {
            rightMove(board);
            if(!checkEmpty(temp,board))
            {
                pair<int,int> pos = generateUnoccupiedPosition();
                board[pos.first][pos.second] = 2;
            }
            if(!checkOver(board))
            {
                cout << "Thua roi nha cu" ;
                canPlay=0;
                break;
            }
            break;
        }
        case 'a':
        {
            leftMove(board);
            if(!checkEmpty(temp,board))
            {
                pair<int,int> pos = generateUnoccupiedPosition();
                board[pos.first][pos.second] = 2;
            }
            if(!checkOver(board))
            {
                cout << "Thua roi nha cu" ;
                canPlay=0;
                break;
            }
            break;
        }


        }
    }



    return 0;
}
