#include <vector>
#include <cmath>
#pragma once

namespace WarGame{
    class Soldier {
        public:
        int player;
        int hp;
        int dmg;
        int max_hp;
        
        virtual ~Soldier() {}

        Soldier(int hp, int p,int dmg,int max_hp): hp(hp), player(p) , dmg(dmg) , max_hp(max_hp) {}

        virtual void fire(std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board)=0;
        std::pair<int,int> closest_target(std::pair<int,int> source,const std::vector<std::vector<Soldier*>>& board){
            std::pair<int,int> target = {-1,-1};
            double distance;
            int p;
            double min=1234;
            if(board[source.first][source.second]->player == 1) 
                p=2;
            else
                p=1;

            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[i].size();j++){
                    if(board[i][j]!=nullptr && board[i][j]->player==p){
                        // distance=sqrt(a^2+b^2)
                        distance=sqrt(pow(source.first-i,2)+pow(source.second-j,2)); 
                        if(distance<min) {
                            min=distance;
                            target = {i,j};
                        }
                    }
                }
        
            } 
            return target;       
        }

        std::pair<int,int> highest_hp(std::pair<int,int> source,const std::vector<std::vector<Soldier*>>& board){
            std::pair<int,int> target = {-1,-1};
            double hp;
            double max=0;
            int p;
            if(board[source.first][source.second]->player == 1) 
                p=2;
            else
                p=1;
            
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[i].size();j++){
                    if(board[i][j]!=nullptr && board[i][j]->player==p){
                        hp=board[i][j]->hp;
                        if(hp>max) {
                            max=hp;
                            target = {i,j};
                        }
                    }
                }
        
            } 
            return target;  
            
        }        
    };
}
