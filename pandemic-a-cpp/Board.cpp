#include "Board.hpp"

using namespace std;

namespace pandemic
{
    struct town TOWN;

    int Board::operator[](City i) const
    {
        return 0;
    }

    int &Board::operator[](City i)
    {
        return board[i]=1;
    }
    ostream &operator<<(ostream &os, const Board &board)
    {
        return os;
    }
    bool Board::is_clean()
    {
        return true;
    }
    void Board::remove_cures()
    {
        cout<<"remove_cures"<<endl;
    }
    void Board::remove_stations()
    {
        cout<<"remove_stations"<<endl;
    }
}
