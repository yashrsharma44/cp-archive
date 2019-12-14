import java.util.*;

// Detect cycle in an undirected graph

public class cycle1
{
	int v;
	LinkedList<Integer> adj[];

	public cycle1(int v)
	{
		this.v = v;
		adj = new LinkedList[v];

		for(int i=0;i<v;i++)
		{
			adj[i] = new LinkedList<>();
		}
	}

	public void addEdge(int u, int v)
	{
		adj[u].add(v);
		adj[v].add(u);
	}

	public boolean checkCycle()
	{
		boolean visited[] = new boolean[this.v];

		for(int i=0;i<this.v;i++)
		{
			if(!visited[i] && checkCycleUtil(i, visited, -1))
			{
				// System.out.println(i+"THIS");
				return true;
			}
		}

		return false;
	}

	public boolean checkCycleUtil(int root, boolean[] visited, int parent)
	{
		visited[root] = true;

		for(Integer n: adj[root])
		{
			if(!visited[n])
			{
				if(checkCycleUtil(n, visited, root))
					return true;

			}
			else if(n!=parent)
				return true;
		}

		return false;
	}

	public boolean checkCycleIterUtil(int root, boolean[] visited)
	{
		// Out here we are storing a visited array for checking if an 

		Stack<Integer> stack = new Stack<>();
		stack.push(root);
		int parent[] = new int[this.v];
		visited[root] = true;
		parent[root] = -1;
		while(!stack.isEmpty())
		{
			int el = stack.pop();

			for(Integer n: adj[el])
			{
				if(!visited[n])
				{
					visited[n] = true;
					parent[n] = el;
					stack.push(n);
				}
				else if(el != parent[n])
					return true;
			}
		}
		return false;
	}

	public boolean checkCycleIter()
	{
		boolean visited[] = new boolean[this.v];

		for(int i=0;i<this.v;i++)
		{
			if(checkCycleIterUtil(i, visited))
				return true;
		}

		return false;
	}

	public static void main(String args[]) 
    { 
        // Create a graph given in the above diagram 
        cycle1 g1 = new cycle1(5); 
        g1.addEdge(1, 0); 
        g1.addEdge(0, 2); 
        g1.addEdge(2, 1); 
        g1.addEdge(0, 3); 
        g1.addEdge(3, 4); 
        if (g1.checkCycle()) 
            System.out.println("Graph contains cycle"); 
        else
            System.out.println("Graph doesn't contains cycle"); 
  
        cycle1 g2 = new cycle1(3); 
        g2.addEdge(0, 1); 
        g2.addEdge(1, 2); 
        // System.out.println(g2.adj)0;
        // for(LinkedList<Integer> n: g2.adj)
        // {
        // 	for(Integer n1: n)
        // 	{
        // 		System.out.print(" "+n1);
        // 	}
        // 	System.out.println("");
        // }
        if (g2.checkCycle()) 
            System.out.println("Graph contains cycle"); 
        else
            System.out.println("Graph doesn't contains cycle"); 
    } 
} 
