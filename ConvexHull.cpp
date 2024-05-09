#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <fstream>

using namespace std;

//take the point with  smallest y
#define fori(i,n) for(int i=0;i<n;i++)
#define forj(j,n) for (int j=0; j<n;j++)
#define pb push_back

struct point{
  double x;
  double y;
  double angulo;
  point(double a, double b){
    this->x = a;
    this->y = b;
  }
};

double angle(point A, point B){
    return atan2(B.y - A.y, B.x - A.x);
}

bool SortP(point const& p1, point const& p2){
  return p1.angulo < p2.angulo;
}

double orientation(point const& A, point const& B, point const& C){
  return (B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y);
}

double vetProduct(point A, point B){
  //produto vetorial
  return (-1)*(A.x * B.y - B.x * A.y);
}
point next_to_top(stack<point>& Stack){
  point top = Stack.top(); Stack.pop();
  point nextTop = Stack.top();
  Stack.push(top);
  return nextTop;
}

void ConvexHull(vector<point>& P){
  stack<point> convexHull;
  int bot = 0;
  int mid = 1;
  int top = 2;
  convexHull.push(P[bot]);
  convexHull.push(P[mid]);
  convexHull.push(P[top]);
  int n = P.size();

  //se fizer uma curva pra esquerda, coloca na pilha
  for(int i=3;i<n;i++){
    while(orientation(next_to_top(convexHull), convexHull.top(), P[i]) < 0){
      convexHull.pop();
    }
    convexHull.push(P[i]);
  }
  
  ofstream arquivo("output.txt");
  if(!arquivo.is_open()){
    cout << "erro ao abrir arquivo" << endl;
  }

  arquivo << P[P.size()-1].x << " " << P[P.size()-1].y << endl;
  int a = 1;

  while(!convexHull.empty()){
    if(a>1)
      arquivo << endl;
    a++;
    point p = convexHull.top();
    arquivo << p.x << " " << p.y;
    convexHull.pop();
  }
}

int main(){

  ifstream arquivo("input.txt"); 
  if (!arquivo.is_open()) { 
        cout << "Erro ao abrir o arquivo." << endl;
        return 1;
  }
  vector<point> P;  
  double x,y;  
  
  while(arquivo >> x >> y){
    P.push_back({x,y});
  }
  int n = P.size();
  int indexLessP=0;
  //encontro o ponto mais baixo -> ta ok
  fori(i,n){
    if(P[i].y < P[indexLessP].y)
	    indexLessP = i;
  }

  point Less = P[indexLessP];
  point aux = {Less.x - 10,Less.y};

  //calculo o angulo polar para todo ponto
  fori(i,n){
    P[i].angulo = angle(Less, P[i]);
    //cout << "ponto(" << P[i].x << "," << P[i].y << "):" << vetProduct(P[indexLessP], P[i]) << endl;
  }
  
  //ordeno por angulo polar
  sort(P.begin(), P.end(), &SortP);

  ConvexHull(P);
}














