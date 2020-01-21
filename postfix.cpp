#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

/*
INPUT
7 4 - 5 *
3 2 4 * +
3 4 2 - *
42 7 - 3 * 2 4 + *
5 3 5 - * 11 2 - 1 * -
#
*/

/*
OUTPUT
15 -15 15
11 10 10
6 2 4
630 -412 630
-19 41 3
*/

int main() {
    string d, data;
    int x, y;
    stack<int> stacc;
    queue<int> qiu;
    priority_queue<int, vector<int>, greater<int> > prioriti;

    getline(cin, data);
    while (data != "#")
    {
        stringstream ss1;
        ss1 << data;
        while (ss1 >> d)
        {
            if (d == "+")
            {
                x = stacc.top();
                stacc.pop();
                y = stacc.top();
                stacc.pop();
                stacc.push(y + x);
            }
            else if (d == "-")
            {
                x = stacc.top();
                stacc.pop();
                y = stacc.top();
                stacc.pop();
                stacc.push(y - x);
            }
            else if (d == "*")
            {
                x = stacc.top();
                stacc.pop();
                y = stacc.top();
                stacc.pop();
                stacc.push(y * x);
            }
            else
            {
                stacc.push(stoi(d));
            }
        }

        cout << stacc.top() << " ";
        stacc.pop();

        stringstream ss2;
        ss2 << data;
        while (ss2 >> d)
        {
            if (d == "+")
            {
                x = qiu.front();
                qiu.pop();
                y = qiu.front();
                qiu.pop();
                qiu.push(y + x);
            }
            else if (d == "-")
            {
                x = qiu.front();
                qiu.pop();
                y = qiu.front();
                qiu.pop();
                qiu.push(y - x);
            }
            else if (d == "*")
            {
                x = qiu.front();
                qiu.pop();
                y = qiu.front();
                qiu.pop();
                qiu.push(y * x);
            }
            else
            {
                qiu.push(stoi(d));
            }
        }

        cout << qiu.front() << " ";
        qiu.pop();

        stringstream ss3;
        ss3 << data;
        while (ss3 >> d)
        {
            if (d == "+")
            {
                x = prioriti.top();
                prioriti.pop();
                y = prioriti.top();
                prioriti.pop();
                prioriti.push(y + x);
            }
            else if (d == "-")
            {
                x = prioriti.top();
                prioriti.pop();
                y = prioriti.top();
                prioriti.pop();
                prioriti.push(y - x);
            }
            else if (d == "*")
            {
                x = prioriti.top();
                prioriti.pop();
                y = prioriti.top();
                prioriti.pop();
                prioriti.push(y * x);
            }
            else
            {
                prioriti.push(stoi(d));
            }
        }

        cout << prioriti.top() << endl;
        prioriti.pop();

        getline(cin, data);
    }
}
