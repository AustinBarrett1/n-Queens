// Code made by Austin Barrett

// Worked in a group with Shade Kaiser (only person I worked with) which is allowed according to the rules.
// We did not do the same thing but much of the work is simalar. That is why some methods look simalar in function but
// Work off different parameters and variable types.

#include <iostream> 
#include <stack>

// all primary functions
bool check(int board[][14], int r, int c, int n);
void place(int board[][14], int n ,int& count);
void input(int& n);
// other functions added
int colPos(int board[][14],int i,int n);
void printBoard(int board[][14], int n, int& count);



// main method, initializing board, filling starting board with empty positions
// prints the number of solutions

int main(){
    int board[14][14];
    int n;
    input(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }
    int count = 0;
    //place(board,0 ,n, count);
    place(board,n,count);
    std::cout << '\n' << "There are " << count << " solutions!" << std::endl;
    
    return 0;
}

// this is the function to check if the current queen placement is an ok spot
// it is just checking for a 1 (represents the queens) in the array for a possible apposing position 
// this loop is checking the current colum
bool check(int board[][14], int r, int c, int n){
for (int i = 0; i < r; i++){
    if(board[i][c] == 1){
        return false;
    }
}

// this loop is checking the \ (negative) diangle
// it only needs to check up left because nothing will be bottom right with how we are placing it
for(int i = r, j = c; i >= 0 && j >= 0; i--, j-- ){
    if(board[i][j] == 1){
        return false;
    }
}

// this loop is checking the / (positive) diangle
// it only needs to check up righ because nothing will be bottom left with how we are placing it
for(int i = r, j = c; i >= 0 && j < n; i--, j++ ){
    if(board[i][j] == 1){
        return false;
    }
}
return true;
}

// the print the board method
// only prints the locations of the queens 
// it is reading through the 2d array and every time it comes across a queen it is marking the position and printing it

void printBoard(int board[][14], int n, int& count){
    // is to add a space between new boards
    std::cout << '\n';
    // this is how im keeping track on the board/#solutions to print in main and befor the board queen cords
    ++count;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
           
            if(board[i][j] == 1){
                enum pos {A= 0 ,B = 1, C = 2, D = 3, E = 4, F = 5, G = 6, H = 7, I = 8, J = 9, K = 10, L = 11, M = 12, N = 13};
                switch(i){
                    case A:
                    std::cout << "Board " << count << ": " << "A" << j +1 << " ";
                    break;
                    case B:
                    std::cout << "B" << j+1 << " ";
                    break;
                    case C:
                    std::cout << "C" << j+1 << " ";
                    break;
                    case D:
                    std::cout << "D" << j+1 << " ";
                    break;
                    case E:
                    std::cout << "E" << j+1 << " ";
                    break;
                    case F:
                    std::cout << "F" << j+1 << " ";
                    break;
                    case G:
                    std::cout << "G" << j+1 << " ";
                    break;
                    case H:
                    std::cout << "H" << j+1 << " ";
                    break;
                    case I:
                    std::cout << "I" << j+1 << " ";
                    break;
                    case J:
                    std::cout << "J" << j+1 << " ";
                    break;
                    case K:
                    std::cout << "K" << j+1 << " ";
                    break;
                    case L:
                    std::cout << "L" << j+1 << " ";
                    break;
                    case M:
                    std::cout << "M" << j+1 << " ";
                    break;
                    case N:
                    std::cout << "N" << j+1 << " ";
                    break;
                    default: ;
                }
            }
        }
        
    }
}


// what this method is doing is checking the current position in the collom that a queen is placed on in a specified row
// this method exist so that i can just check at anytime

int colPos(int board[][14],int i,int n){

    for(int j = 0; j < n; j++){
        if(board[i][j] == 1){
            
            return j;
        }
    }
    
    return 0;
}

// this is the bulk of the work
// this is were it checks for all the posibilitys and places them

void place(int board[][14], int n ,int& count){
    // the reset is a bool for reseting the current row and going back
    bool reset = false;
    int i  = 0;

// iterating throw the board and untill the board is solved

    while(i < n && i != -1){
        for(int j = 0; j < n; j++){

            // This is the reset. When this is ran, the queen already placed on that row gets removed and 
            // we go up 1 row and one to the right (colum) and place a new one and check for posibilitys.

            if(reset){
                int col = colPos(board,i,n);
                board[i][col] = 0;
                j = col + 1;
                reset = false;

            }

            // placeing a queen if parameters are met

            if(check(board,i,j,n) && j < n){
                board[i][j] = 1;

                // if this was the queen on the last row we found a solution and print the board
                // then we set the position to 0 (remove the queen) to start the process again
                if(i == n-1){
                    printBoard(board,n,count);
                    board[i][j] = 0;

                    // if also in the last colum we chould reset the row and the reset value to loop over again
                    if(j == n-1){
                        i=i -2;
                        reset = true;
                        break;
                    }
                    continue;
                }

                j = n-1;
                continue;

            }
            // reset again if last queen was placed
            if(j == n -1 || j >= n){
                i = i -2;
                reset = true;
                break;
            }
        }
        i++;
    }
}


       


// is to make sure that the input by the user works and is valid
// just getting value for n

void input(int& n) {
    do {
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid entry." << std::endl;
        }
        std::cout << "Enter a value for N (0 < N <= 14): ";
        std::cin >> n;
        if (n > 14 || n <= 0) {
            std::cin.setstate(std::ios_base::failbit);
            continue;
        }
    } while(!std::cin);
}
