#include "Board.hpp"

namespace WarGame{
    //scanning the for troops of specific player.
    bool Board::has_soldiers(uint pn) const {
        for(int i = 0; i < board.size() ; i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j]!=nullptr && board[i][j]->player==pn)
                    return true;
            }
        }
        return false;


    }
    Soldier*& Board::operator[](std::pair<int,int> location){
        return this->board[location.first][location.second];
        
    }
    Soldier* Board::operator[](std::pair<int,int> location) const{
        if(location.first<0)
            throw std::invalid_argument("ERROR");
        if(location.first>=board.size())
            throw std::invalid_argument("ERROR");
        if(location.second<0)
            throw std::invalid_argument("ERROR");
        if(location.second>=board[0].size())
            throw std::invalid_argument("ERROR"); 
        return this->board[location.first][location.second];
        
    }

    void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction){
        if(source.first<0)
            throw std::invalid_argument("ERROR");
        if(source.second<0)
            throw std::invalid_argument("ERROR");
        if(source.first>=this->board.size())
            throw std::invalid_argument("ERROR");
        if(source.second>=this->board[0].size())
            throw std::invalid_argument("ERROR");
        if(this->board[source.first][source.second]==nullptr)
            throw std::invalid_argument("ERROR");
        
        Soldier* temp = this->board[source.first][source.second];
        if(temp==nullptr)
            throw std::invalid_argument("ERROR");
        if(temp->player!=player_number)
            throw std::invalid_argument("ERROR");
    
        std::pair<int,int> dest;
        dest.first=source.first;
        dest.second=source.second;
        
        switch(direction){
             case Left:
                --dest.second;
                break;

            case Right:
                ++dest.second;
                break;
                
            case Up:
                ++dest.first;
                break;

            case Down:    
                --dest.first;
                break;                    


            default: break;                
        }
        if(dest.first<0)
            throw std::invalid_argument("ERROR");
        if(dest.second<0)
             throw std::invalid_argument("ERROR");
        if(dest.first>=this->board.size())
            throw std::invalid_argument("ERROR");
        if(dest.second>=this->board[0].size())
            throw std::invalid_argument("ERROR");
        
        if(board[dest.first][dest.second]!=nullptr)
            throw std::invalid_argument("ERROR");
        board[dest.first][dest.second]=temp;
        board[source.first][source.second]=nullptr;

        temp->fire(dest,board);
        
    }

}
