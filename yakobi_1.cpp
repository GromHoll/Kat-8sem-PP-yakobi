#include <iostream>
#include <fstream>
#include <math.h>

#include <time.h>

using namespace std;

#define SIZE 5
#define E 0.0001

int main(int arc, char * argv[]) {

    clock_t start = clock();

    double grid[SIZE][SIZE];
    double next[SIZE][SIZE];

    for(int i = 1; i < SIZE-1; i++) {        
        for(int j = 1; j < SIZE-1; j++) {
            grid[i][j] = 5;
        }
    }
    for(int i = 0; i < SIZE; i++) {        
        grid[i][0] = 3;
        grid[0][i] = 3;
        grid[i][SIZE-1] = 3;
        grid[SIZE-1][i] = 3;
    }

    int iter(0);
    double maxdiff;
    while(true) {
        iter++;

        for(int i = 1; i < SIZE-1; i++) {        
            for(int j = 1; j < SIZE-1; j++) {
                next[i][j] = (grid[i-1][j] + grid[i+1][j] + grid[i][j-1] + grid[i][j+1])*0.25;
            }
        }

        maxdiff = 0;

        for(int i = 1; i < SIZE-1; i++) {        
            for(int j = 1; j < SIZE-1; j++) {
                maxdiff = max(maxdiff, fabs(grid[i][j] - next[i][j]));
            }
        }

        if(maxdiff < E) {
            break;        
        }

        for(int i = 1; i < SIZE-1; i++) {        
            for(int j = 1; j < SIZE-1; j++) {
                grid[i][j] = next[i][j];
            }
        }
    }

    cout << iter << endl;

    ofstream out("out_1.txt");
    for(int i = 0; i < SIZE; i++) {        
        for(int j = 0; j < SIZE; j++) {
            out << grid[i][j] << "\t";
        }
        out << endl;
    }
    out.close();

    cout << (long double) (clock() - start) / CLOCKS_PER_SEC << endl;

    return 0;
}
