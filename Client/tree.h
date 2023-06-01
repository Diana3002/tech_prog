#ifndef TREE_H
#define TREE_H
#include <vector>
#include "node.h"

using namespace std;

class Tree
{
public:
    Node* root; //Ссылка на корень дерева
    int n; // Количество узлов в дереве
    vector <Node*> listiks;
    vector <int> prufer;

    Tree();
    Tree (Node* root);//Конструктор с параметром
    void Add(Node* parent, Node* child); // К родителю нужно добавить ребёнка, это значит, что мы должны внести его в вектор детей родителя
};

//Функция на вход которой подаётся вектор целых чисел, она ищет минимальное из отсутствующих
// Вункция возвращает это отсутствующее числа
int find_min_absent(vector <int> v);
//Функция создаёт список смежности из кода Прюфера, на вход подаётся вектор целых чисел, на выход подаётся вектор векторов целых чисел
vector <vector <int>> get_smeg_by_cod_prufer(vector <int> v);
void print_smeg(vector <vector <int>> smeg);
//Проверяет на наличие данное значение в векторе, если есть, то возвращает True
bool is_in_using(vector <int> using_nodes, int ind);
void create_by_smeg(vector <vector <int>> smeg, vector <int> using_nodes, Tree& tree, Node* p);// Поскольку дерево будем меняится, ставим имперсанд (ссылка), и передаём по адресу
Tree& create_tree_by_list_of_smeg(vector <vector <int>> smeg, int root_info);
// Главная программа Декодера
Tree create_tree_by_cod_prufer(vector <int> prufer); //Эта программа по коду Прюфера строит дерево

#endif // TREE_H
