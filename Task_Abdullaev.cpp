#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// ������� ��� �������� ������� ����� ���������� � �����
bool hasHamiltonianCycle(const vector<vector<int>>& graph, vector<int>& path, unordered_set<int>& visited, int currentVertex, int numVisited) {
    if (numVisited == graph.size()) {
        // ��� ������� ���� ��������
        if (graph[currentVertex - 1][path[0] - 1] == 1) {
            // ��������� ������� ������� � ���������, ���� ���������� ������
            path.push_back(path[0]);
            return true;
        }
        else {
            return false;
        }
    }

    for (int nextVertex = 1; nextVertex <= graph.size(); ++nextVertex) {
        if (graph[currentVertex - 1][nextVertex - 1] == 1 && visited.find(nextVertex) == visited.end()) {
            // ���� ���� ����� ����� ������� �������� � ��������� ������������ ��������
            visited.insert(nextVertex);
            path.push_back(nextVertex);

            if (hasHamiltonianCycle(graph, path, visited, nextVertex, numVisited + 1)) {
                // ������ ���� ����������
                return true;
            }

            // ���� �� ������ ���� ����������, ������� ��������� ����������� ������� � ���������� �����
            visited.erase(nextVertex);
            path.pop_back();
        }
    }

    return false;
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");
    int numVertices;
    cout << "������� ���������� ������ � �����: ";
    cin >> numVertices;

    vector<vector<int>> graph(numVertices, vector<int>(numVertices, 0));

    int numEdges;
    cout << "������� ���������� ����� � �����: ";
    cin >> numEdges;

    cout << "������� ����� � ������� (�������1 �������2):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        graph[vertex1 - 1][vertex2 - 1] = 1;
        graph[vertex2 - 1][vertex1 - 1] = 1;
    }

    vector<int> path;
    unordered_set<int> visited;
    bool foundCycle = false;

    for (int startVertex = 1; startVertex <= numVertices; ++startVertex) {
        visited.insert(startVertex);
        path.push_back(startVertex);

        if (hasHamiltonianCycle(graph, path, visited, startVertex, 1)) {
            cout << "���� �������� ���� ����������." << endl;
            cout << "����: ";
            for (int vertex : path) {
                cout << vertex << " ";
            }
            cout << endl;
            foundCycle = true;
            break;
        }

        visited.erase(startVertex);
        path.pop_back();
    }

    if (!foundCycle) {
        cout << "���� �� �������� ���� ����������." << endl;
    }

    return 0;
}