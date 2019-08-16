// This file is a "Hello, world!" in C++ language by GCC for wandbox.
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int quad_tree[65][65];

void check_tree(int width, int sx, int sy){
    if(width==0)
        return;

    // 현재 검사
    int w=0, b=0;
    for(int i=sy; i<sy+width; ++i){
        for(int j=sx; j<sx+width; ++j){
            if(quad_tree[i][j]==1)
                ++b;
            else
                ++w;
        }
    }

    if(b==width*width)
        printf("1");
    else if(w==width*width)
        printf("0");
    else{          // 검사결과 실패라면 depth+1 후 검사시작
        printf("(");
        check_tree(width/2,sx,sy);
        check_tree(width/2,sx+width/2,sy);
        check_tree(width/2,sx,sy+width/2);
        check_tree(width/2,sx+width/2,sy+width/2);
        printf(")");
    }
    return;
}

int main(){
    int n_quad;
    scanf("%d",&n_quad);

    for(int i=0; i<n_quad; ++i){
        for(int j=0; j<n_quad; ++j)
            scanf("%1d",&quad_tree[i][j]);
    }

    check_tree(n_quad,0,0);

    return 0;
}
