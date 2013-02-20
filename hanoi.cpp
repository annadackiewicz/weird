#include "hanoi.h"

// -------------------    BLOCK ----------------------------
Block::Block(int _size, int _pole_id, int _id) {
	size = _size;
	pole_id = _pole_id;
	id = _id;
}

int Block::getSize() {
	return size;
}

void Block::setSize(int _size) {
	size = _size;
}

int Block::getPoleId() {
	return pole_id;
}

void Block::setPoleId(int _pole_id) {
	pole_id = _pole_id;
}

int Block::getId() {
	return id;
}

void Block::setId(int _id) {
	id = _id;
}


// -------------------    POLE  ----------------------------
Pole::Pole(int _id) {
	id = _id;
}

int Pole::getId() {
	return id;
}

void Pole::setId(int _id) {
	id = _id;
}

void Pole::pushOnPole(Block* block) {
	blocks.push(block);
}

int Pole::getTopSize() {
	if (blocks.size() > 0) {
		return blocks.top()->getSize();
	}
	return 0;
}

bool Pole::ifCanPush(Block* block) {
	int size = getTopSize();
	if (size == 0 || size > block->getSize()) {
		return true;
	}
	return false;
}

int Pole::getTopBlockId() {
	if (blocks.size() >= 1) {
		return blocks.top()->getId();
	}
	return -1;
}

bool Pole::popBlock(Block* block) {
	if (blocks.size() > 0 && blocks.top()->getId() == block->getId()) {
		blocks.pop();
		return true;
	}
	return false;
}

bool Pole::pushBlock(Block* block) {
	if (ifCanPush(block)) {
		block->setPoleId(id);
		blocks.push(block);
		return true;
	}
	return false;
}

// -------------------    BLOCK ----------------------------

Hanoi::Hanoi(int num_blocks, int num_poles) {
	for (int i = 0; i < num_blocks; ++i) {
		Block b(i+1, 0, i);
		blocks.push_back(b);
	}
	for (int i = 0; i < num_poles; ++i) {
		Pole p(i);
		poles.push_back(p);
	}
	for (int i = blocks.size() - 1; i >= 0; --i) {
		poles[0].pushOnPole(&blocks[i]);
	}
}

// pole_1 - the pole we want to everything end up.
void Hanoi::solve(int which, int pole_1) {
	if (which > 0) {
		int where_to = 3 - pole_1 - blocks[which-1].getPoleId();
		solve(which-1, where_to);

		getBlockToPole(which, pole_1);

		solve(which-1, pole_1);
	} else {
		getBlockToPole(which, pole_1);
	}
}

bool Hanoi::getBlockToPole(int id_block, int id_pole) {
	if (id_block >= blocks.size() || id_block < 0 ||
			id_pole >= poles.size() || id_pole < 0) {
		return false;
	}
	if (poles[blocks[id_block].getPoleId()].getTopBlockId() != id_block) {
		// Check if not the top: there is another block on top.
		return false;
	}
	if (poles[id_pole].getTopSize() > 0 &&
			poles[id_pole].getTopSize() < blocks[id_block].getSize()) {
		// Can't put on the next pole.
		return false;
	}
	cout << "get " << id_block << " from "
			<< blocks[id_block].getPoleId() << " to "
			<< id_pole << endl;
	poles[blocks[id_block].getPoleId()].popBlock(&blocks[id_block]);
	poles[id_pole].pushBlock(&blocks[id_block]);
	return true;
}

void Hanoi::printPoles() {
	for (int i = 0; i < blocks.size(); ++i) {
		cout << blocks[i].getId() << " na " << blocks[i].getPoleId()
				<< endl;
	}
	cout << endl;
}
