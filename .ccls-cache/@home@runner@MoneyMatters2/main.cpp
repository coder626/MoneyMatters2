#include <iostream>
#include <unordered_map>
#include <iterator>
#include <cstring>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cassert>
using namespace std;

 int balanceList[10000];

  bool visitedArray[10000];

  vector<vector<int>> adjList(10000);

int depthFirstSearch(int node){
  int total = 0;
  if(visitedArray[node] == true){
    return 0;
  }
  total = total + balanceList[node];
  visitedArray[node] = true;

  for(int i = 0; i < adjList[node].size(); i++){
      total = total + depthFirstSearch(adjList.at(node).at(i));
  }
  return total;
}

int main() {

  //tester code, comment out on Kattis
  ifstream cin("input.txt");
  ifstream textFile;
  textFile.open("input.txt");
  if(textFile.fail()){
    cout << "File Open Failed";
    return 0;
  }


  
  int a;
  int b;
  cin >> a >> b;

  for(int i = 0; i < a; i++){
    int value;
    cin >> value;
    balanceList[i] = value;
    visitedArray[i] = false;
  }

  for(int i = 0; i < b; i++){
    int c;
    int d;
    cin >> c >> d;
    adjList[d].push_back(c);
    adjList[c].push_back(d);
  }

  for(int i = 0; i < a; i++){
    if(visitedArray[i] == false){
      if(depthFirstSearch(i) != 0){
        cout << "IMPOSSIBLE";
        return 0;
      }
    
  }
    }

cout << "POSSIBLE";
  return 0;

  
  
}