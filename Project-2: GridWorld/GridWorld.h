#ifndef _GRID_WORLD_H
#define _GRID_WORLD_H
#include <vector>
#include <iostream>

using std::vector;

class Node 
{
private:
    int ID;
public:
    Node* next;
    Node* prev;
    Node(int id, Node * _next = nullptr, Node* _prev = nullptr)
    {
        ID = id;
        next = _next;
        prev = _prev;
    }

    int getId()
    {
        return ID;
    }
};

//use for the person array
class Person 
{
private:
    int Id;
    
public:
    int _row;
    int _col;
    Node* nike = nullptr;
    bool isAlive = false;
    Person(int id, int row, int col, Node* _nike, bool _isAlive)
    {
        Id = id;
        _row = row;
        _col = col;
        nike = _nike;
        isAlive = _isAlive;
    }

    int get_row()
    {
        return _row;
    }

    void set_row(int row)
    {
        _row = row;
    }
	
	int get_col()
    {
        return _col;
    }
	
	void set_col(int col)
    {
        _col = col;
    }

    int getPId()
    {
        return Id;
    }
};

//used for doubly linked list
struct List 
{
    Node* front = nullptr;
    Node* back = nullptr;
    int gridSize = 0;
};

class GridWorld
{

private:

    List** GridWorldArray;
    int personalID;
    int _nrows;
    int _ncols;
    int _size;
    vector<Person> love;
    List deadPool;

    bool junk_node(List* list, Node* node)
    {
        if (list->front != nullptr)
        {
            if(node == list->front || node == list->back)
            {
                if (node == list->front && node == list->back)
                {
                    list->front = list->back = nullptr;
                }
                else if (node == list->front)
                {
                    list->front = node->next;
                    list->front->prev = nullptr;
                }
                else
                {
                    list->back->prev->next = nullptr;
                    list->back = node->prev;
                }
            }
            else
            {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }
            node->next = nullptr;
            node->prev = nullptr;
            list->gridSize--;
            return true;
        }
        return false;
    }

public:
    GridWorld(unsigned nrows, unsigned ncols)   
    {
        GridWorldArray = new List*[nrows];
        for (int i = 0; i < nrows; GridWorldArray[i] = new List[ncols], i++);
        personalID = 0;
        _size = 0;
        _nrows = nrows;
        _ncols = ncols;
    }
    ~GridWorld()
    {
        for (int i = 0; i < _nrows; delete[] GridWorldArray[i], i++);
        delete[] GridWorldArray;
    }


    //runtime of O(1)
    bool birth(int row, int col, int &id){

        if (row < 0 || row >= _nrows || col < 0 || col >= _ncols)
        {
            return false;
        }

        if (deadPool.gridSize != 0)
        {
            Node* temp1 = deadPool.front;
            id = temp1->getId();
            Node* temp2 = new Node(deadPool.front->getId(), nullptr, nullptr);;
            GridWorldArray[row][col].gridSize++;

            if (GridWorldArray[row][col].front != nullptr)
            {
                GridWorldArray[row][col].back->next = temp2;
                temp2->prev = GridWorldArray[row][col].back;
                GridWorldArray[row][col].back = temp2;
            }
            else
            {
                GridWorldArray[row][col].front = GridWorldArray[row][col].back = temp2;
            }
            love[id] = Person(id, row, col, GridWorldArray[row][col].back, true );
            if(!junk_node(&deadPool, temp1))
            {
                return false;
            }
            _size++;

        }
        else
        {
            Node *chhavi = new Node(personalID, nullptr, nullptr);
            GridWorldArray[row][col].gridSize++;
            if (GridWorldArray[row][col].front != nullptr)
            {
                GridWorldArray[row][col].back->next = chhavi;
                chhavi->prev = GridWorldArray[row][col].back;
                GridWorldArray[row][col].back = chhavi;
            }
            else
            {
                GridWorldArray[row][col].front = GridWorldArray[row][col].back = chhavi;
            }
            id = personalID;
            love.push_back( Person(id, row, col, GridWorldArray[row][col].back, true) );
            personalID++;
            _size++;   
        }

        return true;
    }

    bool death(int personID)
    {
        if (personID >= love.size() || personID < 0 || love.size() == 0)
        {
            return false;
        }

        Person* hiral = &love[personID];

        if (!hiral->isAlive)
        {
            return false;
        }
        else
        {
            if(!junk_node(&GridWorldArray[hiral->get_row()][hiral->get_col()], hiral->nike))
            {
                return false;
            }
            delete hiral->nike;
            Node *temp1 = new Node(hiral->getPId(), nullptr, nullptr);
            deadPool.gridSize++;

            if (deadPool.front == nullptr)
            {
                deadPool.front = deadPool.back = temp1;
            }
            else
            {
                deadPool.back->next = temp1;
                temp1->prev = deadPool.back;
                deadPool.back = temp1;
            }
            hiral->isAlive = false;
            _size--;
        }

        return true;
    }

    bool whereis(int id, int &row, int &col)const
    {
        if (id >= 0 && _size > 0 && id < love.size() && love[id].isAlive == true)
        {
            row = love[id]._row;
            col = love[id]._col;
            return true;
        }
        return false;
    }

    //runtime of O(1)

    bool move(int id, int targetRow, int targetCol)
    {

        if (id >= love.size() || id < 0 || love.size() == 0
            || targetRow < 0 || targetRow >= _nrows || targetCol < 0
            || targetCol >= _ncols)
        {
            return false;
        }

        Person* temp = &love[id];

        if (temp->isAlive == false || GridWorldArray[temp->get_row()][temp->get_col()].front == nullptr)
        {
            return false;
        }
        if (temp->nike == GridWorldArray[temp->get_row()][temp->get_col()].front && temp->nike == GridWorldArray[temp->get_row()][temp->get_col()].back)
        {
            GridWorldArray[temp->get_row()][temp->get_col()].front = GridWorldArray[temp->get_row()][temp->get_col()].back = nullptr;
        }
        else if (temp->nike == GridWorldArray[temp->get_row()][temp->get_col()].front)
        {
            GridWorldArray[temp->get_row()][temp->get_col()].front = temp->nike->next;
            GridWorldArray[temp->get_row()][temp->get_col()].front->prev = nullptr;
        }
        else if (temp->nike == GridWorldArray[temp->get_row()][temp->get_col()].back)
        {
            GridWorldArray[temp->get_row()][temp->get_col()].back->prev->next = nullptr;
            GridWorldArray[temp->get_row()][temp->get_col()].back = temp->nike->prev;
        }
        else
        {
            temp->nike->prev->next = temp->nike->next;
            temp->nike->next->prev = temp->nike->prev;
        }
        temp->nike->next = nullptr;
        temp->nike->prev = nullptr;
        GridWorldArray[temp->get_row()][temp->get_col()].gridSize--;

        if (GridWorldArray[targetRow][targetCol].front != nullptr)
        {
            GridWorldArray[targetRow][targetCol].back->next = temp->nike;
            (temp->nike)->prev = GridWorldArray[targetRow][targetCol].back;
            GridWorldArray[targetRow][targetCol].back = temp->nike;
            (temp->nike)->next = nullptr;
            GridWorldArray[targetRow][targetCol].gridSize++;
        }

        else
        {
            GridWorldArray[targetRow][targetCol].front = GridWorldArray[targetRow][targetCol].back = (temp->nike);
            (temp->nike)->next = nullptr;
            (temp->nike)->prev = nullptr;
            GridWorldArray[targetRow][targetCol].gridSize++;
        }

        temp->set_row(targetRow);
        temp->set_col(targetCol);
        return true;
    }

    //runtime of O(N(r,c)) where N is the population of that district
    std::vector<int> * members(int row, int col)const
    {
        if (row < 0 || row >= _nrows || col < 0 || col >= _ncols)
        {
            return nullptr;
        }
        vector<int> *result = new vector<int>();
        for(Node* temp = GridWorldArray[row][col].front; temp != nullptr; result->push_back(temp->getId()), temp = temp->next);
        return result;
    }

    int population()const
    {
      return _size;
    }

    //runtime of O(1)
    int population(int row, int col)const
    {
        if (row < 0 || row >= _nrows || col < 0 || col >= _ncols)
        {
            return 0;
        }
        return GridWorldArray[row][col].gridSize;
    }

    //runtime of O(1)
    int num_rows()const
    {
      return _nrows;
    }

    //runtime of O(1)
    int num_cols()const
    {
      return _ncols;
    }
};

#endif