#pragma  once

#include "Soldier.hpp"
namespace WarGame{
    class Sniper : public Soldier{
    public:
        Sniper(int p) : Soldier(100,p,50,100){}

        void fire(std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board) override{
            std::pair<int,int> target = this->highest_hp(source,board);
            if(target.first==-1)
                if(target.second==-1)
                    return;

            board[target.first][target.second]->hp-=board[source.first][source.second]->dmg;
            if(board[target.first][target.second]->hp<1){
                delete(board[target.first][target.second]);
                board[target.first][target.second]=nullptr;
            }

        }        

    };
}
