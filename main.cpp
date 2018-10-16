#include "head.h"

int main(){
    char term[50];
    char term2[50];
    char term3[50];
    int opt = 0;
    int opt2 = 0;
    Game my_games;
    my_games.addGame();
    while(again(0)) my_games.addGame();
    if(edMenu(opt,opt2,term,term2,term3)) my_games.editRemove(opt,opt2,term,term2,term3);
    my_games.displayAll();
    return 0;
}
bool edMenu(int & opt, int & opt2, char term[],char term2[], char term3[]){
    bool flag = false;
    char select =' '; 
    cout << "\n\n\nWould you like to [E]dit/[D]elete some things?\n";
    if(option()){
        flag = true;
        cout << "\nWould you like to modify:\n";
        cout << "[G]ames\n[A]vatars\n[S]tats\n";
        cin >> select;
        cin.clear();
        select = toupper(select);
        if (select == 'G')++opt;
        else if (select == 'A')opt = 2;
        else if (select == 'S')opt = 3;
        select = ' ';
        cout << "\n[E]dit or [D]elete?\n";
        cin >> select;
        cin.clear();
        select = toupper(select);
        if(select == 'E') ++opt2; 
        if(select == 'D') opt2 = 2;
        switch(opt){
            case 1:{
                       searchTerm(term,1); 
                   }
            case 2:{
                       searchTerm(term,1);
                       searchTerm(term2,2);
                   }
            case 3:{
                       searchTerm(term,1);
                       searchTerm(term2,2);
                       searchTerm(term3,3);
                   }
        }
    }
    return flag;
}

bool again(int opt){
    cout << "\nWould you like to add another ";
    switch(opt){
    case 1: cout << "game?\n";
    case 2: cout << "avatar?\n";
    case 3: cout << "stat?\n";
    }
    return option();
}
bool option(){
    char option = ' ';
    bool flag = false;
    cout << "Enter [Y] if you would: ";
    cin >> option;
    cin.clear();
    cin.ignore(500,'\n');
    option = toupper(option);
    if (option == 'Y') flag = true;
    return flag;
}
int searchTerm(char term[],int opt){
    cout << "\nPlease enter the name of the ";
    switch(opt){
        case 1: cout << "game";
        case 2: cout << "avatar";
        case 3: cout << "stat";
    }
    cout <<  "  you want to edit/delete.\n";
    int flag = 0;
    if(cin.get(term,49,'\n'))++flag;
    cin.clear();
    cin.ignore(50,'\n');
    return flag;
}
