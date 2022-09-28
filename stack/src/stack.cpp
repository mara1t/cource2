#include "stack.h"
#include "stack_bool.h"

int main()
{
    stack::Stack_t<bool> mystack{};
    mystack.push(bool(1));
    mystack.push(bool(1));
    mystack.push(bool(0));
    mystack.push(bool(0));
    std::cout << mystack.pop() << mystack.pop() << mystack.pop() << mystack.pop() << std::endl;


    return 0;
}