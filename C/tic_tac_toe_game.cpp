#include<bits/stdc++.h>
using namespace std;

void draw_board(char[]);
int check_winner(char[]);
int check_double(char[]);

int main()
{
    int i;
    char sign;
    int win;
    char board[9]={'1','2','3','4','5','6','7','8','9'};
    for(i=0;i<9;i++)
    {
    win=check_winner(board);
    if(win==1)
    {
        system("cls");
        draw_board(board);
        cout<<endl<<"Player 1 is winner ...!"<<endl;
        break;
    }
    else
    {
        if(win==0)
        {
            system("cls");
            draw_board(board);
            cout<<endl<<"Player 2 is winner ...!"<<endl;
            break;
        }
    }
    int player=(i%2)+1;
    int num;
    draw_board(board);
    cout<<"Player "<<player<<" enter the position :";
    cin>>num;
    num = num-1;
    if(board[num]=='X' || board[num]=='O')
    {
        system("cls");
        draw_board(board);
        num=check_double(board);
    }
    if(player==1)
    {
        sign='X';
    }
    else
    {
        sign='O';
    }
    board[num]=sign;
    draw_board(board);
    }
    if(board[0]!='1'&& board[1]!='2' && board[2]!='3' && board[3]!='4' && board[4]!='5' && board[5]!='6' && board[6]!='7' && board[7]!='8' && board[8]!='9')
    {
        win=check_winner(board);
        if(win==2)
        {
            system("cls");
            draw_board(board);
            cout<<endl<<"Game is Draw"<<endl;
        }
    }
    return 0;
    system("pause");
}

void draw_board(char a[])
{
    system("cls");
    cout<<"          |"<<" "<<a[0]<<" "<<"|"<<" "<<a[1]<<" "<<"|"<<" "<<a[2]<<" "<<"|"<<endl;
    cout<<" Tic      |"<<"===+"<<"===+"<<"===+"<<endl;
    cout<<"   Tac    |"<<" "<<a[3]<<" "<<"|"<<" "<<a[4]<<" "<<"|"<<" "<<a[5]<<" "<<"|"<<endl;
    cout<<"     Toe  |"<<"===+"<<"===+"<<"===+"<<endl;
    cout<<"          |"<<" "<<a[6]<<" "<<"|"<<" "<<a[7]<<" "<<"|"<<" "<<a[8]<<" "<<"|"<<endl;
    cout<<"          |"<<"===+"<<"===+"<<"===+"<<endl;
}

int check_winner(char a[])
{
    if(a[0]==a[1] && a[1]==a[2] && a[0]=='X')
    {
        return 1;
    }
    if(a[0]==a[3] && a[3]==a[6] && a[0]=='X')
    {
        return 1;
    }
    if(a[2]==a[5] && a[5]==a[8] && a[2]=='X')
    {
        return 1;
    }
    if(a[6]==a[7] && a[7]==a[8] && a[6]=='X')
    {
        return 1;
    }
    if(a[0]==a[4] && a[4]==a[8] && a[0]=='X')
    {
        return 1;
    }
    if(a[2]==a[4] && a[4]==a[6] && a[2]=='X')
    {
        return 1;
    }
    if(a[1]==a[4] && a[4]==a[7] && a[1]=='X')
    {
        return 1;
    }
    if(a[3]==a[4] && a[4]==a[5] && a[3]=='X')
    {
        return 1;
    }


    if(a[0]==a[1] && a[1]==a[2] && a[0]=='O')
    {
        return 0;
    }
    if(a[0]==a[3] && a[3]==a[6] && a[0]=='O')
    {
        return 0;
    }
    if(a[2]==a[5] && a[5]==a[8] && a[2]=='O')
    {
        return 0;
    }
    if(a[6]==a[7] && a[7]==a[8] && a[6]=='O')
    {
        return 0;
    }
    if(a[0]==a[4] && a[4]==a[8] && a[0]=='O')
    {
        return 0;
    }
    if(a[2]==a[4] && a[4]==a[6] && a[2]=='O')
    {
        return 0;
    }
    if(a[1]==a[4] && a[4]==a[7] && a[1]=='O')
    {
        return 0;
    }
    if(a[3]==a[4] && a[4]==a[5] && a[3]=='O')
    {
        return 0;
    }

    return 2;
}

int check_double(char board[])
{
    int number;
    for(;;)
    {
        cout<<"Please enter valid position :";
        cin>>number;
        if(board[number]=='X' || board[number]=='O')
        {
            continue;
        }
        else
        {
            break;
        }
    }
    return number;
}

