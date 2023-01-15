    int c = 0;
        for(int j = 1; j < N; j++){
            int ind = (i - j + N) % N;
            if(check[ind] > j){
                c++;
            }
        }
        if(c != check[i])
            return;
    }
    ans++;