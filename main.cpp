/* 
 * Author: Savvas Theofilou
 */

#include <iostream>
#include "State.h"

using namespace std;

template <typename myState>
bool DFS(const myState &goal, stack<myState> &agenda, set<myState> &closed, myState &solution)
{
    myState s;
    if (agenda.empty())
        return false;
    s = agenda.top();
    agenda.pop();

    if (s == goal){
        solution=s;
        return true;
    }
    if (closed.size() == 0 || (closed.find(s) == closed.end())){
        vector<myState> children;
        children = s.expand();
        closed.insert(s);
        for (int i = children.size()-1; i >=0; i--)
            agenda.push(children.at(i));
    }
    return DFS(goal, agenda, closed, solution);
}

template <typename myState>
bool BFS(const myState &goal, queue<myState> &agenda, set<myState> &closed, myState &solution)
{
    myState s;
    if (agenda.empty())
        return false;
    s = agenda.front();
    agenda.pop();

    if (s == goal){
        solution = s;
        return true;
    }
    if (closed.size()==0 || (closed.find(s)==closed.end())){
        vector<myState> children;
        children = s.expand();
        closed.insert(s);
        for (int i=children.size()-1;i>=0;i--)
            agenda.push(children.at(i));
    }
    return BFS(goal,agenda,closed,solution);
}

int main()
{
    cout<<"// 8 Puzzle Solver //"<<endl<<endl<<endl;

    int initialTiles2D[3][3] = {
        {1,2,3},
        {4,0,6},
        {7,5,8}
    };
    
    int goalTiles2D[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,0}
    };


    State initial(initialTiles2D);
    State goal(goalTiles2D);

    cout<<"Initial puzzle:"<<endl;
    cout<<initial.toString();
    cout<<endl;

    cout<<"Goal puzzle:"<<endl;
    cout<<goal.toString();;
    cout<<endl;

    stack <State> agendaDFS;
    set <State> closedDFS;
    agendaDFS.push(initial);
    State solutionDFS;
    DFS(goal,agendaDFS,closedDFS,solutionDFS);
    cout<<"Solution steps(DFS): "<<endl;
    cout<<solutionDFS.getPath();
    cout<<endl<<endl;


    queue <State> agendaBFS;
    set <State> closedBFS;
    agendaBFS.push(initial);
    State solutionBFS;
    BFS(goal,agendaBFS,closedBFS,solutionBFS);
    cout<<"Solution steps(BFS): "<<endl;
    cout<<solutionBFS.getPath();
    return 0;
}


