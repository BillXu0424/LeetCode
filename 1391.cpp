class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int dir; // left: 1, right: 2, up: 3, down: 4
        int i = 0, j = 0, row = grid.size(), col = grid[0].size();
        int count = 0;
        while (i >= 0 && i < row && j >= 0 && j < col) {
            if (count >= row * col + 3) break;
            if (i == 0 && j == 0) {
                if (grid[0][0] == 1) {
                    dir = 2;
                    j++;
                    count++;
                }
                else if (grid[0][0] == 2) {
                    dir = 4;
                    i++;
                    count++;
                }
                else if (grid[0][0] == 3) {
                    dir = 4;
                    i++;
                    count++;
                }
                else if (grid[0][0] == 4) {
                    dir = 2; // dir = 4 not considered yet
                    j++;
                    count++;
                }
                else if (grid[0][0] == 6) {
                    dir = 2;
                    j++;
                    count++;
                }
                else return (row == 0 && col == 0);
            }
            else {
                if (grid[i][j] == 1) {
                    if (dir == 2) {
                        if (i == row - 1 && j == col - 1) return true;
                        dir = 2;
                        j++;
                        count++;
                    }
                    else if (dir == 1) {
                        if (i == row - 1 && j == col - 1) return true;
                        dir = 1;
                        j--;
                        count++;
                    }
                    else break;
                }
                else if (grid[i][j] == 2) {
                    if (dir == 3) {
                        if (i == row - 1 && j == col - 1) return true;
                        dir = 3;
                        i--;
                        count++;
                    }
                    else if (dir == 4) {
                        if (i == row - 1 && j == col - 1) return true;
                        dir = 4;
                        i++;
                        count++;
                    }
                    else break;
                }
                else if (grid[i][j] == 3) {
                    if (dir == 2) {
                        if (i == row - 1 && j == col - 1) return true;
                        dir = 4;
                        i++;
                        count++;
                    }
                    else if (dir == 3) {
                        if (i == row - 1 && j == col - 1) return true;
                        dir = 1;
                        j--;
                        count++;
                    }
                    else break;
                }
                else if (grid[i][j] == 4) {
                    if (dir == 1) {
                        if (i == row - 1 && j == col - 1) return true;
                        dir = 4;
                        i++;
                        count++;
                    }
                    else if (dir == 3) {
                        if (i == row - 1 && j == col - 1) return true;
                        dir = 2;
                        j++;
                        count++;
                    }
                    else break;
                }
                else if (grid[i][j] == 5) {
                    if (dir == 2){
                        if (i == row - 1 && j == col - 1) return true;
                        dir = 3;
                        i--;
                        count++;
                    }
                    else if (dir == 4) {
                        if (i == row - 1 && j == col - 1) return true;
                        dir = 1;
                        j--;
                        count++;
                    }
                    else break;
                }
                else {
                    if (dir == 1) {
                        if (i == row - 1 && j == col - 1) return true;
                        dir = 3;
                        i--;
                        count++;
                    }
                    else if (dir == 4) {
                        if (i == row - 1 && j == col - 1) return true;
                        dir = 2;
                        j++;
                        count++;
                    }
                    else break;
                }
            }
        }
        if (grid[0][0] == 4) {
            count = 0;
            i = 0;
            j = 0;
            while (i >= 0 && i < row && j >= 0 && j < col) {
                if (count >= row * col + 3) return false;
                if (i == 0 && j == 0) {
                    dir = 4;
                    i++;
                    count++;
                }
                else {
                    if (grid[i][j] == 1) {
                        if (dir == 2) {
                            if (i == row - 1 && j == col - 1) return true;
                            dir = 2;
                            j++;
                            count++;
                        }
                        else if (dir == 1) {
                            if (i == row - 1 && j == col - 1) return true;
                            dir = 1;
                            j--;
                            count++;
                        }
                        else return false;
                    }
                    else if (grid[i][j] == 2) {
                        if (dir == 3) {
                            if (i == row - 1 && j == col - 1) return true;
                            dir = 3;
                            i--;
                            count++;
                        }
                        else if (dir == 4) {
                            if (i == row - 1 && j == col - 1) return true;
                            dir = 4;
                            i++;
                            count++;
                        }
                        else return false;
                    }
                    else if (grid[i][j] == 3) {
                        if (dir == 2) {
                            if (i == row - 1 && j == col - 1) return true;
                            dir = 4;
                            i++;
                            count++;
                        }
                        else if (dir == 3) {
                            if (i == row - 1 && j == col - 1) return true;
                            dir = 1;
                            j--;
                            count++;
                        }
                        else return false;
                    }
                    else if (grid[i][j] == 4) {
                        if (dir == 1) {
                            if (i == row - 1 && j == col - 1) return true;
                            dir = 4;
                            i++;
                            count++;
                        }
                        else if (dir == 3) {
                            if (i == row - 1 && j == col - 1) return true;
                            dir = 2;
                            j++;
                            count++;
                        }
                        else return false;
                    }
                    else if (grid[i][j] == 5) {
                        if (dir == 2){
                            if (i == row - 1 && j == col - 1) return true;
                            dir = 3;
                            i--;
                            count++;
                        }
                        else if (dir == 4) {
                            if (i == row - 1 && j == col - 1) return true;
                            dir = 1;
                            j--;
                            count++;
                        }
                        else return false;
                    }
                    else {
                        if (dir == 1) {
                            if (i == row - 1 && j == col - 1) return true;
                            dir = 3;
                            i--;
                            count++;
                        }
                        else if (dir == 4) {
                            if (i == row - 1 && j == col - 1) return true;
                            dir = 2;
                            j++;
                            count++;
                        }
                        else return false;
                    }
                }
            }
        }
        return (i == row && j == col - 1) || (i == row - 1 && j == col);
    }    
};