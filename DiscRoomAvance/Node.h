#pragma once
#include "CSprite.h"

ref class Node {
public:
	CSprite^ disc;
	Node^ next;
	Node(CSprite^ disco, Node^ next): disc(disco), next(next) {}
};

