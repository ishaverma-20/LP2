import heapq

class PuzzleState:
    def __init__(self, board, goal, moves=0, parent=None):
        self.board = board
        self.goal = goal
        self.moves = moves
        self.parent = parent

    def __eq__(self, other):
        return self.board == other.board

    def __lt__(self, other):
        return (self.moves + self.heuristic()) < (other.moves + other.heuristic())

    def heuristic(self):
        return sum(1 if self.board[i] != self.goal[i] else 0 for i in range(9))

    def f_value(self):
        return self.moves + self.heuristic()

    def possible_moves(self):
        moves = []
        i = self.board.index(0)
        if i not in [0, 1, 2]:  #not in top row
            moves.append(-3)
        if i not in [0, 3, 6]:  #not in left column
            moves.append(-1)
        if i not in [2, 5, 8]:  #not in right column
            moves.append(1)
        if i not in [6, 7, 8]:  #not in botton row
            moves.append(3)
        return moves

    def make_move(self, direction):
        new_board = self.board[:]
        i = new_board.index(0)
        new_board[i], new_board[i + direction] = new_board[i + direction], new_board[i]
        return PuzzleState(new_board, self.goal, self.moves + 1, parent=self)

    def print_board(self):
        for i in range(0, 9, 3):
            print(self.board[i:i + 3])
        print()

def solve_puzzle(start, goal):
    open_list = [start]
    closed_list = []
    heapq.heapify(open_list)

    while open_list:
        current_state = heapq.heappop(open_list)
        closed_list.append(current_state)

        if current_state.board == goal:
            return current_state

        for move in current_state.possible_moves():
            new_state = current_state.make_move(move)
            if new_state not in closed_list:
                heapq.heappush(open_list, new_state)

    return None

def get_solution_moves(solution):
    moves = []
    current_state = solution
    while current_state:
        moves.append(current_state)
        current_state = current_state.parent
    return moves[::-1]

def print_solution_moves(moves):
    if moves:
        print("Solution found! Moves:")
        for i, state in enumerate(moves):
            if i > 0:
                print("Move", i, "(f(n) =", state.f_value(), "):")
                state.print_board()
    else:
        print("No solution found.")

if __name__ == "__main__":
    start_board = [1, 2, 3, 5, 6, 0, 7, 8, 4]
    goal_board = [1, 2, 3, 5, 8, 6, 0, 7, 4]
    
    start_state = PuzzleState(start_board, goal_board)
    solution = solve_puzzle(start_state, goal_board)
    
    if solution:
        solution_moves = get_solution_moves(solution)
        print_solution_moves(solution_moves)
    else:
        print("No solution found.")
