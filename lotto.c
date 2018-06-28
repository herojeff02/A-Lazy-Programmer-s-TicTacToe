//로또
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 30

int lotto[4]={};

int main() {
    int in[4]={};
    int cnt=0;

    printf("당신에게 행운이 깃들길 (입력은 숫자 사이에 스페이스 한 칸씩) : ");
    for(int i=0;i<4;i++){
        scanf(" %d",&in[i]);
    }

    srand((unsigned int)time(0));
    for(int i=0;i<4;i++) {
        lotto[i] = (rand() % N) + 1;
        if (isSame(i)) {
            i--;
            continue;
        }

        for(int j=0;j<4;j++){
            if(lotto[i]==in[j])
                cnt++;
            else
                continue;
        }
    }

    switch (cnt){
        case 0 : case 1 :
            puts("꽝입니다");
            break;
        case 2 :
            puts("3등입니다.");
            break;
        case 3 :
            puts("2등입니다.");
            break;
        case 4 :
            puts("1등입니다.");
            break;
        default:
            puts("뭐야 무슨 일이야 이게");
    }
    return 0;
}
int isSame(int k){
    for(int i=0;i<=k;i++){
        for(int j=0;j<=k;j++){
            if(i==j)
                j++;
            if(lotto[i]==lotto[j])
                return 1;
        }
    }
    return 0;
}
