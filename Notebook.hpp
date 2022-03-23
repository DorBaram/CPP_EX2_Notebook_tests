/**
 * Notebook Exercise
 * 
 * Author: Dor Baram
 * Since : 2022-03
 */

#include "Direction.hpp"
#include <iostream>
#include <string>
using namespace std;

namespace ariel{
    
    const int COLMAX = 100;

    class Notebook
    {
        public:
        Notebook();
        void write(int page,int row, int col, Direction dire, string const &str);
        string read( int page,  int row,  int col, Direction dire, int amount);
        void erase( int page,  int row,  int col, Direction dire, int amount);
        void show( int page);
        
    };
}