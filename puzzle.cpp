#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
using namespace std;

class Item {
public:
	int x;
	int y;
	vector<vector<int> > mapa;
	
	Item();
	Item(int x, int y, vector<vector<int> >& mapa){
		this->x = x;
		this->y = y;
		this->mapa = mapa;
	}
};

bool check(vector<vector<int> > &mapa) {
	bool ret = true;
	int cont = 1;
	for(int i = 0; i  < mapa.size(); i++){
		for(int j = 0; j < mapa[i].size(); j++){
			if(!(i == mapa.size()-1 && j == mapa[i].size()-1)) {
				if(mapa[i][j] != cont)
					ret = false;
			}
			
			//cout << mapa[i][j] << " ";
			cont++;
		}
		//cout << endl;
	}
	//cout << endl;
	return ret;
}

int bfs(int x, int y, vector<vector<int> > &mapa) {
	int size_x = mapa[0].size();
	int size_y = mapa.size();
	
	map<vector<vector<int> >, bool> visitado;
	
	int dx[] = {-1, 1,  0, 0};
	int dy[] = { 0, 0, -1, 1};
	
	queue<pair<Item, int>> fila;
	fila.push({Item(x, y, mapa),0});
	
	while(!fila.empty()) {
		pair<Item,int> front = fila.front();
		fila.pop();
		visitado[front.first.mapa] = true;
		x = front.first.x;
		y = front.first.y;
		
		if(check(front.first.mapa)) {
			return front.second;
		}
		
		for(int i = 0; i < 4; i++){
			int _x = x + dx[i];
			int _y = y + dy[i];
			if(_x < size_x && _y < size_y && _x >= 0 && _y >= 0){
				vector<vector<int> > aux = front.first.mapa;
				//cout << aux[y][x] << " " << aux[_y][_x];
				//getchar();
				int tmp = aux[y][x];
				aux[y][x] = aux[_y][_x];
				aux[_y][_x] = tmp;
								
				if(!visitado[aux])
					fila.push({Item(_x, _y, aux), front.second+1});
			}
		}
	}
}

int main() {
	vector<vector<int> > vec = {{0,1,2},{5,6,3},{4,7,8}};
	cout << bfs(0,0, vec) << endl;
}

