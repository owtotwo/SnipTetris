#pragma once

#include <memory>
#include "Tetromino.h"
#include "Block.h"

using std::shared_ptr;

class Tetromino;

typedef shared_ptr<Block> grid_t[MAX_COL][MAX_ROW];

#define ALL_OF_GRID(callback) (all_of((shared_ptr<Block>*)_grid, (shared_ptr<Block>*)_grid + MAX_COL * MAX_ROW, (callback)))

// enum GRID_STATE { ALIVE, FULL_LINE, };

class TetrominoGrid
{
public:
	TetrominoGrid();
	const grid_t& getGrid() const { return _grid; }

	void nextRound();
	void putTetro(const shared_ptr<Tetromino>& tetro);

	bool canFall();
	bool canMove(DIRECTION dir);
	bool fall();
	bool move(DIRECTION dir);
	bool rotate();
	bool hardDrop();

	bool hasFullRow();
	bool isGameOver();

	void checkState();

	shared_ptr<Tetromino> getRandomTetromino();
	shared_ptr<Block> getBlockOrNull(int cx, int ry);
	bool isOccupied(int cx, int ry);
	bool isAccessible(int cx, int ry);

	shared_ptr<Tetromino> curTetro = nullptr;
	int curTetroCoord[4][2] = { 0 };
	shared_ptr<Tetromino> nextTetro = nullptr;

private:
	grid_t _grid = { nullptr };
};