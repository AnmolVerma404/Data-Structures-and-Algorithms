#include <bits/stdc++.h>

using namespace std;

class MinHeap
{
public:
    int *harr;
    int capacity;
    int heap_size;

    MinHeap(int cap)
    {
        heap_size = 0;
        capacity = cap;
        harr = new int[cap];
    }

    void linearSearch(int val)
    {
        for (int i = 0; i < heap_size; ++i)
        {
            if (harr[i] == val)
            {
                cout << "Value Found!";
                return;
            }
        }
        cout << "Value Not Found!";
    }

    void printArray()
    {
        for (int i = 0; i < heap_size; ++i)
        {
            cout << harr[i] << " ";
        }
        cout << "\n";
    }

    int height()
    {
        return ceil(log2(heap_size + 1)) - 1;
    }
};

int main()
{
    int s;
    cout << "Enter Size of Min Heap" << endl;
    cin >> s;
    MinHeap obj(s);
    cout << "Min Heap Created" << endl;

    int option, val;
    do
    {
        cout << "What operation do you want to perform? "
             << " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert Key/Node" << endl;
        cout << "2. Search Key/Node" << endl;
        cout << "3. Delete Key/Node" << endl;
        cout << "4. Get Min" << endl;
        cout << "5. Extract Min" << endl;
        cout << "6. Height of Heap" << endl;
        cout << "7. Print/Traversal Heap values" << endl;
        cout << "8. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "INSERT Operation -" << endl;
            cout << "Enter VALUE to INSERT in HEAP: ";
            cin >> val;
            // obj.insertKey(val);
            cout << endl;
            break;
        case 2:
            cout << "SEARCH Operation -" << endl;
            cout << "Enter VALUE to SEARCH in HEAP: ";
            cin >> val;
            obj.linearSearch(val);
            break;
        case 3:
            cout << "DELETE Operation -" << endl;
            cout << "Enter INDEX of Heap Array to DELETE: ";
            cin >> val;
            // obj.deleteKey(val);
            break;
        case 4:
            // cout << "GET Min value : " << obj.getMin();
            cout << endl;
            break;
        case 5:
            // cout << "EXTRACT Min value : " << obj.extractMin();
            cout << endl;
            break;
        case 6:
            cout << "HEAP TREE HEIGHT : " << obj.height() << endl;
            break;

        case 7:
            cout << "PRINT Heap Array : " << endl;
            obj.printArray();

            cout << endl;
            break;

        case 8:
            system("cls");
            break;

        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}