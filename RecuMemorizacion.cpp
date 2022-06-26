#include <bits/stdc++.h>

#define Modulo ULLONG_MAX

using namespace std;

typedef unsigned long long Arreglo64;

Arreglo64 func(Arreglo64 a, Arreglo64 b, Arreglo64 c, map<vector<Arreglo64>, Arreglo64> &dp)
{
    vector<Arreglo64> key = {a, b, c};
    if (dp.find(key) != dp.end())
    {
        return dp[key];
    }

    Arreglo64 NMinimo = min(min(a, b), c);
    Arreglo64 Valor = 0;

    if (NMinimo <= 3)
    {
        Valor = (a % Modulo) + (((2) * (b % Modulo)) % Modulo) + ((3) * (c % Modulo) % Modulo);
    }
    else if ((a + b + c) == 100ULL)
    {
        Valor = 0;
    }
    else
    {
        Valor = ((func(a - 1, b - 1, c - 1, dp)) % Modulo) + (func(a, b - 3, c - 3, dp) % Modulo) + (func(a / 2, b, c, dp) % Modulo);
    }

    return dp[key] = Valor % Modulo;
}

int main()
{

    Arreglo64 a, b, c;
    cin >> a >> b >> c;

    map<vector<Arreglo64>, Arreglo64> dp;

    Arreglo64 result = func(a, b, c, dp);

    cout << result << " " << dp.size() << endl;

    return (0);
}