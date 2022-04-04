#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int cases, C, M, Y, K, C1, M1, Y1, K1, C2, M2, Y2, K2;
    int Cm, Mm, Ym, Km;
    int t = 1000000;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        cin >> C >> M >> Y >> K >> C1 >> M1 >> Y1 >> K1 >> C2 >> M2 >> Y2 >> K2;

        vector<int> vecC = {C, C1, C2};
        vector<int> vecM = {M, M1, M2};
        vector<int> vecY = {Y, Y1, Y2};
        vector<int> vecK = {K, K1, K2};

        Cm = *min_element(vecC.begin(), vecC.end());
        Mm = *min_element(vecM.begin(), vecM.end());
        Ym = *min_element(vecY.begin(), vecY.end());
        Km = *min_element(vecK.begin(), vecK.end());

        int sum = Cm + Mm + Ym + Km;

        if (sum == t)
        {
            cout << "Case #" << i + 1 << ": " << Cm << " " << Mm << " " << Ym << " " << Km << endl;
        }
        else if (sum < t)
        {
            cout << "Case #" << i + 1 << ": "<< "IMPOSSIBLE" << endl;
        }
        else if (sum > t)
        {
            int pre = sum - t;
            int state = pre;

            vector<int> fin = {Cm, Mm, Ym, Km};

            // cout << "state "<<state<<endl;
            // cout << fin[0] << " " << fin[1] << " " << fin[2] << " " << fin[3] << endl;
            // cout <<"state- el fin: "<<state-fin[0]<<endl;
            for (int i = 0; i < fin.size() - 1; i++)
            {

                if (fin[i] > state)
                {
                    fin[i] = fin[i] - state;
                    break;
                }
                else
                {
                    int prev = fin[i];
                    fin[i] = fin[i] - state;
                    if (fin[i] < 0)
                    {
                        fin[i] = 0;
                    }
                    state = state - prev;
                }
            }
            cout << "Case #" << i + 1 << ": " << fin[0] << " " << fin[1] << " " << fin[2] << " " << fin[3] << endl;
        }
    }
    return 0;
}