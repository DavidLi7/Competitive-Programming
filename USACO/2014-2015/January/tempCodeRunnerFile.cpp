for(int y1: yvals){
    //     for(int y2: yvals) if(y1 <= y2){
    //         int currcow = 0;
    //         int recg = 0;
    //         for(int x = 0; x < MAXV; x++){
    //             int hc = hpre[x][y2] - hpre[x][y1 - 1];
    //             int gc = gpre[x][y2] - gpre[x][y1 - 1];
    //             if(gc != 0){
    //                 currcow = 0;
    //                 recg = x + 1;
    //                 continue;
    //             }
    //             currcow += hc;
    //             if((currcow > cows) || (currcow == cows && (x - recg) * (y2 - y1) < area)){
    //                 cows = currcow;
    //                 area = (x - recg) * (y2 - y1);
    //             }
    //         }
    //     }
    // }