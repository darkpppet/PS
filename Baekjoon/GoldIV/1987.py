import sys

r, c = [int(x) for x in sys.stdin.readline().rstrip().split()]

board = [['' for _ in range(c+2)]]
for _ in range(r):
    board.append([''] + list(sys.stdin.readline().rstrip()) + [''])
board.append(['' for _ in range(c+2)])

def char_to_index(char):
    if char == '':
        return 26
    else:
        return ord(char) - 65

history_list = [False for _ in range(26+1)]
history_list[26] = True
history_list[char_to_index(board[1][1])] = True

max_length = 1
def dfs(index, length):
    global max_length
    max_length = max(max_length, length)

    check_next_board((index[0]-1, index[1]), length+1)
    check_next_board((index[0]+1, index[1]), length+1)
    check_next_board((index[0], index[1]-1), length+1)
    check_next_board((index[0], index[1]+1), length+1)

def check_next_board(index, length):
    board_char = board[index[0]][index[1]]
    board_char_index = char_to_index(board_char)
    if not history_list[board_char_index]:
        history_list[board_char_index] = True
        dfs((index[0], index[1]), length)
        history_list[board_char_index] = False

dfs((1, 1), 1)

print(max_length)
