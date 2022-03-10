//simple program that checks for missing parantheses
#include <iostream>
#include <stack>
#include <string>

using namespace std;
// returns whether the parentheses in the input are balanced
bool parChecker(string symbolString) {
    stack<string> s;
    bool balanced = true;
    int index = 0;
    int str_len = symbolString.length();

    while (index < str_len && balanced) {
              string symbol;
              symbol = symbolString[index];
              if (symbol == "<") {
                  s.push(symbol); //pushes the open parentheses to the stack.
              } else { if(symbol=="/"){//if there is an open parentheses in the stack,
                           //the closing parentheses just found has a matching open parentheses.
                       s.pop();
                       s.pop();}
                 else {
                     if(symbol != "<" && symbol!="/"){}
                 else{
                      if (s.empty()) { //if there is no open parentheses in the stack,
                                   //the closing parentheses just found makes the string unbalanced.
                        balanced = false;}
                  } 
                
                  }
              }
    index = index + 1;
    }

    if (balanced && s.empty()) { //if the string is balanced and there are no
                                 //remaining open parentheses.
        return true;
    } else {
        return false;
    }
}

int main() {
    cout << parChecker(" <html>><head> <title> Example</title></head><body><h1>Hello, world</h1> </body></html> ") << endl;
    cout << parChecker("") << endl;
}
