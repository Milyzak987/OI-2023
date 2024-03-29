
void dfs(int x) {
    visited[x] = 1;
    for (auto u : graph[x]) {
        if (!visited[u]) dfs(u);
    }
}

void BFS(int x) {
    queue<int> q;
    q.push(x);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : graph[v])
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
    }
}

void zeroOneBFS(int src) {
    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    deque<int> Q;
    dist[src] = 0;
    Q.push_back(src);

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop_front();

        for (int i = 0; i < edges[v].size(); i++) {
            if (dist[edges[v][i].to] > dist[v] + edges[v][i].weight) {
                dist[edges[v][i].to] = dist[v] + edges[v][i].weight;
                if (edges[v][i].weight == 0)
                    Q.push_front(edges[v][i].to);
                else
                    Q.push_back(edges[v][i].to);
            }
        }
    }
}

void dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[s] = 0;
    pq.push(make_pair(0, s));
    while (!pq.empty()) {
        s = pq.top().second;
        pq.pop();
        for (int i = 0; i < graph[s].size(); i++) {
            int u = graph[s][i].first;
            if (dist[s] + graph[s][i].second < dist[u] || dist[u] == -1) {
                dist[u] = dist[s] + graph[s][i].second;
                pq.push(make_pair(dist[u], u));
            }
        }
    }
}

int find(int i) {
    if (Parent[i] == i) {
        return i;
    } else {
        int result = find(Parent[i]);
        Parent[i] = result;
        return result;
    }
}

void uni(int i, int j) {
    int irep = find(i);
    int jrep = find(j);
    if (irep == jrep)
        return;

    int isize = Size[irep];
    int jsize = Size[jrep];
    if (isize < jsize) {
        Parent[irep] = jrep;
        Size[jrep] += Size[irep];
    } else {
        Parent[jrep] = irep;
        Size[irep] += Size[jrep];
    }
}

long long power(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        n /= 2;
    }
    return res;
}
