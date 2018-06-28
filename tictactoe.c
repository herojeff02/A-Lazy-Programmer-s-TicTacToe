//틱택토
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//blank : 0, O : 1, X : 2

char board[3][3] = {};

int main(){

    printf("--당신은 O, 컴퓨터는 X입니다.\n--입력 양식 : b3 꼴\n");

    char row_char;
    int row,column;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            board[i][j]=' ';

    while(1){
        printf("어디에 두시겠습니까?\ninput : ");
        do{
            scanf(" %c%d", &row_char, &column);
            column--;
            switch(row_char) {
                case 'a':
                    row = 0;
                    break;
                case 'b':
                    row = 1;
                    break;
                case 'c':
                    row = 2;
                    break;
            }
            if(!isPlaceable(row,column))
                printf("놓을 수 없습니다.\n");
        }while(!isPlaceable(row, column) && !isFull());

        board[row][column] = 'O';
        prt();
        AI();
        prt();

        if(isWin()==1) {
            printf("O won!");
            return 0;
        }
        else if(isWin()==2){
            printf("X won!");
            return 0;
        }
        else if(isWin()==0 && isFull()){
            printf("Draw!");
            return 0;
        }
    }
}
int isWin(){
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2]){
            if(board[i][0]=='O')
                return 1;
            else if(board[i][0]=='X')
                return 2;
            else
                continue;
        }
    }
    for(int i=0;i<3;i++){
        if(board[0][i]==board[1][i] && board[1][i]==board[2][i]){
            if(board[0][i]=='O')
                return 1;
            else if(board[0][i]=='X')
                return 2;
            else
                continue;
        }
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]) {
        if(board[0][0]=='O')
            return 1;
        else if(board[0][0]=='X')
            return 2;
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]) {
        if(board[0][2]=='O')
            return 1;
        else if(board[0][2]=='X')
            return 2;
    }
    return 0;
}

int prt(){
    puts("");
    puts("    1   2   3");
    puts("  +---+---+---+");
    printf("A | ");
    printf("%c | %c | %c |",board[0][0],board[0][1],board[0][2]);
    puts("");
    printf("B | ");
    printf("%c | %c | %c |",board[1][0],board[1][1],board[1][2]);
    puts("");
    printf("C | ");
    printf("%c | %c | %c |",board[2][0],board[2][1],board[2][2]);
    puts("");
    puts("  +---+---+---+");
    return 0;
}

int isPlaceable(int row, int column){
    if(row>2 || row<0 || column > 2 || column < 0)
        return 0;
    else if(board[row][column]==' ')
        return 1;
    else
        return 0;
}
int isFull(){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(board[i][j]==' ')
                return 0;
    return 1;
}
int AI(){
    int row,col;
    do {
        srand((unsigned int)time(0));
        row = (rand() % 3);
        col = (rand() % 3);

        if(isPlaceable(row, col) == 1) {
            board[row][col] = 'X';
            break;
        }
    }while(!isFull());
    return 0;
}
