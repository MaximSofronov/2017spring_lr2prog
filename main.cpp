#include "Queen.h"

int main()
{
    a=false;
    null_board();
    try_to_set_queen(0);
    std::cout << "На доске " << SIZE << " на " << SIZE << std::endl;
    std::cout << "Минимальное количество ферзей, бьющих всю доску, но не бьющих друг друга = " << m << std::endl;
    std::cout << "Примеры расстановки:" << std::endl;
    a=true;
    null_board();
    try_to_set_queen(0);
    return 0;
}