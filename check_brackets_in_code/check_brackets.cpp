#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);
    int exit=0;

    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            opening_brackets_stack.push(Bracket(next,position));
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
           auto temp=opening_brackets_stack.top();
           if (!opening_brackets_stack.empty())
           {
           if (!temp.Matchc(next))
           {

                std::cout<<position+1;
                exit=1;
                break;

            }
            else
            {
                opening_brackets_stack.pop();
            }

        }
        else
        {
              std::cout<<position+1;
              exit=1;
              break;
        }
    }
    }
    if (opening_brackets_stack.empty()&&exit==0)
    {
        std::cout<<"Success";
    }
    else if(exit==0)
    {
        auto t=opening_brackets_stack.top();
        std::cout<<t.position+1;
    }
    // Printing ans wer, write your code here



return 0;
}
