#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Block {
public:
	Block(int _size = 0, int _pole_id = 0, int _id = 0);
	int getSize();
	void setSize(int _size);
	int getPoleId();
	void setPoleId(int _pole_id);
	int getId();
	void setId(int _id);
private:
	int size;
	int pole_id;
	int id;
};

class Pole {
public:
	Pole(int _id);
	int getId();
	void setId(int _id);
	void pushOnPole(Block* block);
	int getTopSize();
	bool ifCanPush(Block* block);
	bool ifCanPop(Block* block);
	int getTopBlockId();
	bool popBlock(Block* block);
	bool pushBlock(Block* block);
private:
	stack<Block*> blocks;
	int id;
};

class Hanoi {
public:
	Hanoi(int num_blocks, int num_poles);
	~Hanoi() {}
	void solve(int which_b, int pole_1);
	void printPoles();
private:
	vector<Block> blocks;
	vector<Pole> poles;
	bool getBlockToPole(int id_block, int id_pole);

};
