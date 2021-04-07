#include <string>
#include <unordered_map>
#include <utility> 
#include "Direction.hpp"
#include <math.h>
using namespace std;
namespace ariel {
    
    class Board {
 
        private:
        unordered_map<string,char> DynamicBoard;
        public:
        Board() {}
        ~Board() {}
        void post(unsigned int row, unsigned int column, Direction direction, string message);
        string read(unsigned int row, unsigned int column, Direction direction, unsigned int length);
        void show();
    };
}