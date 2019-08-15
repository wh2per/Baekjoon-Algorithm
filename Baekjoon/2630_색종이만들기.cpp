// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int b_paper;
int w_paper;
int n_paper;
int end_depth;

int paper[129][129];

void check_paper(int width, int sx, int sy){
    if(width==0)
        return;

    // 현재 검사
    int w=0, b=0;
    for(int i=sy; i<sy+width; ++i){
        for(int j=sx; j<sx+width; ++j){
            if(paper[i][j]==1)
                ++b;
            else
                ++w;
        }
    }
    if(b==width*width)
        ++b_paper;
    else if(w==width*width)
        ++w_paper;
    else{          // 검사결과 실패라면 depth+1 후 검사시작
        check_paper(width/2,sx,sy);
        check_paper(width/2,sx+width/2,sy);
        check_paper(width/2,sx,sy+width/2);
        check_paper(width/2,sx+width/2,sy+width/2);
    }
    return;
}

int main(){
    b_paper = 0;
    w_paper = 0;
    scanf("%d",&n_paper);


    for(int i=0; i<n_paper; ++i){
        for(int j=0; j<n_paper; ++j)
            scanf("%d",&paper[i][j]);
    }

    check_paper(n_paper,0,0);

    printf("%d\n",w_paper);
    printf("%d\n",b_paper);
    return 0;
}
