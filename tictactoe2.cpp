#include <iostream>
using namespace std;

int winDetetction(int space[9]){ //win detection function, returns integer of player who wins
    if(space[0] == 1 && space[1] == 1 && space[2] == 1||
       space[3] == 1 && space[4] == 1 && space[5] == 1||
       space[6] == 1 && space[7] == 1 && space[8] == 1||
       space[0] == 1 && space[3] == 1 && space[6] == 1||
       space[1] == 1 && space[4] == 1 && space[7] == 1||
       space[2] == 1 && space[5] == 1 && space[8] == 1||
       space[0] == 1 && space[4] == 1 && space[8] == 1||
       space[2] == 1 && space[4] == 1 && space[6] == 1){
       return 1; //detected a win for player 1
       }
    else if(space[0] == 2 && space[1] == 2 && space[2] == 2||
       space[3] == 2 && space[4] == 2 && space[5] == 2||
       space[6] == 2 && space[7] == 2 && space[8] == 2||
       space[0] == 2 && space[3] == 2 && space[6] == 2||
       space[1] == 2 && space[4] == 2 && space[7] == 2||
       space[2] == 2 && space[5] == 2 && space[8] == 2||
       space[0] == 2 && space[4] == 2 && space[8] == 2||
       space[2] == 2 && space[4] == 2 && space[6] == 2){
        return 2; // detected a win for player 2
       }
    else{
        return 0; // no win detected
    }
}

void displayBoard(int space[9]){ //board display fuctions, input is the game board array, displays which spaces are open and which are occupied
    if (space[0] == 1){
        cout << " X ";
    }
    else if (space [0] == 2){
        cout << " o ";
    }
    else{
        cout << " 1 ";
    }
    cout << " | ";

    if (space[1] == 1){
        cout << " X ";
    }
    else if (space [1] == 2){
        cout << " o ";
    }
    else{
        cout << " 2 ";
    }
    cout << " | " ;

    if (space[2] == 1){
        cout << " X ";
    }
    else if (space [2] == 2){
        cout << " o ";
    }
    else{
        cout << " 3 ";
    }
    cout << endl;
//-------------------------------
    if (space[3] == 1){
        cout << " X ";
    }
    else if (space [3] == 2){
        cout << " o ";
    }
    else{
        cout << " 4 ";
    }
    cout << " | ";

    if (space[4] == 1){
        cout << " X ";
    }
    else if (space [4] == 2){
        cout << " o ";
    }
    else{
        cout << " 5 ";
    }
    cout << " | " ;

    if (space[5] == 1){
        cout << " X ";
    }
    else if (space [5] == 2){
        cout << " o ";
    }
    else{
        cout << " 6 ";
    }
    cout << endl;
//---------------------------------------
    if (space[6] == 1){
        cout << " X ";
    }
    else if (space [6] == 2){
        cout << " o ";
    }
    else{
        cout << " 7 ";
    }
    cout << " | ";

    if (space[7] == 1){
        cout << " X ";
    }
    else if (space [7] == 2){
        cout << " o ";
    }
    else{
        cout << " 8 ";
    }
    cout << " | " ;

    if (space[8] == 1){
        cout << " X ";
    }
    else if (space [8] == 2){
        cout << " o ";
    }
    else{
        cout << " 9 ";
    }
    cout << endl;
}

int main()
{
    int x=0; 
    int space[9];
    int badmove = 0;
    int sp;

    for (int cnt = 0; cnt < 9; cnt++){ // intializing our gameboard array to 0 in all spaces
        space[cnt] = 0;
    }
    
    cout << "* -- * Tic Tac Toe * -- *" << endl;
    cout << "         1 | 2 | 3   " << endl;
    cout << "         4 | 5 | 6   " << endl;
    cout << "         7 | 8 | 9   " << endl; // visual representation of game board
    
    cout << "Enter 1 to play or anything else to quit" << endl;
    cin >> x;
    
    if (x == 1){
        do{// start of game loop
            cout << "Now it is player 1's turn, which space would you like to play?" << endl;
            
            do{
                cin >> sp; //in put which space player wants to play
                if(space[sp - 1] == 0){ //storing input in specific location in space array only if that space is open (open represented by being equal to zero)
                    space[sp - 1] = 1; // 1 means occupied by player 1
                    badmove = 0; // no bad move flag triggered
                    displayBoard(space); // displays which spaces are currently open and which are occupied
                }
                
                else{
                    badmove = 1; //bad move flag if player tries to input move into occupied space
                    cout << "invalid move, try again" << endl;
                }
                
            }while(badmove == 1); // retry if bad move detected
            
            if(winDetetction(space) == 1){ //break out of gameflow loop if a win is detedted for player 1
                        break;             //this is so we can ignore player 2 input move code
                    }
            
            cout << "now it is player 2's turn, please enter the space you wish to play" << endl;
            
            do{
                cin >> sp;
                
                if(space[sp - 1] == 0){
                    space[sp - 1] = 2;
                    badmove = 0;
                    displayBoard(space);
                }
                
                else{
                    badmove = 1;
                    cout << "invalid move, try again" << endl;
                }
                
            }while(badmove == 1);
        }while(winDetetction(space)==0);

        if(winDetetction(space)==1){//display player 1 wins if a win is detected for player 1
            cout << "PLAYER 1 WINS" << endl;
            return 0;
        }
        
        else if(winDetetction(space)==2){ //display player 2 wins if a win is detected for player 2
            cout << "PLAYER 2 WINS" << endl;
            return 0;
        }
    }
    else{
        cout << "okay, have a good day" << endl; //goodbye message if 1 was not entered initially
    }

    return 0;
}
