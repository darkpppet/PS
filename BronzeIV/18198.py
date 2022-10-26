game_log = input()

score_a = 0
score_b = 0

for i in range(0, len(game_log)//2):
    letter_index = i*2
    point_index = i*2 + 1

    match game_log[letter_index]:
        case 'A':
            score_a += int(game_log[point_index])
        
        case 'B':
            score_b += int(game_log[point_index])
    
print('A' if score_a > score_b else 'B')
