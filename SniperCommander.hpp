#pragma once

#include "Soldier.hpp"
namespace WarGame{
    class SniperCommander : public Soldier{
    public:
        SniperCommander(int p):Soldier(120,p,100,120){}
        
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
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[0].size();j++){
                    if(board[i][j]!=nullptr && board[i][j]->player==board[source.first][source.second]->player) {
                        if(board[i][j]->max_hp==100 && board[i][j]->dmg==50)
                            board[i][j]->fire({i,j},board);
                    }
                }
            }
        }            
    };
}
