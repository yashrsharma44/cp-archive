#include <cmath>
#include <ctime>
#include <functional>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct neighbor {
  // c = count, i = moves index
  int c, i;

  bool operator > (neighbor const& n) const {
    return c > n.c;
  }
};

int main() {
  // Chessboard NxN
  int n;
  cout<<"Enter the dimensions! "<<"\n";

  cin>>n;

  // Chessboard first initialization
  vector<vector<int>> board (n, vector<int>(n, 0));

  // Knight's legal moves
  vector<vector<int>> moves {
    {1, 2}, {2, 1}, {-1, 2}, {1, -2}, {-2, 1}, {2, -1}, {-2, -1}, {-1, -2}
  };

  /*! Knight's move checker

   * Return true if the Knight could be moved to (x, y) point.
   * Otherwise, false.
   */
  function<bool(int, int)> moveable = [n](int x, int y) {
    return x > -1 && x < n && y > -1 && y < n;
  };

  /*! Chessboard visits checker
   * Return true if the board at the (x, y) point has been visited.
   *      Otherwise, false.
   */
  function<bool(int, int)> visited = [&board](int x, int y) {
    return board[x][y] > 0;
  };

  /*! Convert a microseconds to a seconds
   * Return the seconds form in the integer data type.
   */
  function<float(clock_t)> toSecs = [](clock_t start) {
    return (clock() - start) / 1000000.0;
  };

  /*! Timeout checker
   *  The running tour with a defined time limit.
   *  Return true if the limit passed. Otherwise, false.
   */
  function<bool(clock_t, int)> isTimeout = [&toSecs](clock_t start, int limit) {
    return toSecs(start) >= (limit / 1.0);
  };

  clock_t start = clock();
  int limit = 20;

  /*! Common backtracking approach.
   *  Blank state chessboard.
   *  Return true if the Knight's tour could be performed.
   *      Otherwise, false. Chessboard has been filled out.
   */
  function<bool(int, int, int)> tourable1 =
  [
    n,
    moves,
    &board,
    &isTimeout,
    &limit,
    &moveable,
    &start,
    &toSecs,
    &tourable1,
    &visited
  ](int x, int y, int i) {
    if (i == (n * n)) return true;

    if (isTimeout(start, limit)) return false;

    for (int k = 0; k < 8; k++) {
      int nx = x + moves[k][0];
      int ny = y + moves[k][1];

      if (moveable(nx, ny) && !visited(nx, ny)) {
        board[nx][ny] = i + 1;

        if (tourable1(nx, ny, i + 1))
          return true;
        else
          board[nx][ny] = 0;
      }
    }

    return false;
  };

  /*! Chessboard printer
   * 
   *  Print out the chessboard state with a pretty print format.
   */
  function<void()> printBoard = [n, &board]() {
    int maxdigit = log10(n * n);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int step = board[i][j];
        int digit = log10(step);

        for (int k = 0; k < maxdigit - digit; k++)
          cout<<(" ");

        cout<<(" %d", step);

        if (j < n - 1) cout<<(" ");
      }

      cout<<"\n";
    }
  };


    function<bool(int, int, int)> tourable =
  [
    moves,
    n,
    &board,
    &moveable,
    &tourable,
    &visited
  ](int x, int y, int p) {
    // Mark the chessboard
    board[x][y] = p;

    // Found a solution
    if (p == n * n) return true;

    // Min Heap for the available neighbors
    priority_queue<neighbor, vector<neighbor>, greater<neighbor>> heap;

    // Check all possible moves
    for (int i = 0; i < moves.size(); i++) {
      // Next moves
      int nx = x + moves[i][0];
      int ny = y + moves[i][1];

      if (moveable(nx, ny) && !visited(nx, ny)) {
        int count = 0;

        // Check all possible neighbors
        for (int j = 0; j < moves.size(); j++) {
          int mx = nx + moves[j][0];
          int my = ny + moves[j][1];

          if (moveable(mx, my) && !visited(mx, my)) count++;
        }

        neighbor ne;
        ne.c = count;
        ne.i = i;

        heap.push(ne);
      }
    }

    // If there is at least one possible move exists
    if (heap.size() > 0) {
      neighbor ne = heap.top();
      int nx = moves[ne.i][0];
      int ny = moves[ne.i][1];

      if(tourable(x + nx, y + ny, p + 1)) return true;
    }

    // No solution
    return false;
  };




  /*! Chessboard initialization helper
   * Current chessboard state
   * Reset the chessboard and fill `0` on the each grid.
   */
  function<void()> initializeBoard = [n, &board]() {
    vector<vector<int>> v (n, vector<int>(n, 0));

    board = v;
  };


  // Find the solution from a random starting point
  function<void()> findRandomSolution1 =
  [
    n,
    limit,
    &board,
    &initializeBoard,
    &isTimeout,
    &printBoard,
    &start,
    &toSecs,
    &tourable1
  ]() {
    srand(time(0));

    int x, y;
    int tries = 0;
    clock_t total = clock();

    cout<<(" Finding a random solution from the %dx%d chessboard.", n, n)<<"\n";
    cout<<"\n";

    do {
      tries++;
      x = 0;
      y = 0;

      initializeBoard();

      start = clock();
      board[x][y] = 1;
    } while (!tourable1(x, y, 1) && tries < n * n);

    if (tries >= n * n) {
      if (isTimeout(start, limit))
        cout<<(" Timeout for each possible solution")<<"\n";
      else
        cout<<(" The solution doesn't exist")<<"\n";
    }
    else {
      cout<<(" Found a solution at starting point")<<"\n";
      cout<<"\n";
      cout<<x<<" "<<y<<"\n";
      printBoard();
    }

    cout<<"\n";
    cout<<(" Took about ")<<toSecs(total)<<(" seconds ")<<"\n";
    cout<<(" after ")<< tries;

    if (tries < 2)
      cout<<(" try");
    else
      cout<<(" tries");

    cout<<"\n";
  };

    // Find the solution from a random starting point
    // Wansdorff ALgorithm
  function<void()> findRandomSolution =
  [
    n,
    &initializeBoard,
    &printBoard,
    &toSecs,
    &tourable,
    &start
  ]() {
    srand(time(0));

    int x = 0;
    int y = 0;
    int tries = 0;

    cout<<(" Finding a random solution from the %dx%d chessboard", n, n)<<"\n";
    cout<<"\n";

    while (!tourable(x, y, 1) && tries < n * n) {
      tries++;

      x = rand() % n;
      y = rand() % n;

      initializeBoard();
    }

    if (tries >= n * n)
      cout<<(" The solution doesn't exist")<<"\n";
    else {
      cout<<(" Found a solution at starting point")<<"\n";
      cout<<x<<" "<<y<<"\n";
      cout<<"\n";
      printBoard();
    }

    cout<<"\n";
    cout<<" Took about "<<toSecs(start)<<"  seconds"<<"\n";
    cout<<(" after ")<< ++tries;

    if (tries < 2)
      cout<<(" try");
    else
      cout<<(" tries");

    cout<<"\n";
  };
 
  int c;
  cout<<"Enter 1 for backtracking, 2 for Wansdorff Algorithm"<<"\n";
  cin>>c;
  if(c==1)
  {
      findRandomSolution1();
  }
  else if(c==2)
  {
      findRandomSolution();
  }
  else
  {
      cout<<"Choice is invalid! Please try again!"<<"\n";
  }
  


  return 0;
}