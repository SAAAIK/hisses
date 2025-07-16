#include "controller.h"

void UserInputToUserAction(int user_input)
{
  switch(user_input)
  {
    case KEY_LEFT:
      userInput(Left, false);
      break;
    case KEY_RIGHT:
      userInput(Right, false);
      break;
    case KEY_UP:
      userInput(Up, false);
      break;
    case KEY_DOWN:
      userInput(Down, false);
      break;
    case 'a':
      userInput(Action, false);
      break;
    case 's':
      userInput(Start, false);
      break;
    case 'p':
      userInput(Pause, false);
      break;
    case 't':
      userInput(Terminate, false);
      break;
    default:
      break;
  }
}