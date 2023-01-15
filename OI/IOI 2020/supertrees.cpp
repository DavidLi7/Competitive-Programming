#include "supertrees.h"
#include <vector>

const int MAXN = 1000;

int parent[MAXN], sz[MAXN], comp[MAXN];

int find(int p){
    while (p != parent[p])
        p = parent[p];
    return p;
}

void merge(int p, int q) {
    int rootP = find(p);
    int rootQ = find(q);
    if (rootP == rootQ) return;
    if (sz[rootP] < sz[rootQ]) {
        parent[rootP] = rootQ;
        sz[rootQ] += sz[rootP];
    }
    else {
        parent[rootQ] = rootP;
        sz[rootP] += sz[rootQ];
    }
}

int construct(std::vector<std::vector<int> > p) {
	int n = p.size();
	std::vector<std::vector<int> > answer;
	for (int i = 0; i < n; i++) {
		std::vector<int> row;
		row.resize(n);
		answer.push_back(row);
	}
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(p[i][j])
                merge(i, j);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(find(i) == find(j) && !p[i][j])
                return 0;
        }
    }
    for(int i = 0; i < n; i++){
        int r = find(i);
        if(r == i){
            std::vector<int> inComp;
            for(int j = 0; j < n; j++){
                if(find(j) == r){
                    inComp.push_back(j);
                }
            }
            int start = -1;
            int prev = -1;
            int second = -1;
            int c = 0;
            bool isThree = false;
            bool isTwo = false;
            for(int j = 0; j < inComp.size(); j++) if(comp[inComp[j]] == 0){
                comp[inComp[j]] = ++c;
                for(int k = j + 1; k < inComp.size(); k++){
                    if(p[inComp[j]][inComp[k]] == 3){
                        isThree = true;
                    }
                    if(p[inComp[j]][inComp[k]] == 3){
                        isTwo = true;
                    }
                    if(comp[inComp[k]] == 0 && p[inComp[j]][inComp[k]] == 1){
                        comp[inComp[k]] = comp[inComp[j]];
                        answer[inComp[j]][inComp[k]] = 1;
                        answer[inComp[k]][inComp[j]] = 1;
                    }
                }
                if(isThree && isTwo)
                    return 0;
                if(start == -1){
                    start = inComp[j];
                    prev = inComp[j];
                }
                else{
                    if(second == -1){
                        second = inComp[j];
                    }
                    answer[prev][inComp[j]] = 1;
                    answer[inComp[j]][prev] = 1;
                    prev = inComp[j];
                }
            }
            if(c == 1)
                continue;
            if(c == 2)
                return 0;
            if(c == 3 && isThree)
                return 0;
            answer[prev][start] = 1;
            answer[start][prev] = 1;
            if(isThree){
                answer[prev][second] = 1;
                answer[second][prev] = 1;
            }
        }
    }
	build(answer);
	return 1;
}
