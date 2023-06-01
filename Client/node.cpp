#include "node.h"

Node::Node(int info) // Node:: Всегда ставится перед методом, который он реализует
{
    this->info = info;
    this->parent = nullptr;

}
Node::Node()
{



}
