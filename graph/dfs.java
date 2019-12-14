import java.util.*;

class dfs
{
	int V;
	LinkedList<Integer> adj[];

	public dfs(int v)
	{
		this.V = v;
		adj = new LinkedList[v];

		for(int i=0;i<v;i++)
		{
			adj[i] = new LinkedList<Integer>();
		}
	}

	public void addEdge(int u, int v)
	{
		adj[u].add(v);
	}

	public void bfs(int root, boolean[] visited)
	{
		// Iterative
		visited[root] = true;
		Queue<Integer> q = new LinkedList<>();
		q.add(root);

		while(!q.isEmpty())
		{
			int el = q.poll();
			System.out.print(el+" ");

			for(Integer n: adj[el])
			{
				if(!visited[n])
				{
					visited[n] = true;
					q.add(n);
				}
			}
		}
	}

	public void bfs_a(int root)
	{
		boolean[] visited = new boolean[this.V];
		Arrays.fill(visited, false);
		bfs(root, visited);
	}

	public void dfs_iter(int root, boolean[] visited)
	{
		Stack<Integer> s = new Stack<>();
		s.push(root);
		visited[root] = true;
		while(!s.isEmpty())
		{
			int el = s.pop();
			System.out.print(el+" ");

			for(Integer n: adj[el])
			{
				if(!visited[n])
				{
					s.push(n);
					visited[n] = true;
				}
			}

		}
	}

	public void dfs_a(int root)
	{
		boolean visited[] = new boolean[this.V];

		dfs_iter(root, visited);
	}

	public void dfs_rec(int root, boolean[] visited)
	{
		visited[root] = true;
		System.out.print(root+" ");
		for(Integer n: adj[root])
		{
			if(!visited[n])
			{
				dfs_rec(n, visited);
			}
		}
	}

	public static void main(String args[]) 
    { 
        dfs g = new dfs(4); 
  
        g.addEdge(0, 1); 
        g.addEdge(0, 2); 
        g.addEdge(1, 2); 
        g.addEdge(2, 0); 
        g.addEdge(2, 3); 
        g.addEdge(3, 3); 
  
        System.out.println("Following is Breadth First Traversal "+ 
                           "(starting from vertex 2)"); 
  
        g.bfs_a(2); 
    } 
}