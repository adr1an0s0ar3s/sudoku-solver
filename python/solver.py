import math
import time

#------------------------------------ Back-Tracking Method ----------------------------------------

# Helper Functions

def check_square(M, x, y, value):

    square_initial_x, square_initial_y = math.floor(x/3)*3, math.floor(y/3)*3

    for j in range(square_initial_y, square_initial_y+3):
        for i in range(square_initial_x, square_initial_x+3):
            if (M[j][i] == value):
                return False

    return True

def check_row(M, y, value):

    for i in range(len(M)):
        if (M[y][i] == value):
            return False

    return True

def check_column(M, x, value):

    for j in range(len(M)):
        if (M[j][x] == value):
            return False
    
    return True

def board_complete(M):

    for y in range(len(M)):
        for x in range(len(M)):
            if (M[y][x] == 0):
                return False

    return True

def print_board(M):

    for y in range(len(M)):
        for x in range(len(M)):

            if (x != len(M)-1):
                print(f" {M[y][x]}", end="")
            else: print(f" {M[y][x]}")

            if ((x+1)%3 == 0 and x != len(M)-1):
                print(" |", end="")
            
            if ((y+1)%3 == 0 and x == len(M)-1 and y != len(M)-1):
                print("-------+-------+-------")
    
    print()

# Brain Function

def back_tracking_solver(M):

    m = M.copy()
    possible_value = False

    for y in range(len(m)):
        for x in range(len(m)):

            if (m[y][x] != 0):
                continue

            for value in range(1, 10):
                if (check_square(m, x, y, value) and check_row(m, y, value) and check_column(m, x, value)):
                    m[y][x] = value
                    possible_value = True
                    if (not back_tracking_solver(m)):
                        m[y][x] = 0
                        possible_value = False

            if (not possible_value): return False
    
    print_board(m)

def back_tracking_greedy_solver(M):

    if (board_complete(M)):
        print_board(M)
        return True

    m = M.copy()

    # Find coordinates with less possibilities
    best_x = 0; best_y = 0
    possibilities = [1,2,3,4,5,6,7,8,9]
    for y in range(9):
        for x in range(9):
            if (m[y][x] != 0):
                continue
            temp = [value for value in range(1, 10) if (check_square(m, x, y, value) and check_row(m, y, value) and check_column(m, x, value))]
            if (len(temp) == 0):
                return False
            elif (len(possibilities) > len(temp)):
                best_x = x; best_y = y
                possibilities = temp.copy()

    for value in possibilities:
        m[best_y][best_x] = value
        if back_tracking_greedy_solver(m):
            return True
        m[best_y][best_x] = 0

    return False

matrix = [[0,0,0,0,9,0,0,2,0]
         ,[4,0,2,5,0,0,0,6,0]
         ,[0,5,3,0,7,0,0,4,0]
         ,[0,7,8,0,0,1,0,0,0]
         ,[9,0,0,0,5,0,0,0,0]
         ,[0,4,0,6,0,0,0,0,0]
         ,[0,0,0,0,0,7,0,0,2]
         ,[5,0,0,0,4,0,7,0,0]
         ,[0,0,0,0,0,0,1,0,6]]

print_board(matrix)

print("Back-Tracking Algorithm:")
t0 = time.time()
back_tracking_solver(matrix)
t1 = time.time()

print("Back-Tracking Algorithm with Greedy Approach:")
t2 = time.time()
back_tracking_greedy_solver(matrix)
t3 = time.time()

print(f"Back-Tracking Algorithm: {t1-t0}")
print(f"Back-Tracking Algorithm with Greedy Approach: {t3-t2}")