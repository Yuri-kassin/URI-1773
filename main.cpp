#include<iostream>
#include<vector>
#include<queue>
#include <cstdlib>

using namespace std;

vector< vector<int> > g; // Lista de Adjac�ncia

vector<int> fechado;
int *chave;


int bfs(int inicio)
{
//    cout<<"começou"<<endl;
    int aux = g.size()-1;
//    cout<<"aux começou assim "<<aux<<endl;

    vector<bool> cor(g.size(), false);
    vector<bool> tentando(g.size(), false);
    vector<bool> chaveiro(g.size(), false);
    queue<int> Q;

    cor[inicio] = true;

    Q.push(inicio);


    while(!Q.empty())
    {
        aux--;
//        cout<<"aux agora ta assim "<<aux<<endl;
        int u = Q.front();
        Q.pop();
//        cout<<"vertice atual: "<<u<<endl;
        chaveiro[u]=false ;
        for(int i = 2; i<g.size();i++){
            if(chave[i] == u){
                chaveiro[i] = true;

//                cout<<"entrou a chave "<<i<<endl;


            }
//            if(tentando[i]==true && cor[i] == false){
            if(tentando[i]==true && chaveiro[i]==true){
//                cout<<"foiii "<<i<<endl;
//                tentando[i] = false;
                Q.push(i);
                chaveiro[i]=false;
            }
        }
//        cout<<u<<" tem "<<g[u].size()<<" elementos"<<endl;
        for(int i = 0; i < g[u].size(); i++)
        {


            if(cor[g[u][i]] == false && chaveiro[g[u][i]] == true)
            {
//                cout<<g[u][i]<<endl;
                if(tentando[g[u][i]] == false)Q.push(g[u][i]);
                cor[g[u][i]] = true;
            }
            else if(cor[g[u][i]] == false){
//                fechado.push_back(g[u][i]);

                tentando[g[u][i]]=true;
//                cout<<"tentou "<<g[u][i]<<" logooo  "<<tentando[g[u][i]]<<endl;
//                cout<<"fechado "<<g[u][i]<<endl;
            }

        }


    }
//    cout<<"saiu "<<aux<<endl;
//    for(it = cor.begin()+1; it!=cor.end(); it++){
        if(aux == 0) return 1;
 //   }
//    cout<<"opss"<<endl;
    else return 0;
}


int main()
{
    int N,M;
    int x, y, vertice = 1;

    while(cin>>N>>M) {
        chave = new int[N+1];
        g.clear();
        g.resize(N + 1);

        for (int i = 0; i < M; i++) {
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x); //Em seguida haverá M linhas contendo dois inteiros A e B cada, indicando que há um corredor que liga a sala A e B, o qual pode ser atravessado em ambas as direções (1 ≤ A, B ≤ N).
        }
        for(int i = 2; i<=N; i++)cin>>chave[i];
        
        if(bfs(vertice) == 0) cout<<"nao"<<endl;
        else cout<<"sim"<<endl;
    }
    return 0;
}
