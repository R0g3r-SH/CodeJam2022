#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int cases, ndice;
    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        cin >> ndice;
        vector<int> dices(ndice);
        for (int i = 0; i < ndice; i++)
        {
            cin >> dices[i];
        }
        sort(dices.begin(), dices.end());
        int counter = 1;
        for (auto x : dices)
        {
            if (x >= counter)
            {
                counter += 1;
            }
        }
        counter -= 1;
        cout << "Case #" << i + 1 << ": " << counter << endl;
        dices.clear();
    }

    return 0;
}