#include "tree.h"
#include "node.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <QDebug> // Распечатать консоль

using namespace std;




Tree::Tree()
{
    this->root = nullptr;
    this->n = 0;

}



Tree::Tree (Node* root)//Конструктор с параметром
{
    this->root = root;
    this->n = 1;

}
void Tree::Add(Node* parent, Node* child) // К родителю нужно добавить ребёнка, это значит, что мы должны внести его в вектор детей родителя
{
    parent->childs.push_back(child); //Добавили ребёнка в вектор родителя
    // У этого ребёнка нужно указать его родителя
    child->parent = parent;
    n++;


}






//Функция на вход которой подаётся вектор целых чисел, она ищет минимальное из отсутствующих
// Вункция возвращает это отсутствующее числа
int find_min_absent(vector <int> v)
{
    //В диапозоне размер вектора +2
    // В цикле 1 до последнего, если его нет, то возвращаем его
    for(int ind = 1;ind<=v.size()+2;ind++)
    {
        bool flag = false; //Если найдёт, то true
        for(int i = 0; i<v.size(); i++)
        {
            if(ind==v[i])
            {
                flag = true;
                break;

            }


        }
        if (!flag)
        {
            return ind;
        }

    }




}

//Функция создаёт список смежности из кода Прюфера, на вход подаётся вектор целых чисел, на выход подаётся вектор векторов целых чисел
vector <vector <int>> get_smeg_by_cod_prufer(vector <int> v)
{
    vector <vector <int>> smeg; //Это список смежности
    int N = v.size() + 2; //Число вершин дерева
    for (int i = 0; i<N; i++)
    {
        vector <int> a;
        smeg.push_back(a);



    }

    //Строем список смежности
    //1 Найдём минимальное в отсутсвующее в векторе v -ind +
    //2 Вычёркиваем из вектора v, первый элемент - front +
    //3 Запишем минимальное отсутсвующее в вектор v +
    //4 Добавить в вектор смежности соответствующие вершины +
    //5 Повторить цикл (размер вектора) раз +
    for(int i = 0; i<v.size();i++)
    {
        int ind = find_min_absent(v);
        int front = v[0];
        v.erase(v.begin()); //Удаляет первое число из вектора
        v.push_back(ind);
        smeg[ind-1].push_back(front);
        smeg[front-1].push_back(ind);


    }
    // Теперь добавим ребро из двух вершин, отсутствующих в текущем векторе v
    int first_absent = find_min_absent(v);
    v.push_back(first_absent);
    int second_absent = find_min_absent(v);
    smeg[first_absent - 1].push_back(second_absent);
    smeg[second_absent - 1].push_back(first_absent);

    return smeg;


}

void print_smeg(vector <vector <int>> smeg)
{
    cout << "---------------------Список смежности------------------------\n";
    for(int i = 0; i<smeg.size(); i++)
    {
        cout << i + 1 << ": ";
        for(int j = 0;j<smeg[i].size();j++)
        {
            cout << smeg[i][j] << " ";

        }
        cout << endl;


    }




}
//Проверяет на наличие данное значение в векторе, если есть, то возвращает True
bool is_in_using(vector <int> using_nodes, int ind)
{

    for(int i = 0; i<using_nodes.size();i++)
    {
        if(ind==using_nodes[i])
        {
            return true;

        }
    }
    return false;

}


void create_by_smeg(vector <vector <int>> smeg, vector <int> using_nodes, Tree& tree, Node* p)// Поскольку дерево будем меняится, ставим имперсанд (ссылка), и передаём по адресу
{
    if (using_nodes.size() == smeg.size()) // когда все узлы исользованны
    {
        return;
    }
    for(int i = 0; i < smeg[p->info-1].size(); i++) // p->info номер, который содержится в узле p
    {
        int ind = smeg[p->info - 1][i]; //Номер ребёнка
        //Проверим, использовался номер ребёнка или нет
        if (!is_in_using(using_nodes, ind))
        {
            Node* child = new Node(ind);
            tree.Add(p, child); //Строем ребро между родителем и ребёнком
            using_nodes.push_back(ind);
            create_by_smeg(smeg, using_nodes, tree, child);

        }

    }

}

//Создает дерево по списку смежности, проинимает так же информацию узла корня
Tree& create_tree_by_list_of_smeg(vector <vector <int>> smeg, int root_info)
{
    //1 Создать узел root. Создать дерево по этому узлу +
    //2 Звсести вектор, куда будем добавлять уже добавленные узлы. Добавить узел root
    //3 Пройтись по списку смежных и добавить детей, кроме самого узла
    //4 Повторить это для детей -: пройтись по списку смежных и добавлять детей, кроме всех уже добавленных узлов
    Node* root = new Node(root_info);
    Tree tree(root);

    vector <int> using_nodes; // вектор использованных узлов
    using_nodes.push_back(root_info);

    create_by_smeg(smeg, using_nodes, tree, root);
    return tree;
}


// Главная программа Декодера
Tree create_tree_by_cod_prufer(vector <int> prufer) //Эта программа по коду Прюфера строит дерево
{
    //1 получаем список смежности по коду Прюфера
    //2 По коду Прюфера формируем дерева
    vector <vector <int>> smeg;
    smeg = get_smeg_by_cod_prufer(prufer);
    print_smeg(smeg);
    Tree tree; // Создаём пустой объект дерева
    tree = create_tree_by_list_of_smeg(smeg,6); //Создаём дерево по списку смежности
    return tree;




}
