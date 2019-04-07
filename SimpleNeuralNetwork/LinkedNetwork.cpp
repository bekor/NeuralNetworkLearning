#include "pch.h"
#include "LinkedNetwork.h"


LinkedNetwork::LinkedNetwork()
{
	head = nullptr;
	tail = head;
}

void LinkedNetwork::AddToEnd(Layer value)
{
	auto node = CreateNode(value);

	if (head == nullptr) {
		head = node;
	}
	else if (head->next == nullptr) {
		head->next = node;
		node->prev = head;
	}
	else if (head->next != nullptr && tail != nullptr) {
		tail->next = node;
		node->prev = tail;
	}
	
	tail = node;
}

std::vector<Point> LinkedNetwork::RunNetwork(const std::vector<Point> input)
{
	auto current = head;
	std::vector<Point> output = input;
	while (current != nullptr) {
		output = current->layer.CalculateConvolution(output);
		current = current->next;
	}
	return output;
}

std::shared_ptr<Node> LinkedNetwork::CreateNode(Layer value)
{
	return std::make_shared<Node>(value);
}
