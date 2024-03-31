#include <iostream>
#include <deque>
using namespace std;

// void Rotate(deque<int>& stability, deque<int>& human){
//     int st_fr = stability.front();
//     stability.pop_front();
//     stability.push_back(st_fr);

//     int hu_fr = human.front();
//     human.pop_front();
//     human.push_back(hu_fr);
// }

// void Walk(deque<int>& stability, deque<int>& human, int& n_zero){
//     for(int h=n-1;h>=0;h--){
//         if(human[h]==1){
//             if(h==n-1){
//                 human[h] = 0;
//             }
//             else{
//                 if(human[h+1]==0 && stability[h+1]>0){
//                     human[h] = 0;
//                     human[h+1] = 1;
//                     stability[h+1]--;
//                     if(stability[h+1]==0){
//                         n_zero++;
//                     }
//                 }
//             }
//         }
//     }
// }

// void Onboard(deque<int>& stability, deque<int>& human, int&n_zero){
//     if(stability[0]>0 && human[0]==0){
//         human[0] = 1;
//         stability[0]--;
//         if(stability[0]==0){
//             n_zero++;
//         }
//     }
// }

int main(){
    int n, k;
    cin >> n;
    cin >> k;
    deque<int> stability(2*n);
    for(int i=0;i<2*n;i++){
        cin >> stability[i];
    }

    deque<int> human(n);

    int n_zero = 0;
    int n_trial = 0;

   do{
        int st_bk = stability.back();
        stability.pop_back();
        stability.push_front(st_bk);
        int hu_bk = human.back();
        human.pop_back();
        human.push_front(hu_bk);

        for(int h=n-1;h>=0;h--){
            if(human[h]==1){
                if(h==n-1){
                    human[h] = 0;
                }
                else{
                    if(human[h+1]==0 && stability[h+1]>0){
                        human[h] = 0;
                        human[h+1] = 1;
                        stability[h+1]--;
                        if(stability[h+1]==0){
                            n_zero++;
                        }
                    }
                }
            }
        }

        if(stability[0]>0 && human[0]==0){
            human[0] = 1;
            stability[0]--;
            if(stability[0]==0){
                n_zero++;
            }
        }

        n_trial++;

    }while(n_zero < k);

    cout << n_trial;

    return 0;
}