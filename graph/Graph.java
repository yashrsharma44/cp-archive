import java.util.*;

public class Graph
{
	int V;
	LinkedList<Integer> adj[];
	public Graph(int V)
	{
		this.V = V;
		adj = new LinkedList[V];

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
		visited.set(root,true);
		LinkedList<Integer> queue = new LinkedList<>();
		queue.add(root);

		while(!queue.isEmpty())
		{
			int s = queue.pop();

			res.add(s);
			for(int i=0;i<this.adj[s].size();i++)
			{
				if(!visited.get(this.adj[s].get(i)))
				{
					queue.add(this.adj[s].get(i));
					visited.set(this.adj[s].get(i), true);
				}
			}

		}
	}

	public void DFS(int root, LinkedList<Boolean> visited, LinkedList<Integer> res)
	{
		// Iterative version

		Stack<Integer> s = new Stack<Integer>();
		s.push(root);
		visited.set(root, true);

		while(!s.isEmpty())
		{
			int el = s.pop();
			res.add(el);
			for(Integer n: adj[el])
			{
				if(!visited.get(n))
				{
					s.push(n);
					visited.set(n, true);
				}
			}
		}
	}

	public int countLevel(int root, LinkedList<Boolean> visited, int val)
	{	
		visited.set(root, true);
		Queue<Integer> queue = new LinkedList<>();
		queue.add(root);

		// Create an array of levels
		int[] level = new int[this.V];
		for(int i=0;i<this.V;i++) level[i]=0;

		while(!queue.isEmpty())
		{
			int s = queue.poll();

			for(int i=0;i<this.adj[s].size();i++)
			{
				if(!visited.get(adj[s].get(i)))
				{
					visited.set(adj[s].get(i), true);
					level[adj[s].get(i)] = level[s] + 1;
					queue.add(adj[s].get(i));
				}
			}
		}

		int count=0;

		for(int i=0;i<V;i++)
		{
			if(level[i] == val)count+=1;
		}
		// for(int i=0;i<level.length;i++)System.out.print(" "+level[i]);
		return count;
	}

	public static void main(String args[])
	{
		Graph g = new Graph(6); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(2, 4); 
    g.addEdge(2, 5); 
  
    int level = 2; 
  		LinkedList<Integer> res = new LinkedList<>();
  		LinkedList<Boolean> visited = new LinkedList<>();
  		for(int i=0;i<6;i++)
  		{
  			visited.add(false);
  		}
  		System.out.println("Following is Breadth First Traversal "+ 
                           "(starting from vertex 2)"); 
  
        g.BFS(0, visited, res);
        
        System.out.println(res); 
        for(int i=0;i<6;i++)
  		{
  			visited.set(i,false);
  		}
  		LinkedList<Integer> res1 = new LinkedList<>(); 
  		g.DFS(0, visited, res1); 		
        System.out.println(res1);
	}
}