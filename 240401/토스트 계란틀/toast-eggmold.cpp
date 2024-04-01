#include <iostream>
#include <deque>
#include <tuple>
using namespace std;

//20240331 13:21 -- 14:21 / 20240401 10:50 -- 

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int main() {
    int n, L, R;
    cin >> n >> L >> R;

    int arr[52][52];
    int marked[52][52];
    for(int j=0;j<52;j++){
        for(int i=0;i<52;i++){
            arr[j][i] = -500;
            marked[j][i] = 1;
        }
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
            cin >> arr[j][i];
            marked[j][i] = 0;
        }
    }

    bool hasmoved;
    int nloop = 0;
    do{
        hasmoved= false;

        for(int j=1;j<=n;j++){////
            for(int i=1;i<=n;i++){
                if(!marked[j][i]){
                    deque<tuple<int,int>> basket;
                    basket.push_back(tuple<int,int>(i,j)); //use tuple
                    // cout << "\n" << i << j << endl;
                    marked[j][i] = 1;
                    deque<tuple<int,int>>::iterator iter = basket.begin(); //set iterator

                    do{
                        int x,y;
                        tie(x,y) = *iter;
                        for(int k=0;k<4;k++){
                            if(x+dx[k] >= 1 && x+dx[k] <= n && y+dy[k] >= 1 && y+dy[k] <= n){
                                if(!marked[y+dy[k]][x+dx[k]] 
                                && abs(arr[y+dy[k]][x+dx[k]]-arr[y][x])>=L 
                                && abs(arr[y+dy[k]][x+dx[k]]-arr[y][x])<=R){
                                    basket.push_back(tuple<int,int>(x+dx[k],y+dy[k]));
                                    marked[y+dy[k]][x+dx[k]] = 1;
                                    // cout << x+dx[k] << y+dy[k] << " ";
                                    hasmoved = true;
                                }
                            }
                        }
                        iter++;
                    }while(iter!=basket.end());

                    int basket_sum = 0;
                    for(tuple<int,int> temp : basket){
                        int x,y;
                        tie(x,y) = temp;
                        basket_sum+=arr[y][x];
                    }
                    int basket_avg = basket_sum/basket.size();

                    for(tuple<int,int> temp : basket){
                        int x,y;
                        tie(x,y) = temp;
                        arr[y][x] = basket_avg;
                    }
                }
            }
        }
        
        if(hasmoved){
            nloop++;
            for(int j=1;j<=n;j++){ //init
                for(int i=1;i<=n;i++){
                    // cout << arr[j][i] << " ";
                    marked[j][i] = 0;
                }
                // cout << endl;
            }
        }
        // hasmoved=false;////
    }while(hasmoved);

    cout << nloop;

    return 0;
}


// #include <iostream>
// #include <deque>
// #include <tuple>
// using namespace std;

// //20240331 13:21 -- 14:21 / 20240401 10:50 -- 

// int dx[] = {-1,1,0,0};
// int dy[] = {0,0,-1,1};

// int main() {
//     int n, L, R;
//     cin >> n >> L >> R;

//     int arr[52][52];
//     int marked[52][52];
//     for(int j=0;j<52;j++){
//         for(int i=0;i<52;i++){
//             arr[j][i] = -500;
//             marked[j][i] = 1;
//         }
//     }
//     for(int j=1;j<=n;j++){
//         for(int i=1;i<=n;i++){
//             cin >> arr[j][i];
//             marked[j][i] = 0;
//         }
//     }

//     bool hasmoved;
//     int nloop = 0;
//     do{
//         hasmoved= false;

//         for(int j=1;j<=n;j++){
//             for(int i=1;i<=n;i++){
//                 if(!marked[j][i]){
//                     deque<tuple<int,int>> basket;
//                     basket.push_back(tuple<int,int>(i,j)); //use tuple
//                     marked[j][i] = 1;
//                     deque<tuple<int,int>>::iterator iter = basket.begin(); //set iterator

//                     do{
//                         int x,y;
//                         tie(x,y) = *iter;
//                         for(int k=0;k<4;k++){
//                             if(!marked[y+dy[k]][x+dx[k]] 
//                             && abs(arr[y+dy[k]][x+dx[k]]-arr[y][x])>=L 
//                             && abs(arr[y+dy[k]][x+dx[k]]-arr[y][x])<=R){
//                                 basket.push_back(tuple<int,int>(x+dx[k],y+dy[k]));
//                                 marked[y+dy[k]][x+dx[k]] = 1;
//                                 hasmoved = true;
//                             }
//                         }
//                         iter++;
//                     }while(iter!=basket.end());

//                     int basket_sum = 0;
//                     for(tuple<int,int> temp : basket){
//                         int x,y;
//                         tie(x,y) = temp;
//                         basket_sum+=arr[y][x];
//                     }
//                     int basket_avg = basket_sum/basket.size();

//                     for(tuple<int,int> temp : basket){
//                         int x,y;
//                         tie(x,y) = temp;
//                         arr[y][x] = basket_avg;
//                     }


//                 }
//             }
//         }
//         nloop++;
//     }while(hasmoved);

//     cout << nloop;

//     return 0;
// }