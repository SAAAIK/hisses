void finite_state_machine_func(GameInfo_t *gameInfo, UserAction_t action)
{
    switch (gameInfo->state)
    {
    case GameStart:
        switch (action)
        {
        case Start:
            // здесь должна происходить инициализация игры, поля, змейки и параметров игры
            gameInfo->state = Spawn;
            break;
        case Terminate:
            gameInfo->state = GameExit;
            break;
        }
        break;
    case Spawn:
        // PlacePieceonField;
        // spawnApple;
        break;
    case Moving:
        switch (action)
        {
        case Left:
            movePieceLeft(gameInfo);
            break;
        case Right:
            movePieceRight(gameInfo);
            break;
        case Down:
            movePieceDown(gameInfo);
            break;
        case Up:
            movePieceUp(gameInfo);
            break;
        case Action:
            // ускорение змейки
            break;
        case Pause:
            // пауза
            break;
        case Terminate:
            // переходим в состояние выхода
            break;
        }
        gameInfo->state = Shifting;
        break;
    case Shifting:
    // snakeShifting;
        break;
    case Colliding:
    // сюда нужно написать новую функцию проверки на то, с чем УЖЕ столкнулись 
    // будет менять стейт на Spawn или Game Over 
        break;
    case GameOver:
    // здесь зависит, можно возвращать в ожидание старта, можно в экзит
        break;
    case Pause:
    // вопрос как реализовывать паузу
        break;
    case GameExit:
    // здесь чистить всю память
        break;
    default:
        break;
    }
}

user_input_to_action(getch());

void user_input_to_action(int user_input)
{
    switch (user_input)
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

void userInput(UserAction_t user_input, bool hold)
{
    (void)hold;
    GameInfoExtended_t *game_inf_ex = get_current_game_inf_ex();
    if (!game_inf_ex->new_input)
    {
        game_inf_ex->input = user_input;
        game_inf_ex->new_input = true;
    }
}