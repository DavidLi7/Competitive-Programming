#include <iostream>

using namespace std;

bool ok[2001][2001];

int main() {
    freopen("billboard.in","r",stdin);
    freopen("billboard.out","w",stdout);

    int x1, y1, x2, y2;

    //billboard 1
    cin >> x1 >> y1 >> x2 >> y2;
    for(int i = x1; i < x2; i++){//quadratic time complexity
        for(int j = y1; j < y2; j++){
            ok[i + 1000][j + 1000] = true;
        }
    }

    //billboard 2
    cin >> x1 >> y1 >> x2 >> y2;
    for(int i = x1; i < x2; i++){
        for(int j = y1; j < y2; j++){
            ok[i + 1000][j + 1000] = true;
        }
    }

    //truck
    cin >> x1 >> y1 >> x2 >> y2;
    for(int i = x1; i < x2; i++){
        for(int j = y1; j < y2; j++){
            ok[i + 1000][j + 1000] = false;
        }
    }

    int ans = 0;
    for(int i = 0; i < 2000; i++){
        for(int j = 0; j < 2000; j++){
            if(ok[i][j])
                ans++;
        }
    }
    cout << ans;

}