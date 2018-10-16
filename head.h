#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
//John Bedette, cs163
//
//basic rundown
//a set of three linear linked lists managed by a larger game class
//add a game
//add an avatar to the game
//add a stat to the avatar
//
//
//
//
//things got a little... messy at the end
//

//structs
struct stat{
    //stats need to hold any kind of data
    stat * next;
    char * statName;
    char * charStat;
    int intStat;
    bool boolStat;
};
struct avatar{
    //avatars need to hold any amount of stats
    avatar * next;
    stat * statHead;
    stat * statTail;
    char * name;
};
struct node{
    //node is a stand in for a single game
    //it needs to hold any amount of avatars
    node * next;
    char * name;
    avatar * avHead;
    avatar * avTail;
};
//classes
class Game{
    public:

        Game();
        ~Game();
        //wrappers
        int addGame();
        int addAvatar();
        int addStat();
        bool displayAll();
        bool displayAvatar();
        int findGame(char[]);
        int editRemove(int opt, int edOrDel, char term[], char term2[], char term3[]);
 
    private:
        //utility
        int copyN(node * & head); 
        int copyA(avatar * & head); 
        int copyS(stat * & head); 
        //destroy
        int destroyN(node * & head); 
        int destroyA(avatar * & head); 
        int destroyS(stat * & head); 
        int removeN(node * & head, char term[]); 
        int removeA(node * & head, char term[], char term2[]);
        int removeS(node * & head, char term[], char term2[], char term3[]);
        //Adding values
        int addGame(node * & head);
        int addAvatar(avatar * & head);
        int addStat(stat * & head);
        //display
        bool displayAll(node * head);
        bool displayAvatar(avatar * head);
        bool displayStat(stat * head);
        //finding values
        int findGame(node * head, char term[], int opt);
        int findAvatar(avatar * head, char term[], int opt);
        int findStat(stat * head, char term[], int opt);
        node * head;
        node * tail;
};
//utility
bool again(int);
bool option();
int searchTerm(char term[], int);
bool edMenu(int & opt, int & opt2, char term[],char term2[], char term3[]);
