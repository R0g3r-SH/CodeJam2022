#include <iostream>
using namespace std;

int main()
{
    int cases, row, col;
    string top = "..+";
    string body = "\n..|";
    string body1 = "\n|.|";
    string sepa = "\n+-+";
    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        cin >> row >> col;
        cout<<"Case #"<<i+1<<":"<<endl;
        if (row == 1 && col == 1)
        {
            cout << top << body << sepa;
            break;
        }
        for (int i = 0; i < col - 1; i++)
        {
            top.append("-+");
            body1.append(".|");
            body.append(".|");
            sepa.append("-+");
        }
        cout << top << body << sepa;
        if (row > 1)
        {
            for (int i = 0; i < row - 1; i++)
            {
                cout << body1 << sepa;
            }
        }
        cout << endl;
        top = "..+";
        body = "\n..|";
        body1 = "\n|.|";
        sepa = "\n+-+";
    }
    

    return 0;
}