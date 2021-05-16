import random

player1 = None
player2 = None
game_field = [[' ', ' ', ' '], [' ', ' ', ' '], [' ', ' ', ' ']]


def main():
    if start_game():
        print_current_field()

        while True:
            x_move()
            print_current_field()
            full_field, someone_won = decide_state()

            if full_field or someone_won:
                decide_result()
                break

            o_move()
            print_current_field()
            full_field, someone_won = decide_state()

            if full_field or someone_won:
                decide_result()
                break


def start_game():
    while True:
        commands = input("Input command: ").split(' ')

        if len(commands) == 3:
            if commands[1] == 'easy' or commands[1] == 'user' or commands[1] == 'medium':
                if commands[2] == 'easy' or commands[2] == 'user' or commands[2] == 'medium':
                    global player1
                    player1 = commands[1]
                    global player2
                    player2 = commands[2]
                    game = True
                    break

                else:
                    print("Bad parameters!")

            else:
                print("Bad parameters!")

        elif commands[0] == 'exit':
            game = False
            break

        else:
            print("Bad parameters!")

    return game


def print_current_field():
    print("""---------
| {} {} {} |
| {} {} {} |
| {} {} {} |
---------"""
          .format(game_field[0][0], game_field[0][1], game_field[0][2], game_field[1][0], game_field[1][1],
                  game_field[1][2], game_field[2][0], game_field[2][1], game_field[2][2]))


def x_move():
    if player1 == 'easy':
        easy_computer_move()

    elif player1 == 'medium':
        medium_computer_move()

    elif player1 == 'user':
        user_move()


def o_move():
    if player2 == 'easy':
        easy_computer_move()

    elif player2 == 'medium':
        medium_computer_move()

    elif player2 == 'user':
        user_move()


def easy_computer_move():
    print('Making move level easy')

    number = random.randint(1, 9)
    coordinates = translate_coordinates(number)

    while True:
        if game_field[coordinates[0]][coordinates[1]] == ' ':
            game_field[coordinates[0]][coordinates[1]] = 'O'
            break

        else:
            number = random.randint(1, 9)
            coordinates = translate_coordinates(number)


def medium_computer_move():
    print('Making move level medium')
    opponent_can_win = False
    i_can_win = False


def user_move():
    while True:
        error = False

        usr_coordinates = input("Enter the coordinates: ")
        usr_coordinates = usr_coordinates.split(' ')

        for number in usr_coordinates:

            try:
                number = int(number)

            except:
                print("You should enter numbers!")
                error = True
                break

            if number <= 0 or number > 3:
                print("Coordinates should be from 1 to 3!")
                error = True
                break

        if not error:
            proper_coordinates = [int(usr_coordinates[0]) - 1, 3 - int(usr_coordinates[1])]

            if game_field[proper_coordinates[1]][proper_coordinates[0]] == ' ':
                game_field[proper_coordinates[1]][proper_coordinates[0]] = 'X'
                break

            else:
                print("This cell is occupied! Choose another one!")


def translate_coordinates(num):
    if num == 1:
        return [0, 0]

    elif num == 2:
        return [0, 1]

    elif num == 3:
        return [0, 2]

    elif num == 4:
        return [1, 0]

    elif num == 5:
        return [1, 1]

    elif num == 6:
        return [1, 2]

    elif num == 7:
        return [2, 0]

    elif num == 8:
        return [2, 1]

    elif num == 9:
        return [2, 2]

    else:
        print("Error!")


def decide_state():
    full_field = True
    someone_won = False

    for row in game_field:
        for symbol in row:
            if symbol == ' ':
                full_field = False
                break
        else:
            continue
        break

    if not full_field:
        for x in range(3):
            if game_field[x][0] == game_field[x][1] == game_field[x][2]:
                someone_won = True

            elif game_field[0][x] == game_field[1][x] == game_field[2][x]:
                someone_won = True

            elif game_field[0][0] == game_field[1][1] == game_field[2][2] or game_field[0][2] == game_field[1][1] == \
                    game_field[2][0]:
                someone_won = True

    return full_field, someone_won


def decide_result():
    for x in range(3):
        if game_field[x][0] == game_field[x][1] == game_field[x][2]:

            if game_field[x][0] == "X":
                print("X wins")
                break

            elif game_field[x][0] == 'O':
                print("O wins")
                break

        elif game_field[0][x] == game_field[1][x] == game_field[2][x]:

            if game_field[0][x] == 'X':
                print("X wins")
                break

            elif game_field[0][x] == 'O':
                print("O wins")
                break

        elif game_field[0][0] == game_field[1][1] == game_field[2][2] or game_field[0][2] == game_field[1][1] == \
                game_field[2][0]:

            if game_field[1][1] == "X":
                print("X wins")
                break

            elif game_field[1][1] == 'O':
                print("O wins")
                break

        else:
            print("Draw")


if __name__ == "__main__":
    main()
