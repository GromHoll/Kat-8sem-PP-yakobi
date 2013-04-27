#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

#define SIZE 5
#define E 0.0001
#define MAX_ITER 20

int main(int arc, char * argv[]) {

    double grid[2][SIZE][SIZE];
    int old(0), next(1); 

    for(int i = 1; i < SIZE-1; i++) {        
        for(int j = 1; j < SIZE-1; j++) {
            grid[old][i][j] = 5;
        }
    }
    for(int i = 0; i < SIZE; i++) {  
        for(int j = 0; j < 2; j++) {
            grid[j][i][0] = 3;
            grid[j][0][i] = 3;    
            grid[j][i][SIZE-1] = 3;
            grid[j][SIZE-1][i] = 3;
        }
    }

    int iter(0);
    double maxdiff;
    while(iter < MAX_ITER) {
        iter++;

        for(int i = 1; i < SIZE-1; i++) {        
            for(int j = 1; j < SIZE-1; j++) {
                grid[next][i][j] = (grid[old][i-1][j] + grid[old][i+1][j] + grid[old][i][j-1] + grid[old][i][j+1])*0.25;
            }
        }

        maxdiff = 0;

        for(int i = 1; i < SIZE-1; i++) {        
            for(int j = 1; j < SIZE-1; j++) {
                maxdiff = max(maxdiff, fabs(grid[old][i][j] - grid[next][i][j]));
            }
        }

        if(maxdiff < E) {
            break;        
        }

        old = 1 - old;
        next = 1 - next;
    }

    cout << iter << endl;

    ofstream out("out_2.txt");
    for(int i = 0; i < SIZE; i++) {        
        for(int j = 0; j < SIZE; j++) {
            out << grid[old][i][j] << "\t";
        }
        out << endl;
    }
    out.close();

    return 0;
}
