/* 
 * Author: Savvas Theofilou
 */

#ifndef STATE_H
#define STATE_H

#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <set>
#include <vector>

#define Width  3
#define Height  3

#include <iostream>
using namespace std;

class State{

    public:
        State();
        State(int[Width][Height]);
        int getValue(int,int);
        void setValue(int,int,int);
        State operator= (State);
        bool operator== (const State&) const;
        friend bool operator< (const State& a,const State& o);
        string toString() const;
        string getPath();
        int getBlankX();
        int getBlankY();
        bool moveUp(State&);
        bool moveDown(State&);
        bool moveRight(State&);
        bool moveLeft(State&);
        vector <State> expand();
    private:
        int tiles2D[Width][Height];
        vector <string> path;
};

#endif // STATE_H


