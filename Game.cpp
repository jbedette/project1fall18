#include "head.h"
//init
Game::Game(){
    cerr << "\nConstructing\n";
};
Game::~Game(){
    cerr << "\nDestroying\n";
    destroyN(head);
};



//wrappers
int Game::addGame(){return addGame(head);}
int Game::addAvatar(){return 0;}
int Game::addStat(){return 0;}
bool Game::displayAll(){return displayAll(head);}
int Game::findGame(char test[]){
    return findGame(head,test,1);
}

int Game::editRemove(int opt, int edOrDel, char term[], char term2[], char term3[]){
    switch(opt){
        case 1:{switch(edOrDel){
                   case 1:{};
                   case 2:{removeN(head,term);}
               }}
        case 2:{switch(edOrDel){
                   case 1:{};
                   case 2:{removeA(head,term,term2);}
               }}
        case 3:{switch(edOrDel){
                   case 1:{};
                   case 2:{};
               }}
    }

    return 0;
}

int Game::removeN(node * & head, char term[]){
    int flag = 0;
    node * current = head;
    node * prev = current;
        if(!head) return flag;
        while(current->next && strcmp(current->name,term)){
            prev = current;
            current = current->next;
        }
        if(!strcmp(current->name,term)){
            destroyA(current->avHead);
            delete current->name;
            if(current->next){
                prev->next = current->next;
                current = NULL;
            }else prev->next = NULL;
            ++flag;
        }
    return flag;
}
int Game::removeA(node * & head, char term[], char term2[]){
    int flag = 0;
    node * currentNode = head;
    while(currentNode->next){
        if(!strcmp(currentNode->name,term)){
            avatar * currentAv = currentNode->avHead;
            avatar * prevAv = currentNode->avHead;
            while(currentAv->next && flag==0){
                if(!strcmp(currentAv->name,term2)){
                    delete currentAv->name;
                    if(currentAv->next){
                        prevAv->next = currentAv->next;
                    }else prevAv->next;
                    currentAv = NULL;
                    ++flag;
                }
                prevAv = currentAv;
                currentAv = currentAv->next;
            }
            currentNode = currentNode->next;
        }
    }
    return flag;
}
int Game::removeS(node * & head, char term[], char term2[],char term3[]){
    int flag = 0;
    node * current = head;
    while(current->next){
        
    }
    return flag;
}

//destroy
int Game::destroyN(node * & head){
    if (!head) return 0;
    else{
        destroyN(head->next);
        destroyA(head->avHead);
    }
    delete head->name;
    head->next = NULL;
    return 0;
} 
int Game::destroyA(avatar * & head){
    if (!head) return 0;
    else {
        destroyA(head->next);
        destroyS(head->statHead);
    }
    delete head->name; 
    head->next = NULL;
    return 0;
} 
int Game::destroyS(stat * & head){
    if (!head) return 0;
    else destroyS(head->next);
    delete head->statName;
    delete head->charStat;
    head->next = NULL;
    return 0;
}

int Game::addGame(node * & head){
    int flag = 0;
    char temp[500];
    char * output;
    cout << ">>Please enter a new game name\n\n"; 
    cin.get(temp, 499, '\n');
    cin.clear();
    cin.ignore(500,'\n');
    output = new char[strlen(temp)+1];
    strcpy(output,temp);
    if(!head){
        head = new node;
        head->name = output;
        head->next = NULL;
        head->avHead = NULL;
        tail = head;
        ++flag;
    }else{
        node * tempNode = new node;
        tempNode->name = output;
        tempNode->next = head;
        head = tempNode;
        ++flag;
    }
    cout << "\nWould you like to add an Avatar?\n"; 
    if(option()) addAvatar(head->avHead);
    while(again(1))addAvatar(head->avHead);
    return flag;
}

int Game::addAvatar(avatar * & head){
    int flag = 0;

    char temp[500];
    char * output;
    cout << ">>Please enter a new avatar name\n\n"; 
    cin.get(temp, 499, '\n');
    cin.clear();
    cin.ignore(500,'\n');
    output = new char[strlen(temp)+1];
    strcpy(output,temp);

    if(!head){
        head = new avatar;
        head->name = output;
        head->next = NULL;
        
        //avTail = head;
        ++flag;
    }else{
        avatar * tempAv = new avatar;
        tempAv->name = output;
        tempAv->next = head;
        head = tempAv;
        ++flag;
    }
    cout << "\nWould you like to add a Stat?\n";
    if(option())addStat(head->statHead);
    while(again(2)){
        addStat(head->statHead);
    }
    return flag;
}
int Game::addStat(stat * & head){
    int flag = 0; 
    char temp[500];
    char selection = ' ';
    char * output;
    cout<< "\nWhat is this stat called?\n";
    cin.get(temp, 499, '\n');
    cin.clear();
    cin.ignore(500,'\n');
    output = new char[strlen(temp)+1];
    strcpy(output,temp);
    if(!head){
        head = new stat;
        head->statName = output;
        head->next = NULL;
        ++flag;
    }else{
        stat * tempStat = new stat;
        tempStat->statName = output;
        tempStat->next = head;
        head = tempStat;
        ++flag;
    }
    cout << "\nNow what kind of value is this?\n";
    cout << "[I]nteger\n[T]ext\n\n";
    cin >> selection;
    cin.clear();
    cin.ignore(10,'\n');
    if(toupper(selection) == 'I'){
        cout << "Please enter an Integer: ";
        cin >> head->intStat;
        head->charStat = NULL;
    }else if (toupper(selection) == 'T'){
        char wTemp[500];
        cout << "Please enter your Text: ";
        cin.get(wTemp,499,'\n');
        cin.clear();
        cin.ignore(500,'\n');
        head->charStat = new char[strlen(wTemp)+1];
        strcpy(head->charStat,wTemp);
        head->intStat = 0;
    }
    return flag;
}

int Game::findGame(node * head, char term[], int opt){
    int flag = 0;
    if(!head) {return flag;}
    else if(strcmp(head->name,term)){
        ++flag;
        if(opt == 1){
            cout << "\nGame Name: " << head->name<<'\n'; 
            displayAvatar(head->avHead);
        }
        else if(opt == 2){
            /*
               char temp[100];
               cout << "\nWhat would you like to rename the Game?\n";
               cin.get(temp, 99, '\n');
               cin.clear();
               cin.ignore(100, '\n');
               delete head->name;
               head->name = new char[strlen(temp)+1];
               strcpy(name,temp);
               cout << "\nYou have renamed the game to: " >> head->name; 
               cout << '\n';
               */
        }
        else if(opt == 3){
            cout << "Are you sure you want to delete your game and all";
            cout << " associated data?\n";
            if(option()){
            }
        }
    }else if(head->next)findGame(head->next, term, opt);
    return flag;
}

int Game::findAvatar(avatar * head, char term[], int opt){
    int flag = 0;
    if(!head) return flag;
    return flag;
}
int Game::findStat(stat * head, char term[], int opt){
    int flag = 0;
    if(!head) return flag;
    return flag;
}

bool Game::displayAll(node * head){
    if(head && head->name){
        cout << "\nGame name: " << head->name;
        if(head->avHead){
            //cout << "\nAvatar: "<< head->avHead->name;
            displayAvatar(head->avHead);
        }else cerr << "\nno avHead"<< head->avHead<<'\n';
    }else cerr << "\n\n no node head name\n";
    if(head->next) displayAll(head->next);
    return false;
}

bool Game::displayAvatar(avatar * head){
    bool flag = false;
    if(head && head->name){
        cout << "\nAvatar name: " << head->name<< '\n';
        flag = true;
    }
    cout<< "Stats:\n";
    if(head->statHead) displayStat(head->statHead);
    if(head->next) displayAvatar(head->next);
    return flag;
}

bool Game::displayStat(stat * head){
    bool flag = false;
    if(head && head->statName){
        cout << head->statName << ": ";
        if(head->intStat) cout << head->intStat;
        else if(head->charStat) cout << head->charStat;
        else cerr << "ERROR: NO STAT VALUE";
    }else cerr << "ERROR: NO STAT NAME";
    cout <<'\n';
    if(head->next)displayStat(head->next);
    return flag;
}






