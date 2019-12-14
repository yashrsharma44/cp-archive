import java.util.*;

public class Graph1
{
	int V;
	LinkedList<Integer> adj[];

	public Graph1(int V)
	{
		this.V = V;
		this.adj = new LinkedList[V];

		for(int i=0;i<V;i++)
		{
			adj[i] = new LinkedList<Integer>();
		}
	}

	public void addEdge(int u, int v)
	{
		adj[u].add(v);
	}

	public int pathCount(int u, int d, boolean visited[], int count)
	{
		visited[u] = true;
		
		if(u==d)
		{
			count++;
		}
		else
		{
			for(int i=0;i<adj[u].size();i++)
			{
				if(!visited[adj[u].get(i)])
				{
					count = pathCount(adj[u].get(i), d, visited, count);
				}
			}
		}
		visited[u] = false;
		return count;
	}

	public static void main(String args[])
	{
		Graph1 g = new Graph1(4); 
        g.addEdge(0, 1); 
        g.addEdge(0, 2); 
        g.addEdge(0, 3); 
        g.addEdge(2, 0); 
        g.addEdge(2, 1); 
        g.addEdge(1, 3); 
  
        int s = 2, d = 3; 
        boolean visited[] = new boolean[4];
        Arrays.fill(visited, false);
        System.out.println(g.pathCount(s, d, visited,0)); 
	}
}