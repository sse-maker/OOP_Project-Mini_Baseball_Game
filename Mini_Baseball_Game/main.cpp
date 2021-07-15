//
//  main.cpp
//  Mini_Baseball_Game
//
//  Created by 세광 on 2021/06/28.
//

#include <iostream>
#include <random>

using namespace std;

class Menu {
public:
    int Print_Menu();
    void Select_Menu();
    void Print_Info();
    void Draw_Line();
    
protected:
    int num;
};

class Game : public Menu {
public:
    void Start_Game();
    void Start_Inning();
    void Print_Score();
    void Print_Count();
    void Print_Base();
    void Get_Swing_Result();
    void Get_Pass_Result();
    void Increasing_Score();
    void Game_Result();
    
private:
    unsigned int nowinning = 1;
    unsigned int firstscore = 0, secondscore = 0, thirdscore = 0;
    unsigned int ballcount = 0, strikecount = 0, outcount = 0;
    unsigned int swing;
    bool firstbase = false, secondbase = false, thirdbase = false;
};

int main() {
    Game menu;
    menu.Print_Menu();
    menu.Select_Menu();
}

void Menu::Draw_Line() {
    for(int i = 0; i < 80; i++) { cout << "="; }
    cout << endl;
}

int Menu::Print_Menu() {
    Draw_Line();
    cout << '\n' << '\t' << '\t' << '\t' << '\t' << "1. Game Start" << '\n' << endl;
    cout << '\t' << '\t' << '\t' << '\t' << "2. Game Explanation" << '\n' << endl;
    cout << '\t' << '\t' << '\t' << '\t' << "3. Game Exit" << '\n' << endl;
    Draw_Line();
    cout << "Select the menu: "; cin >> num;
    return num;
}

void Menu::Select_Menu() {
    switch(num) {
        case 1: {
            Game game;
            game.Start_Game();
            break;
        }
        case 2: {
            Print_Info();
            Print_Menu();
            Select_Menu();
            break;
        }
        case 3: {
            cout << "Exit the program..." << '\n' << endl;
            exit(0);
            break;
        }
        default: {
            system("clear");
            cout << "Select the menu again. " << endl;
            Print_Menu();
            Select_Menu();
            break;
        }
    }
}

void Menu::Print_Info() {
    while(1) {
        system("clear");
        for(int i = 0; i < 25; i++) { cout << "-"; }
        cout << "Mini Baseball Game Explanation";
        for(int i = 0; i < 25; i++) { cout << "-"; }
            
        cout << '\n' << '\n' << "This game is 'Mini Baseball Game' with some baseball rules applied." << '\n' << endl;
        cout << "1. The game consists of 3 innings in total." << '\n' << endl;
        cout << "2. The player can swing or skip the ball." << '\n' << endl;
        cout << "3. If you 'Hit' or 'Base on Balls', you can get on the base." << '\n' << endl;
        cout << "4. There are no outs by runners, only flyouts and strikeouts." << '\n' << endl;
        cout << "5. If you score more than 5 points in the third inning, you will win the game." << '\n' << endl;
            
        for(int i = 0; i < 80; i++) { cout << "-"; }
        cout << '\n' << "Back to main menu(-1): "; cin >> num;
        if(num == -1) {
            system("clear");
            Print_Menu();
            Select_Menu();
            break;
        }
    }
}

void Game::Start_Game() {
    for(int i = 0; i < 3; i++) {
        Start_Inning();
        if(firstscore + secondscore + thirdscore >= 10) { break; }
    }
    Game_Result();
}

void Game::Start_Inning() {
    if(nowinning == 1) {
        system("clear");
        Draw_Line();
        cout << "Start the game." << endl;
        Draw_Line();
        cout << endl;
        Draw_Line();
    }
    swing = 0;
    while(1) {
        if(swing == 1) {
            Draw_Line();
            Get_Swing_Result();
            Draw_Line();
        }
        else if(swing == 2) {
            Draw_Line();
            Get_Pass_Result();
            Draw_Line();
        }
        
        if(outcount != 3) {
            Print_Score();
            Print_Count();
            Print_Base();
            cout << "1. Swing,  2. Skip" << endl;
            cout << "Enter: ";
        }
        else if(outcount == 3) { break; }
        cin >> swing;
        if(swing != 1 && swing != 2) { system("clear"); }
    }
    nowinning++;
    outcount = 0; strikecount = 0; ballcount = 0;
    firstbase = false; secondbase = false; thirdbase = false;
}

void Game::Print_Score() {
    if(nowinning <= 3 && firstscore + secondscore + thirdscore < 10) { cout << nowinning << "회" << endl; }
    cout << "┌──────────────────────────────────────────────────────────────────┐" << endl;
    cout << "│           1st Inning   2nd Inning   3rd Inning   Total Score     │" << endl;
    if(firstscore + secondscore + thirdscore < 10) {
        if(nowinning == 1) {
            cout << "     Score       " << firstscore << endl;
        }
        else if(nowinning == 2) {
            cout << "    Score       " << firstscore << "            " << secondscore << endl;
        }
        else if(nowinning == 3) {
            cout << "    Score       " << firstscore << "            " << secondscore << "            " << thirdscore << endl;
        }
    }
    if(nowinning == 4 || firstscore + secondscore + thirdscore >= 10) {
        cout << "    Score       " << firstscore << "            " << secondscore << "            " << thirdscore << "           " << firstscore + secondscore + thirdscore << endl;
    }
    cout << "│                                                                  │" << endl;
    cout << "└──────────────────────────────────────────────────────────────────┘" << endl;
}

void Game::Print_Count() {
    if(ballcount == 0) { cout << "B " << "○○○" << endl; }
    else if(ballcount == 1) { cout << "B " << "●○○" << endl; }
    else if(ballcount == 2) { cout << "B " << "●●○" << endl; }
    else if(ballcount == 3) { cout << "B " << "●●●" << endl; }
    if(strikecount == 0) { cout << "S " << "○○" << endl; }
    else if(strikecount == 1) { cout << "S " << "●○" << endl; }
    else if(strikecount == 2) { cout << "S " << "●●" << endl; }
    if(outcount == 0) { cout << "O " << "○○" << endl; }
    else if(outcount == 1) { cout << "O " << "●○" << endl; }
    else if(outcount == 2) { cout << "O " << "●●" << endl; }
}

void Game::Print_Base() {
    if(secondbase == false) { cout << '\t' << "        " << "◇" << "       " << endl; }
    else if(secondbase == true) { cout << '\t' << "        " << "◆" << "       " << endl; }
    cout << '\t' << "      ↙   ↖      " << endl;
    cout << '\t' << "    ↙       ↖    " << endl;
    cout << '\t' << "  ↙           ↖  " << endl;
    if(thirdbase == false && firstbase == false) { cout << '\t' << "◇" << "               " << "◇" << endl; }
    else if(thirdbase == false && firstbase == true) { cout << '\t' << "◇" << "               " << "◆" << endl; }
    else if(thirdbase == true && firstbase == false) { cout << '\t' << "◆" << "               " << "◇" << endl; }
    else if(thirdbase == true && firstbase == true) { cout << '\t' << "◆" << "               " << "◆" << endl; }
    cout << '\t' << "  ↘           ↗  " << endl;
    cout << '\t' << "    ↘       ↗    " << endl;
    cout << '\t' << "      ↘   ↗      " << endl;
    cout << '\t' << "        " << "◇" << "       " << endl;
}

void Game::Get_Swing_Result() {
    system("clear");
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 100);
    int swing_random = dis(gen);
    
    if(0 <= swing_random && swing_random < 14) {
        cout << "Single!" << endl;
        if(firstbase == false) {
            if(secondbase == false && thirdbase == false) {
                firstbase = true;
            }
            else if(secondbase == true && thirdbase == false) {
                firstbase = true; secondbase = false; thirdbase = true;
            }
            else if(secondbase == false && thirdbase == true) {
                firstbase = true; thirdbase = false;
                cout << '\n' << "Third base runner home in! Increase the score one point." << endl;
                Increasing_Score();
            }
            else if(secondbase == true && thirdbase == true) {
                firstbase = true; secondbase = false;
                cout << '\n' << "Third base runner home in! Increase the score one point." << endl;
                Increasing_Score();
            }
        }
        else if(firstbase == true) {
            if(secondbase == false && thirdbase == false) {
                secondbase = true;
            }
            else if(secondbase == true && thirdbase == false) {
                thirdbase = true;
            }
            else if(secondbase == false && thirdbase == true) {
                secondbase = true; thirdbase = false;
                cout << '\n' << "Third base runner home in! Increase the score one point." << endl;
                Increasing_Score();
            }
            else if(secondbase == true && thirdbase == true) {
                cout << '\n' << "Third base runner home in! Increase the score one point." << endl;
                Increasing_Score();
            }
        }
        ballcount = 0;
        strikecount = 0;
    }
    else if(14 <= swing_random && swing_random < 21) {
        cout << "Double!" << endl;
        if(firstbase == false) {
            if(secondbase == false && thirdbase == false) {
                secondbase = true;
            }
            else if(secondbase == true && thirdbase == false) {
                cout << '\n' << "Second base runner home in! Increase the score one point." << endl;
                Increasing_Score();
            }
            else if(secondbase == false && thirdbase == true) {
                secondbase = true; thirdbase = false;
                cout << '\n' << "Third base runner home in! Increase the score one point." << endl;
                Increasing_Score();
            }
            else if(secondbase == true && thirdbase == true) {
                thirdbase = false;
                cout << '\n' << "Third base runner home in! Increase the score one point." << endl;
                Increasing_Score();
                cout << '\n' << "Second base runner home in! Increase the score one point." << endl;
                Increasing_Score();
            }
        }
        else if(firstbase == true) {
            if(secondbase == false && thirdbase == false) {
                firstbase = false; secondbase = true; thirdbase = true;
            }
            else if(secondbase == true && thirdbase == false) {
                firstbase = false; thirdbase = true;
                cout << '\n' << "Second base runner home in! Increase the score one point." << endl;
                Increasing_Score();
            }
            else if(secondbase == false && thirdbase == true) {
                firstbase = false; secondbase = true;
                cout << '\n' << "Third base runner home in! Increase the score one point." << endl;
                Increasing_Score();
            }
            else if(secondbase == true && thirdbase == true) {
                firstbase = false;
                cout << '\n' << "Third base runner home in! Increase the score one point." << endl;
                Increasing_Score();
                cout << '\n' << "Second base runner home in! Increase the score one point." << endl;
                Increasing_Score();
            }
        }
        ballcount = 0;
        strikecount = 0;
    }
    else if(21 <= swing_random && swing_random < 26) {
        cout << "Triple!" << endl;
        if(firstbase == false) {
            if(secondbase == false && thirdbase == false) { thirdbase = true; }
            else if(secondbase == true && thirdbase == false) {
                secondbase = false; thirdbase = true;
                cout << '\n' << "Second base runner home in! Increase the score one point." << endl;
                Increasing_Score();
            }
            else if(secondbase == false && thirdbase == true) {
                cout << '\n' << "Third base runner home in! Increase the score one point." << endl;
                Increasing_Score();
            }
            else if(secondbase == true && thirdbase == true) {
                secondbase = false;
                cout << '\n' << "Third base runner home in! Increase the score one point." << endl;
                Increasing_Score();
                cout << '\n' << "Second base runner home in! Increase the score one point." << endl;
                Increasing_Score();
            }
        }
        else if(firstbase == true) {
            if(secondbase == false && thirdbase == false) {
                firstbase = false; thirdbase = true;
                cout << '\n' << "First base runner home in! Increase the score one point." << endl;
                Increasing_Score();
            }
            else if(secondbase == true && thirdbase == false) {
                firstbase = false; secondbase = false; thirdbase = true;
                cout << '\n' << "Second base runner home in! Increase the score one point." << endl;
                Increasing_Score();
                cout << '\n' << "First base runner home in! Increase the score one point." << endl;
                Increasing_Score();
            }
            else if(secondbase == false && thirdbase == true) {
                firstbase = false;
                cout << '\n' << "Third base runner home in! Increase the score one point." << endl;
                Increasing_Score();
                cout << '\n' << "First base runner home in! Increase the score one point." << endl;
                Increasing_Score();
            }
            else if(secondbase == true && thirdbase == true) {
                firstbase = false; secondbase = false;
                cout << '\n' << "Third base runner home in! Increase the score one point." << endl;
                Increasing_Score();
                cout << '\n' << "Second base runner home in! Increase the score one point." << endl;
                Increasing_Score();
                cout << '\n' << "First base runner home in! Increase the score one point." << endl;
                Increasing_Score();
            }
        }
        ballcount = 0;
        strikecount = 0;
    }
    else if(26 <= swing_random && swing_random < 29) {
        cout << "Homerun!!" << endl;
        if(firstbase == false) {
            if(secondbase == false && thirdbase == false) {
                cout << '\n' << "Home in! Increase the score one point." << endl;
                Increasing_Score();
            }
            else if(secondbase == true && thirdbase == false) {
                secondbase = false;
                cout << '\n' << "Second base runner home in! Increase the score one point." << endl;
                Increasing_Score();
                cout << '\n' << "Home in! Increase the score one point." << endl;
                Increasing_Score();
                
            }
            else if(secondbase == false && thirdbase == true) {
                thirdbase = false;
                cout << '\n' << "Third base runner home in! Increase the score one point." << endl;
                Increasing_Score();
                cout << '\n' << "Home in! Increase the score one point." << endl;
                Increasing_Score();
            }
            else if(secondbase == true && thirdbase == true) {
                secondbase = false; thirdbase = false;
                cout << '\n' << "Third base runner home in! Increase the score one point." << endl;
                Increasing_Score();
                cout << '\n' << "Second base runner home in! Increase the score one point." << endl;
                Increasing_Score();
                cout << '\n' << "Home in! Increase the score one point." << endl;
                Increasing_Score();
            }
        }
        else if(firstbase == true) {
            if(secondbase == false && thirdbase == false) {
                firstbase = false;
                cout << '\n' << "First base runner home in! Increase the score one point." << endl;
                Increasing_Score();
                cout << '\n' << "Home in! Increase the score one point." << endl;
                Increasing_Score();
            }
            else if(secondbase == true && thirdbase == false) {
                firstbase = false; secondbase = false;
                cout << '\n' << "Second base runner home in! Increase the score one point." << endl;
                Increasing_Score();
                cout << '\n' << "First base runner home in! Increase the score one point." << endl;
                Increasing_Score();
                cout << '\n' << "Home in! Increase the score one point." << endl;
                Increasing_Score();
            }
            else if(secondbase == false && thirdbase == true) {
                firstbase = false; thirdbase = false;
                cout << '\n' << "Third base runner home in! Increase the score one point." << endl;
                Increasing_Score();
                cout << '\n' << "First base runner home in! Increase the score one point." << endl;
                Increasing_Score();
                cout << '\n' << "Home in! Increase the score one point." << endl;
                Increasing_Score();
            }
            else if(secondbase == true && thirdbase == true) {
                firstbase = false; secondbase = false; thirdbase = false;
                cout << '\n' << "Third base runner home in! Increase the score one point." << endl;
                Increasing_Score();
                cout << '\n' << "Second base runner home in! Increase the score one point." << endl;
                Increasing_Score();
                cout << '\n' << "First base runner home in! Increase the score one point." << endl;
                Increasing_Score();
                cout << '\n' << "Home in! Increase the score one point." << endl;
                Increasing_Score();
            }
        }
        ballcount = 0;
        strikecount = 0;
    }
    else if(29 <= swing_random && swing_random < 62) {
        cout << "Pop up" << endl;
        outcount++;
        ballcount = 0;
        strikecount = 0;
        if(outcount == 3) { cout << "End inning" << endl; }
    }
    else {
        cout << "Strike" << endl;
        strikecount++;
        if(strikecount == 3) {
            cout << "Strikeout" << endl;
            outcount++;
            ballcount = 0;
            strikecount = 0;
            if(outcount == 3) { cout << "End inning" << endl; }
        }
    }
}

void Game::Get_Pass_Result() {
    system("clear");
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 100);
    int pass_random = dis(gen);
    
    if(0 <= pass_random && pass_random < 65) {
        cout << "Ball" << endl;
        ballcount++;
        if(ballcount == 4) {
            cout << "Base on balls!" << endl;
            if(firstbase == false) { firstbase = true; }
            else if(firstbase == true && secondbase == false) { secondbase = true; }
            else if(firstbase == true && secondbase == true) {
                if(thirdbase == false) { thirdbase = true; }
                else if(thirdbase == true) {
                    cout << '\n' << "Third base runner home in! Increase the score one point." << endl;
                    Increasing_Score();
                }
            }
            ballcount = 0;
            strikecount = 0;
        }
    }
    else {
        cout << "Strike" << endl;
        strikecount++;
        if(strikecount == 3) {
            cout << "Strikeout" << endl;
            ++outcount;
            ballcount = 0;
            strikecount = 0;
            if(outcount == 3) { cout << "End inning" << endl; }
        }
    }
}

void Game::Increasing_Score() {
    if(nowinning == 1) { firstscore++; }
    else if(nowinning == 2) { secondscore++; }
    else if(nowinning == 3) { thirdscore++; }
}

void Game::Game_Result() {
    cout << "Game ended." << endl;
    Draw_Line();
    cout << endl;
    Print_Score();
    if(firstscore + secondscore + thirdscore < 5) { cout << "Result: Player lose" << endl; }
    else { cout << "Result: Player win!" << endl; }
    cout << "Go to main menu(-1): "; cin >> num;
    if(num == -1) {
        system("clear");
        Print_Menu();
        Select_Menu();
    }
}
