#include <bits/stdc++.h>
using namespace std;

char grid[9][9];
char modified[9][9];

bool no_duplicates_in_rows() {
  bool ok = true;
  for (int r = 0; r < 9; r++) {
    vector<int> row;
    for (int c = 0; c < 9; c++) {
      if (grid[r][c] != '.') {
        row.push_back(grid[r][c] - '0');
      }
    }
    set<int> s(row.begin(), row.end());
    if (row.size() != s.size()) {
      ok = false;
      break;
    }
  }
  return ok;
}

bool no_duplicates_in_columns() {
  bool ok = true;
  for (int c = 0; c < 9; c++) {
    vector<int> column;
    for (int r = 0; r < 9; r++) {
      if (grid[r][c] != '.') {
        column.push_back(grid[r][c] - '0');
      }
    }
    set<int> s(column.begin(), column.end());
    if (column.size() != s.size()) {
      ok = false;
      break;
    }
  }
  return ok;
}

bool no_duplicates_in_boxes() {
  bool ok = true;
  for (int r = 0; r < 9; r += 3) {
    for (int c = 0; c < 9; c += 3) {
      vector<int> box;
      for (int dr = 0; dr < 3; dr++) {
        for (int dc = 0; dc < 3; dc++) {
          char cell = grid[r + dr][c + dc];
          if (cell != '.') {
            box.push_back(cell - '0');
          }
        }
      }
      set<int> s(box.begin(), box.end());
      if (box.size() != s.size()) {
        ok = false;
        break;
      }
    }
  }
  return ok;
}

void cross(int n) {
  for (int r = 0; r < 9; r++) {
    for (int c = 0; c < 9; c++) {
      if (modified[r][c] - '0' == n) {
        for (int i = 0; i < 9; i++) {
          if (modified[r][i] == '.') {
            modified[r][i] = 'x';
          }
        }
        for (int i = 0; i < 9; i++) {
          if (modified[i][c] == '.') {
            modified[i][c] = 'x';
          }
        }
        for (int dr = 0; dr < 3; dr++) {
          for (int dc = 0; dc < 3; dc++) {
            int br = 3 * (r / 3) + dr;
            int bc = 3 * (c / 3) + dc;
            if (modified[br][bc] == '.') {
              modified[br][bc] = 'x';
            }
          }
        }
      }
    }
  }
}

int hatch(int n) {
  for (int r = 0; r < 9; r += 3) {
    for (int c = 0; c < 9; c += 3) {
      int nr, nc;
      int filled = 0, empty = 0;
      for (int dr = 0; dr < 3; dr++) {
        for (int dc = 0; dc < 3; dc++) {
          char cell = modified[r + dr][c + dc];
          if (cell == n + '0') {
            filled++;
          }
          if (cell == '.') {
            nr = r + dr;
            nc = c + dc;
            empty++;
          }
        }
      }
      if (filled + empty == 0) {
        return -1;
      } else if (empty == 1) {
        grid[nr][nc] = n + '0';
        return 1;
      }
    }
  }
  return 0;
}

bool solve() {
  bool ok = (
    no_duplicates_in_rows() and
    no_duplicates_in_columns() and
    no_duplicates_in_boxes()
  );
  if (!ok) {
    return false;
  }
  bool more = true;
  while (more) {
    more = false;
    for (int n = 1; n < 10; n++) {
      // reset
      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
          modified[i][j] = grid[i][j];
        }
      }
      cross(n);
      int result = hatch(n);
      if (result == 1) {
        more = true;
      } else if (result == -1) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  for (int r = 0; r < 9; r++) {
    for (int c = 0; c < 9; c++) {
      char temp;
      cin >> temp;
      grid[r][c] = temp;
      modified[r][c] = temp;
    }
  }
  bool solved = solve();
  if (solved) {
    for (int r = 0; r < 9; r++) {
      for (int c = 0; c < 9; c++) {
        cout << grid[r][c];
      }
      cout << endl;
    }
  } else {
    cout << "ERROR" << endl;
  }
  return 0;
}