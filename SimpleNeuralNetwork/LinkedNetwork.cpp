#include "pch.h"
#include "LinkedNetwork.h"


LinkedNetwork::LinkedNetwork()
{
	head = nullptr;
	tail = head;
}

void LinkedNetwork::AddToEnd(Layer value)
{
	auto current = head;
	if (current == nullptr) {
		auto node = CreateNode(value);
		head = node;
		tail = node;
	}
	else if (current->next == nullptr) {
		auto node = CreateNode(value);
		current->next = node;
		node->prev = current;
		tail = node;
	}
	else if (current->next != nullptr && tail != nullptr) {
		auto node = CreateNode(value);
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
}

std::vector<Point> LinkedNetwork::RunNetwork(const std::vector<Point> input)
{
	auto current = head;
	std::vector<Point> output = input;
	while (current != nullptr) {
		output = current->layer.OutputConvolution(output);
		current = current->next;
	}
	return output;
}

std::shared_ptr<Node> LinkedNetwork::CreateNode(Layer value)
{
	return std::make_shared<Node>(value);
}
