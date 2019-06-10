#pragma once
#include <memory>
#include "Layer.h"

struct Node
{
	std::weak_ptr<Node> prev;
	std::shared_ptr<Node> next;
	Node() :layer(Layer()) {};
	Node(Layer l) : layer(l) {};

	Layer layer;
};

