#include "Board.hpp"
#include <algorithm>
#include <ctype.h>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
namespace ariel {
void Board::post(unsigned int row, unsigned int column, Direction direction,
                 string message) {

  if (direction == Direction::Vertical) {
    for (size_t i = 0; i < message.size(); i++) {
      DynamicBoard["Row: "+to_string(row + i)+" Column: "+to_string(column)] = message.at(i);
    
    }
  }

  if (direction == Direction::Horizontal) {

    for (size_t i = 0; i < message.size(); i++) {
      
      DynamicBoard["Row: "+to_string(row)+" Column: "+to_string(column+i)] = message.at(i);
    
    }
  }
}
char check_exists_key_Row_Column(
    unordered_map<string,char> m,unsigned int row, unsigned int column) {
  if (m.find("Row: "+to_string(row)+" Column: "+to_string(column)) == m.end()) {
    return '_';
  }
  return m["Row: "+to_string(row)+" Column: "+to_string(column)];
}
string Board::read(unsigned int row, unsigned int column, Direction direction,
                   unsigned int length) {
  string read;
  if (direction == Direction::Vertical) {

    for (size_t i = 0; i < length; i++) {
      read += check_exists_key_Row_Column(DynamicBoard, row + i, column);
    }
  }

  if (direction == Direction::Horizontal) {
    for (size_t i = 0; i < length; i++) {
      read += check_exists_key_Row_Column(DynamicBoard, row, column + i);
    }
  }

  return read;
}
void Board::show() {
for(auto& it : DynamicBoard)
{
  cout << "("<<it.first<<")=";
cout<<it.second<<endl;


}
}

} // namespace ariel
