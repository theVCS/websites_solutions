vector <ll> phi;

// void init()
// {
//     for (ll i = 0; i < maxN; i++)
//     {
//         phi.push_back(i);
//     }

//     for (ll i = 2; i < maxN; i++)
//     {
//         if (phi[i] == i)
//         {
//             for (ll j = i; j < maxN; j += i)
//             {
//                 phi[j] /= i;
//                 phi[j] *= i - 1;
//             }
//         }
//     }
// }