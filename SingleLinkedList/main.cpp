#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;
#include "list.cpp"
int main()
{
    list linked;
    srand(time(0));
    for(int i = 0;i<22;i++)
    {
    
    int r = rand()%100 +1;
    stringstream st;
    st << "A" << i;
    string result = st.str();
    stock s(result,r);
    linked.AddNode(s);
    }
    cout << "Original List: "<<endl;
    linked.printList();
    cout << "\n";
    linked.getMiddleNode();
    cout << "\n";
    linked.splitList();
    return 0;
};