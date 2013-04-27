#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

#define SIZE 5
#define E 0.0001
#define MAX_ITER 20
#define RELAX 1.5

int main(int arc, char * argv[]) {

    double grid[SIZE][SIZE];

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
    while(iter < MAX_ITER) {
        iter+=2;

        for(int i = 1; i < SIZE-1; i++) {        
            for(int j = 1; j < SIZE-1; j++) {
                grid[i][j] = (grid[i-1][j] + grid[i+1][j] + grid[i][j-1] + grid[i][j+1])*0.25*RELAX
                                   + (1-RELAX)*grid[i][j];
            }
        }
    }

    cout << iter << endl;

    ofstream out("out_relax.txt");
    for(int i = 0; i < SIZE; i++) {        
        for(int j = 0; j < SIZE; j++) {
            out << grid[i][j] << "\t";
        }
        out << endl;
    }
    out.close();

    return 0;
}
