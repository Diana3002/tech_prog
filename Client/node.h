#ifndef NODE_H
#define NODE_H
#include <vector>

using namespace std;


class Node
{
public:
    int info; // Узел содержит целое число
    Node* parent; // Указатель на родительский узел
    vector <Node*> childs; // Массив детей
    Node(int info);
    Node();



};

#endif // NODE_H
