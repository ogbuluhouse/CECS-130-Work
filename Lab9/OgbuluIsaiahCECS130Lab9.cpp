#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

// Isaiah Ogbulu, 3/29/2019, Lab 9, Tic-Tac-Toe Ai

using namespace std;

class Cell{         //creating class for each cell of tic-tac-toe board
    private:
        
    public:
		void setChar(char);         //declaring variables for each cell as public so they can be accessed outside of class
		void setUsed(bool);
        void changeCell(char);
		char cellChar;
        bool isUsed;       
};

void Cell::setChar(char givenChar){         //method to change character
	cellChar = givenChar;
}
void Cell::setUsed(bool givenUsed){          //method to change boolean saying if tile is used
    isUsed = givenUsed; 
}

void Cell::changeCell(char charChange){         //method to change character for tile and set it to used
    cellChar = charChange;
    isUsed = true;
}
            
int main(){

	bool playerTurn;                //declaring needed variables and seeding random time for random numbers
	bool gameEnd = false;
	srand(time(NULL));
    int userIn, cellChoice, randTurn, randCell;
    int turnCount = 1;
    char userChar, botChar; 

    Cell cell1;         //initailizing all the cells for tic-tac-toe board
    Cell cell2;
    Cell cell3;
    Cell cell4;
    Cell cell5;
    Cell cell6;
    Cell cell7;
    Cell cell8;
    Cell cell9;
    

	
	do{
        cell1.setUsed(false);           //resetting each cell to unused and their default number for each run through
        cell2.setUsed(false); 
        cell3.setUsed(false); 
        cell4.setUsed(false); 
        cell5.setUsed(false); 
        cell6.setUsed(false); 
        cell7.setUsed(false); 
        cell8.setUsed(false); 
        cell9.setUsed(false);    	

        cell1.setChar('1');
        cell2.setChar('2');
        cell3.setChar('3');
        cell4.setChar('4');
        cell5.setChar('5');
        cell6.setChar('6');
        cell7.setChar('7');
        cell8.setChar('8');
        cell9.setChar('9');
        turnCount = 1;
        gameEnd = false;
        
        cout << "Enter the number of one of the coices below:" << endl;         //prompting user to see if they want to run the program again
        cout << "0) Exit Program\t" << "1) Play another game" << endl;
        cin >> userIn;

        if(userIn == 1){                        //if they run the program again, randomly picking who goes first
            randTurn = rand()%2;        

            if(randTurn % 2 == 0){
                cout << "You go first! Your symbol is the X" << endl;
                userChar = 'X';
                botChar = 'O';
                playerTurn = true;
            }else {
               	cout << "You go second! Your symbol is the O" << endl;
                userChar = 'O';
                botChar = 'X';
                playerTurn = false;
            }

            do{ 
                
                cout << "Turn: " << turnCount << endl;
                turnCount++;

                cout << "\t"<<cell1.cellChar<<" | "<<cell2.cellChar<<" | "<<cell3.cellChar<<endl;           //displaying the board before each turn
    	        cout << "\t"<<"---------\n";
    	        cout << "\t"<<cell4.cellChar<<" | "<<cell5.cellChar<<" | "<<cell6.cellChar<<endl;
    	        cout << "\t"<<"---------\n";
    	        cout << "\t"<<cell7.cellChar<<" | "<<cell8.cellChar<<" | "<<cell9.cellChar<<endl;

                while(playerTurn){
                    cout << "Enter The Number of the cell where you want to place your "<< userChar << endl;        //prompting user for thier move
                    cin >> cellChoice;
                    
                    if(cellChoice == 1 && !cell1.isUsed){           //changing cell based off user input if the cell is not used already
                        cell1.changeCell(userChar);
                        playerTurn = false;
                        }
                    else if(cellChoice == 2 && !cell2.isUsed){
                        cell2.changeCell(userChar);
                        playerTurn = false;
                        }
                    else if(cellChoice == 3 && !cell3.isUsed){
                        cell3.changeCell(userChar);
                        playerTurn = false;
                        }
                    else if(cellChoice == 4 && !cell4.isUsed){
                        cell4.changeCell(userChar);
                        playerTurn = false;
                        }
                    else if(cellChoice == 5 && !cell5.isUsed){
                        cell5.changeCell(userChar);
                        playerTurn = false;
                        }
                    else if(cellChoice == 6 && !cell6.isUsed){
                        cell6.changeCell(userChar);
                        playerTurn = false;
                        }
                    else if(cellChoice == 7 && !cell7.isUsed){
                        cell7.changeCell(userChar);
                        playerTurn = false;
                        }
                    else if(cellChoice == 8 && !cell8.isUsed){
                        cell8.changeCell(userChar);
                        playerTurn = false;
                        }
                    else if(cellChoice == 9 && !cell9.isUsed){
                        cell9.changeCell(userChar);
                        playerTurn = false;
                        }else{
                        cout << "Illegal Move, Try again" << endl;
                    }

		        }
                while(!playerTurn){
                    randCell = (rand()%9)+1;                // generating random number for bot's turn and then testing if it's used or not

                    if(randCell == 1 && !cell1.isUsed){
                        cell1.changeCell(botChar);
                        playerTurn = true;
                        }
                    else if(randCell == 2 && !cell2.isUsed){
                        cell2.changeCell(botChar);
                        playerTurn = true;
                        }
                    else if(randCell == 3 && !cell3.isUsed){
                        cell3.changeCell(botChar);
                        playerTurn = true;
                        }
                    else if(randCell == 4 && !cell4.isUsed){
                        cell4.changeCell(botChar);
                        playerTurn = true;
                        }
                    else if(randCell == 5 && !cell5.isUsed){
                        cell5.changeCell(botChar);
                        playerTurn = true;
                        }
                    else if(randCell == 6 && !cell6.isUsed){
                        cell6.changeCell(botChar);
                        playerTurn = true;
                        }
                    else if(randCell == 7 && !cell7.isUsed){
                        cell7.changeCell(botChar);
                        playerTurn = true;
                        }
                    else if(randCell == 8 && !cell8.isUsed){
                        cell8.changeCell(botChar);
                        playerTurn = true;
                        }
                    else if(randCell == 9 && !cell9.isUsed){
                        cell9.changeCell(botChar);
                        playerTurn = true;
                        }
		        }
                if(cell1.isUsed && cell2.isUsed && cell3.isUsed && cell4.isUsed && cell5.isUsed && cell6.isUsed && cell7.isUsed && cell8.isUsed && cell9.isUsed){
                    cout << "The game ends in a TIE!!!" << endl;            //Ending game and outputting tie if all the cells are used
                    gameEnd = true;
                }
                else if(cell1.cellChar == cell2.cellChar && cell1.cellChar == cell3.cellChar){
                    cout << "GAME OVER" << endl;                    //ending game and outputting winner if 3 in a row have the same character
                    if(cell1.cellChar == userChar){
                        cout << "USER WINS!!!!" << endl;
                    }else{
                        cout << "BOT WINS!!!!!" << endl;
                    }
                    gameEnd = true;
                }
                else if(cell1.cellChar == cell4.cellChar && cell1.cellChar == cell7.cellChar){
                    cout << "GAME OVER" << endl;                    //ending game and outputting winner if 3 in a row have the same character
                    if(cell1.cellChar == userChar){
                        cout << "USER WINS!!!!" << endl;
                    }else{
                        cout << "BOT WINS!!!!!" << endl;
                    }
                    gameEnd = true;
                }
                else if(cell1.cellChar == cell5.cellChar && cell1.cellChar == cell9.cellChar){
                    cout << "GAME OVER" << endl;                    //ending game and outputting winner if 3 in a row have the same character
                    if(cell1.cellChar == userChar){
                        cout << "USER WINS!!!!" << endl;
                    }else{
                        cout << "BOT WINS!!!!!" << endl;
                    }
                    gameEnd = true;
                }
                else if(cell2.cellChar == cell5.cellChar && cell2.cellChar == cell8.cellChar){
                    cout << "GAME OVER" << endl;                    //ending game and outputting winner if 3 in a row have the same character
                    if(cell2.cellChar == userChar){
                        cout << "USER WINS!!!!" << endl;
                    }else{
                        cout << "BOT WINS!!!!!" << endl;
                    }
                    gameEnd = true;
                }
                else if(cell3.cellChar == cell6.cellChar && cell3.cellChar == cell9.cellChar){
                    cout << "GAME OVER" << endl;                    //ending game and outputting winner if 3 in a row have the same character
                    if(cell3.cellChar == userChar){
                        cout << "USER WINS!!!!" << endl;
                    }else{
                        cout << "BOT WINS!!!!!" << endl;
                    }
                    gameEnd = true;
                }
                else if(cell3.cellChar == cell5.cellChar && cell3.cellChar == cell7.cellChar){
                    cout << "GAME OVER" << endl;                    //ending game and outputting winner if 3 in a row have the same character
                    if(cell3.cellChar == userChar){
                        cout << "USER WINS!!!!" << endl;
                    }else{
                        cout << "BOT WINS!!!!!" << endl;
                    }
                    gameEnd = true;
                }
                else if(cell4.cellChar == cell5.cellChar && cell4.cellChar == cell6.cellChar){
                    cout << "GAME OVER" << endl;                    //ending game and outputting winner if 3 in a row have the same character
                    if(cell4.cellChar == userChar){
                        cout << "USER WINS!!!!" << endl;
                    }else{
                        cout << "BOT WINS!!!!!" << endl;
                    }
                    gameEnd = true;
                }
                else if(cell7.cellChar == cell8.cellChar && cell7.cellChar == cell9.cellChar){
                    cout << "GAME OVER" << endl;                    //ending game and outputting winner if 3 in a row have the same character
                    if(cell7.cellChar == userChar){
                        cout << "USER WINS!!!!" << endl;
                    }else{
                        cout << "BOT WINS!!!!!" << endl;
                    }
                    gameEnd = true;
                }

            }while(!gameEnd);
            
        }
        else if(userIn == 0){               //exiting program if user chose not to play again
            cout << "Exiting Program..." << endl;
        }else{
            cout << "Unexpected Input Please Enter again" << endl;
        }
		
    	
	}while(userIn != 0);
}
