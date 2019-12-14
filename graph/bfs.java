import java.util.io;

public class Graph
{
	int V;
	LinkedList<LinkedList<Integer>> adj[];
	public Graph(int V)
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

	public void BFS(int root, LinkedList<Boolean> visited, LinkedList<Integer> res)
	{
		visited[root] = true;
		Queue<Integer> queue = new LinkedLinkedList<>();
		queue.add(root);

		while(!queue.isEmpty())
		{
			int s = queue.pop();

			res.add(s);
			for(int i=0;i<this.adj[s].size();i++)
			{
				if(!visited[this.adj[i]])
				{
					queue.add(this.adj[i]);
					visited(this.adj[i]) = true;
				}
			}

		}
	}

	public static void main()
	{
		Graph g = new Graph(4); 
  
        g.addEdge(0, 1); 
        g.addEdge(0, 2); 
        g.addEdge(1, 2); 
        g.addEdge(2, 0); 
        g.addEdge(2, 3); 
        g.addEdge(3, 3); 
  		LinkedList<Integer> res = new LinkedList<>();
  		LinkedList<Integer> visited = new LinkedList<>();
  		for(int i=0;i<4;i++)
  		{
  			visited[i]=false;
  		}
  		System.out.println("Following is Breadth First Traversal "+ 
                           "(starting from vertex 2)"); 
  
        g.BFS(2, visited, res);
        System.out.println(res); 
	}
}