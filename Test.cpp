/**
 * Notebook Exercise
 * 
 * Author: Dor Baram
 * Since : 2022-03
 */

#include "doctest.h"
using namespace doctest;
#include <iostream>
#include <stdexcept>
using namespace std;
#include "Direction.hpp"
#include "Notebook.hpp"
using namespace ariel;

TEST_CASE("Loop")
{
    Notebook n;
    string str;
    string str2 = "_";
    for (int i = 1; i < 100; i++)
    {
        str =+ "_";
        CHECK(n.read(0,0,0,Direction::Horizontal,i) == str);
        CHECK(n.read(100-i,0,0,Direction::Horizontal,i) == str2);
    }    
}

TEST_CASE("Good Input")
{
    Notebook n;
    string str = "This Is A Hundred Characters Long Text That I, Dor Baram Came Up With, For Testing Purposes, Mostly.";
    int strl = str.length();
    CHECK_NOTHROW( n.write(0,0,0,Direction::Horizontal,str));
    CHECK_EQ( n.read(0,0,0,Direction::Horizontal,strl) , str);
    CHECK_NOTHROW(n.erase(0,0,0,Direction::Horizontal,strl));
    for (int i = 0; i < strl; i++)
    {
        for (int j = 0; j < strl; j++)
        {
            CHECK_EQ(n.read(0,0,i,Direction::Horizontal,1) , n.read(0,0,j,Direction::Horizontal,1));
        }
    }
}

TEST_CASE("Bad Input")
{
    Notebook n;
    string str = "This Is A Hundred Characters Long Text That I, Dor Baram Came Up With, For Testing Purposes, Mostly.";
    CHECK_THROWS(n.write(0,0,0,Direction::Horizontal,str+"This Should Overflow"));
    n.write(0,0,0,Direction::Horizontal,str);
    CHECK_THROWS(n.write(0,0,0,Direction::Horizontal,str));
    n.erase(0,0,0,Direction::Horizontal,str.length());
    CHECK_THROWS(n.write(0,0,0,Direction::Horizontal,str));
    Notebook no;
    CHECK_THROWS(no.write(-1,0,0,Direction::Horizontal,str));
    CHECK_THROWS(no.write(0,-1,0,Direction::Horizontal,str));
    CHECK_THROWS(no.write(0,0,-1,Direction::Horizontal,str));
    CHECK_THROWS(no.write(-1,0,0,Direction::Vertical,str));
    CHECK_THROWS(no.write(0,-1,0,Direction::Vertical,str));
    CHECK_THROWS(no.write(0,0,-1,Direction::Vertical,str));
}