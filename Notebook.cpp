/**
 * Notebook Exercise
 * 
 * Author: Dor Baram
 * Since : 2022-03
 */
#include <iostream>
#include <string>
using namespace std;

#include "Notebook.hpp"
using namespace ariel;



ariel::Notebook::Notebook()
{
    
}

void ariel::Notebook::write( int page,  int row,  int col, Direction dire, string const &str)
{
        /*
        int strl = str.length();
        if(col>COLMAX || strl >COLMAX || col + strl > COLMAX)
            __throw_invalid_argument("invalid string or coloum");
        
        if(strl == 0)
        */
        //return;

        //no implementation yet
}

string ariel::Notebook::read( int page,  int row,  int col, Direction dire, int amount)
{
    return "";  //no implementation yet
}

void ariel::Notebook::erase( int page,  int row,  int col, Direction dire, int amount)
{
    //no implementation yet
}

void ariel::Notebook::show( int page)
{
    //no implementation yet
}

