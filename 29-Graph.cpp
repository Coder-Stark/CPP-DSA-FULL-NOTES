//GRAPH

#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
  

//creation of graph                                        {T.C = O(N+E), S.C = O(N+E)}
class graph{
public:
    unordered_map<int , list<int>>adj;

    void addEdge(int u , int v , bool direction){
        //direction = 0 => undirected
        //direction = 1 => directed

        //create edge from u to v
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i : adj){
            cout<<i.first<<"->";
            for(auto j : i.second){
                cout<<j<<" , ";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n;
    cout<<"Enter the numbers of nodes : "<<endl;
    cin>>n;

    int m;
    cout<<"Enter the numbers of edges : "<<endl;
    cin>>m;

    graph g;
    for(int i = 0 ; i < m ; i++){
        int u , v;
        cout<<"Enter the value of u and v : "<<endl;
        cin>>u>>v;

        //creating an undirected graph
        g.addEdge(u , v , 0);
    }

    //print graph
    g.printAdjList();

    return 0;
}
/*output
Enter the numbers of nodes : 
5
Enter the numbers of edges : 
6
Enter the value of u and v : 
0 1
Enter the value of u and v : 
1 2
Enter the value of u and v : 
2 3
Enter the value of u and v : 
3 1
Enter the value of u and v : 
3 4
Enter the value of u and v : 
0 4 
4->3 , 0 , 
0->1 , 4 ,
1->0 , 2 , 3 ,
2->1 , 3 ,
3->2 , 1 , 4 ,
*/


//CREATING AND PRINTING                                 {T.C = O(N+M),S.C = O(N+M)}
#include <bits/stdc++.h> 
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    vector<int>ans[n];     //ans array store all adjacent nodes corresponds to index

    for(int i = 0 ; i < m ; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int>>adj(n);

    for(int i = 0 ; i < n ; i++){
        adj[i].push_back(i);

        //entering neighbour
        for(int j = 0 ; j < ans[i].size(); j++){
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
}
/*
Sample Input 1:
2
4 3
1 2
0 3
2 3
3 3
0 1
1 2
2 0
Sample Output 1:
0 3
1 2
2 1 3
3 0 2
0 1 2
1 0 2
2 0 1
*/


//BFS IN GRAPH                                               {T.C = O(V+E), S.C = O(V+E)}
#include <bits/stdc++.h> 
#include<vector>
#include<set>
#include<list>
#include<unordered_map>

void prepareAdjList(unordered_map<int,set<int>>&adjList,vector<pair<int, int>> &edges){
    for(int i = 0 ; i < edges.size() ; i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}
void bfs(unordered_map<int,set<int>>&adjList,unordered_map<int,bool>&visited,vector<int>&ans,int node){
    queue<int>q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        //store frontNode into ans
        ans.push_back(frontNode);

        //traverse all neighbours of frontNode
        for(auto i: adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int,set<int>>adjList;
    vector<int>ans;
    unordered_map<int,bool>visited;

    prepareAdjList(adjList,edges);

    //traverse all component of graph
    for(int i = 0 ; i < vertex ; i++){
        if(!visited[i]){
            bfs(adjList,visited,ans,i);
        }
    }
    return ans;
}
/*
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
0 1 3 2
*/


//DFS TRAVERSAL                                                                      {T.C = O(N+M),S.C = O(N+M)}
void dfs(unordered_map<int,list<int>>&adj, unordered_map<int,bool>&visited, vector<int>&component, int node){
    //ans store
    component.push_back(node);
    visited[node] = 1;

    //every connected node make recursive call
    for(auto i: adj[node]){
        if(!visited[i]){
            dfs(adj, visited, component, i);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    //prepare adjList
    unordered_map<int , list<int>>adj;
    for(int i = 0 ; i < edges.size() ; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>>ans;
    unordered_map<int,bool>visited;

    //traverse all component of graph
    for(int i = 0 ; i < V ; i++){
        if(!visited[i]){
            vector<int>component;
            dfs(adj, visited,component,i);
            ans.push_back(component);
        }
    }
    return ans;
}
/*
Sample Input 1:
5 4
0 2
0 1
1 2
3 4
Sample Output 1:
2
0 1 2
3 4
*/


//CYCLE DETECTION IN UNORDERED GRAPH                                                {T.C = O(N+M),S.C = O(N+M)}
//USING BFS
#include<unordered_map>
#include<queue>
#include<list>

bool isCyclicBFS(unordered_map<int, list<int>>&adj,unordered_map<int,bool>&visited , int src ){
    unordered_map<int,int>parent;
    parent[src] = -1;
    visited[src] = 1;
    queue<int>q;
    q.push(src);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto i : adj[front]){
            if(visited[i] == true && i != parent[front]){
                return true;
            }
            else if(!visited[i]){
                q.push(i);
                visited[i] = 1;
                parent[i] = front;
            }
        }
    }
    return false;
}         
      
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //create adjacancy list
    unordered_map<int, list<int>>adj;
    for(int i = 0 ; i < m ; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //handle all components of graph
    unordered_map<int,bool>visited;
    for(int i = 0 ; i < n ; i++){
        if(!visited[i]){
            bool ans = isCyclicBFS(adj , visited , i);
            if(ans == 1){
                return "Yes";
            }
        }
    }
    return "No";
}


//USING DFS
#include <unordered_map>
#include <vector>
#include <list>

using namespace std;

bool isCyclicDFS(unordered_map<int, list<int>>& adj, unordered_map<int, bool>& visited, int src, int parent) {
    visited[src] = true;

    for (auto i : adj[src]) {
        if (!visited[i]) {
            if (isCyclicDFS(adj, visited, i, src)) {
                return true;
            }
        }
        else if (i != parent) {
            return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m) {
    // Create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Handle all components of the graph
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bool ans = isCyclicDFS(adj, visited, i, -1);
            if (ans) {
                return "Yes";
            }
        }
    }
    return "No";
}

/*
Sample Input 1:
1
3 2
1 2
2 3
Sample Output 1:
No
*/


//DETECT CYCLE IN A DIRECTED GRAPH                                    {T.C = O(N+M),S.C = O(N+M)}
//USING DFS
#include<unordered_map>
#include<list>

bool checkCycleDFS(unordered_map<int,list<int>>&adj, unordered_map<int,bool>&visited, unordered_map<int,bool>&dfsVisited , int node ){
  visited[node] = true;
  dfsVisited[node] = true;

  for(auto i : adj[node]){
    if(!visited[i]){
      bool cycleDetected = checkCycleDFS(adj , visited , dfsVisited , i);
      if(cycleDetected){
        return true;
      }
    }
    else if(dfsVisited[i]){
      return true;
    }
  }
  dfsVisited[node] = false;
  return false;
}                              
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  //create adjacancy list
  unordered_map<int,list<int>>adj;

  for(int i = 0 ; i < edges.size(); i++){
    int u = edges[i].first;
    int v = edges[i].second;

    //directed graph so only 1 side push
    adj[u].push_back(v);
  }

  //handle all component
  unordered_map<int,bool>visited;
  unordered_map<int,bool>dfsVisited;

  for(int i = 0 ; i <= n ; i++){
    if(!visited[i]){
      bool cycleFound = checkCycleDFS(adj , visited, dfsVisited , i);
      if(cycleFound){
        return true;
      }
    }
  }
  return false;
}
/*
Sample Input 1 :
1
5
6
1 2
4 1
2 4
3 4
5 2
1 3
Sample Output 1 :
true
*/


//TOPOLOGICAL SORT                                                          {T.C = O(N+M),S.C = O(N+M)}
#include <bits/stdc++.h> 

void topoSort(unordered_map<int, list<int>>& adj, vector<bool>& visited, stack<int>& s, int node) {
    visited[node] = true;

    for (auto i : adj[node]) {
        if (!visited[i]) {
            topoSort(adj, visited, s, i);
        }
    }

    // Important
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>>& edges, int v, int e) {
    // Create adjacency list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // Call topology function for all the components
    vector<bool> visited(v);
    stack<int> s;
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            topoSort(adj, visited, s, i);
        }
    }

    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}


//TOPOLOGICAL SORT (KAHN'S ALGORITHIM)                                    {T.C = O(N+M),S.C = O(N+M)}
#include <bits/stdc++.h> 
#include<unordered_map>
#include<list>
#include<queue>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
    //create adjacancy list
    unordered_map<int,list<int>>adj;
    for(int i = 0 ; i < e ; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }

    //for all indegree
    vector<int>indegree(v);
    
    for(auto i : adj){
        for(auto j : i.second){
           indegree[j]++;
        }
    }

    // push 0 degree in queue
    queue<int>q;
    
    for(int i = 0 ; i < v ; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    //do bfs
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        //ans store
        ans.push_back(front);
        
        //neighbour indegree update
        for(auto neighbour : adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
    return ans;
}
/*
Sample Input 1:
2
2 1
1 0
3 2
0 1
0 2
Sample Output 1:
1 0
0 2 1
*/


////DETECT CYCLE IN A DIRECTED GRAPH                                    {T.C = O(N+M),S.C = O(N+M)}
//USING BFS
#include<unordered_map>
#include<list>
#include<queue>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  //create adjacancy list
  unordered_map<int,list<int>>adj;
  for(int i = 0 ; i < edges.size() ; i++){
      int u = edges[i].first-1;                   //vector<pair<int,int>>
      int v = edges[i].second-1;                  // -1 = to convert node start 1 to 0 
      
      adj[u].push_back(v);
  }
  //for all indegree
  vector<int>indegree(n);
  
  for(auto i : adj){
      for(auto j : i.second){
         indegree[j]++;
      }
  }
  // push 0 degree in queue
  queue<int>q;
  
  for(int i = 0 ; i < n ; i++){              
      if(indegree[i] == 0){
          q.push(i);
      }
  }
  //do bfs
  int count = 0;
  while(!q.empty()){
      int front = q.front();
      q.pop();
      //increament count
      count++;
      
      //neighbour indegree update
      for(auto neighbour : adj[front]){
          indegree[neighbour]--;
          if(indegree[neighbour]==0){
              q.push(neighbour);
          }
      }
  }
  if(count == n){                           //acyclic valid topological sort
      return false;                         //we check cycle 
  }
  else{
      return true;
  }
}


//SHORTEST PATH IN A UNWEIGHTED GRAPH                                   {T.C = O(N+M),S.C = O(N+M)}

#include<unordered_map>
#include<queue>
#include<list>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	//create adjacancy list
	unordered_map<int,list<int>>adj;
	for(int i = 0 ; i < m ; i++){
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//do Bfs
	unordered_map<int,bool>visited;
	unordered_map<int,int>parent;
	queue<int>q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	while(!q.empty()){
		int front = q.front();
		q.pop();

		for(auto i : adj[front]){
			if(!visited[i]){
				visited[i] = true;
				parent[i] = front;
				q.push(i);
			}
		}
	}

	//prepare shortest path
	vector<int>ans;
	int currentNode = t;
	ans.push_back(t);

	while(currentNode != s){
		currentNode = parent[currentNode];
		ans.push_back(currentNode);
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
/*
Sample Input 1 :
1
4 4
1 4
1 2
2 3
3 4
1 3
Sample Output 1 :
( 1 , 3 , 4 )
*/


//SHORTEST PATH IN DIRECTED ACYCLIC GRAPH


//DIJKSTRA'S SHORTEST PATH                                             {T.C = O(E(LOGV)),S.C = O(E+V)}
#include <bits/stdc++.h> 
#include<unordered_map>
#include<list>
#include<set>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    //create adjacancy list
    unordered_map<int,list<pair<int,int>>>adj;
    for(int i = 0 ; i < edges ; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    //create of distance array with infinite values initially
    vector<int>dist(vertices);
    for(int i = 0 ; i < vertices ; i++){
        dist[i] = INT_MAX;
    }

    //create a set on basis of (distance  , node)
    set<pair<int,int>>st;
    
    //intialize distance and set node with source node
    dist[source] = 0;
    st.insert(make_pair(0,source));

    while(!st.empty()){
        //fetch top record
        auto top = *(st.begin());
        int nodeDist = top.first;
        int topNode = top.second;

        //remove top recorde now
        st.erase(st.begin());

        //traverse on neighbour
        for(auto neighbour : adj[topNode]){
            if(nodeDist+neighbour.second < dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first] , neighbour.first));

                //if record found erase it 
                if(record != st.end()){
                    st.erase(record);
                }

                //distance update
                dist[neighbour.first] = nodeDist + neighbour.second;

                //record push in set
                st.insert(make_pair(dist[neighbour.first] , neighbour.first));
            }
        }
    }
    return dist;
}
//using priority queue
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    int n, m, source;
    cin >> n >> m;
    vector<pii > g[n + 1]; 	// 1-indexed adjacency list for of graph

    int a, b, wt;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> wt;
        g[a].push_back(make_pair(b, wt));
        g[b].push_back(make_pair(a, wt));
    }

    cin >> source;

    // Dijkstra's algorithm begins from here
    priority_queue<pii, vector<pii >, greater<pii > > pq;// min-heap ; In pair => (dist,from)
    vector<int> distTo(n + 1, INT_MAX); 	// 1-indexed array for calculating shortest paths; 

    distTo[source] = 0;
    pq.push(make_pair(0, source));	// (dist,from)

    while (!pq.empty()) {
        int dist = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        vector<pii >::iterator it;
        for (auto it : g[curr]) {
            int next = it.first;
            int nextDist = it.second;
            if (distTo[next] > distTo[curr] + nextDist) {
                distTo[next] = distTo[curr] + nextDist;
                pq.push(make_pair(distTo[next], next));
            }
        }
    }

    cout << "The distances from source, " << source << ", are : \n";
    for (int i = 1; i <= n; i++)	cout << distTo[i] << " ";
    cout << "\n";

    return 0;
}
/*
Sample input 1
2
5 7
0 1 7
0 2 1
0 3 2
1 2 3
1 3 5 
1 4 1
3 4 7
4 5
0 1 5
0 2 8
1 2 9
1 3 2
2 3 6
Sample output 1
0 4 1 2 5
0 5 8 7
*/


//PRIM'S MST(MINIMUM SPANNING TREE)                                                {T.C = O(N^2),S.C = O(E+V)} / T.C = E(LOGV) IF WE USE PRIORITY KEY IN MAIN LOOP 
#include <bits/stdc++.h> 
#include<unordered_map>
#include<list>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    //create adjacancy list
    unordered_map<int,list<pair<int,int>>>adj;
    for(int i = 0 ; i < g.size() ; i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    //create require datastructures
    vector<int>key(n+1);
    vector<bool>mst(n+1);
    vector<int>parent(n+1);

    //initialization
    for(int i = 0 ; i <= n ; i++){
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    //main algo
    key[1] = 0;
    parent[1] = -1;

    for(int i = 1 ; i < n ; i++){
        int mini = INT_MAX;
        int u;

        //find mini node
        for(int v = 1; v <= n; v++){
            if(mst[v] == false && key[v] < mini){
                u = v;
                mini  = key[v];
            }
        }

        //mark mini node as true
        mst[u] = true;

        //check its adjacent node
        for(auto i : adj[u]){
            int v = i.first;
            int w = i.second;

            if(mst[v] == false && w < key[v]){
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    //create ans/result
    vector<pair<pair<int, int>, int>>result;
    for(int i = 2 ; i <= n ; i++){
        result.push_back({{parent[i],i},key[i]});
    }

    return result;
}
/*

Sample Input 1 :
1
5 14
1 2 2
1 4 6
2 1 2
2 3 3
2 4 8
2 5 5
3 2 3
3 5 7
4 1 6
4 2 8
4 5 9
5 2 5
5 3 7
5 4 9
Sample Output 1 :
1 2 2
1 4 6
2 3 3
2 5 5
*/


//MINIMUM SPANNING TREE                                               {T.C = O(M*LOGM),S.C = O(N)}
#include <algorithm>
#include <vector>
// Compare on the basis of weight
bool cmp(vector<int>& a, vector<int>& b) {
  return a[2] < b[2];
}

void makeSet(vector<int>& parent, vector<int>& rank, int n) {
  for (int i = 0; i < n; i++) {
    parent[i] = i;
    rank[i] = 0;
  }
}

int findParent(vector<int>& parent, int node) {
  if (parent[node] == node) {
    return node;
  }
  return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
  u = findParent(parent, u);
  v = findParent(parent, v);

  if (rank[u] < rank[v]) {
    parent[u] = v;
  } else if (rank[u] > rank[v]) {
    parent[v] = u;
  } else {
    parent[v] = u;
    rank[u]++;
  }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n) {
  sort(edges.begin(), edges.end(), cmp);

  vector<int> parent(n);
  vector<int> rank(n);
  makeSet(parent, rank, n);

  int minW = 0;
  for (int i = 0; i < edges.size(); i++) {
    int u = findParent(parent, edges[i][0]);
    int v = findParent(parent, edges[i][1]);
    int w = edges[i][2];

    if (u != v) {
      minW += w;
      unionSet(u, v, parent, rank);
    }
  }
  return minW;
}
/*
Sample Input 2:
4 4
1 2 6
2 3 2
1 3 2
1 0 2
Sample Output 2:
6*/


//BRIDGES IN A GRAPH                                                       {T.C = O(E+V),S.C = O(N)}
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

void dfs(unordered_map<int, list<int>>& adj, unordered_map<int, bool>& visited, vector<int>& disc, vector<int>& low, vector<vector<int>>& result, int parent, int& timer, int node) {
    visited[node] = true;
    disc[node] = low[node] = timer++;

    for (auto nbr : adj[node]) {
        if (nbr == parent) {
            continue;
        }
        if (!visited[nbr]) {
            dfs(adj, visited, disc, low, result, node, timer, nbr);
            low[node] = min(low[node], low[nbr]);

            // Check if the edge is a bridge
            if (low[nbr] > disc[node]) {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else {
            // Back edge (node already visited && not parent)
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>>& edges, int v, int e) {

    // Create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Create all required data structures
    int timer = 0;
    vector<int> disc(v, -1);                        //discovery time
    vector<int> low(v, -1);                         //earliest possible time
    int parent = -1;
    unordered_map<int, bool> visited;

    vector<vector<int>> result;
    // DFS call
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            dfs(adj, visited, disc, low, result, parent, timer, i);
        }
    }
    return result;
}
/*
Sample Input 1 :
2
5 4
0 1
3 1
1 2
3 4
3 3
0 1
1 2
2 0
Sample Output 1 :
4
0 1
1 2    
1 3
3 4
0
*/


//ARTICULATION POINT IN A GRAPH                                         {T.C = O(N+E), S.C = O(N)}
#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>

using namespace std;

int min(int a , int b){
    if(a < b){
        return a;
    }
    else{
        return b;
    }
}
void dfs(int node , int parent , vector<int>&disc, vector<int>&low, unordered_map<int,bool>&vis,unordered_map<int,list<int>>&adj, vector<int>&ap, int &timer ){
    vis[node] = true;
    disc[node] = low[node] = timer++;

    int child = 0;

    for(auto nbr : adj[node]){
        if(nbr == parent){
            continue;
        }
        if(!vis[nbr]){
            dfs(nbr, node , disc, low, vis , adj, ap, timer);
            low[node] = min(low[node], low[nbr]);

            //chekck AP or not
            if(low[node] >= disc[node] && parent != -1){
                ap[node] = 1;
            }
            child++;
        }
        else{
            low[node] = min(low[node] , disc[nbr]);
        }
    }
    if(parent ==  -1 && child > 1){
        ap[node] = 1;
    }
}
int main(){
    int n = 5;
    int e = 5;

    vector<pair<int,int>>edges;
    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(3,4));
    edges.push_back(make_pair(0,4));
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(1,2));

    //create adjacancy list
    unordered_map<int,list<int>>adj;
    for(int i = 0 ; i < edges.size() ;i++ ){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    //create all require datastructures
    int timer = 0;
    int parent = -1;
    vector<int>disc(n);
    vector<int>low(n);
    unordered_map<int,bool>vis;
    vector<int>ap(n, 0);

    //initialization
    for(int i = 0 ; i < n ;i++){
        disc[i] = -1;
        low[i] = -1;
    }

    //dfs call
    for(int i = 0 ; i < n ; i++){
        if(!vis[i]){
            dfs(i,parent,disc, low, vis, adj, ap, timer);
        }
    }

    //print articulation points
    cout<<"Articulations points : "<<endl;
    for(int i = 0; i < n ; i++){
        if(ap[i] != 0){
            cout<<i<<" ";
        }cout<<endl;
    }
}
/*
output
Articulations points : 
0 
1 
*/


//COUNT STRONGLY CONNECTED COMPONENTS (KOSARAJU’S ALGORITM)                    {T.C = O(N+E), S.C = O(N)}
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>

using namespace std;

void dfs(unordered_map<int, list<int>>& adj, unordered_map<int, bool>& vis, stack<int>& s, int node) {
    vis[node] = true;
    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            dfs(adj, vis, s, nbr);
        }
    }
    //topo logic
    s.push(node);
}

void revDFS(unordered_map<int, list<int>>& adj, unordered_map<int, bool>& vis, int node) {
    vis[node] = true;
    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            revDFS(adj, vis, nbr);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>>& edges) {
    //create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //topo sort
    stack<int> s;
    unordered_map<int, bool> vis;
    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            dfs(adj, vis, s, i);
        }
    }

    //create transpose graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++) {
        vis[i] = false;
        for (auto nbr : adj[i]) {
            transpose[nbr].push_back(i);
        }
    }

    //revDFS call
    int count = 0;
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        if (!vis[top]) {
            count++;
            revDFS(transpose, vis, top);
        }
    }
    return count;
}
/*
Sample Input 2 :
2
1 0
4 4
0 1
1 2
2 3
3 1
Sample Output 2 :
1
2
*/


//BELLMON FORD                                  {T.C = O(N*M),S.C = O(N)}             
#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    
    vector<int>dist(n+1, 1e9);
    dist[src] = 0;

    //n-1 times
    for(int i = 1 ; i <= n ; i++){
        //traverse all edges
        for(int j = 0 ; j < m ; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(dist[u] != 1e9 && ((dist[u] + w < dist[v]))){
                dist[v] = dist[u] + w;
            }
        }
    }

    //check negative cycle
    bool flag = 0;
    for(int j = 0 ; j < m ; j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if(dist[u] != 1e9 && ((dist[u] + w < dist[v]))){
            flag = 1;
        }
    }
    if(flag == 0){
        return dist[dest];
    }
    return -1;
}
/*
Sample Input 1 :
1    
4 4 1 4
1 2 4
1 3 3
2 4 7 
3 4 -2
Sample Output 1 :
1
*/
