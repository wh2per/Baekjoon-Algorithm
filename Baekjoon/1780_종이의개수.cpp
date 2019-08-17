// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int one_paper;
int zero_paper;
int minus_paper;

int newpaper[2188][2188];

void check_newpaper(int width, int sx, int sy){
    // 현재 검사
    int o=0, z=0, m=0;
    for(int i=sy; i<sy+width; ++i){
        for(int j=sx; j<sx+width; ++j){
            if(newpaper[i][j]==1)
                ++o;
            else if(newpaper[i][j] == 0)
                ++z;
            else
                ++m;
        }
    }
    if(o==width*width)
        ++one_paper;
    else if(z==width*width)
        ++zero_paper;
    else if(m==width*width)
        ++minus_paper;
    else{          // 검사결과 실패라면 depth+1 후 검사시작
        if(width/3!=0){
            check_newpaper(width/3,sx,sy);
            check_newpaper(width/3,sx+width/3,sy);
            check_newpaper(width/3,sx+2*width/3,sy);
            check_newpaper(width/3,sx,sy+width/3);
            check_newpaper(width/3,sx+width/3,sy+width/3);
            check_newpaper(width/3,sx+2*width/3,sy+width/3);
            check_newpaper(width/3,sx,sy+2*width/3);
            check_newpaper(width/3,sx+width/3,sy+2*width/3);
            check_newpaper(width/3,sx+2*width/3,sy+2*width/3);
        }
    }
    return;
}

int main(){
    one_paper = 0;
    zero_paper = 0;
    minus_paper = 0;
    int n;
    scanf("%d",&n);


    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j)
            scanf("%d",&newpaper[i][j]);
    }

    check_newpaper(n,0,0);

    printf("%d\n",minus_paper);
    printf("%d\n",zero_paper);
    printf("%d\n",one_paper);
    return 0;
}
