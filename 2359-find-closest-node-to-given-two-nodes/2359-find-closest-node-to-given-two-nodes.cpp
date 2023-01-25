class Solution
{
    public:

        int closestMeetingNode(vector<int> &edges, int node1, int node2)
        {
            int n=edges.size();
            vector<int> dist1(n, -1);
            vector<int> dist2(n, -1);
            DFS(edges, node1, dist1, 0);
            DFS(edges, node2, dist2, 0);
            int minDist = INT_MAX;
            int minNode = -1;
            for (int i = 0; i < n; i++)
            {
                if (dist1[i] != -1 && dist2[i] != -1)
                {
                    if (max(dist1[i], dist2[i]) < minDist)
                    {
                        minDist = max(dist1[i], dist2[i]);
                        minNode = i;
                    }
                    // else if (max(dist1[i], dist2[i]) == minDist && i < minNode)
                    // {
                    //     minNode = i;
                    // }
                }
            }
            return minNode;
        }

    void DFS(vector<int> &edges, int node, vector<int> &dist, int d)
    {
        if (dist[node] != -1)
        {
            return;
        }
        dist[node] = d;
        if (edges[node] != -1)
        {
            DFS(edges, edges[node], dist, d + 1);
        }
    }
};