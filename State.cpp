/* 
 * Author: Savvas Theofilou
 */

#include "State.h"

State::State(){

}

State::State(int tiles2D[Width][Height]){
    for (int i = 0; i < Width; i++){
        for (int j = 0; j < Height; j++){
            setValue(i, j, tiles2D[i][j]);
        }
    }
}

int State::getValue(int x, int y){
    return tiles2D[x][y];
}

void State::setValue(int x, int y, int value){
    tiles2D[x][y] = value;
}

State State::operator=(State myState){
    for (int i = 0; i < Width; i++){
        for (int j = 0; j < Height; j++){
            setValue(i, j, myState.getValue(i, j));
        }
    }
    path = myState.path;
    return *this;
}

bool State::operator==(const State& myState) const {
    bool result = true;
    for (int i = 0; i < Width; i++){
        for (int j = 0; j < Height; j++){
            if (tiles2D[i][j]!= myState.tiles2D[i][j]){
                result = false;
            }
        }
    }
    return result;
}

bool operator< (const State& a,const State& o){
    return (a.toString() < o.toString());
}

string State::toString() const {
    stringstream stringToReturn;
    for (int i = 0; i < Width; i++){
        for (int j = 0; j < Height; j++){
            if (tiles2D[i][j] != 0){
                stringToReturn<<tiles2D[i][j]<<" ";
            }
            else{
                stringToReturn<<"  ";
            }
        }
        stringToReturn<<endl;
    }
    return stringToReturn.str();
}

string State::getPath(){
    unsigned i;
    string s;
    if (path.size() > 0)
    {
        for (i=0; i<path.size()-1; i++)
            s += path.at(i)+", ";
        s += path.at(i)+ "\n";
    }
    return s;
}

int State::getBlankX(){
    for (int i=0;i<Width;i++){
        for (int j=0;j<Height;j++){
            if (tiles2D[i][j]==0){
                return j;
            }
        }
    }
}

int State::getBlankY(){
    for (int i=0;i<Width;i++){
        for (int j=0;j<Height;j++){
            if (tiles2D[i][j]==0){
                return i;
            }
        }
    }
}

bool State::moveUp(State& myState){

    if (getBlankY()==1 || getBlankY()==2){
        myState=*this;
        int temp=tiles2D[getBlankY()-1][getBlankX()];
        int tempX,tempY;
        tempX=getBlankX();
        tempY=getBlankY();
        myState.tiles2D[getBlankY()-1][getBlankX()]=0;
        myState.tiles2D[tempY][tempX]=temp;
        myState.path.push_back("moveUp");
        return true;
    }
    return false;
}

bool State::moveDown(State& myState){

    if (getBlankY()==1 || getBlankY()==0){
        myState=*this;
        int temp=tiles2D[getBlankY()+1][getBlankX()];
        int tempX,tempY;
        tempX=getBlankX();
        tempY=getBlankY();
        myState.tiles2D[getBlankY()+1][getBlankX()]=0;
        myState.tiles2D[tempY][tempX]=temp;
        myState.path.push_back("moveDown");
        return true;
    }
    return false;
}

bool State::moveRight(State& myState){
    if (getBlankX()==1 || getBlankX()==0){
        myState=*this;
        int temp=tiles2D[getBlankY()][getBlankX()+1];
        int tempX,tempY;
        tempX=getBlankX();
        tempY=getBlankY();
        myState.tiles2D[getBlankY()][getBlankX()+1]=0;
        myState.tiles2D[tempY][tempX]=temp;
        myState.path.push_back("moveRight");
        return true;
    }
    return false;
}

bool State::moveLeft(State& myState){
    if (getBlankX() == 1 || getBlankX() == 2){
        myState = *this;
        int temp = tiles2D[getBlankY()][getBlankX()-1];
        int tempX, tempY;
        tempX = getBlankX();
        tempY = getBlankY();
        myState.tiles2D[getBlankY()][getBlankX()-1] = 0;
        myState.tiles2D[tempY][tempX] = temp;
        myState.path.push_back("moveLeft");
        return true;
    }
    return false;
}

vector <State> State::expand(){
    vector <State> children;
    State child;

    if (moveUp(child)){
        children.push_back(child);
    }
    if (moveDown(child)){
        children.push_back(child);
    }
    if (moveLeft(child)){
        children.push_back(child);
    }
    if (moveRight(child)){
        children.push_back(child);
    }
    return children;
}


