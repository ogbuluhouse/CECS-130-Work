#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>

using namespace std;

//Isaiah Ogbulu, 4/24/19, Lab 11, 3D Tic Tak Toe Competition
//Aaron Cromis, 4/24/19, Lab 11, 3D Tic Tac Toe Competition

class boardGame
{
	public: 
	int board[3] [3];
	boardGame()
	{
		for(int x=0;x<3;x++)
		{
			for(int y=0;y<3;y++)
			{
			board[x] [y] = 0;
			}
		}
	}

~boardGame() {} //Decon to free memory
void setX(int x, int y);
void set0(int x, int y);
bool vacancy(int x, int y);
void draw();
string checkMarks(int x);
bool checkWinner();
void aaronBot();
};
class tdBoard: public boardGame
{
	public:
		int boardTwo[3][3][3];
		int isaiahScore;
		int aaronScore;
	tdBoard()
	{
		for(int x=0;x<3;x++)
		{
		for(int y=0;y<3;y++)
		{
			for(int z=0;z<3;z++){
				boardTwo[x][y][z] = 0;
			}
		}
		}
		isaiahScore = 0;
	aaronScore = 0;
	}
	void draw(); //draws board
	~tdBoard() {}
	void setX(int z, int x, int y);//sqaure to x
	void set0(int z, int x, int y);//square to y
	bool vacancy(int x, int y, int z);//check if space is filled
	string checkMarks(int x);// insert o's and x's
	int checkWinner();//check for win
	void isaiahBot();//lets user make a move
	void aaronBot();
	bool checkFull();//check if all possible moves are made	
};

class Competition: public tdBoard{
    public:
        const int numGames = 10;
        void startBots(int);
};

 void boardGame::setX(int x, int y)
 {
 	if(vacancy(x,y))
 	{
 		board[x] [y] = 8;
 	}
 	else{
 		cout << "This space is already taken!";
 	}
 }
 void boardGame::set0(int x, int y)
 {
 	if(vacancy(x,y))
 	{
 		board[x] [y] = 9;
 	}
 	else{
 		cout << "This space is already taken!";
 	}
 }
 bool boardGame::vacancy(int x, int y)
 {
 	if(board[x] [y] !=0)
 	{
 		return false;
 	}
 	else{
 		return true;
 	}
 }
 bool boardGame::checkWinner()
 {
 	int result = 50;
 	for(int x=0;x<3;x++)
 	{
 		if(((board[x] [0] == 8)&&(board[x][2]==8))||((board[x][0]== 9)&&(board[x][1] ==9)&&(board[x][2]==9)))
 		{
 			result = board[x][0];
 		}
 	}
 	for(int y=0;y<3;y++)
 	{
 		if(((board[y] [0] == 8)&&(board[y][2]==8))||((board[y][0]== 9)&&(board[y][1] ==9)&&(board[y][2]==9)))
		{
			result = board[0][y];
		} 	
 	}
 	if(((board[0][0] == 8)&&(board[1][1]==8))&&((board[2][2]== 8)||(board[0][2] ==8)&&(board[1][1]==8)&&(board[2][0]==8))||
 	((board[0][0]==9)&&(board[1][1]==9)&&(board[2][2]==9))||((board[0][2]==9)&&(board[1][1]==9)&&board[2][0]==9))
 	{
 		result = board [1][1];
 	}
int fullCount = 0;
for(int x=0;x<3;x++)
	{
		for(int y=0;y<3;y++)
		{
			if(board[x][y] != 0)
			{
				fullCount++;
			}
		}
	}
	if(fullCount == 9)
	{
		result = 0;
	}
	if(result==8)
	{
		cout<<"You win";
		return false;
	}
	else if(result==9)
	{
		cout<<"You lose";
		return false;
	}
	else if(result==0)
	{
		cout<<"Tie";
		return false;
	}
	return true;
 }
 void boardGame::draw()
 {
 	cout<<"\n";
 	cout<<" 0 1 2\n";
 	for(int x=0;x<3;x++){
 		cout<<x;
 		for(int y=0;y<3;y++){
 			cout<<"|"<<checkMarks(board[x][y])<<"|";
 		}
 		cout<<endl;
 	}
 }
 string boardGame::checkMarks(int x)
 {
 	if(x==0)
 	{
 		return "X";
 	}
 	else if(x==8)
 	{
 		return "X";
 	}
 	return "0";
 }
 void boardGame::aaronBot()
 {
 	int exit = 0;
 	int compXCoord;
 	int compYCoord;
 	do{
 		srand((unsigned)time(NULL));
 		compXCoord = rand() % 3;
 		compYCoord = rand() % 3;
 		
 		if(vacancy(compXCoord,compYCoord))
 		{
 			set0(compXCoord,compYCoord);
 			exit = 1;
 		}
 	}while(exit == 0);
 	for(int x=0;x<3;x++){
 		for(int y=0;y<3;y++){
 			if((board[x][y]==0))
 			{
 				set0(x,y);
 			
 			}
 		}
 	}
 }
 void tdBoard::setX(int x, int y, int z)		//changes integer in 3D array based off given coordinates
 {
 	boardTwo[x][y][z] = 8;
 }
 void tdBoard::set0(int z, int x, int y)		//changes integer in 3D array based off given coordinates
 {
 	boardTwo[x][y][z] = 9;
 }
 bool tdBoard::vacancy(int x, int y, int z)		//checks if given index has been changed
 {
 	if(boardTwo[x][y][z] != 0)
 	{
 		return false;
 	}
 	else{
 		return true;
 	}
 }
 int tdBoard::checkWinner()			//checks each winning combonation and keeps track of which bot is winning the most and returns an integer based off number of wins or if there is a tie
 {
 	for(int z=0;z<3;z++)
 	{
 		for(int x=0;x<3;x++)
 		{
 			if(((boardTwo[x][0][z] == 8)&&(boardTwo[x][1][z] == 8)&&(boardTwo[x][2][z]==8))||
 			((boardTwo[x][0][z] == 9)&&(boardTwo[x][1][z] == 9)&&(boardTwo[x][2][z]==9)))
 			{ 
 				if((boardTwo[x][0][z] == 8)&&(boardTwo[x][1][z] == 8)&&(boardTwo[x][2][z]==8))
 				{
 					isaiahScore++;
 				}
 				else{
 					aaronScore++;
 				}
 				
 			}
 		}
 	
 	for(int y=0;y<3;y++)
 	{
 		if((boardTwo[0][y][z] == 8)&&(boardTwo[1][y][z] == 8)&&(boardTwo[2][y][z]==8)||
 		((boardTwo[0][y][z] == 9)&&(boardTwo[1][y][z] == 9)&&(boardTwo[2][y][z]==9)))
 		{
 			if((boardTwo[0][y][z] ==8)&&(boardTwo[1][y][z] == 8)&&(boardTwo[2][y][z]==8))
 			{
 				isaiahScore++;
 			}
 			else{
 				aaronScore++;
 			}
 		}
 	}
 
 	if(((boardTwo[0][0][z] == 8)&&(boardTwo[1][1][z] ==8)&&(boardTwo[2][2][z]==8))||
 	((boardTwo[0][2][z] ==8)&&(boardTwo[1][1][z] ==8)&&(boardTwo[2][0][z]==8))||
 	((boardTwo[0][0][z] ==9)&&(boardTwo[1][1][z] ==9)&&(boardTwo[2][2][z]==9))||
 	((boardTwo[0][2][z] ==9)&&(boardTwo[1][1][z] ==9)&&(boardTwo[2][0][z]==9)))
 	{
 		if(((boardTwo[0][0][z] == 8)&&(boardTwo[1][1][z] == 8)&&(boardTwo[2][2][z] ==8))||
 		((boardTwo[0][2][z] ==8)&&(boardTwo[1][1][z] ==8)&&(boardTwo[2][0][z]==8)))
 		{
 			isaiahScore++;
 		}
 		else
 		{
 			aaronScore++;
 		}
 	}}
 
 int z=0;z<3;z++;
 
 	if(boardTwo[0][0][z]+boardTwo[0][0][z+1]+boardTwo[0][0][z+2] ==24){
 	
 	isaiahScore++;
 }
 if(boardTwo[1][0][z]+boardTwo[1][0][z+1]+boardTwo[1][0][z+2] ==24){
 	isaiahScore++;
 }
 if(boardTwo[2][0][z]+boardTwo[2][0][z+1]+boardTwo[2][0][z+2] ==24){
 	
 	isaiahScore++;
 }
 if(boardTwo[0][1][z]+boardTwo[0][1][z+1]+boardTwo[0][1][z+2] ==24){
 	
 	isaiahScore++;
 }
 if(boardTwo[1][1][z]+boardTwo[1][1][z+1]+boardTwo[1][1][z+2] ==24){
 	
 	isaiahScore++;
 }
 if(boardTwo[0][2][z]+boardTwo[0][2][z+1]+boardTwo[0][2][z+2] ==24){
 	
 	isaiahScore++;
 }
 if(boardTwo[2][2][z]+boardTwo[2][2][z+1]+boardTwo[2][2][z+2] ==24){
 	
 	isaiahScore++;
 }
 if(boardTwo[2][1][z]+boardTwo[2][1][z+1]+boardTwo[2][1][z+2] ==24){
 	
 	isaiahScore++;
 }
 if(boardTwo[0][0][z]+boardTwo[1][1][z+1]+boardTwo[2][2][z+2] ==24){
 	
 	isaiahScore++;
 }
 if(boardTwo[2][0][z]+boardTwo[1][1][z+1]+boardTwo[0][2][z+2] ==24){
 	
 	isaiahScore++;
 }
 if(boardTwo[0][2][z]+boardTwo[1][1][z+1]+boardTwo[2][0][z+2] ==24){
 	
 	isaiahScore++;
 }
 if(boardTwo[2][2][z]+boardTwo[1][1][z+1]+boardTwo[0][0][z+2] ==24){
 	
 	isaiahScore++;
 }
 if(boardTwo[1][0][z]+boardTwo[1][1][z+1]+boardTwo[1][2][z+2] ==24){
 	
 	isaiahScore++;
 }
 if(boardTwo[1][2][z]+boardTwo[1][1][z+1]+boardTwo[1][0][z+2] ==24){
 	
 	isaiahScore++;
 }
 if(boardTwo[0][1][z]+boardTwo[1][1][z+1]+boardTwo[2][1][z+2] ==24){
 	
 	isaiahScore++;
 }
 if(boardTwo[2][1][z]+boardTwo[1][1][z+1]+boardTwo[0][1][z+2] ==24){
 	
 	isaiahScore++;
 }
 if(boardTwo[2][2][z]+boardTwo[1][2][z+1]+boardTwo[0][2][z+2] ==24){
 	
 	isaiahScore++;
 }
 if(boardTwo[0][2][z]+boardTwo[1][2][z+1]+boardTwo[2][2][z+2] ==24){
 	
 	isaiahScore++;
 }
 if(boardTwo[0][2][z]+boardTwo[0][1][z+1]+boardTwo[0][0][z+2] ==24){
 	
 	isaiahScore++;
 }
 if(boardTwo[0][0][z]+boardTwo[0][1][z+1]+boardTwo[0][2][z+2] ==24){
 	
 	isaiahScore++;
 }
 if(boardTwo[0][0][z]+boardTwo[1][0][z+1]+boardTwo[2][0][z+2] ==24){
 	
 	isaiahScore++;
 }
 if(boardTwo[2][0][z]+boardTwo[1][0][z+1]+boardTwo[0][0][z+2] ==24){
 	
 	isaiahScore++;
 }
 if(boardTwo[2][0][z]+boardTwo[2][1][z+1]+boardTwo[2][2][z+2] ==24){
 	
 	isaiahScore++;
 }
 if(boardTwo[2][2][z]+boardTwo[2][1][z+1]+boardTwo[2][0][z+2] ==24){
 	
 	isaiahScore++;
 }
 if(boardTwo[0][0][z]+boardTwo[0][0][z+1]+boardTwo[0][0][z+2] ==27){
 	
 	aaronScore++;
 }
 if(boardTwo[1][0][z]+boardTwo[1][0][z+1]+boardTwo[1][0][z+2] ==27){
 	aaronScore++;
 }
 if(boardTwo[2][0][z]+boardTwo[2][0][z+1]+boardTwo[2][0][z+2] ==27){
 	
 	aaronScore++;
 }
 if(boardTwo[0][1][z]+boardTwo[0][1][z+1]+boardTwo[0][1][z+2] ==27){
 	
 	aaronScore++;
 }
 if(boardTwo[1][1][z]+boardTwo[1][1][z+1]+boardTwo[1][1][z+2] ==27){
 	
 	aaronScore++;
 }
 if(boardTwo[0][2][z]+boardTwo[0][2][z+1]+boardTwo[0][2][z+2] ==27){
 	
 	aaronScore++;
 }
 if(boardTwo[2][2][z]+boardTwo[2][2][z+1]+boardTwo[2][2][z+2] ==27){
 	
 	aaronScore++;
 }
 if(boardTwo[2][1][z]+boardTwo[2][1][z+1]+boardTwo[2][1][z+2] ==27){
 	
 	aaronScore++;
 }
 if(boardTwo[0][0][z]+boardTwo[1][1][z+1]+boardTwo[2][2][z+2] ==27){
 	
 	aaronScore++;
 }
 if(boardTwo[2][0][z]+boardTwo[1][1][z+1]+boardTwo[0][2][z+2] ==27){
 	
 	aaronScore++;
 }
 if(boardTwo[0][2][z]+boardTwo[1][1][z+1]+boardTwo[2][0][z+2] ==27){
 	
 	aaronScore++;
 }
 if(boardTwo[2][2][z]+boardTwo[1][1][z+1]+boardTwo[0][0][z+2] ==27){
 	
 	aaronScore++;
 }
 if(boardTwo[1][0][z]+boardTwo[1][1][z+1]+boardTwo[1][2][z+2] ==27){
 	
 	aaronScore++;
 }
 if(boardTwo[1][2][z]+boardTwo[1][1][z+1]+boardTwo[1][0][z+2] ==27){
 	
 	aaronScore++;
 }
 if(boardTwo[0][1][z]+boardTwo[1][1][z+1]+boardTwo[2][1][z+2] ==27){
 	
 	aaronScore++;
 }
 if(boardTwo[2][1][z]+boardTwo[1][1][z+1]+boardTwo[0][1][z+2] ==27){
 	
 	aaronScore++;
 }
 if(boardTwo[2][2][z]+boardTwo[1][2][z+1]+boardTwo[0][2][z+2] ==27){
 	
 	aaronScore++;
 }
 if(boardTwo[0][2][z]+boardTwo[1][2][z+1]+boardTwo[2][2][z+2] ==27){
 	
 	aaronScore++;
 }
 if(boardTwo[0][2][z]+boardTwo[0][1][z+1]+boardTwo[0][0][z+2] ==27){
 	
 	aaronScore++;
 }
 if(boardTwo[0][0][z]+boardTwo[0][1][z+1]+boardTwo[0][2][z+2] ==27){
 	
 	aaronScore++;
 }
 if(boardTwo[0][0][z]+boardTwo[1][0][z+1]+boardTwo[2][0][z+2] ==27){
 	
 	aaronScore++;
 }
 if(boardTwo[2][0][z]+boardTwo[1][0][z+1]+boardTwo[0][0][z+2] ==27){
 	
 	aaronScore++;
 }
 if(boardTwo[2][0][z]+boardTwo[2][1][z+1]+boardTwo[2][2][z+2] ==27){
 	
 	aaronScore++;
 }
 if(boardTwo[2][2][z]+boardTwo[2][1][z+1]+boardTwo[2][0][z+2] ==27){
 	
 	aaronScore++;
 }
 if(isaiahScore<aaronScore)
 {
 	return 0;
 }
 else if(isaiahScore>aaronScore)
 {
 	return 1;
 }
 else{
 	return 2;
 }
}
void tdBoard::draw()		//Outputs 3D board with labeled columns and rows
{
	cout<<"\n";
	
	for(int z=0;z<3;z++){
		cout<<"Board:  "<<z<<endl;
		cout<<"  0  1  2\n";
		for(int y=0;y<3;y++){
			cout<<y;
			for(int x=0;x<3;x++){
				cout<<"|"<<checkMarks(boardTwo[x][y][z])<<"|";
				
			}
			cout<<endl;
		}
		cout<<endl;
	}
	cout<<"\n";
}
string tdBoard::checkMarks(int x)
{
	if(x==0)
	{
		return " ";
	}
	else if(x==8)
	{
		return "X";
	}
	return "0";
}
//computer move method
void tdBoard::aaronBot()
{
	srand((unsigned)time(NULL));
	int exit = 0;
	int compXCoord;
	int compYCoord;
	int compZCoord;
	do{
		compXCoord = rand() % 3;
		compYCoord = rand() % 3;
		compZCoord = rand() % 3;
		if(vacancy(1,1,1))
		{
			set0(1,1,1);
			return;
		}
		if(vacancy(compXCoord, compYCoord, compZCoord))
		{
			set0(compZCoord,compXCoord,compYCoord);
			exit = 1;
		}
	}while(exit == 0);
}
//checks if board is full
bool tdBoard::checkFull()
{
	int totalCount = 0;
	for(int z=0;z<3;z++)
	{
		for(int y=0;y<3;y++)
		{
			for(int x=0;x<3;x++)
			{
				if(boardTwo[x][y][z] !=0)
				{
					totalCount++;
				}
			}
		}
	}
	if(totalCount == 27)
	{
		return true;
	}
	else{
		return false;
	}
}
void tdBoard::isaiahBot(){		//generates random number from 1 to 27 then converts them to coordinates to change index in 3D array
    bool turnEnd = false;

    do{
    srand(time(NULL));
    int randNum = (rand()%27) + 1;
    switch(randNum){
        case 1:
            if(vacancy(0,0,0)){
                setX(0,0,0);
                turnEnd = true;
            } 
            break;
        case 2:
            if(vacancy(0,1,0)){
                setX(0,1,0);
                turnEnd = true;
            } 
            break;
        case 3:
            if(vacancy(0,2,0)){
                setX(0,2,0);
                turnEnd = true;
            } 
            break;
        case 4:
            if(vacancy(1,0,0)){
                setX(1,0,0);
                turnEnd = true;
            } 
            break;
        case 5:
            if(vacancy(1,1,0)){
                setX(1,1,0);
                turnEnd = true;
            } 
            break;
        case 6:
            if(vacancy(1,2,0)){
                setX(1,2,0);
                turnEnd = true;
            } 
            break;
        case 7:
            if(vacancy(2,0,0)){
                setX(2,0,0);
                turnEnd = true;
            } 
            break;
        case 8:
            if(vacancy(2,1,0)){
                setX(2,1,0);
                turnEnd = true;
            } 
            break;
        case 9:
            if(vacancy(2,2,0)){
                setX(2,2,0);
                turnEnd = true;
            } 
            break;
        case 10:
            if(vacancy(0,0,1)){
                setX(0,0,1);
                turnEnd = true;
            } 
            break;
        case 11:
            if(vacancy(0,1,1)){
                setX(0,1,1);
                turnEnd = true;
            } 
            break;
        case 12:
            if(vacancy(0,2,1)){
                setX(0,2,1);
                turnEnd = true;
            } 
            break;
        case 13:
            if(vacancy(1,0,1)){
                setX(1,0,1);
                turnEnd = true;
            } 
            break;
        case 14:
            if(vacancy(1,1,1)){
                setX(1,1,1);
                turnEnd = true;
            } 
            break;
        case 15:
            if(vacancy(1,2,1)){
                setX(1,2,1);
                turnEnd = true;
            } 
            break;
        case 16:
            if(vacancy(2,0,1)){
                setX(2,0,1);
                turnEnd = true;
            } 
            break;
        case 17:
            if(vacancy(2,1,1)){
                setX(2,1,1);
                turnEnd = true;
            } 
            break;
        case 18:
            if(vacancy(2,2,1)){
                setX(2,2,1);
                turnEnd = true;
            } 
            break;
        case 19:
            if(vacancy(0,0,2)){
                setX(0,0,2);
                turnEnd = true;
            } 
            break;
        case 20:
            if(vacancy(0,1,2)){
                setX(0,1,2);
                turnEnd = true;
            } 
            break;
        case 21:
            if(vacancy(0,2,2)){
                setX(0,2,2);
                turnEnd = true;
            } 
            break;
        case 22:
            if(vacancy(1,0,2)){
                setX(1,0,2);
                turnEnd = true;
            } 
            break;
        case 23:
            if(vacancy(1,1,2)){
                setX(1,1,2);
                turnEnd = true;
            } 
            break;
        case 24:
            if(vacancy(1,2,2)){
                setX(1,2,2);
                turnEnd = true;
            } 
            break;
        case 25:
            if(vacancy(2,0,2)){
                setX(2,0,2);
                turnEnd = true;
            } 
            break;
        case 26:
            if(vacancy(2,1,2)){
                setX(2,1,2);
                turnEnd = true;
            } 
           break;
        case 27:
            if(vacancy(2,2,2)){
                setX(2,2,2);
                turnEnd = true;
            } 
            break;
        default:
            continue;
    }
    }while(turnEnd == false);
    
}

void Competition::startBots(int starter){	//Runs both bots together, outputing which bot's turn it is and the board for each turn
    int isaiahWins = 0;
    int aaronWins = 0;
    for(int i = 0; i < numGames; i++){
        tdBoard botComp;
        do{
            if(starter%2 == 1){
                cout << "Isaiah's Turn" << endl;
                botComp.isaiahBot();
				botComp.draw();
            }
            else{
                cout << "Aaron's Turn" << endl;
                botComp.aaronBot();
				botComp.draw();				
            }
            starter++;
        }while(botComp.checkFull() == false);

        cout << "Game " << (i+1) << " Over! ";
        if(botComp.checkWinner() == 1){
            cout << "Isaiah Wins this round!"<< endl;
            isaiahWins++;
        }
        else if(botComp.checkWinner() == 0){
            cout << "Aaron Wins this round!"<< endl;
            aaronWins++;
        }
        else if(botComp.checkWinner() == 2){
            cout << "This Round ends in a TIE!" << endl;
        }
    }
    cout << endl;
    if(isaiahWins > aaronWins){
        cout << "Isaiah's bot wins with " << isaiahWins << " winning games!" << endl;
    }
    else if(aaronWins > isaiahWins){
        cout << "Aaron's bot wins with " << aaronWins << " winning games!" << endl;
    }
    else{
        cout << "This match ends in a Tie!" << endl;
    }
}

int main()
{
	Competition thisComp;
	int userTurn;
    int userChoice;
	srand((unsigned)time(NULL));
	do{
        userTurn = rand() % 10;

		cout<<"Enter 1 to run a game, and enter 0 to exit program" << endl;		//prompts user if they want to run another game and if not exits program
        cin >> userChoice;
        if(userChoice == 1){
        	cout << "STARTING GAME" <<endl <<endl;
        	thisComp.startBots(userTurn);
        }
		else if(userChoice == 0){
			cout << "EXITING GAME..." << endl;
		}
        else{
        	cout << "Unexpected input please try again" << endl;
        }
        
    }while(userChoice != 0);
	return 0;
}
