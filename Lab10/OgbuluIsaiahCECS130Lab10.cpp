#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

// Isaiah Ogbulu, 4/12/2019, Lab 10, 3D Tic-Tac-Toe With Ai

using namespace std;


class Cell{         //creating class for each cell of tic-tac-toe board
    private:
        
    public:
        void changeCell(char);
		char cellChar;
        bool isUsed;  
        void setCell(char);
};

void Cell::setCell(char charIn){
    cellChar = charIn;
    isUsed = false;
}

void Cell::changeCell(char charChange){         //method to change character for tile and set it to used
    cellChar = charChange;
    isUsed = true;
}

class Field : public Cell{			//Creating Field of 27 cell objects
    public:
        Cell cella1;        
        Cell cella2;
        Cell cella3;
        Cell cella4;
        Cell cella5;
        Cell cella6;
        Cell cella7;
        Cell cella8;
        Cell cella9;
        Cell cellb1;       
        Cell cellb2;
        Cell cellb3;
        Cell cellb4;
        Cell cellb5;
        Cell cellb6;
        Cell cellb7;
        Cell cellb8;
        Cell cellb9;
        Cell cellc1;        
        Cell cellc2;
        Cell cellc3;
        Cell cellc4;
        Cell cellc5;
        Cell cellc6;
        Cell cellc7;
        Cell cellc8;
        Cell cellc9;
    	Field();
        bool turnEnd;	//declaring needed variables for class
        int playerWins = 0;
        int botWins = 0;
        char botChar = 'X';
        char playerChar = 'O';
        void showField();
        void playerTurn();
        void botTurn();
        bool checkWin(int);
        bool checkEnd();
};

Field::Field(){ //Sets each cell to unused and sets default char
    cella1.setCell('1');        
    cella2.setCell('2');
    cella3.setCell('3');
    cella4.setCell('4');
    cella5.setCell('5');
    cella6.setCell('6');
    cella7.setCell('7');
    cella8.setCell('8');
    cella9.setCell('9');
    cellb1.setCell('1'); 
    cellb2.setCell('2');
    cellb3.setCell('3');
    cellb4.setCell('4');
    cellb5.setCell('5');
    cellb6.setCell('6');
    cellb7.setCell('7');
    cellb8.setCell('8');
    cellb9.setCell('9');
    cellc1.setCell('1');
    cellc2.setCell('2');
    cellc3.setCell('3');
    cellc4.setCell('4');
    cellc5.setCell('5');
    cellc6.setCell('6');
    cellc7.setCell('7');
    cellc8.setCell('8');
    cellc9.setCell('9');
    
}

            
int main(){

    srand(time(NULL));      //randomizes number generation
    int userChoice;
    

    do{
        cout << "Enter 1 to play onother game or 0 to exit" << endl;        //prompting user and recording input
        cin >> userChoice;
        Field newField;
        if(userChoice == 1){
            do{
                newField.showField();
                cout << "Player Score:\t" << newField.playerWins << endl;       //displaying field and score for player and bot
                cout << "Bot Score:\t" << newField.botWins << endl;
                newField.playerTurn();
                newField.botTurn();
            }while(newField.checkEnd() != true);
            cout << "Game Over!!" << endl;
            if(newField.playerWins < newField.botWins){
                cout << "Player Wins with " << newField.playerWins << " Winning Combinations!" << endl;
            }else{
                cout << "Bot Wins with " << newField.botWins << " Winning Combinations!" << endl;
            }
        }
        else if(userChoice == 0){
            cout << "Ending game" << endl;
        }
        else{cout << "Unexpected Input" << endl;}
        
    }while(userChoice != 0);
    
    return 0;
}

void Field::showField(){            //method to output current field
    cout << "Board 1: " << endl;
    cout << "\t"<<cella1.cellChar<<" | "<<cella2.cellChar<<" | "<<cella3.cellChar<<endl;
    cout << "\t"<<"---------\n";
    cout << "\t"<<cella4.cellChar<<" | "<<cella5.cellChar<<" | "<<cella6.cellChar<<endl;
    cout << "\t"<<"---------\n";
    cout << "\t"<<cella7.cellChar<<" | "<<cella8.cellChar<<" | "<<cella9.cellChar<<endl;
    cout << "Board 2: " << endl;
    cout << "\t"<<cellb1.cellChar<<" | "<<cellb2.cellChar<<" | "<<cellb3.cellChar<<endl;
    cout << "\t"<<"---------\n";
    cout << "\t"<<cellb4.cellChar<<" | "<<cellb5.cellChar<<" | "<<cellb6.cellChar<<endl;
    cout << "\t"<<"---------\n";
    cout << "\t"<<cellb7.cellChar<<" | "<<cellb8.cellChar<<" | "<<cellb9.cellChar<<endl;
    cout << "Board 3: " << endl;
    cout << "\t"<<cellc1.cellChar<<" | "<<cellc2.cellChar<<" | "<<cellc3.cellChar<<endl;
    cout << "\t"<<"---------\n";
    cout << "\t"<<cellc4.cellChar<<" | "<<cellc5.cellChar<<" | "<<cellc6.cellChar<<endl;
    cout << "\t"<<"---------\n";
    cout << "\t"<<cellc7.cellChar<<" | "<<cellc8.cellChar<<" | "<<cellc9.cellChar<<endl;
}

void Field::botTurn(){      //Method  for bot turn that generates a random number from 1-27 then changes a cell based off number generated
    turnEnd = false;

    do{
    int randNum = (rand()%27) + 1;
    switch(randNum){
        case 1:
            if(cella1.isUsed == false){
                cella1.changeCell(botChar);
                if(checkWin(1)){
                    botWins++;
                }
                turnEnd = true;
            } 
            break;
        case 2:
            if(cella2.isUsed == false){
                cella2.changeCell(botChar);
                if(checkWin(2)){
                    botWins++;
                }
                turnEnd = true;
            } 
            break;
        case 3:
            if(cella3.isUsed == false){
                cella3.changeCell(botChar);
                if(checkWin(3)){
                    botWins++;
                }
                turnEnd = true;
            } 
            break;
        case 4:
            if(cella4.isUsed == false){
                cella4.changeCell(botChar);
                if(checkWin(4)){
                    botWins++;
                }
                turnEnd = true;
            } 
            break;
        case 5:
            if(cella5.isUsed == false){
                cella5.changeCell(botChar);
                if(checkWin(5)){
                    botWins++;
                }
                turnEnd = true;
            } 
            break;
        case 6:
            if(cella6.isUsed == false){
                cella6.changeCell(botChar);
                if(checkWin(6)){
                    botWins++;
                }
                turnEnd = true;
            } 
            break;
        case 7:
            if(cella7.isUsed == false){
                cella7.changeCell(botChar);
                if(checkWin(7)){
                    botWins++;
                }
                turnEnd = true;
            } 
            break;
        case 8:
            if(cella8.isUsed == false){
                cella8.changeCell(botChar);
                if(checkWin(8)){
                    botWins++;
                }
                turnEnd = true;
            } 
            break;
        case 9:
            if(cella9.isUsed == false){
                cella9.changeCell(botChar);
                if(checkWin(9)){
                    botWins++;
                }
                turnEnd = true;
            } 
            break;
        case 10:
            if(cellb1.isUsed == false){
                cellb1.changeCell(botChar);
                if(checkWin(10)){
                    botWins++;
                }
                turnEnd = true;
            } 
            break;
        case 11:
            if(cellb2.isUsed == false){
                cellb2.changeCell(botChar);
                if(checkWin(11)){
                    botWins++;
                }
                turnEnd = true;
            } 
            break;
        case 12:
            if(cellb3.isUsed == false){
                cellb3.changeCell(botChar);
                if(checkWin(12)){
                    botWins++;
                }
                turnEnd = true;
            } 
            break;
        case 13:
            if(cellb4.isUsed == false){
                cellb4.changeCell(botChar);
                if(checkWin(13)){
                    botWins++;
                }
                turnEnd = true;
            } 
            break;
        case 14:
            if(cellb5.isUsed == false){
                cellb5.changeCell(botChar);
                if(checkWin(14)){
                    botWins++;
                }
                turnEnd = true;
            } 
            break;
        case 15:
            if(cellb6.isUsed == false){
                cellb6.changeCell(botChar);
                if(checkWin(15)){
                    botWins++;
                }
                turnEnd = true;
            } 
            break;
        case 16:
            if(cellb7.isUsed == false){
                cellb7.changeCell(botChar);
                if(checkWin(16)){
                    botWins++;
                }
                turnEnd = true;
            } 
            break;
        case 17:
            if(cellb8.isUsed == false){
                cellb8.changeCell(botChar);
                if(checkWin(17)){
                    botWins++;
                }
                turnEnd = true;
            } 
            break;
        case 18:
            if(cellb9.isUsed == false){
                cellb9.changeCell(botChar);
                if(checkWin(18)){
                    botWins++;
                }
                turnEnd = true;
            } 
            break;
        case 19:
            if(cellc1.isUsed == false){
                cellc1.changeCell(botChar);
                if(checkWin(19)){
                    botWins++;
                }
                turnEnd = true;
            } 
            break;
        case 20:
            if(cellc2.isUsed == false){
                cellc2.changeCell(botChar);
                if(checkWin(20)){
                    botWins++;
                }
                turnEnd = true;
            } 
            break;
        case 21:
            if(cellc3.isUsed == false){
                cellc3.changeCell(botChar);
                if(checkWin(21)){
                    botWins++;
                }
                turnEnd = true;
            } 
            break;
        case 22:
            if(cellc4.isUsed == false){
                cellc4.changeCell(botChar);
                if(checkWin(22)){
                    botWins++;
                }
                turnEnd = true;
            } 
            break;
        case 23:
            if(cellc5.isUsed == false){
                cellc5.changeCell(botChar);
                if(checkWin(23)){
                    botWins++;
                }
                turnEnd = true;
            } 
            break;
        case 24:
            if(cellc6.isUsed == false){
                cellc6.changeCell(botChar);
                if(checkWin(24)){
                    botWins++;
                }
                turnEnd = true;
            } 
            break;
        case 25:
            if(cellc7.isUsed == false){
                cellc7.changeCell(botChar);
                if(checkWin(25)){
                    botWins++;
                }
                turnEnd = true;
            } 
            break;
        case 26:
            if(cellc8.isUsed == false){
                cellc8.changeCell(botChar);
                if(checkWin(26)){
                    botWins++;
                }
                turnEnd = true;
            } 
           break;
        case 27:
            if(cellc9.isUsed == false){
                cellc9.changeCell(botChar);
                if(checkWin(27)){
                    botWins++;
                }
                turnEnd = true;
            } 
            break;
        default:
            continue;
    }
    }while(turnEnd != true);
    
}

void Field::playerTurn(){       //Method that prompts user for input for what cell to change, then changes the cell if it's not already occupied
    turnEnd = false;
    int boardIn;
    int cellIn;

    do{
    cout << "Enter Which board You want to " << endl;
    cin >> boardIn;
    cout << "Enter Which cell You want to " << endl;
    cin >> cellIn;

    if(boardIn == 1){
        switch(cellIn){
            case 1:
                if(cella1.isUsed == false){
                    cella1.changeCell(playerChar);
                    if(checkWin(1)){
                        playerWins++;
                    }
                    turnEnd = true;
                }
                break;
            case 2:
                if(cella2.isUsed == false){
                    cella2.changeCell(playerChar);
                    if(checkWin(2)){
                        playerWins++;
                    }
                    turnEnd = true;
                }
                break;
            case 3:
                if(cella3.isUsed == false){
                    cella3.changeCell(playerChar);
                    if(checkWin(3)){
                        playerWins++;
                    }
                    turnEnd = true;
                }
                break;
            case 4:
                if(cella4.isUsed == false){
                    cella4.changeCell(playerChar);
                    if(checkWin(4)){
                        playerWins++;
                    }
                    turnEnd = true;
                } 
                break;
            case 5:
                if(cella5.isUsed == false){
                    cella5.changeCell(playerChar);
                    if(checkWin(5)){
                        playerWins++;
                    }
                    turnEnd = true;
                } 
                break;
            case 6:
                if(cella6.isUsed == false){
                    cella6.changeCell(playerChar);
                    if(checkWin(6)){
                        playerWins++;
                    }
                    turnEnd = true;
                } 
                break;
            case 7:
                if(cella7.isUsed == false){
                    cella7.changeCell(playerChar);
                    if(checkWin(7)){
                        playerWins++;
                    }
                    turnEnd = true;
                } 
                break;
            case 8:
                if(cella8.isUsed == false){
                    cella8.changeCell(playerChar);
                    if(checkWin(8)){
                        playerWins++;
                    }
                    turnEnd = true;
                } 
                break;
            case 9:
                if(cella9.isUsed == false){
                    cella9.changeCell(playerChar);
                    if(checkWin(9)){
                        playerWins++;
                    }
                    turnEnd = true;
                } 
                break;
        }
    }
    else if(boardIn == 2){
        switch(cellIn){
            case 1:
                if(cellb1.isUsed == false){
                    cellb1.changeCell(playerChar);
                    if(checkWin(10)){
                        playerWins++;
                    }
                    turnEnd = true;
                } 
                break;
            case 2:
                if(cellb2.isUsed == false){
                    cellb2.changeCell(playerChar);
                    if(checkWin(11)){
                        playerWins++;
                    }
                    turnEnd = true;
                } 
                break;
            case 3:
                if(cellb3.isUsed == false){
                    cellb3.changeCell(playerChar);
                    if(checkWin(12)){
                        playerWins++;
                    }
                    turnEnd = true;
                } 
                break;
            case 4:
                if(cellb4.isUsed == false){
                    cellb4.changeCell(playerChar);
                    if(checkWin(13)){
                        playerWins++;
                    }
                    turnEnd = true;
                } 
                break;
            case 5:
                if(cellb5.isUsed == false){
                    cellb5.changeCell(playerChar);
                    if(checkWin(14)){
                        playerWins++;
                    }
                    turnEnd = true;
                } 
                break;
            case 6:
                if(cellb6.isUsed == false){
                    cellb6.changeCell(playerChar);
                    if(checkWin(15)){
                        playerWins++;
                    }
                    turnEnd = true;
                } 
                break;
            case 7:
                if(cellb7.isUsed == false){
                    cellb7.changeCell(playerChar);
                    if(checkWin(16)){
                        playerWins++;
                    }
                    turnEnd = true;
                } 
                break;
            case 8:
                if(cellb8.isUsed == false){
                    cellb8.changeCell(playerChar);
                    if(checkWin(17)){
                        playerWins++;
                    }
                    turnEnd = true;
                } 
                break;
            case 9:
                if(cellb9.isUsed == false){
                    cellb9.changeCell(playerChar);
                    if(checkWin(18)){
                        playerWins++;
                    }
                    turnEnd = true;
                } 
                break;
        }
    }
    else if(boardIn == 3){
        switch(cellIn){
            case 1:
                if(cellc1.isUsed == false){
                    cellc1.changeCell(playerChar);
                    if(checkWin(19)){
                        playerWins++;
                    }
                    turnEnd = true;
                } 
                break;
            case 2:
                if(cellc2.isUsed == false){
                    cellc2.changeCell(playerChar);
                    if(checkWin(20)){
                        playerWins++;
                    }
                    turnEnd = true;
                } 
                break;
            case 3:
                if(cellc3.isUsed == false){
                    cellb3.changeCell(playerChar);
                    if(checkWin(21)){
                        playerWins++;
                    }
                    turnEnd = true;
                } 
                break;
            case 4:
                if(cellc4.isUsed == false){
                    cellc4.changeCell(playerChar);
                    if(checkWin(22)){
                        playerWins++;
                    }
                    turnEnd = true;
                } 
                break;
            case 5:
                if(cellc5.isUsed == false){
                    cellc5.changeCell(playerChar);
                    if(checkWin(23)){
                        playerWins++;
                    }
                    turnEnd = true;
                } 
                break;
            case 6:
                if(cellc6.isUsed == false){
                    cellc6.changeCell(playerChar);
                    if(checkWin(24)){
                        playerWins++;
                    }
                    turnEnd = true;
                } 
                break;
            case 7:
                if(cellc7.isUsed == false){
                    cellc7.changeCell(playerChar);
                    if(checkWin(25)){
                        playerWins++;
                    }
                    turnEnd = true;
                } 
                break;
            case 8:
                if(cellc8.isUsed == false){
                    cellc8.changeCell(playerChar);
                    if(checkWin(26)){
                        playerWins++;
                    }
                    turnEnd = true;
                } 
                break;
            case 9:
                if(cellc9.isUsed == false){
                    cellc9.changeCell(playerChar);
                    if(checkWin(27)){
                        playerWins++;
                    }
                    turnEnd = true;
                } 
                break;
        }
    }
    }while(turnEnd != true);
}

bool Field::checkWin(int cellNumIn){        //Method to check win that checks each win condition for the given cell
    bool isWin = false;
    switch(cellNumIn){
        case 1:
            if(cella1.cellChar == cella2.cellChar && cella1.cellChar == cella3.cellChar){
                isWin = true;
            }
            else if(cella1.cellChar == cella4.cellChar && cella1.cellChar == cella7.cellChar){
                isWin = true;
            }
            else if(cella1.cellChar == cella5.cellChar && cella1.cellChar == cella9.cellChar){
                isWin = true;
            }
            else if(cella1.cellChar == cellb1.cellChar && cella1.cellChar == cellc1.cellChar){
                isWin = true;
            }
            else if(cella1.cellChar == cellb2.cellChar && cella1.cellChar == cellc3.cellChar){
                isWin = true;
            }
            else if(cella1.cellChar == cellb4.cellChar && cella1.cellChar == cellc7.cellChar){
                isWin = true;
            }
            else if(cella1.cellChar == cellb5.cellChar && cella1.cellChar == cellc9.cellChar){
                isWin = true;
            }
            break;
        case 2:
            if(cella2.cellChar == cella1.cellChar && cella2.cellChar == cella3.cellChar){
                isWin = true;
            }
            else if(cella2.cellChar == cella5.cellChar && cella2.cellChar == cella9.cellChar){
                isWin = true;
            }
            else if(cella2.cellChar == cellb2.cellChar && cella2.cellChar == cellc2.cellChar){
                isWin = true;
            }
        case 3:
            if(cella3.cellChar == cella1.cellChar && cella3.cellChar == cella2.cellChar){
                isWin = true;
            }
            else if(cella3.cellChar == cella6.cellChar && cella3.cellChar == cella9.cellChar){
                isWin = true;
            }
            else if(cella3.cellChar == cella5.cellChar && cella3.cellChar == cella7.cellChar){
                isWin = true;
            }
            else if(cella3.cellChar == cellb3.cellChar && cella3.cellChar == cellc3.cellChar){
                isWin = true;
            }
            else if(cella3.cellChar == cellb1.cellChar && cella3.cellChar == cellc2.cellChar){
                isWin = true;
            }
            else if(cella3.cellChar == cellb6.cellChar && cella3.cellChar == cellc9.cellChar){
                isWin = true;
            }
            else if(cella3.cellChar == cellb5.cellChar && cella3.cellChar == cellc7.cellChar){
                isWin = true;
            }
            break;
        case 4:
            if(cella4.cellChar == cella5.cellChar && cella4.cellChar == cella6.cellChar){
                isWin = true;
            }
            else if(cella4.cellChar == cella1.cellChar && cella4.cellChar == cella7.cellChar){
                isWin = true;
            }
            else if(cella4.cellChar == cellb4.cellChar && cella4.cellChar == cellc4.cellChar){
                isWin = true;
            }
            break;
        case 5:
            if(cella5.cellChar == cella3.cellChar && cella5.cellChar == cella7.cellChar){
                isWin = true;
            }
            else if(cella5.cellChar == cella4.cellChar && cella5.cellChar == cella6.cellChar){
                isWin = true;
            }
            else if(cella5.cellChar == cella2.cellChar && cella5.cellChar == cella8.cellChar){
                isWin = true;
            }
            else if(cella5.cellChar == cella1.cellChar && cella5.cellChar == cella9.cellChar){
                isWin = true;
            }
            else if(cella5.cellChar == cellb5.cellChar && cella5.cellChar == cellc5.cellChar){
                isWin = true;
            }
            break;
        case 6:
            if(cella6.cellChar == cella5.cellChar && cella6.cellChar == cella4.cellChar){
                isWin = true;
            }
            else if(cella6.cellChar == cella3.cellChar && cella6.cellChar == cella9.cellChar){
                isWin = true;
            }
            else if(cella6.cellChar == cellb6.cellChar && cella6.cellChar == cellc6.cellChar){
                isWin = true;
            }
            break;
        case 7:
            if(cella7.cellChar == cella8.cellChar && cella7.cellChar == cella9.cellChar){
                isWin = true;
            }
            else if(cella7.cellChar == cella4.cellChar && cella7.cellChar == cella1.cellChar){
                isWin = true;
            }
            else if(cella7.cellChar == cella5.cellChar && cella7.cellChar == cella3.cellChar){
                isWin = true;
            }
            else if(cella7.cellChar == cellb7.cellChar && cella7.cellChar == cellc7.cellChar){
                isWin = true;
            }
            else if(cella7.cellChar == cellb8.cellChar && cella7.cellChar == cellc9.cellChar){
                isWin = true;
            }
            else if(cella7.cellChar == cellb5.cellChar && cella7.cellChar == cellc3.cellChar){
                isWin = true;
            }
            else if(cella7.cellChar == cellb4.cellChar && cella7.cellChar == cellc1.cellChar){
                isWin = true;
            }
            break;
        case 8:
            if(cella8.cellChar == cella7.cellChar && cella8.cellChar == cella9.cellChar){
                isWin = true;
            }
            else if(cella8.cellChar == cella5.cellChar && cella8.cellChar == cella2.cellChar){
                isWin = true;
            }
            else if(cella8.cellChar == cellb8.cellChar && cella8.cellChar == cellc8.cellChar){
                isWin = true;
            }
            break;
        case 9:
            if(cella9.cellChar == cella8.cellChar && cella9.cellChar == cella7.cellChar){
                isWin = true;
            }
            else if(cella9.cellChar == cella6.cellChar && cella9.cellChar == cella3.cellChar){
                isWin = true;
            }
            else if(cella9.cellChar == cella5.cellChar && cella9.cellChar == cella1.cellChar){
                isWin = true;
            }
            else if(cella9.cellChar == cellb9.cellChar && cella9.cellChar == cellc9.cellChar){
                isWin = true;
            }
            else if(cella9.cellChar == cellb5.cellChar && cella9.cellChar == cellc1.cellChar){
                isWin = true;
            }
            else if(cella9.cellChar == cellb6.cellChar && cella9.cellChar == cellc3.cellChar){
                isWin = true;
            }
            else if(cella9.cellChar == cellb8.cellChar && cella9.cellChar == cellc7.cellChar){
                isWin = true;
            }
            break;
        case 10:
            if(cellb1.cellChar == cellb2.cellChar && cellb1.cellChar == cellb3.cellChar){
                isWin = true;
            }
            else if(cellb1.cellChar == cellb4.cellChar && cellb1.cellChar == cellb7.cellChar){
                isWin = true;
            }
            else if(cellb1.cellChar == cellb5.cellChar && cellb1.cellChar == cellb9.cellChar){
                isWin = true;
            }
            else if(cellb1.cellChar == cella1.cellChar && cellb1.cellChar == cellc1.cellChar){
                isWin = true;
            }
        case 11:
            if(cellb2.cellChar == cellb1.cellChar && cellb2.cellChar == cellb3.cellChar){
                isWin = true;
            }
            else if(cellb2.cellChar == cellb5.cellChar && cellb2.cellChar == cellb9.cellChar){
                isWin = true;
            }
            else if(cellb2.cellChar == cella2.cellChar && cellb2.cellChar == cellc2.cellChar){
                isWin = true;
            }
            else if(cellb2.cellChar == cella1.cellChar && cellb2.cellChar == cellc3.cellChar){
                isWin = true;
            }
            else if(cellb2.cellChar == cellc1.cellChar && cellb2.cellChar == cella3.cellChar){
                isWin = true;
            }
            break;
        case 12:
            if(cellb3.cellChar == cellb1.cellChar && cellb3.cellChar == cellb2.cellChar){
                isWin = true;
            }
            else if(cellb3.cellChar == cellb6.cellChar && cellb3.cellChar == cellb9.cellChar){
                isWin = true;
            }
            else if(cellb3.cellChar == cellb5.cellChar && cellb3.cellChar == cellb7.cellChar){
                isWin = true;
            }
            else if(cellb3.cellChar == cella3.cellChar && cellb3.cellChar == cellc3.cellChar){
                isWin = true;
            }
            break;
        case 13:
            if(cellb4.cellChar == cellb5.cellChar && cellb4.cellChar == cellb6.cellChar){
                isWin = true;
            }
            else if(cellb4.cellChar == cellb1.cellChar && cellb4.cellChar == cellb7.cellChar){
                isWin = true;
            }
            else if(cellb4.cellChar == cella1.cellChar && cellb4.cellChar == cellc7.cellChar){
                isWin = true;
            }
            else if(cellb4.cellChar == cella7.cellChar && cellb4.cellChar == cellc1.cellChar){
                isWin = true;
            }
            else if(cellb4.cellChar == cella4.cellChar && cellb4.cellChar == cellc4.cellChar){
                isWin = true;
            }
            break;
        case 14:
            if(cellb5.cellChar == cellb3.cellChar && cellb5.cellChar == cellb7.cellChar){
                isWin = true;
            }
            else if(cellb5.cellChar == cellb4.cellChar && cellb5.cellChar == cellb6.cellChar){
                isWin = true;
            }
            else if(cellb5.cellChar == cellb2.cellChar && cellb5.cellChar == cellb8.cellChar){
                isWin = true;
            }
            else if(cellb5.cellChar == cellb1.cellChar && cellb5.cellChar == cellb9.cellChar){
                isWin = true;
            }
            else if(cellb5.cellChar == cella5.cellChar && cellb5.cellChar == cellc5.cellChar){
                isWin = true;
            }
            else if(cellb5.cellChar == cella1.cellChar && cellb5.cellChar == cellc9.cellChar){
                isWin = true;
            }
            else if(cellb5.cellChar == cella9.cellChar && cellb5.cellChar == cellc1.cellChar){
                isWin = true;
            }
            else if(cellb5.cellChar == cella7.cellChar && cellb5.cellChar == cellc3.cellChar){
                isWin = true;
            }
            else if(cellb5.cellChar == cella3.cellChar && cellb5.cellChar == cellc7.cellChar){
                isWin = true;
            }
            break;
        case 15:
            if(cellb6.cellChar == cellb5.cellChar && cellb6.cellChar == cellb4.cellChar){
                isWin = true;
            }
            else if(cellb6.cellChar == cellb3.cellChar && cellb6.cellChar == cellb9.cellChar){
                isWin = true;
            }
            else if(cellb6.cellChar == cella6.cellChar && cellb6.cellChar == cellc6.cellChar){
                isWin = true;
            }
            else if(cellb6.cellChar == cella1.cellChar && cellb6.cellChar == cellc9.cellChar){
                isWin = true;
            }
            else if(cellb6.cellChar == cella9.cellChar && cellb6.cellChar == cellc1.cellChar){
                isWin = true;
            }
            break;
        case 16:
            if(cellb7.cellChar == cellb8.cellChar && cellb7.cellChar == cellb9.cellChar){
                isWin = true;
            }
            else if(cellb7.cellChar == cellb4.cellChar && cellb7.cellChar == cellb1.cellChar){
                isWin = true;
            }
            else if(cellb7.cellChar == cellb5.cellChar && cellb7.cellChar == cellb3.cellChar){
                isWin = true;
            }
            else if(cellb7.cellChar == cella7.cellChar && cellb7.cellChar == cellc7.cellChar){
                isWin = true;
            }
            break;
        case 17:
            if(cellb8.cellChar == cellb7.cellChar && cellb8.cellChar == cellb9.cellChar){
                isWin = true;
            }
            else if(cellb8.cellChar == cellb5.cellChar && cellb8.cellChar == cellb2.cellChar){
                isWin = true;
            }
            else if(cellb8.cellChar == cella8.cellChar && cellb8.cellChar == cellc8.cellChar){
                isWin = true;
            }
            else if(cellb8.cellChar == cella7.cellChar && cellb8.cellChar == cellc9.cellChar){
                isWin = true;
            }
            else if(cellb8.cellChar == cella9.cellChar && cellb8.cellChar == cellc7.cellChar){
                isWin = true;
            }
            break;
        case 18:
            if(cellb9.cellChar == cellb8.cellChar && cellb9.cellChar == cellb7.cellChar){
                isWin = true;
            }
            else if(cellb9.cellChar == cellb6.cellChar && cellb9.cellChar == cellb3.cellChar){
                isWin = true;
            }
            else if(cellb9.cellChar == cellb5.cellChar && cellb9.cellChar == cellb1.cellChar){
                isWin = true;
            }
            break;
        case 19:
            if(cellc1.cellChar == cellc2.cellChar && cellc1.cellChar == cellc3.cellChar){
                isWin = true;
            }
            else if(cellc1.cellChar == cellc4.cellChar && cellc1.cellChar == cellc7.cellChar){
                isWin = true;
            }
            else if(cellc1.cellChar == cellc5.cellChar && cellc1.cellChar == cellc9.cellChar){
                isWin = true;
            }
            else if(cellc1.cellChar == cella1.cellChar && cellc1.cellChar == cellb1.cellChar){
                isWin = true;
            }
            else if(cellc1.cellChar == cellb2.cellChar && cellc1.cellChar == cella3.cellChar){
                isWin = true;
            }
            else if(cellc1.cellChar == cellb4.cellChar && cellc1.cellChar == cella7.cellChar){
                isWin = true;
            }
            else if(cellc1.cellChar == cellb5.cellChar && cellc1.cellChar == cella9.cellChar){
                isWin = true;
            }
            break;
        case 20:
            if(cellc2.cellChar == cellc1.cellChar && cellc2.cellChar == cellc3.cellChar){
                isWin = true;
            }
            else if(cellc2.cellChar == cellc5.cellChar && cellc2.cellChar == cellc9.cellChar){
                isWin = true;
            }
            else if(cellc2.cellChar == cellb2.cellChar && cellc2.cellChar == cella2.cellChar){
                isWin = true;
            }
        case 21:
            if(cellc3.cellChar == cellc1.cellChar && cellc3.cellChar == cellc2.cellChar){
                isWin = true;
            }
            else if(cellc3.cellChar == cellc6.cellChar && cellc3.cellChar == cellc9.cellChar){
                isWin = true;
            }
            else if(cellc3.cellChar == cellc5.cellChar && cellc3.cellChar == cellc7.cellChar){
                isWin = true;
            }
            else if(cellc3.cellChar == cellb3.cellChar && cellc3.cellChar == cella3.cellChar){
                isWin = true;
            }
            else if(cellc3.cellChar == cellb1.cellChar && cellc3.cellChar == cella2.cellChar){
                isWin = true;
            }
            else if(cellc3.cellChar == cellb6.cellChar && cellc3.cellChar == cella9.cellChar){
                isWin = true;
            }
            else if(cellc3.cellChar == cellb5.cellChar && cellc3.cellChar == cella7.cellChar){
                isWin = true;
            }
            break;
        case 22:
            if(cellc4.cellChar == cellc5.cellChar && cellc4.cellChar == cellc6.cellChar){
                isWin = true;
            }
            else if(cellc4.cellChar == cellc1.cellChar && cellc4.cellChar == cellc7.cellChar){
                isWin = true;
            }
            else if(cellc4.cellChar == cellb4.cellChar && cellc4.cellChar == cella4.cellChar){
                isWin = true;
            }
            break;
        case 23:
            if(cellc5.cellChar == cellc3.cellChar && cellc5.cellChar == cellc7.cellChar){
                isWin = true;
            }
            else if(cellc5.cellChar == cellc4.cellChar && cellc5.cellChar == cellc6.cellChar){
                isWin = true;
            }
            else if(cellc5.cellChar == cellc2.cellChar && cellc5.cellChar == cellc8.cellChar){
                isWin = true;
            }
            else if(cellc5.cellChar == cellc1.cellChar && cellc5.cellChar == cellc9.cellChar){
                isWin = true;
            }
            else if(cellc5.cellChar == cellb5.cellChar && cellc5.cellChar == cella5.cellChar){
                isWin = true;
            }
            break;
        case 24:
            if(cellc6.cellChar == cellc5.cellChar && cellc6.cellChar == cellc4.cellChar){
                isWin = true;
            }
            else if(cellc6.cellChar == cellc3.cellChar && cellc6.cellChar == cellc9.cellChar){
                isWin = true;
            }
            else if(cellc6.cellChar == cellb6.cellChar && cellc6.cellChar == cella6.cellChar){
                isWin = true;
            }
            break;
        case 25:
            if(cellc7.cellChar == cellc8.cellChar && cellc7.cellChar == cellc9.cellChar){
                isWin = true;
            }
            else if(cellc7.cellChar == cellc4.cellChar && cellc7.cellChar == cellc1.cellChar){
                isWin = true;
            }
            else if(cellc7.cellChar == cellc5.cellChar && cellc7.cellChar == cellc3.cellChar){
                isWin = true;
            }
            else if(cellc7.cellChar == cellb7.cellChar && cellc7.cellChar == cella7.cellChar){
                isWin = true;
            }
            else if(cellc7.cellChar == cellb8.cellChar && cellc7.cellChar == cella9.cellChar){
                isWin = true;
            }
            else if(cellc7.cellChar == cellb5.cellChar && cellc7.cellChar == cella3.cellChar){
                isWin = true;
            }
            else if(cellc7.cellChar == cellb4.cellChar && cellc7.cellChar == cella1.cellChar){
                isWin = true;
            }
            break;
        case 26:
            if(cellc8.cellChar == cellc7.cellChar && cellc8.cellChar == cellc9.cellChar){
                isWin = true;
            }
            else if(cellc8.cellChar == cellc5.cellChar && cellc8.cellChar == cellc2.cellChar){
                isWin = true;
            }
            else if(cellc8.cellChar == cellb8.cellChar && cellc8.cellChar == cella8.cellChar){
                isWin = true;
            }
            break;
        case 27:
            if(cellc9.cellChar == cellc8.cellChar && cellc9.cellChar == cellc7.cellChar){
                isWin = true;
            }
            else if(cellc9.cellChar == cellc6.cellChar && cellc9.cellChar == cellc3.cellChar){
                isWin = true;
            }
            else if(cellc9.cellChar == cellc5.cellChar && cellc9.cellChar == cellc1.cellChar){
                isWin = true;
            }
            else if(cellc9.cellChar == cellb9.cellChar && cellc9.cellChar == cella9.cellChar){
                isWin = true;
            }
            else if(cellc9.cellChar == cellb5.cellChar && cellc9.cellChar == cella1.cellChar){
                isWin = true;
            }
            else if(cellc9.cellChar == cellb6.cellChar && cellc9.cellChar == cella3.cellChar){
                isWin = true;
            }
            else if(cellc9.cellChar == cellb8.cellChar && cellc9.cellChar == cella7.cellChar){
                isWin = true;
            }
            break;
    }   
return isWin;
}

bool Field::checkEnd(){ //returns true if all the cells are changed
    if(cella1.isUsed && cella2.isUsed && cella3.isUsed && cella4.isUsed && cella5.isUsed && cella6.isUsed && cella7.isUsed && cella8.isUsed && cella9.isUsed && cellb1.isUsed && cellb2.isUsed && cellb3.isUsed && cellb4.isUsed && cellb5.isUsed && cellb6.isUsed && cellb7.isUsed && cellb8.isUsed &&cellb9.isUsed &&  cellc1.isUsed && cellc2.isUsed && cellc3.isUsed && cellc4.isUsed && cellc5.isUsed && cellc6.isUsed && cellc7.isUsed && cellc8.isUsed && cellc9.isUsed){
        return true;
    }
    else{
        return false;
    }
}
