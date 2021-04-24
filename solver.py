import math

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

def print_sudoku(M):

    for y in range(len(M)):
        for x in range(len(M)):

            if (x != len(M)-1):
                print(f" {M[y][x]}", end="")
            else: print(f" {M[y][x]}")

            if ((x+1)%3 == 0 and x != len(M)-1):
                print(" |", end="")
            
            if ((y+1)%3 == 0 and x == len(M)-1 and y != len(M)-1):
                print("-------+-------+-------")

# Brain Function

def solver(M):

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
                    if (not solver(m)):
                        m[y][x] = 0
                        possible_value = False

            if (not possible_value): return False
    
    print_sudoku(m)

M = [[0,0,4,7,1,0,0,0,0]
    ,[0,7,2,8,0,6,5,0,0]
    ,[0,0,0,0,0,5,0,0,7]
    ,[0,1,0,6,9,0,2,0,0]
    ,[3,9,0,0,5,0,0,0,0]
    ,[0,0,0,0,0,0,0,8,5]
    ,[0,0,1,2,3,0,8,0,4]
    ,[0,0,3,5,0,4,0,0,2]
    ,[2,4,0,9,0,0,0,0,0]]

m = [[0,0,0,0,9,0,0,2,0]
    ,[4,0,2,5,0,0,0,6,0]
    ,[0,5,3,0,7,0,0,4,0]
    ,[0,7,8,0,0,1,0,0,0]
    ,[9,0,0,0,5,0,0,0,0]
    ,[0,4,0,6,0,0,0,0,0]
    ,[0,0,0,0,0,7,0,0,2]
    ,[5,0,0,0,4,0,7,0,0]
    ,[0,0,0,0,0,0,1,0,6]]

solver(M)