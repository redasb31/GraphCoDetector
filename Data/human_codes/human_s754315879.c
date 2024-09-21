#include <iostream>
#include <cstring>
using namespace std;

int h, w;

char buf[20][20];
char mat[20][20];
int chest[20][20];

int adj[20][20];

void calcAdj() {
    memset(adj, 0, sizeof(adj));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    int newx = i+dx, newy = j+dy;
                    if (newx >= 0 && newx < h && newy >= 0 && newy < w) {
                        if (mat[newx][newy] > '0' && mat[newx][newy] <= '9') {
                            adj[i][j]++;
                        }
                    }
                }
            }
        }
    }
}

void updateAdj(int x, int y) {
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            int newx = x+dx, newy = y+dy;
            if (newx >= 0 && newx < h && newy >= 0 && newy < w) {
                adj[newx][newy]--;
            }
        }
    }
}

bool solve(int num) {
    memcpy(mat, buf, sizeof(buf));
    memset(chest, 0, sizeof(chest));
    calcAdj();

    while (num--) {
        int maxAdj = 0, x, y;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (adj[i][j] > maxAdj && mat[i][j] != '.' && !chest[i][j]) {
                    maxAdj = adj[i][j];
                    x = i; y = j;
                }
            }
        }

        chest[x][y] = 1;

//        printf("Position (%d, %d) has max adjacent marks %d\n", x, y, maxAdj);

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                int newx = x+dx, newy = y+dy;
                if (newx >= 0 && newx < h && newy >= 0 && newy < w) {
                    if (mat[newx][newy] > '0' && mat[newx][newy] <= '9') {
//                        printf("Mark (%d, %d) is now %c\n", newx, newy, mat[newx][newy]-1);

                        if (--mat[newx][newy] == '0') {
                            updateAdj(newx, newy);
                        }

                    }
                }
            }
        }
//        printf("Mat:\n");
//        for (int i = 0; i < h; i++) { for (int j = 0; j < w; j++) { printf("%c", mat[i][j]); } printf("\n"); }
//        printf("Adj:\n");
//        for (int i = 0; i < h; i++) { for (int j = 0; j < w; j++) { printf("%d", adj[i][j]); } printf("\n"); }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (mat[i][j] > '0' && mat[i][j] <= '9') return false;
        }
    }
    return true;
}

int main() {
    while(cin >> h >> w && h && w) {
        for (int i = 0; i < h; i++) {
            cin >> buf[i];
        }
        int low = 0, high = h*w;
        while (low < high) {
            int mid = (low+high)/2;
//            printf("Num: %d, %s\n", mid, solve(mid) ? "OK" : "NO");
            if (solve(mid)) high = mid;
            else low = mid+1;
        }
        cout << low << "\n";
    }

}

